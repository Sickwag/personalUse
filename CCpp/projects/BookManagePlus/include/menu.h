#pragma once
#include "utils.h"
#include "MySQLDB.h"
#include "identities.h"

class Menu {
   public:
    Menu();
    void start_menu() const;
    asio::awaitable<void> choose_menu_options() const;
    asio::awaitable<void> after_login(Role& r) const;

   private:
    void display_announcement() const;
    InputValidator<std::string>& iv_str;
    InputValidator<int>& iv_int;
    MySQLDB& db_;
};