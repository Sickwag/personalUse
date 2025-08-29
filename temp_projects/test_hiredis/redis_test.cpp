#include <hiredis/hiredis.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void handleError(redisContext* c, const char* operation) {
    if (c->err) {
        printf("Error in %s: %s\n", operation, c->errstr);
        redisFree(c);
        exit(1);
    }
}

void testStringOperations(redisContext* c) {
    printf("\n=== String Operations ===\n");
    
    // SET command
    redisReply* reply = (redisReply*)redisCommand(c, "SET name Redis_Test");
    if (reply->type == REDIS_REPLY_ERROR) {
        printf("SET Error: %s\n", reply->str);
    } else {
        printf("SET name \"Redis Test\" -> %s\n", reply->str);
    }
    freeReplyObject(reply);
    
    // GET command
    reply = (redisReply*)redisCommand(c, "GET name");
    if (reply->type == REDIS_REPLY_ERROR) {
        printf("GET Error: %s\n", reply->str);
    } else {
        printf("GET name -> %s\n", reply->str);
    }
    freeReplyObject(reply);
    
    // INCR command
    reply = (redisReply*)redisCommand(c, "SET counter 10");
    freeReplyObject(reply);
    
    reply = (redisReply*)redisCommand(c, "INCR counter");
    if (reply->type == REDIS_REPLY_ERROR) {
        printf("INCR Error: %s\n", reply->str);
    } else {
        printf("INCR counter -> %lld\n", reply->integer);
    }
    freeReplyObject(reply);
}

void testHashOperations(redisContext* c) {
    printf("\n=== Hash Operations ===\n");
    
    // HSET command
    redisReply* reply = (redisReply*)redisCommand(c, "HSET user:1000 name \"Alice\" age 25 email \"alice@example.com\"");
    if (reply->type == REDIS_REPLY_ERROR) {
        printf("HSET Error: %s\n", reply->str);
    } else {
        printf("HSET user:1000 -> %lld fields added\n", reply->integer);
    }
    freeReplyObject(reply);
    
    // HGETALL command
    reply = (redisReply*)redisCommand(c, "HGETALL user:1000");
    if (reply->type == REDIS_REPLY_ERROR) {
        printf("HGETALL Error: %s\n", reply->str);
    } else if (reply->type == REDIS_REPLY_ARRAY) {
        printf("HGETALL user:1000:\n");
        for (size_t i = 0; i < reply->elements; i += 2) {
            printf("  %s: %s\n", reply->element[i]->str, reply->element[i+1]->str);
        }
    }
    freeReplyObject(reply);
}

void testListOperations(redisContext* c) {
    printf("\n=== List Operations ===\n");
    
    // LPUSH command
    redisReply* reply = (redisReply*)redisCommand(c, "LPUSH mylist \"item1\" \"item2\" \"item3\"");
    if (reply->type == REDIS_REPLY_ERROR) {
        printf("LPUSH Error: %s\n", reply->str);
    } else {
        printf("LPUSH mylist -> %lld elements\n", reply->integer);
    }
    freeReplyObject(reply);
    
    // LRANGE command
    reply = (redisReply*)redisCommand(c, "LRANGE mylist 0 -1");
    if (reply->type == REDIS_REPLY_ERROR) {
        printf("LRANGE Error: %s\n", reply->str);
    } else if (reply->type == REDIS_REPLY_ARRAY) {
        printf("LRANGE mylist:\n");
        for (size_t i = 0; i < reply->elements; i++) {
            printf("  [%zu]: %s\n", i, reply->element[i]->str);
        }
    }
    freeReplyObject(reply);
}

void testSetOperations(redisContext* c) {
    printf("\n=== Set Operations ===\n");
    
    // SADD command
    redisReply* reply = (redisReply*)redisCommand(c, "SADD myset \"member1\" \"member2\" \"member3\" \"member1\"");
    if (reply->type == REDIS_REPLY_ERROR) {
        printf("SADD Error: %s\n", reply->str);
    } else {
        printf("SADD myset -> %lld elements added\n", reply->integer);
    }
    freeReplyObject(reply);
    
    // SMEMBERS command
    reply = (redisReply*)redisCommand(c, "SMEMBERS myset");
    if (reply->type == REDIS_REPLY_ERROR) {
        printf("SMEMBERS Error: %s\n", reply->str);
    } else if (reply->type == REDIS_REPLY_ARRAY) {
        printf("SMEMBERS myset:\n");
        for (size_t i = 0; i < reply->elements; i++) {
            printf("  [%zu]: %s\n", i, reply->element[i]->str);
        }
    }
    freeReplyObject(reply);
}

int main() {
    // 连接到远程Redis服务器
    const char* hostname = "121.43.98.198";
    int port = 6379;
    const char* password = "123456";
    
    printf("Connecting to Redis server at %s:%d...\n", hostname, port);
    
    // 建立连接
    redisContext* c = redisConnect(hostname, port);
    if (c == NULL || c->err) {
        if (c != NULL) {
            printf("Connection Error: %s\n", c->errstr);
            redisFree(c);
        } else {
            printf("Can't allocate redis context\n");
        }
        exit(1);
    }
    
    printf("Connected successfully!\n");
    
    // 进行身份验证
    redisReply* auth_reply = (redisReply*)redisCommand(c, "AUTH %s", password);
    if (auth_reply == NULL || c->err) {
        if (c->err) {
            printf("Authentication Error: %s\n", c->errstr);
        } else {
            printf("Authentication failed: NULL reply\n");
        }
        if (auth_reply) {
            freeReplyObject(auth_reply);
        }
        redisFree(c);
        exit(1);
    }
    
    if (auth_reply->type == REDIS_REPLY_ERROR) {
        printf("Authentication Error: %s\n", auth_reply->str);
        freeReplyObject(auth_reply);
        redisFree(c);
        exit(1);
    }
    
    printf("Authenticated successfully!\n");
    freeReplyObject(auth_reply);
    
    // 测试各种Redis操作
    testStringOperations(c);
    testHashOperations(c);
    testListOperations(c);
    testSetOperations(c);
    
    // 清理测试数据
    printf("\n=== Cleaning up ===\n");
    redisReply* reply = (redisReply*)redisCommand(c, "DEL name counter user:1000 mylist myset");
    printf("Cleaned up %lld keys\n", reply->integer);
    freeReplyObject(reply);
    
    // 关闭连接
    redisFree(c);
    printf("\nConnection closed. All tests completed successfully!\n");
    
    return 0;
}
