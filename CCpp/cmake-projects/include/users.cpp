#include "users.h"
#include <iostream>
#include<mysqlx/xapi.h>

void User::self_checking() const {
    std::string output = std::format(R"(
        name      : {}
        id        : {}
        nick name : {}
        priority  : {}
        phone     : {}
        created at: {}
        password  : {}
)", name, id, nick_name, priority, phone, create_at, password);
    std::cout << output;
}