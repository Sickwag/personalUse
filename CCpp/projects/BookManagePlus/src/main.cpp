#include <iostream>
#include <format>
#include <nlohmann/json.hpp>
#include <io.h>
#include <fcntl.h>
#include <boost/asio.hpp>

#include "menu.h"
#include "utils.h"
#include "service_locator.h"

using json = nlohmann::json;
namespace asio = boost::asio;
namespace mysql = boost::mysql;

int main(int argc, char* argv[]) {
    // 设置控制台UTF-8编码支持
    SetConsoleOutputCP(CP_UTF8);
    setvbuf(stdout, nullptr, _IOFBF, 1000);
    
    try {
        // get_weather();
        boost::asio::io_context ioc;// 管理所有协程类服务，生命周期必须比这些服务长
        // asio::co_spawn(ioc, test_mysql_functions(), asio::detached);
        // asio::co_spawn(ioc, test_reader_functions(), asio::detached);

        start_service_sync(ioc);
        
        // 创建菜单并显示
        Menu m;
        m.start_menu();
        
        // 启动菜单协程
        asio::co_spawn(ioc, m.choose_menu_options(), asio::detached);
        ioc.run();
    } catch (const std::exception& e) {
        std::cerr << "Exception in main: " << e.what() << std::endl;
        return 1;
    }

    // curl_global_init(CURL_GLOBAL_DEFAULT);
    // std::vector<std::string> attachments;
    // attachments.push_back(R"(D:\Code Files\vscode\CCpp\projects\BookManagePlus\scripts\email_sender_cli.py)");
    // attachments.push_back(R"(D:\Code Files\vscode\CCpp\projects\BookManagePlus\scripts\emailSender.py)");
    // bool success = EmailSender().send_email(et);
    // curl_global_cleanup();

    return 0;
}
