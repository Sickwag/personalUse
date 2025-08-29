#include <boost/asio.hpp>
#include <boost/mysql.hpp>
#include <boost/mysql/tcp_ssl.hpp>
#include <iostream>
#include <map>
#include <nlohmann/json.hpp>
#include <sstream>
#include <string>
#include <thread>

using boost::asio::ip::tcp;
using json = nlohmann::json;

namespace mysql = boost::mysql;
namespace asio = boost::asio;

// 数据库配置
struct db_config {
    std::string host = "mysql2.sqlpub.com";
    unsigned short port = 3307;
    std::string database = "sickwag_learning";
    std::string username = "sickwag";
    std::string password = "LqX9jBDqvDJYeooE";
    mysql::ssl_mode ssl = mysql::ssl_mode::enable;
};

class DBConnect {
   private:
    db_config config_;
    asio::io_context& ctx_;
    mysql::any_connection conn_;

   public:
    DBConnect(asio::io_context& ctx) : ctx_(ctx), conn_(ctx.get_executor()) {
        std::cout << "Connecting to database...\n";
        std::cout << "Host: " << config_.host << ":" << config_.port << "\n";
        std::cout << "Database: " << config_.database << "\n";
        std::cout << "Username: " << config_.username << "\n";
        
        mysql::connect_params params;
        params.server_address.emplace_host_and_port(config_.host, config_.port);
        params.username = config_.username;
        params.database = config_.database;
        params.password = config_.password;
        params.ssl = config_.ssl;
        
        try {
            conn_.connect(params);
            std::cout << "Successfully connected to MySQL database\n";
        } catch (const std::exception& e) {
            std::cerr << "Database connection failed: " << e.what() << std::endl;
            throw;
        }
    }

    bool register_user(const std::string& username, const std::string& password) {
        try {
            std::cout << "Registering user: " << username << std::endl;
            
            // First ensure table exists
            try {
                std::cout << "Ensuring users table exists...\n";
                std::string create_table = R"(
CREATE TABLE IF NOT EXISTS users (
    id INT AUTO_INCREMENT PRIMARY KEY,
    username VARCHAR(255) UNIQUE NOT NULL,
    password VARCHAR(255) NOT NULL,
    created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP
)
)";
                mysql::results create_result;
                conn_.execute(create_table, create_result);
                std::cout << "Users table ensured to exist\n";
            } catch (const std::exception& e) {
                std::cerr << "Error creating table: " << e.what() << std::endl;
                throw;
            }
            
            std::cout << "Inserting user data...\n";
            std::string stmt = "INSERT INTO users (username, password) VALUES ('" + username + "', '" + password + "')";
            std::cout << "Executing SQL: " << stmt << std::endl;
            
            mysql::results result;
            conn_.execute(stmt, result);
            
            std::cout << "User registration successful, affected rows: " << result.affected_rows() << std::endl;
            return true;
        } catch (const std::exception& e) {
            std::cerr << "Error registering user: " << e.what() << std::endl;
            if (std::string(e.what()).find("Duplicate entry") != std::string::npos) {
                std::cout << "User already exists: " << username << std::endl;
                return false;  // User already exists
            }
            throw;
        }
    }

    bool login_user(const std::string& username, const std::string& password) {
        try {
            std::cout << "Starting login verification: " << username << std::endl;
            
            std::string stmt = "SELECT password FROM users WHERE username = '" + username + "'";
            std::cout << "Executing SQL: " << stmt << std::endl;
            
            mysql::results result;
            conn_.execute(stmt, result);

            if (result.rows().empty()) {
                std::cout << "User does not exist: " << username << std::endl;
                return false;
            }
            
            std::string stored_password = result.rows().at(0).at(0).as_string();
            std::cout << "Stored password: " << stored_password << std::endl;
            std::cout << "Input password: " << password << std::endl;
            
            bool match = (stored_password == password);
            std::cout << "Password match result: " << (match ? "Success" : "Failed") << std::endl;
            
            return match;  // Plain text comparison (demo only)
        } catch (const std::exception& e) {
            std::cerr << "Error during login verification: " << e.what() << std::endl;
            return false;
        }
    }
};

// 极简 HTTP 响应生成
std::string http_response(const std::string& body, int status = 200) {
    std::ostringstream oss;
    oss << "HTTP/1.1 " << status << " OK\r\n";
    oss << "Content-Type: application/json\r\n";
    oss << "Access-Control-Allow-Origin: *\r\n";
    oss << "Access-Control-Allow-Methods: POST, GET, OPTIONS\r\n";
    oss << "Access-Control-Allow-Headers: Content-Type\r\n";
    oss << "Connection: close\r\n";
    oss << "Content-Length: " << body.size() << "\r\n";
    oss << "\r\n";
    oss << body;
    return oss.str();
}

// 解析 POST 请求体（简化版）
std::string extract_body(const std::string& request) {
    auto pos = request.find("\r\n\r\n");
    if (pos != std::string::npos) {
        return request.substr(pos + 4);
    }
    return "";
}

// 处理客户端请求
void handle_request(tcp::socket socket, DBConnect& db) {
    try {
        std::cout << "=== New HTTP Request ===" << std::endl;
        
        // 读取请求
        boost::asio::streambuf buffer;
        boost::asio::read_until(socket, buffer, "\r\n\r\n");

        std::istream is(&buffer);
        std::string method_line;
        std::getline(is, method_line);
        std::cout << "Request line: " << method_line << std::endl;

        std::string header;
        std::map<std::string, std::string> headers;
        while (std::getline(is, header) && header != "\r") {
            auto colon = header.find(":");
            if (colon != std::string::npos) {
                std::string key = header.substr(0, colon);
                std::string value = header.substr(colon + 2);
                if (!value.empty() && value.back() == '\r')
                    value.pop_back();
                headers[key] = value;
                std::cout << "Header: " << key << " = " << value << std::endl;
            }
        }

        // 提取路径
        std::istringstream method_stream(method_line);
        std::string method, path, http_version;
        method_stream >> method >> path >> http_version;
        std::cout << "Method: " << method << ", Path: " << path << ", Version: " << http_version << std::endl;

        // 处理 OPTIONS 预检
        if (method == "OPTIONS") {
            std::cout << "Handling OPTIONS preflight request" << std::endl;
            std::string options_response = 
                "HTTP/1.1 200 OK\r\n"
                "Access-Control-Allow-Origin: *\r\n"
                "Access-Control-Allow-Methods: POST, GET, OPTIONS\r\n"
                "Access-Control-Allow-Headers: Content-Type\r\n"
                "Access-Control-Max-Age: 86400\r\n"
                "Content-Length: 0\r\n"
                "Connection: close\r\n"
                "\r\n";
            socket.write_some(boost::asio::buffer(options_response));
            return;
        }

        // 读取 Body（仅支持固定长度）
        size_t content_length = 0;
        if (headers.count("Content-Length")) {
            content_length = std::stoul(headers["Content-Length"]);
            std::cout << "Content-Length: " << content_length << std::endl;
        }

        std::string body;
        if (content_length > 0) {
            std::cout << "Reading request body..." << std::endl;
            // 读取剩余的请求体数据
            std::string body_content;
            body_content.resize(content_length);
            boost::system::error_code ec;
            size_t bytes_read = boost::asio::read(socket, boost::asio::buffer(&body_content[0], content_length), ec);
            if (!ec && bytes_read == content_length) {
                body = body_content;
                std::cout << "Request body content: " << body << std::endl;
            } else {
                std::cerr << "Error reading request body: " << ec.message() << ", bytes read: " << bytes_read << std::endl;
            }
        } else {
            std::cout << "Request body is empty" << std::endl;
        }

        json response;

        if (method == "POST" && path == "/register") {
            std::cout << "Handling registration request" << std::endl;
            try {
                if (body.empty()) {
                    std::cout << "Registration request body is empty" << std::endl;
                    response = {{"success", false}, {"message", "Request body is empty"}};
                } else {
                    auto j = json::parse(body);
                    std::string username = j.value("username", "");
                    std::string password = j.value("password", "");
                    std::cout << "Registration info - Username: " << username << ", Password: " << password << std::endl;

                    if (username.empty() || password.empty()) {
                        std::cout << "Username or password is empty" << std::endl;
                        response = {{"success", false}, {"message", "Username or password is empty"}};
                    } else if (db.register_user(username, password)) {
                        std::cout << "User registration successful: " << username << std::endl;
                        response = {{"success", true}, {"message", "Registration successful"}};
                    } else {
                        std::cout << "User already exists: " << username << std::endl;
                        response = {{"success", false}, {"message", "User already exists"}};
                    }
                }
            } catch (const std::exception& e) {
                std::cerr << "JSON parsing error during registration: " << e.what() << std::endl;
                response = {{"success", false}, {"message", "JSON parsing error: " + std::string(e.what())}};
            }
        } else if (method == "POST" && path == "/login") {
            std::cout << "Handling login request" << std::endl;
            try {
                if (body.empty()) {
                    std::cout << "Login request body is empty" << std::endl;
                    response = {{"success", false}, {"message", "Request body is empty"}};
                } else {
                    auto j = json::parse(body);
                    std::string username = j.value("username", "");
                    std::string password = j.value("password", "");
                    std::cout << "Login info - Username: " << username << ", Password: " << password << std::endl;

                    if (username.empty() || password.empty()) {
                        std::cout << "Please enter complete information" << std::endl;
                        response = {{"success", false}, {"message", "Please enter complete information"}};
                    } else if (db.login_user(username, password)) {
                        std::cout << "User login successful: " << username << std::endl;
                        response = {{"success", true}, {"message", "Login successful"}};
                    } else {
                        std::cout << "Username or password error: " << username << std::endl;
                        response = {{"success", false}, {"message", "Username or password error"}};
                    }
                }
            } catch (const std::exception& e) {
                std::cerr << "JSON parsing error during login: " << e.what() << std::endl;
                response = {{"success", false}, {"message", "JSON parsing error: " + std::string(e.what())}};
            }
        } else {
            std::cout << "Unknown path: " << path << std::endl;
            response = {{"success", false}, {"message", "Unknown path: " + path}};
        }

        // 发送响应
        std::string response_body = response.dump();
        std::cout << "Sending response: " << response_body << std::endl;
        std::string resp = http_response(response_body, 200);
        boost::asio::write(socket, boost::asio::buffer(resp));
        std::cout << "=== Request processing completed ===" << std::endl << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Serious error processing request: " << e.what() << std::endl;
        std::string err = R"({"success": false, "message": "Server error: )" + std::string(e.what()) + "\"}";
        boost::asio::write(socket, boost::asio::buffer(http_response(err, 500)));
    }
}

int main() {
    try {
        asio::io_context io_context;
        tcp::acceptor acceptor(io_context, tcp::endpoint(tcp::v4(), 8080));

        DBConnect db(io_context);

        std::cout << "Server running on http://localhost:8080\n";

        while (true) {
            tcp::socket socket(io_context);
            acceptor.accept(socket);
            std::thread(handle_request, std::move(socket), std::ref(db)).detach();
        }
    } catch (std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
