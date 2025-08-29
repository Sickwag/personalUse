#include <boost/mysql/any_connection.hpp>
#include <boost/asio/io_context.hpp>
#include <iostream>
#include <iomanip>
#include <string>
namespace mysql = boost::mysql;
namespace asio = boost::asio;

struct db_config {
    std::string host;
    unsigned short port;
    std::string database;
    std::string username;
    std::string password;
    mysql::ssl_mode ssl;
};



class DBConnect {
    private:
    db_config config_;
    asio::io_context ctx;
    mysql::any_connection conn_;
    
    public:
    DBConnect(asio::io_context& ctx) : config_({"mysql2.sqlpub.com", 3307, "sickwag_learning", "sickwag", "LqX9jBDqvDJYeooE", mysql::ssl_mode::disable}), conn_(ctx.get_executor()) {
        mysql::connect_params params;
        params.server_address.emplace_host_and_port(config_.host, config_.port);
        params.username = config_.username;
        params.database = config_.database;
        params.password = config_.password;
        params.ssl = config_.ssl;
        conn_.connect(params);
        if(conn_.connection_id()){
            std::cout << "connected " + config_.host + " success.\n";
        }
    };
    void test_mysql_db(){
        std::string sql = "select * from users;";
        mysql::results res;
        conn_.execute(sql, res);
        if(res.empty()){
            std::cout << "the users table is empty.\n";
        }else{
            // Debug information
            std::cout << "Result set size: " << res.size() << "\n";
            const auto& meta = res.meta();
            std::cout << "Meta size: " << meta.size() << "\n";
            
            // Print column headers
            if (meta.size() > 0) {
                for (size_t i = 0; i < meta.size(); i++){
                    if(i > 0)
                        std::cout << "\t";
                    std::cout << meta[i].column_name();
                }
                std::cout << '\n';
            } else {
                std::cout << "No column metadata available\n";
            }
            
            // Print data rows
            for(const auto& row : res.rows()){
                for (size_t i = 0; i < row.size(); i++){
                    if(i > 0)
                        std::cout << "\t";
                    std::cout << row[i];
                }
                std::cout << "\n";
            }
        }
    }

    ~DBConnect() { conn_.close(); };
};


int main(int, char**) {
    std::cout << "Hello, from test_db_conn!\n";
    asio::io_context ctx;
    DBConnect db(ctx);
    db.test_mysql_db();
}
