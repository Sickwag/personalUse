// MySQLDB.cpp
#include "MySQLDB.h"
#include <iostream>
#include <fstream>
#include <boost/algorithm/string/trim.hpp>

namespace mysql = boost::mysql;
namespace asio = boost::asio;
using asio::awaitable;
using asio::use_awaitable;

// 连接到数据库
awaitable<void> MySQLDB::connect(const DBConfig& cfg) {
    mysql::connect_params params;
    params.server_address.emplace_host_and_port(cfg.host, cfg.port);
    params.username = cfg.user;
    params.password = cfg.password;
    params.database = cfg.database;
    params.ssl = cfg.ssl;
    co_await conn_.async_connect(params, use_awaitable);
    std::cout << "connect to mysql successfully.\n";
}

// ---------- 1. 执行单条语句 ----------
awaitable<size_t> MySQLDB::execute(std::string_view sql) {
    mysql::results res;
    auto stmt = co_await conn_.async_prepare_statement(sql, use_awaitable);
    co_await conn_.async_execute(stmt.bind(), res, use_awaitable);
    if (res.affected_rows() == static_cast<std::uint64_t>(-1)){
        throw sql_error("execute failed");
    }
    co_return res.affected_rows();
}

// ---------- 2. 执行整个SQL脚本 ----------
awaitable<size_t> MySQLDB::execute_script(const std::string& script_path) {
    size_t total_affected = 0;
    std::ifstream ifs(script_path);
    if(!ifs){
        throw std::runtime_error("cannot open " + script_path + " this file");
    }
    std::ostringstream oss;
    oss<<ifs.rdbuf();
    std::string content = oss.str();
    std::vector<std::string_view> stmts = split_script(content);
    for (const auto& stmt : stmts) {
        if (!stmt.empty()) {
            total_affected += co_await execute(stmt);
        }
    }
    co_return total_affected;
}


// 多次通过调用单行执行语句执行mysql
awaitable<void> MySQLDB::execute_multi(std::string_view sql_batch) {
    auto executor = co_await boost::asio::this_coro::executor;
    std::vector<std::string_view> statements;

    size_t start = 0;
    bool in_statement = false;

    for (size_t i = 0; i <= sql_batch.size(); ++i) {
        if (i < sql_batch.size()) {
            char c = sql_batch[i];
            if (!std::isspace(static_cast<unsigned char>(c))) {
                if (!in_statement) {
                    start = i;
                    in_statement = true;
                }
            }
            if (c == ';' && in_statement) {
                size_t len = i - start;
                if (len > 0) {
                    statements.emplace_back(sql_batch.substr(start, len));
                }
                in_statement = false;
            }
        } else {
            if (in_statement) {
                size_t len = sql_batch.size() - start;
                statements.emplace_back(sql_batch.substr(start, len));
            }
        }
    }
    for (auto& stmt : statements) {
        auto trimmed = boost::trim_copy(std::string(stmt));
        if (!trimmed.empty()){
            co_await execute(stmt);
        }
    }
    co_return;
}

// ---------- 5. 事务操作 ----------
awaitable<void> MySQLDB::begin() { co_await execute("START TRANSACTION"); }
awaitable<void> MySQLDB::commit() { co_await execute("COMMIT"); }
awaitable<void> MySQLDB::rollback() { co_await execute("ROLLBACK"); }

// ---------- 6. 关闭连接 ----------
awaitable<void> MySQLDB::close() noexcept {
    boost::system::error_code ec;
    co_await conn_.async_close(asio::redirect_error(use_awaitable, ec));
}

// 分割SQL脚本为多个语句
std::vector<std::string_view> MySQLDB::split_script(const std::string& script) {
    std::vector<std::string_view> statements;
    size_t start = 0;
    size_t pos = 0;
    
    while (pos < script.length()) {
        // 查找分号
        pos = script.find(';', start);
        if (pos == std::string_view::npos) {
            pos = script.length();
        }
        
        // 提取语句
        std::string_view stmt = script.substr(start, pos - start);
        
        // 去除首尾空白字符
        while (!stmt.empty() && (stmt.front() == ' ' || stmt.front() == '\t' || stmt.front() == '\n' || stmt.front() == '\r')) {
            stmt.remove_prefix(1);
        }
        while (!stmt.empty() && (stmt.back() == ' ' || stmt.back() == '\t' || stmt.back() == '\n' || stmt.back() == '\r')) {
            stmt.remove_suffix(1);
        }
        
        if (!stmt.empty()) {
            statements.push_back(stmt);
        }
        start = pos + 1;
    }
    
    return statements;
}