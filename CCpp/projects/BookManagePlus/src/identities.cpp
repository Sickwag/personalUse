#include "identities.h"
#include "email_sender.h"

awaitable<bool> Role::login_with_pwd() {
    std::string name = iv_str.prompt("your username: ").length_range(6, 15).render();
    std::string password = iv_str.prompt("your password: ").password_strength().render();
    std::string sql = "select * from users where name = " + name + " and password = " + password + " and is_available = true;";
    auto users = co_await db_.query_into<UserInfo>(sql);
    if (users.empty()) {
        std::cerr << "invalid username or password.";
        co_return false;
    } else {
        std::cout << "login successfully, welcomes, " + name + '\n';
        this->u.is_online = true;
        co_await self_checking(users[0]);
        co_return true;
    }
}

awaitable<bool> Role::login_with_captcha() {
    std::string email = iv_str.prompt("your email: ").email().render();
    std::string captcha = iv_str.prompt("your 6 digits captcha we have just send to your email: ").length_range(6).render();
    std::string sql = "select * from users where email = " + email;
    auto users = co_await db_.query_into<UserInfo>(sql);
    if (users.empty()) {
        std::cerr << "have not found " + email + " account, you can register one.";
        co_return false;
    }
    es.email_config.to = email;
    std::string captcha_code = es.generateCaptcha();
    es.email_config.body = "your captcha code is " + captcha_code + '\n';
    es.send_email(es.email_config);

    std::string input = iv_str.length_range(6).prompt("input captcha we have just sended to you email: " + email + '\n').render();
    if (input != captcha_code) {
        std::cerr << "your code is wrong.";
        co_return false;
    } else {
        std::cout << "login successfully, welcomes, " + email + '\n';
        this->u.is_online = true;
        co_await self_checking(users[0]);
        co_return true;
    }
}

awaitable<UserInfo> Role::register_account() {
    UserInfo u;
    try{
        u.name_ = co_await iv_str.prompt("your name: ")
                      .length_range(6, 15)
                      .custom_async([&](const std::string& s) -> asio::awaitable<bool> {
                          std::string sql = "select * from users u where u.name = ?";
                          auto users = co_await db_.query(sql, s);
                          co_return users.rows().size() != 0;
                      },
                                    "your name has been taken by other.")
                      .render_async();
        u.password_ = iv_str.prompt("your password:").length_range(8, 20).render();
        u.email_ = co_await iv_str.prompt("your email: ")
                       .email()
                       .length_range(4, 40)
                       .custom_async([&](const std::string& s) -> asio::awaitable<bool> {
                           auto users = co_await db_.query("select * from users u where u.email = ?", s);
                           co_return users.rows().size() <= 3;
                            },"one email address only allows 3 accounts.")
                       .render_async();
        u.created_at_ = Time::get_current_time().second;
        u.is_online = false;
        u.last_login_in_ = u.created_at_;
        u.permission_ = iv_str.prompt(R"("the identity you wanna be("reader", "librarian" or "system admin")")
                            .enum_str({"reader", "librarian","system admin"})
                            .render();
    }catch (mysql::error_code& err){
        std::cerr << err.what() << std::endl;
    }
    co_return u;
}

awaitable<bool> Role::borrow_book() {
    this->u.check_online();
    std::string title = iv_str.prompt("the book title you wanna borrow: ").length_range(1, 30).render();
    std::string author = iv_str.prompt(std::format("the author of {}: ", title)).length_range(1, 20).render();
    auto remain = co_await db_.query("select b.remain from books b where b.title = ? and b.author = ?", title, author);
    if (remain.rows().at(0).at(0).as_uint64() == 0){
        std::cerr << "the " + title + " written by " + author + " was borrowed out.";
        co_return false;
    }else{
        auto affected = co_await db_.execute("UPDATE books SET lending = lending + 1, remain = remain - 1 WHERE title = '" + title + "' AND author = '" + author + "'");
        is_already_done(affected, "borrow book");
    }
    co_return true;
}

awaitable<bool> Role::return_book() {
    this->u.check_online();
    std::string title = iv_str.prompt("the book title you wanna return: ").length_range(1, 30).render();
    std::string author = iv_str.prompt(std::format("the author of {}: ", title)).length_range(1, 20).render();
    auto affected = co_await db_.execute("UPDATE books SET lending = lending - 1, remaining = remaining + 1, sum = sum + 1 WHERE title = '" + title + "' AND author = '" + author + "'");
    co_return affected > 0;
}

awaitable<void> Role::self_checking(const UserInfo& u) {
    std::cout << std::setw(10) << std::left << u.name_.value() << std::setw(10) << std::left << u.email_.value() << '\n'
    << std::setw(10) << std::left << u.permission_.value() << '\n'
    << u.last_login_in_.value();
    co_return;
}

awaitable<bool> Role::change_password() {
    this->u.check_online();
    std::string new_password = iv_str.prompt("new password: ")
                                   .length_range(8, 20)
                                   .password_strength()
                                   .render();
    auto affected_rows = co_await db_.execute("update users u set password = " + new_password + " where u.name = " + this->u.name_.value() + " and " + " u.email = " + u.email_.value());
    is_already_done(affected_rows, "change password");
    co_return affected_rows;
}

UserInfo& Role::get_user_info() { return this->u; }

void UserInfo::check_online() const {
    if (!this->is_online) {
        throw std::runtime_error("you have not login.");
    }
}

awaitable<void> Role::check_book() {
    this->u.check_online();
    if(this->u.permission_ != "Librarian" or this->u.permission_ != "SystemAdmin"){
        throw std::runtime_error("operate denied by your " + this->u.permission_.value() + " role now.");
    }
    std::vector<Book, std::allocator<Book>> result;
    std::string code = co_await iv_str.prompt("the book code you wanna check(8 characters code): ")
                           .length_range(8)
                           .custom_async(
                               [&](const std::string& s) -> asio::awaitable<bool> {
                                   std::string sql = "select * from books b where b.code = " + s;
                                   result = co_await db_.query_into<Book>(sql);
                                   co_return result.empty();
                               },
                               " the code points no book, ")
                           .render_async();
    Book& u = result[0];
    u.show_book_info(this->u.permission_.value());
    co_return;
}

awaitable<bool> Role::add_book() {
    if (this->u.permission_ != "Librarian" or this->u.permission_ != "SystemAdmin") {
        throw std::runtime_error("operate denied by your " + this->u.permission_.value() + " role now.");
    }
    this->u.check_online();
    Book b;
    b.title = iv_str.prompt("book title: ")
                  .length_range(1, 12)
                  .render();
    b.author = iv_str.prompt("book author: ")
                   .length_range(1, 20)
                   .render();
    b.created_at = Time::get_current_time().second;
    b.lending = 0;
    b.remain = iv_int.range(0,150).render();
    b.sum = b.remain;
    std::string sql = std::format("insert into books(title, author, lending, remaining, sum) values({},{},{},{}.{})", b.title.value(), b.author.value(), b.lending, b.remain, b.sum);
    auto affected = co_await db_.execute(sql);
    is_already_done(affected, "add book");
    co_return affected > 0;
}

awaitable<bool> Role::remove_book() {
    if (this->u.permission_ != "Librarian" or this->u.permission_ != "SystemAdmin") {
        throw std::runtime_error("operate denied by your " + this->u.permission_.value() + " role now.");
    }
    this->u.check_online();
    std::vector<Book, std::allocator<Book>> result;
    std::string code = co_await iv_str.prompt("the book code you wanna check(8 characters code): ")
                           .length_range(8)
                           .custom_async(
                               [&](const std::string& s) -> asio::awaitable<bool> {
                                   std::string sql = "select * from books b where b.code = " + s;
                                   result = co_await db_.query_into<Book>(sql);
                                   co_return result.empty();
                               },
                               " the code points no book, ")
                           .render_async();
    Book& u = result[0];
    u.show_book_info(this->u.permission_.value());
    std::string d_code = iv_str.prompt("the code of book you wanna delete: ").length_range(8).render();
    std::string choice = iv_str.prompt("delete the book which coded of "+ d_code + "?").yes_or_no().render();
    if(choice[0] == 'y'){
        std::string sql = std::format("delete from books b where b.code = {}", d_code);
        auto affected_rows = co_await db_.execute(sql);
        is_already_done(affected_rows, "delete book");
        co_return true;
    }else{
        std::cout << "you canceled the delete operation.\n";
    }
    co_return false;
}

awaitable<bool> Role::adjust_permission() {
    if (this->u.permission_ != "SystemAdmin") {
        throw std::runtime_error("operate denied by your " + this->u.permission_.value() + " role now.");
    }
    this->u.check_online();
    std::string name = co_await iv_str.prompt("the user name you wanna change permission: ")
                           .length_range(6, 15)
                           .custom_async([&](const std::string& s) -> asio::awaitable<bool> {
                               auto users = co_await db_.query("select u.permission from users u where u.name = ? and u.permission <=> \"system admin\"", s);
                               co_return users.rows().size() != 0;
                           },
                            "The user whose name you gave is not an system admin does not exist.")
                           .render_async();
    std::string permission = iv_str.prompt("the permission you wanna give to " + name)
                                 .enum_str({"system admin", "librarian"})
                                 .render();
    std::string sql = std::format("update users u set u.permission = {} where u.name = {}", permission, name);
    auto affected = co_await db_.execute(sql);
    is_already_done(affected, "change permission");
    co_return affected > 0;
}

awaitable<bool> Role::set_announcement() {
    if (this->u.permission_ != "SystemAdmin") {
        throw std::runtime_error("operate denied by your " + this->u.permission_.value() + " role now.");
    }
    this->u.check_online();
    // todo
    bool flag = true;
    is_already_done(flag, "set announcement");
    co_return true;
}

void Role::is_already_done(bool flag, const std::string& description, std::exception& err) const {
    if(flag){
        std::cout << description << " successfully.\n";
    }else{
        std::cerr << description << " failed for unknow reason.\n" << err.what();
    }
}

void Role::is_already_done(bool flag, const std::string& description) const {
    if(flag){
        std::cout << description << " successfully.\n";
    }else{
        std::cerr << description << " failed for unknow reason.\n";
    }
}

void Book::show_book_info(std::string_view permission) const {
    std::cout << std::setw(15) << std::left << this->title.value() << std::setw(10) << std::left << this->author.value() << std::setw(10) << std::left << "remaining" << std::setw(10) << std::left<< this->remain;
    if(permission == "librarian" || permission == "system admin"){
        std::cout << std::setw(10) << std::left << this->lending << std::setw(10) << std::left << this->created_at.value() << std::setw(10) << std::left << this->sum;
    }
}
