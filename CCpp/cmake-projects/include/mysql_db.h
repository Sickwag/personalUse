#ifndef MYSQL_DB_H
#define MYSQL_DB_H

#include <mysqlx/xdevapi.h>
#include <memory>
#include <string>
#include <vector>
#include <filesystem>

class MySQLDB {
public:
    MySQLDB(const std::string& host, unsigned int port, 
           const std::string& user, const std::string& password);
    
    bool connect();
    int execute_sql(const std::string& sql);
    int execute_sql_file(const std::filesystem::path& file_path);
    
    std::unique_ptr<mysqlx::RowResult> query(const std::string& sql);
    void display_result(std::unique_ptr<mysqlx::RowResult>& result);
    
    template<typename... Args>
    int execute_prepared(const std::string& sql, Args... args) {
        auto stmt = session_->prepare(sql);
        auto sql_result = stmt.execute(args...);
        return sql_result.getAffectedItemsCount();
    }
    
    bool is_initialized() const { return static_cast<bool>(session_); }
    void print_error(const std::string& context = "Database error");

private:
    std::string host_;
    unsigned int port_;
    std::string user_;
    std::string password_;
    std::unique_ptr<mysqlx::Session> session_;
};

#endif // MYSQL_DB_H
