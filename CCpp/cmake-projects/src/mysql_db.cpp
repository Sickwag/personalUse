#include "mysql_db.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <mysqlx/xdevapi.h>


MySQLDB::MySQLDB(const std::string& host, unsigned int port, 
                const std::string& user, const std::string& password)
    : host_(host), port_(port), user_(user), password_(password) {}

bool MySQLDB::connect() {
    try {
        session_ = std::make_unique<mysqlx::Session>(mysqlx::Session(host_, port_, user_, password_));
        return true;
    } catch (const mysqlx::Error& err) {
        session_.reset();
        std::cerr << "MySQL connection error: " << err.what() << std::endl;
        return false;
    }
}

int MySQLDB::execute_sql(const std::string& sql) {
    if (!is_initialized()) {
        print_error("execute_sql - No active connection");
        return -1;
    }
    
    try {
        auto result = session_->sql(sql).execute();
        return result.getAffectedItemsCount();
    } catch (const mysqlx::Error& err) {
        std::cerr << "SQL execution error: " << err.what() << std::endl;
        return -1;
    }
}

int MySQLDB::execute_sql_file(const std::filesystem::path& file_path) {
    if (!std::filesystem::exists(file_path)) {
        print_error("SQL file not found: " + file_path.string());
        return -1;
    }

    std::ifstream file(file_path);
    if (!file.is_open()) {
        print_error("Failed to open SQL file: " + file_path.string());
        return -1;
    }

    std::stringstream buffer;
    buffer << file.rdbuf();
    std::string sql = buffer.str();
    file.close();
    
    return execute_sql(sql);
}

std::unique_ptr<mysqlx::RowResult> MySQLDB::query(const std::string& sql) {
    if (!is_initialized()) {
        print_error("Query - No active connection");
        return nullptr;
    }
    
    try {
        return std::make_unique<mysqlx::RowResult>(session_->sql(sql).execute());
    } catch (const mysqlx::Error& err) {
        std::cerr << "Query execution error: " << err.what() << std::endl;
        return nullptr;
    }
}

void MySQLDB::display_result(std::unique_ptr<mysqlx::RowResult>& result) {
    if (!result) {
        std::cerr << "Invalid result set" << std::endl;
        return;
    }

    std::cout << "Query result (" << result->getColumnCount() << " columns):" << std::endl;
    
    auto rows = result->fetchAll();
    for (const auto& row : rows) {
        for (size_t i = 0; i < result->getColumnCount(); ++i) {
            if (row[i].isNull()) {
                std::cout << "NULL" << "\t";
            } else {
                std::cout << row[i].get<std::string>() << "\t";
            }
        }
        std::cout << std::endl;
    }
}

void MySQLDB::print_error(const std::string& context) {
    std::cerr << context << " - Error: ";
    if (session_) {
        try {
            throw;
        } catch (const mysqlx::Error& err) {
            std::cerr << err.what();
        } catch (...) {
            std::cerr << "Unknown error";
        }
    } else {
        std::cerr << "No session available";
    }
    std::cerr << std::endl;
}
