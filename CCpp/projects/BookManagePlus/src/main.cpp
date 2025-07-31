#include <curl/curl.h>
#include <curl/easy.h>
#include <boost/asio.hpp>
#include <boost/asio/experimental/awaitable_operators.hpp>
#include <iostream>
#include <format>
#include <nlohmann/json.hpp>
#include <io.h>
#include <fcntl.h>
#include <Windows.h>

#include "MySQLDB.h"
#include "email_sender.h"
#include "identities.h"
#include "service_locator.h"
#include "utils.h"

using json = nlohmann::json;
namespace asio = boost::asio;
namespace mysql = boost::mysql;


asio::awaitable<void> test_mysql_functions() {
    try {
        // 创建数据库连接对象
        MySQLDB db(co_await asio::this_coro::executor);

        // 配置数据库连接参数
        DBConfig cfg;
        cfg.host = "mysql2.sqlpub.com";
        cfg.port = 3307;
        cfg.user = "sickwag";
        cfg.password = "LqX9jBDqvDJYeooE";
        cfg.database = "sickwag_learning";
        cfg.ssl = mysql::ssl_mode::enable;

        // 连接到数据库
        std::cout << "Connecting to database..." << std::endl;
        co_await db.connect(cfg);
        std::cout << "Connected successfully!" << std::endl;

        // 1. 测试执行单条语句
        std::cout << "\n1. Testing execute() function..." << std::endl;
        std::string sql_string = "CREATE TABLE IF NOT EXISTS test_users (id INT, name VARCHAR(255))";
        co_await db.execute(sql_string);
        std::cout << "Single statement executed successfully!" << std::endl;

        // 2. 测试执行SQL脚本
        std::cout << "\n2. Testing execute_script() function..." << std::endl;
        std::string script = "INSERT INTO test_users VALUES (1, 'Alice'); INSERT INTO test_users VALUES (2, 'Bob'); INSERT INTO test_users VALUES (3, 'Charlie');";
        co_await db.execute_script(script);
        std::cout << "SQL script executed successfully!" << std::endl;

        // 3. 测试执行预处理语句
        std::cout << "\n3. Testing query() function..." << std::endl;
        auto result = co_await db.query("SELECT * FROM test_users WHERE id = ?", 2);
        std::cout << "Prepared statement executed successfully!" << std::endl;
        std::cout << "Query result: " << result.rows().size() << " rows returned" << std::endl;

        // 4. 测试将SQL执行结果解析到简单结构体
        std::cout << "\n4. Testing query_into() function..." << std::endl;
        auto users = co_await db.query_into<user>("SELECT id, name FROM test_users");
        std::cout << "Query results parsed into struct successfully!" << std::endl;
        std::cout << "Retrieved " << users.size() << " users:" << std::endl;
        for (const auto& u : users) {
            std::cout << "  ID: " << u.id.value() << ", Name: " << u.name.value() << std::endl;
        }

        // 5. 测试事务操作
        std::cout << "\n5. Testing transaction operations..." << std::endl;
        co_await db.begin();
        co_await db.execute("INSERT INTO test_users VALUES (4, 'David')");
        co_await db.rollback();  // 回滚事务

        // 验证回滚是否成功
        auto users_after_rollback = co_await db.query_into<user>("SELECT id, name FROM test_users WHERE id = 4");
        if (users_after_rollback.empty()) {
            std::cout << "Transaction rollback successful!" << std::endl;
        } else {
            std::cout << "Transaction rollback failed!" << std::endl;
        }

        // 关闭数据库连接
        co_await db.close();
        std::cout << "\nDatabase connection closed." << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

// 测试Reader类功能的异步函数
asio::awaitable<void> test_reader_functions() {
    try {
        // 创建Reader对象，传入数据库引用
        MySQLDB db(co_await asio::this_coro::executor);

        // 配置数据库连接参数
        DBConfig cfg;
        cfg.host = "mysql2.sqlpub.com";
        cfg.port = 3307;
        cfg.user = "sickwag";
        cfg.password = "LqX9jBDqvDJYeooE";
        cfg.database = "sickwag_learning";
        cfg.ssl = mysql::ssl_mode::enable;

        // 连接到数据库
        std::cout << "Connecting to database..." << std::endl;
        co_await db.connect(cfg);
        std::cout << "Connected successfully!" << std::endl;

        Role reader;

        // 测试登录功能
        std::cout << "\nTesting login_with_pwd..." << std::endl;
        co_await reader.login_with_pwd();
        std::cout << "Login successful!" << std::endl;

    } catch (const std::exception& e) {
        std::cerr << "Error in test_reader_functions: " << e.what() << std::endl;
    }
}

asio::awaitable<void> start_service(asio::io_context& ioc) {
    try {
        // 注册服务
        ServiceLocator::provide(std::make_shared<MySQLDB>(ioc.get_executor()));
        ServiceLocator::provide(std::make_shared<InputValidator<std::string>>());
        ServiceLocator::provide(std::make_shared<InputValidator<int>>());
        ServiceLocator::provide(std::make_shared<DBConfig>());
        ServiceLocator::provide(std::make_shared<EmailTemplate>());
        ServiceLocator::provide(std::make_shared<EmailSender>());
        
        auto& db_config = ServiceLocator::get<DBConfig>();
        db_config.host = "mysql2.sqlpub.com";
        db_config.port = 3307;
        db_config.user = "user";
        db_config.password = "password";
        db_config.database = "base";
        db_config.ssl = mysql::ssl_mode::enable;
        
        auto& db = ServiceLocator::get<MySQLDB>();
        co_await db.connect(db_config);
        
        auto& et = ServiceLocator::get<EmailTemplate>();
        auto& email = ServiceLocator::get<EmailSender>();
        email.email_config = et;
    } catch (const std::exception& e) {
        std::cerr << "Error in start_service: " << e.what() << std::endl;
    }
}
int main(int argc, char* argv[]) {
    // 设置控制台UTF-8编码支持
    SetConsoleOutputCP(CP_UTF8);
    setvbuf(stdout, nullptr, _IOFBF, 1000);
    
    try {
        get_weather();
        // boost::asio::io_context ioc;// 管理所有协程类服务，生命周期必须比这些服务长

        // auto& logger = ServiceLocator::get<Logger>();
        // asio::co_spawn(ioc, test_mysql_functions(), asio::detached);
        // asio::co_spawn(ioc, test_reader_functions(), asio::detached);
        // asio::co_spawn(ioc, start_service(ioc), asio::detached);
        // ioc.run();
    } catch (const std::exception& e) {
        std::cerr << "Exception in main: " << e.what() << std::endl;
        return 1;
    }

    // curl_global_init(CURL_GLOBAL_DEFAULT);
    // std::vector<std::string> attachments;
    // attachments.push_back(R"(D:\Code Files\vscode\CCpp\projects\BookManagePlus\scripts\email_sender_cli.py)");
    // attachments.push_back(R"(D:\Code Files\vscode\CCpp\projects\BookManagePlus\scripts\emailSender.py)");
    // bool success = EmailSender().send_email(et);
    // curl_global_cleanup();

    return 0;
}
