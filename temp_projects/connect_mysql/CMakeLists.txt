cmake_minimum_required(VERSION 3.10.0)

# 工具链文件必须在project()之前设置
set(CMAKE_TOOLCHAIN_FILE "D:\\Program\\vcpkg\\scripts\\buildsystems\\vcpkg.cmake")

project(test_db_conn VERSION 0.1.0 LANGUAGES C CXX)

add_executable(test_db_conn main.cpp)

find_package(Boost REQUIRED COMPONENTS system filesystem mysql)

target_link_libraries(test_db_conn PRIVATE 
    Boost::system 
    Boost::filesystem
    Boost::mysql
)
