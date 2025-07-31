cmake_minimum_required(VERSION 3.10)
project(CLI11learning)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_TOOLCHAIN_FILE "D:\\Program\\vcpkg\\scripts\\buildsystems\\vcpkg.cmake")

include_directories(${PROJECT_SOURCE_DIR}/include)
add_executable(CLI11learning src/main.cpp)
