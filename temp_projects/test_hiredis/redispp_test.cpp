#include <sw/redis++/redis++.h>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <list>
#include <set>

using namespace sw::redis;

int main() {
    try {
        // 连接到远程Redis服务器
        ConnectionOptions connection_options;
        connection_options.host = "121.43.98.198";
        connection_options.port = 6379;
        connection_options.password = "123456";  // 设置密码
        
        ConnectionPoolOptions pool_options;
        pool_options.size = 3;  // 连接池大小
        
        Redis redis(connection_options, pool_options);
        
        std::cout << "Connected to Redis server successfully!" << std::endl;
        
        // === 字符串操作 ===
        std::cout << "\n=== String Operations ===" << std::endl;
        
        // SET/GET 操作
        redis.set("name", "Redis++ Test");
        auto name = redis.get("name");
        if (name) {
            std::cout << "GET name: " << *name << std::endl;
        } else {
            std::cout << "Key 'name' not found" << std::endl;
        }
        
        // INCR 操作
        redis.set("counter", "10");
        long long counter = redis.incr("counter");
        std::cout << "INCR counter: " << counter << std::endl;
        
        // === 哈希操作 ===
        std::cout << "\n=== Hash Operations ===" << std::endl;
        
        // HSET/HGETALL 操作
        std::map<std::string, std::string> user_info = {
            {"name", "Alice"},
            {"age", "25"},
            {"email", "alice@example.com"}
        };
        
        redis.hmset("user:1000", user_info.begin(), user_info.end());
        std::cout << "HSET user:1000 completed" << std::endl;
        
        std::map<std::string, std::string> user_data;
        redis.hgetall("user:1000", std::inserter(user_data, user_data.end()));
        std::cout << "HGETALL user:1000:" << std::endl;
        for (const auto &pair : user_data) {
            std::cout << "  " << pair.first << ": " << pair.second << std::endl;
        }
        
        // === 列表操作 ===
        std::cout << "\n=== List Operations ===" << std::endl;
        
        // LPUSH/LRANGE 操作
        std::vector<std::string> items = {"item1", "item2", "item3"};
        redis.lpush("mylist", items.begin(), items.end());
        std::cout << "LPUSH mylist completed" << std::endl;
        
        std::vector<std::string> list_items;
        redis.lrange("mylist", 0, -1, std::back_inserter(list_items));
        std::cout << "LRANGE mylist:" << std::endl;
        for (size_t i = 0; i < list_items.size(); ++i) {
            std::cout << "  [" << i << "]: " << list_items[i] << std::endl;
        }
        
        // === 集合操作 ===
        std::cout << "\n=== Set Operations ===" << std::endl;
        
        // SADD/SMEMBERS 操作
        std::vector<std::string> members = {"member1", "member2", "member3"};
        redis.sadd("myset", members.begin(), members.end());
        std::cout << "SADD myset completed" << std::endl;
        
        std::set<std::string> set_members;
        redis.smembers("myset", std::inserter(set_members, set_members.end()));
        std::cout << "SMEMBERS myset:" << std::endl;
        for (const auto &member : set_members) {
            std::cout << "  - " << member << std::endl;
        }
        
        // === 有序集合操作 ===
        std::cout << "\n=== Sorted Set Operations ===" << std::endl;
        
        // ZADD/ZRANGE 操作
        std::map<std::string, double> scores = {
            {"player1", 100.0},
            {"player2", 200.0},
            {"player3", 150.0}
        };
        
        redis.zadd("leaderboard", scores.begin(), scores.end());
        std::cout << "ZADD leaderboard completed" << std::endl;
        
        std::vector<std::pair<std::string, double>> leaderboard;
        redis.zrange("leaderboard", 0, -1, std::back_inserter(leaderboard));
        std::cout << "ZRANGE leaderboard:" << std::endl;
        for (const auto &pair : leaderboard) {
            std::cout << "  " << pair.first << ": " << pair.second << std::endl;
        }
        
        // === 发布/订阅操作 ===
        std::cout << "\n=== Pub/Sub Operations ===" << std::endl;
        
        // 发布消息
        long long subscribers = redis.publish("channel1", "Hello from Redis++!");
        std::cout << "Published message to channel1, " << subscribers << " subscribers" << std::endl;
        
        // === 事务操作 ===
        std::cout << "\n=== Transaction Operations ===" << std::endl;
        
        // MULTI/EXEC 事务
        auto tx = redis.transaction();
        tx.set("tx_key1", "value1");
        tx.set("tx_key2", "value2");
        tx.incr("tx_counter");
        auto tx_results = tx.exec();
        std::cout << "Transaction executed with " << tx_results.size() << " commands" << std::endl;
        
        // === 管道操作 ===
        std::cout << "\n=== Pipeline Operations ===" << std::endl;
        
        // Pipeline 批量操作
        auto pipe = redis.pipeline();
        pipe.set("pipe_key1", "pipe_value1");
        pipe.set("pipe_key2", "pipe_value2");
        pipe.get("pipe_key1");
        pipe.get("pipe_key2");
        auto pipe_results = pipe.exec();
        std::cout << "Pipeline executed with " << pipe_results.size() << " commands" << std::endl;
        
        // 获取管道结果
        auto pipe_value1 = pipe_results.get<std::string>(2);
        auto pipe_value2 = pipe_results.get<std::string>(3);
        std::cout << "Pipeline results: " << pipe_value1 << ", " << pipe_value2 << std::endl;
        
        // === 清理测试数据 ===
        std::cout << "\n=== Cleaning up ===" << std::endl;
        
        std::vector<std::string> keys_to_delete = {
            "name", "counter", "user:1000", "mylist", "myset", 
            "leaderboard", "tx_key1", "tx_key2", "tx_counter",
            "pipe_key1", "pipe_key2"
        };
        
        long long deleted = redis.del(keys_to_delete.begin(), keys_to_delete.end());
        std::cout << "Cleaned up " << deleted << " keys" << std::endl;
        
        std::cout << "\nAll Redis++ tests completed successfully!" << std::endl;
        
    } catch (const Error &e) {
        std::cerr << "Redis error: " << e.what() << std::endl;
        return 1;
    } catch (const std::exception &e) {
        std::cerr << "Standard exception: " << e.what() << std::endl;
        return 1;
    }
    
    return 0;
}
