cmake_minimum_required(VERSION 3.15)
project(CodeLinesCounter)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_C_COMPILER "D:\\Program\\mingw64\\bin\\gcc.exe")
set(CMAKE_CXX_COMPILER "D:\\Program\\mingw64\\bin\\g++.exe")

add_executable(CodeLinesCounter
    src/main.cpp
    src/filter.cpp
    src/counter.cpp
    src/CLI_parser.cpp
)

target_include_directories(CodeLinesCounter PRIVATE ${PROJECT_SOURCE_DIR}/include)
