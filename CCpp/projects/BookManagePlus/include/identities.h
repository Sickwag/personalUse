#pragma once
#include <MySQLDB.h>
#include <boost/asio.hpp>
#include <optional>
#include <string>
#include "email_sender.h"
#include "service_locator.h"
#include "utils.h"

namespace asio = boost::asio;
using asio::awaitable;

struct Book {
    std::optional<std::string> code, title, author, created_at;
    short lending, remain, sum;
    void show_book_info(std::string_view permission) const;
};

struct UserInfo {
    std::optional<std::string> name_, password_, permission_, created_at_, email_, last_login_in_;
    bool is_online;
    void check_online() const;
};

class RoleOPError : public std::exception{

};

class Role {
   public:
    Role() : db_(ServiceLocator::get<MySQLDB>()),
               iv_str(ServiceLocator::get<InputValidator<std::string>>()),
               iv_int(ServiceLocator::get<InputValidator<int>>()),
               es(ServiceLocator::get<EmailSender>()) {}

    awaitable<bool> login_with_pwd();
    awaitable<bool> login_with_captcha();
    awaitable<UserInfo> register_account();
    awaitable<bool> borrow_book();
    awaitable<bool> return_book();
    awaitable<void> self_checking(const UserInfo& u);
    awaitable<bool> change_password();
    UserInfo& get_user_info();
    // void set_user_info(const UserInfo& u) const;

    // Librarian
    awaitable<void> check_book();
    awaitable<bool> add_book();
    awaitable<bool> remove_book();

    // SystemAdmin
    awaitable<bool> adjust_permission();
    awaitable<bool> set_announcement();

    protected:
    MySQLDB& db_;
    InputValidator<std::string>& iv_str;
    InputValidator<int>& iv_int;
    EmailSender& es;
    UserInfo u;
};