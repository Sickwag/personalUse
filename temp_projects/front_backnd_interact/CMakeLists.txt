cmake_minimum_required(VERSION 3.10.0)
project(front_backnd_interact VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)
add_definitions(-D_WIN32_WINNT=0x0601)

find_package(Boost REQUIRED COMPONENTS system filesystem mysql)
find_package(nlohmann_json CONFIG REQUIRED)
find_package(OpenSSL REQUIRED)

add_executable(front_backnd_interact main.cpp)

target_compile_options(front_backnd_interact PRIVATE /utf-8)

target_link_libraries(front_backnd_interact PRIVATE 
    Boost::system 
    Boost::filesystem
    Boost::mysql
    nlohmann_json::nlohmann_json
    OpenSSL::SSL
    OpenSSL::Crypto
)
