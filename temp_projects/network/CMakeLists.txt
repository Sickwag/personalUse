cmake_minimum_required(VERSION 3.10.0)
project(network VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_TOOLCHAIN_FILE "D:/Program/vcpkg/scripts/buildsystems/vcpkg.cmake")

find_package(Boost REQUIRED COMPONENTS mysql filesystem system)

add_executable(network 
    src/main.cpp
    src/mysql.cpp
)
include_directories(
    ./include
)

target_link_libraries(network
    Boost::mysql
    Boost::filesystem
    Boost::system
)
