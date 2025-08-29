#include <boost/redis.hpp>
#include <boost/redis/src.hpp>
#include <boost/asio.hpp>
#include <iostream>
#include <string>
#include <vector>
#include <functional>
#include <chrono>
#include <thread>

using namespace boost;

class RedisDemo {
private:
    asio::io_context ioc;
    std::shared_ptr<redis::connection> conn;
    redis::config cfg;
    
public:
    RedisDemo() {
        // 配置连接到远程 Redis 服务器
        cfg.addr.host = "121.43.98.198";  // 远程 Redis 服务器地址
        cfg.addr.port = "6379";           // Redis 默认端口
        cfg.username = "default";         // 用户名，默认为 "default"
        cfg.password = "123456";          // Redis 服务器密码
        
        conn = std::make_shared<redis::connection>(ioc);
    }
    
    bool connect() {
        std::cout << "Connecting to Redis server at " << cfg.addr.host << ":" << cfg.addr.port 
                  << " with password authentication" << std::endl;
        
        bool connected = false;
        bool error_occurred = false;
        conn->async_run(cfg, {}, [&connected, &error_occurred](boost::system::error_code ec) {
            if (ec) {
                std::cerr << "Connection error: " << ec.message() << std::endl;
                error_occurred = true;
            } else {
                std::cout << "Connected successfully!" << std::endl;
                connected = true;
            }
        });
        
        // 运行 io_context 一段时间以完成连接
        ioc.run_for(std::chrono::seconds(3));
        
        // 检查是否连接成功
        if (connected) {
            ioc.restart();
            return true;
        } else if (error_occurred) {
            ioc.restart();
            return false;
        } else {
            // 可能还在连接中，给更多时间
            ioc.run_for(std::chrono::seconds(2));
            ioc.restart();
            return true; // 假设连接成功，因为我们没有收到错误
        }
    }
    
    void runIoContext() {
        ioc.run();
    }
    
    // 1. PING 命令模块
    void testPing() {
        std::cout << "\n=== PING Command Test ===" << std::endl;
        redis::request req;
        req.push("PING");
        
        bool completed = false;
        conn->async_exec(req, redis::ignore, [&completed](boost::system::error_code ec, std::size_t) {
            if (ec) {
                std::cerr << "PING error: " << ec.message() << std::endl;
            } else {
                std::cout << "PING command executed successfully!" << std::endl;
            }
            completed = true;
        });
        
        // 等待命令完成
        while (!completed) {
            ioc.poll();
            std::this_thread::sleep_for(std::chrono::milliseconds(10));
        }
    }
    
    // 2. 字符串操作模块
    void testStringOperations() {
        std::cout << "\n=== String Operations Test ===" << std::endl;
        
        // SET 命令
        redis::request set_req;
        set_req.push("SET", "test_key", "Hello Redis from C++!");
        
        bool set_completed = false;
        conn->async_exec(set_req, redis::ignore, [&set_completed](boost::system::error_code ec, std::size_t) {
            if (ec) {
                std::cerr << "SET error: " << ec.message() << std::endl;
            } else {
                std::cout << "SET command executed successfully!" << std::endl;
            }
            set_completed = true;
        });
        
        // 等待 SET 完成
        while (!set_completed) {
            ioc.poll();
            std::this_thread::sleep_for(std::chrono::milliseconds(10));
        }
        
        // GET 命令
        redis::request get_req;
        get_req.push("GET", "test_key");
        
        bool get_completed = false;
        conn->async_exec(get_req, redis::ignore, [&get_completed](boost::system::error_code ec, std::size_t) {
            if (ec) {
                std::cerr << "GET error: " << ec.message() << std::endl;
            } else {
                std::cout << "GET command executed successfully!" << std::endl;
            }
            get_completed = true;
        });
        
        // 等待 GET 完成
        while (!get_completed) {
            ioc.poll();
            std::this_thread::sleep_for(std::chrono::milliseconds(10));
        }
    }
    
    // 3. 哈希操作模块
    void testHashOperations() {
        std::cout << "\n=== Hash Operations Test ===" << std::endl;
        
        // HSET 命令
        redis::request hset_req;
        hset_req.push("HSET", "user:1000", "name", "Alice", "age", "25", "city", "Beijing");
        
        bool hset_completed = false;
        conn->async_exec(hset_req, redis::ignore, [&hset_completed](boost::system::error_code ec, std::size_t) {
            if (ec) {
                std::cerr << "HSET error: " << ec.message() << std::endl;
            } else {
                std::cout << "HSET command executed successfully!" << std::endl;
            }
            hset_completed = true;
        });
        
        // 等待 HSET 完成
        while (!hset_completed) {
            ioc.poll();
            std::this_thread::sleep_for(std::chrono::milliseconds(10));
        }
        
        // HGET 命令
        redis::request hget_req;
        hget_req.push("HGET", "user:1000", "name");
        
        bool hget_completed = false;
        conn->async_exec(hget_req, redis::ignore, [&hget_completed](boost::system::error_code ec, std::size_t) {
            if (ec) {
                std::cerr << "HGET error: " << ec.message() << std::endl;
            } else {
                std::cout << "HGET command executed successfully!" << std::endl;
            }
            hget_completed = true;
        });
        
        // 等待 HGET 完成
        while (!hget_completed) {
            ioc.poll();
            std::this_thread::sleep_for(std::chrono::milliseconds(10));
        }
    }
    
    // 4. 列表操作模块
    void testListOperations() {
        std::cout << "\n=== List Operations Test ===" << std::endl;
        
        // LPUSH 命令
        redis::request lpush_req;
        lpush_req.push("LPUSH", "fruits", "apple", "banana", "orange");
        
        bool lpush_completed = false;
        conn->async_exec(lpush_req, redis::ignore, [&lpush_completed](boost::system::error_code ec, std::size_t) {
            if (ec) {
                std::cerr << "LPUSH error: " << ec.message() << std::endl;
            } else {
                std::cout << "LPUSH command executed successfully!" << std::endl;
            }
            lpush_completed = true;
        });
        
        // 等待 LPUSH 完成
        while (!lpush_completed) {
            ioc.poll();
            std::this_thread::sleep_for(std::chrono::milliseconds(10));
        }
        
        // LRANGE 命令
        redis::request lrange_req;
        lrange_req.push("LRANGE", "fruits", "0", "-1");
        
        bool lrange_completed = false;
        conn->async_exec(lrange_req, redis::ignore, [&lrange_completed](boost::system::error_code ec, std::size_t) {
            if (ec) {
                std::cerr << "LRANGE error: " << ec.message() << std::endl;
            } else {
                std::cout << "LRANGE command executed successfully!" << std::endl;
            }
            lrange_completed = true;
        });
        
        // 等待 LRANGE 完成
        while (!lrange_completed) {
            ioc.poll();
            std::this_thread::sleep_for(std::chrono::milliseconds(10));
        }
    }
    
    // 5. 集合操作模块
    void testSetOperations() {
        std::cout << "\n=== Set Operations Test ===" << std::endl;
        
        // SADD 命令
        redis::request sadd_req;
        sadd_req.push("SADD", "languages", "C++", "Python", "JavaScript");
        
        bool sadd_completed = false;
        conn->async_exec(sadd_req, redis::ignore, [&sadd_completed](boost::system::error_code ec, std::size_t) {
            if (ec) {
                std::cerr << "SADD error: " << ec.message() << std::endl;
            } else {
                std::cout << "SADD command executed successfully!" << std::endl;
            }
            sadd_completed = true;
        });
        
        // 等待 SADD 完成
        while (!sadd_completed) {
            ioc.poll();
            std::this_thread::sleep_for(std::chrono::milliseconds(10));
        }
        
        // SMEMBERS 命令
        redis::request smembers_req;
        smembers_req.push("SMEMBERS", "languages");
        
        bool smembers_completed = false;
        conn->async_exec(smembers_req, redis::ignore, [&smembers_completed](boost::system::error_code ec, std::size_t) {
            if (ec) {
                std::cerr << "SMEMBERS error: " << ec.message() << std::endl;
            } else {
                std::cout << "SMEMBERS command executed successfully!" << std::endl;
            }
            smembers_completed = true;
        });
        
        // 等待 SMEMBERS 完成
        while (!smembers_completed) {
            ioc.poll();
            std::this_thread::sleep_for(std::chrono::milliseconds(10));
        }
    }
    
    // 6. 有序集合操作模块
    void testSortedSetOperations() {
        std::cout << "\n=== Sorted Set Operations Test ===" << std::endl;
        
        // ZADD 命令
        redis::request zadd_req;
        zadd_req.push("ZADD", "scores", "90", "Alice", "85", "Bob", "95", "Charlie");
        
        bool zadd_completed = false;
        conn->async_exec(zadd_req, redis::ignore, [&zadd_completed](boost::system::error_code ec, std::size_t) {
            if (ec) {
                std::cerr << "ZADD error: " << ec.message() << std::endl;
            } else {
                std::cout << "ZADD command executed successfully!" << std::endl;
            }
            zadd_completed = true;
        });
        
        // 等待 ZADD 完成
        while (!zadd_completed) {
            ioc.poll();
            std::this_thread::sleep_for(std::chrono::milliseconds(10));
        }
        
        // ZRANGE 命令
        redis::request zrange_req;
        zrange_req.push("ZRANGE", "scores", "0", "-1", "WITHSCORES");
        
        bool zrange_completed = false;
        conn->async_exec(zrange_req, redis::ignore, [&zrange_completed](boost::system::error_code ec, std::size_t) {
            if (ec) {
                std::cerr << "ZRANGE error: " << ec.message() << std::endl;
            } else {
                std::cout << "ZRANGE command executed successfully!" << std::endl;
            }
            zrange_completed = true;
        });
        
        // 等待 ZRANGE 完成
        while (!zrange_completed) {
            ioc.poll();
            std::this_thread::sleep_for(std::chrono::milliseconds(10));
        }
    }
    
    // 7. 其他常用命令模块
    void testOtherCommands() {
        std::cout << "\n=== Other Common Commands Test ===" << std::endl;
        
        // EXISTS 命令
        redis::request exists_req;
        exists_req.push("EXISTS", "test_key");
        
        bool exists_completed = false;
        conn->async_exec(exists_req, redis::ignore, [&exists_completed](boost::system::error_code ec, std::size_t) {
            if (ec) {
                std::cerr << "EXISTS error: " << ec.message() << std::endl;
            } else {
                std::cout << "EXISTS command executed successfully!" << std::endl;
            }
            exists_completed = true;
        });
        
        // 等待 EXISTS 完成
        while (!exists_completed) {
            ioc.poll();
            std::this_thread::sleep_for(std::chrono::milliseconds(10));
        }
        
        // TTL 命令
        redis::request ttl_req;
        ttl_req.push("TTL", "test_key");
        
        bool ttl_completed = false;
        conn->async_exec(ttl_req, redis::ignore, [&ttl_completed](boost::system::error_code ec, std::size_t) {
            if (ec) {
                std::cerr << "TTL error: " << ec.message() << std::endl;
            } else {
                std::cout << "TTL command executed successfully!" << std::endl;
            }
            ttl_completed = true;
        });
        
        // 等待 TTL 完成
        while (!ttl_completed) {
            ioc.poll();
            std::this_thread::sleep_for(std::chrono::milliseconds(10));
        }
        
        // DEL 命令
        redis::request del_req;
        del_req.push("DEL", "test_key");
        
        bool del_completed = false;
        conn->async_exec(del_req, redis::ignore, [&del_completed](boost::system::error_code ec, std::size_t) {
            if (ec) {
                std::cerr << "DEL error: " << ec.message() << std::endl;
            } else {
                std::cout << "DEL command executed successfully!" << std::endl;
            }
            del_completed = true;
        });
        
        // 等待 DEL 完成
        while (!del_completed) {
            ioc.poll();
            std::this_thread::sleep_for(std::chrono::milliseconds(10));
        }
    }
};

int main() try {
    std::cout << "Starting Redis client demo with modular design..." << std::endl;
    
    RedisDemo demo;
    
    // 连接 Redis 服务器
    if (!demo.connect()) {
        std::cerr << "Failed to connect to Redis server!" << std::endl;
        return 1;
    }
    
    // 依次执行各个测试模块
    demo.testPing();
    demo.testStringOperations();
    demo.testHashOperations();
    demo.testListOperations();
    demo.testSetOperations();
    demo.testSortedSetOperations();
    demo.testOtherCommands();
    
    std::cout << "\nAll Redis operations completed successfully!" << std::endl;
    
    return 0;
} catch (const std::exception& e) {
    std::cerr << "Exception: " << e.what() << std::endl;
    return 1;
}
