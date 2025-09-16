cmake_minimum_required(VERSION 3.10.0)

if(WIN32)
    set(CMAKE_TOOLCHAIN_FILE D:/Program/vcpkg/scripts/buildsystems/vcpkg.cmake CACHE STRING "Vcpkg toolchain file")
endif()

project(CodeLinesCount VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Boost CONFIG COMPONENTS filesystem system json regex REQUIRED)
find_package(tabulate CONFIG REQUIRED)
find_package(CLI11 CONFIG REQUIRED)

include_directories(
    ./include
)

add_executable(CodeLinesCount
    src/main.cpp
    src/arg_parse.cpp
    src/count.cpp
    src/output.cpp
    src/config.cpp

    utils/utils.cpp
)

# 正确的链接语法：先指定目标，再列出库
target_link_libraries(CodeLinesCount PRIVATE
    tabulate::tabulate
    CLI11::CLI11
    Boost::json
    Boost::filesystem
    Boost::system
)
