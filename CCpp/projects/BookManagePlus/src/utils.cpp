#include <curl/curl.h>
#include <curl/easy.h>
#include <boost/asio.hpp>
#include <boost/asio/experimental/awaitable_operators.hpp>
#include <iostream>
#include "utils.h"
#include "service_locator.h"
#include "MySQLDB.h"
#include "identities.h"

void is_already_done(bool flag, const std::string& description, std::exception& err) {
    if (flag) {
        std::cout << description << " successfully.\n";
    } else {
        std::cerr << description << " failed for unknow reason.\n"
                  << err.what();
    }
}

void is_already_done(bool flag, const std::string& description) {
    if (flag) {
        std::cout << description << " successfully.\n";
    } else {
        std::cerr << description << " failed for unknow reason.\n";
    }
}

void get_weather() {
    CURL* curl = curl_easy_init();
    if (!curl)
        return;

    std::string response;
    curl_easy_setopt(curl, CURLOPT_URL, "https://api.dwo.cc/api/tianqi?districtId=上海市");
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);
    curl_easy_setopt(curl, CURLOPT_TIMEOUT, 10L);
    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);

    CURLcode rc = curl_easy_perform(curl);
    if (rc != CURLE_OK) {
        std::cerr << "request failed: " << curl_easy_strerror(rc) << '\n';
        curl_easy_cleanup(curl);
        return;
    }

    long status = 0;
    curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &status);
    curl_easy_cleanup(curl);

    if (status != 200 || response.empty()) {
        std::cerr << "HTTP error/empty\n";
        return;
    }

    try {
        json j = json::parse(response);
        if (j.value("code", 0) == 1) {
            const auto& d = j["data"];
            std::cout << "城市: " << d.value("city", "") << "\n"
                      << "日期: " << d.value("date", "") << "\n"
                      << "天气: " << d.value("weather", "") << "\n"
                      << "当前温度: " << d.value("temp", "") << "\n"
                      << "体感: " << d.value("feelsLike", "") << "\n"
                      << "最低/最高: " << d.value("lowTemp", "") << "/" << d.value("highTemp", "") << "\n"
                      << "风向风力: " << d.value("wind", "") << "\n";
        } else {
            std::cerr << "API error: " << j.value("message", "") << '\n';
        }
    } catch (const std::exception& e) {
        std::cerr << "JSON parse error: " << e.what() << '\n';
    }
}

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

size_t WriteCallback(void* contents, size_t size, size_t nmemb, std::string* output) {
    size_t total = size * nmemb;
    output->append(static_cast<char*>(contents), total);
    return total;
}

asio::awaitable<void> start_service(asio::io_context& ioc) {
    try {
        // 注册服务
        ServiceLocator::provide<MySQLDB>(std::make_shared<MySQLDB>(ioc.get_executor()));
        ServiceLocator::provide<InputValidator<std::string>>(std::make_shared<InputValidator<std::string>>());
        ServiceLocator::provide<InputValidator<int>>(std::make_shared<InputValidator<int>>());
        ServiceLocator::provide<DBConfig>(std::make_shared<DBConfig>());
        ServiceLocator::provide<EmailTemplate>(std::make_shared<EmailTemplate>());
        ServiceLocator::provide<EmailSender>(std::make_shared<EmailSender>());

        std::cout << "Services registered successfully" << std::endl;

        auto& db_config = ServiceLocator::get<DBConfig>();
        db_config.host = "mysql2.sqlpub.com";
        db_config.port = 3307;
        db_config.user = "sickwag";
        db_config.password = "LqX9jBDqvDJYeooE";
        db_config.database = "sickwag_learning";
        db_config.ssl = mysql::ssl_mode::enable;

        // 注意：数据库连接现在在需要时按需创建，而不是在这里预连接

        auto& et = ServiceLocator::get<EmailTemplate>();
        auto& email = ServiceLocator::get<EmailSender>();
        email.email_config = et;
        
        std::cout << "Service initialization completed" << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error in start_service: " << e.what() << std::endl;
    }
    co_return;
}

// unused
void start_service_sync(asio::io_context& ioc) {
    try {
        // 注册服务
        ServiceLocator::provide<MySQLDB>(std::make_shared<MySQLDB>(ioc.get_executor()));
        ServiceLocator::provide<InputValidator<std::string>>(std::make_shared<InputValidator<std::string>>());
        ServiceLocator::provide<InputValidator<int>>(std::make_shared<InputValidator<int>>());
        ServiceLocator::provide<DBConfig>(std::make_shared<DBConfig>());
        ServiceLocator::provide<EmailTemplate>(std::make_shared<EmailTemplate>());
        ServiceLocator::provide<EmailSender>(std::make_shared<EmailSender>());

        std::cout << "Services registered successfully" << std::endl;

        auto& db_config = ServiceLocator::get<DBConfig>();
        db_config.host = "mysql2.sqlpub.com";
        db_config.port = 3307;
        db_config.user = "sickwag";
        db_config.password = "LqX9jBDqvDJYeooE";
        db_config.database = "sickwag_learning";
        db_config.ssl = mysql::ssl_mode::enable;

        // 注意：数据库连接现在在需要时按需创建，而不是在这里预连接

        auto& et = ServiceLocator::get<EmailTemplate>();
        auto& email = ServiceLocator::get<EmailSender>();
        email.email_config = et;
        
        std::cout << "Service initialization completed" << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error in start_service: " << e.what() << std::endl;
    }
}
