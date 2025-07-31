#pragma once

#include <boost/asio.hpp>
#include <boost/mysql/any_address.hpp>
#include <boost/mysql/with_params.hpp>
#include <boost/mysql/any_connection.hpp>
#include <boost/mysql/pfr.hpp>
#include <boost/mysql/results.hpp>
#include <boost/mysql/static_results.hpp>
#include <boost/mysql/results.hpp>
#include <boost/mysql/ssl_mode.hpp>
#include <stdexcept>
#include <iostream>
#include <string_view>
#include <vector>
namespace mysql = boost::mysql;
namespace asio = boost::asio;
using asio::awaitable;
using asio::use_awaitable;

// 连接配置结构体
struct DBConfig {
    std::string host;
    std::uint16_t port = 3306;
    std::string user;
    std::string password;
    std::string database;
    mysql::ssl_mode ssl = mysql::ssl_mode::enable;
};

// SQL错误异常类
struct sql_error : std::runtime_error {
    using std::runtime_error::runtime_error;
};

// 用户结构体示例
struct user {
    std::optional<int> id;
    std::optional<std::string> name;
};

// MySQL数据库操作类
class MySQLDB {
   public:
    MySQLDB() = delete;

    /**
     * @param ex 通常传入io_context对象的executor，如果传入asio::this_coro::executor表示当前协程被 co_spawn 时绑定的那个 executor
     * @waring param ex 的生命周期必须要比MySQLDB类对象的长，否则会引发悬空引用
     */
    explicit MySQLDB(asio::any_io_executor ex) : conn_(ex) {}
    awaitable<void> connect(const DBConfig& cfg);
    awaitable<size_t> execute(std::string_view sql);
    awaitable<size_t> execute_script(const std::string& script);

    template <typename... Args>
    awaitable<size_t> execute_multi(Args&&... args);

    awaitable<void> execute_multi(std::string_view sql_batch);

    template <typename... Args>
    awaitable<mysql::results> query(std::string_view sql, Args&&... args) {
        auto stmt = co_await conn_.async_prepare_statement(sql, use_awaitable);
        mysql::results res;
        co_await conn_.async_execute(stmt.bind(std::forward<Args>(args)...), res, use_awaitable);
        co_return res;
    }

    template <typename T>
    awaitable<std::vector<T>> query_into(std::string_view sql) {
        mysql::static_results<mysql::pfr_by_name<T>> res;
        co_await conn_.async_execute(sql, res);
        std::vector<T> results;
        if (res.rows().empty()) {
            throw std::runtime_error("sql matched nothing.");
            co_return std::vector<T>();
        } else {
            for (const auto& row : res.rows()) {
                const T& res_struct = row;
                results.emplace_back(res_struct);
            }
        }
        co_return results;
    }
    awaitable<void> begin();
    awaitable<void> commit();
    awaitable<void> rollback();
    awaitable<void> close() noexcept;

   private:
    mysql::any_connection conn_;
    static std::vector<std::string_view> split_script(const std::string& script);
};

template <typename... Args>
inline awaitable<size_t> MySQLDB::execute_multi(Args&&... args) {
    mysql::results result;
    try {
        co_await conn_.async_execute(mysql::with_params(std::forward<Args>(args)...), result, use_awaitable);
    } catch (const mysql::error_with_diagnostics& err) {
        std::cerr << err.code() << '\n'
                  << err.what() << '\n';
    }
    co_return result.affected_rows();
}
