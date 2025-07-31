#include "menu.h"
#include "utils.h"
#include "identities.h"
#include "service_locator.h"
#include <fstream>
#include <nlohmann/json.hpp>

Menu::Menu() : iv_int(ServiceLocator::get<InputValidator<int>>()),
               iv_str(ServiceLocator::get<InputValidator<std::string>>()),
               db_(ServiceLocator::get<MySQLDB>()) {}

void Menu::start_menu() const {
    display_announcement();
}

asio::awaitable<void> Menu::choose_menu_options() const {
    std::cout << "welcomes to book manage plus:\n\n\t1) Login with password \n\t2) Login with email captcha \n\t3) Register \n\t 4) Exit" << std::endl;
    int choice = iv_int.prompt("input the choice number:")
                     .range(1, 4)
                     .render();
    while (true) {
        Role r;
        switch (choice) {
            case 1: {
                auto is_login_psw = co_await r.login_with_pwd();
                if (!is_login_psw) {
                    break;
                }
                break;
            }
            case 2: {
                auto is_login_cap = co_await r.login_with_captcha();
                if (!is_login_cap) {
                    break;
                }
            }
            case 3: {
                UserInfo reader_info = co_await r.register_account();
                r.self_checking(reader_info);
            }
            case 4: {
                co_return;
            }
            default:
                break;
        }
    }
}

asio::awaitable<void> Menu::after_login(Role& r) const {
    using namespace std;
    auto& user = r.get_user_info();
    auto& p = user.permission_.value();
    if (p == "Reader") {
        cout << "welcomes " + p + " " + user.name_.value();
    }
    while (true) {
        string_view rd = "\t1) borrow book\n\t2) return book\n\t3) self checking\n\t4) change password\n\t5) check book info";
        string_view lib = "\n\t6) add book to vault\n\t7) remove book from vault";
        string_view sa = "\n\t8) change permission\n\t9) set announcement\n";
        int available_options = 5;
        cout << rd;
        if (p == "Librarian") {
            cout << lib;
            available_options = 7;
        }
        if (p == "SystemAdmin") {
            cout << lib << sa;
            available_options = 9;
        }
        cout << "\n\t" << available_options << ") back to previous";
        int choice = iv_int.prompt("input choice number:")
                         .range(1, available_options)
                         .render();
        bool jump_to_previous = false;
        switch (choice == available_options ? 100 : choice) {
            case 1:{ r.borrow_book();            break; }
            case 2:{ r.return_book();            break; }
            case 3:{ r.self_checking(user);      break; }
            case 4:{ r.change_password();        break; }
            case 5:{ r.check_book();             break; }
            case 6:{ r.add_book();               break; }
            case 7:{ r.remove_book();            break; }
            case 8:{ r.adjust_permission();      break; }
            case 9:{ r.set_announcement();       break; }
            case 100:{
                jump_to_previous = true;
                break;
            }
        }
        if(jump_to_previous)
            break;
    }
    co_await choose_menu_options();
    co_return;
}

void Menu::display_announcement() const {
    std::ifstream f("./configs/all_text.json");
    nlohmann::json j = nlohmann::json::parse(f);
    auto time = Time::get_current_time().second;
    std::string formatted = std::vformat(j.value("announcement", ""), std::make_format_args(time));
    get_weather();
    std::cout << formatted << std::endl;
    choose_menu_options();
}
