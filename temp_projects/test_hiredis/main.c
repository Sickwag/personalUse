#include<hiredis/hiredis.h>
#include<stdio.h>
#include<stdlib.h>

int main() {
    // 连接到远程Redis服务器
    const char* hostname = "121.43.98.198";
    int port = 6379;
    const char* password = "123456";

    printf("Connecting to Redis server at %s:%d...\n", hostname, port);

    // 建立连接
    redisContext* c = redisConnect(hostname, port);

    // 检查连接是否成功
    if (c == NULL || c->err) {
        if (c != NULL) {
            printf("Error: %s\n", c->errstr);
            redisFree(c);
        } else {
            printf("Can't allocate redis context\n");
        }
        exit(1);
    }

    printf("Connected successfully!\n");

    // 进行身份验证
    redisReply* auth_reply = redisCommand(c, "AUTH %s", password);
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

    // 测试设置和获取键值
    redisReply* reply = redisCommand(c, "SET hello world");
    if (reply == NULL || c->err) {
        if (c->err) {
            printf("SET Error: %s\n", c->errstr);
        } else {
            printf("SET failed: NULL reply\n");
        }
        if (reply) {
            freeReplyObject(reply);
        }
        redisFree(c);
        exit(1);
    }

    if (reply->type == REDIS_REPLY_ERROR) {
        printf("SET Error: %s\n", reply->str);
    } else {
        printf("SET Reply: %s\n", reply->str);
    }
    freeReplyObject(reply);

    // 获取刚刚设置的键值
    reply = redisCommand(c, "GET hello");
    if (reply == NULL || c->err) {
        if (c->err) {
            printf("GET Error: %s\n", c->errstr);
        } else {
            printf("GET failed: NULL reply\n");
        }
        if (reply) {
            freeReplyObject(reply);
        }
        redisFree(c);
        exit(1);
    }

    if (reply->type == REDIS_REPLY_ERROR) {
        printf("GET Error: %s\n", reply->str);
    } else {
        printf("GET Reply: %s\n", reply->str);
    }
    freeReplyObject(reply);

    // 关闭连接
    redisFree(c);
    printf("Connection closed.\n");

    return 0;
}
