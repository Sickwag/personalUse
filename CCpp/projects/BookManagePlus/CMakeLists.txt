cmake_minimum_required(VERSION 3.15)
project(BookManagePlus)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
set(Boost_DEBUG ON)
set(CMAKE_TOOLCHAIN_FILE "D:\\Program\\vcpkg\\scripts\\buildsystems\\vcpkg.cmake")

set(CMAKE_PREFIX_PATH "D:/Program/vcpkg/installed/x64-windows/" ${CMAKE_PREFIX_PATH})
message(STATUS "CMAKE_PREFIX_PATH: ${CMAKE_PREFIX_PATH}")

find_package(Boost 1.88.0 REQUIRED COMPONENTS system filesystem mysql json describe)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
include_directories(D:/Program/vcpkg/installed/x64-windows/include)
find_package(CURL CONFIG REQUIRED)
find_package(spdlog CONFIG REQUIRED)

# add_subdirectory(test/input)
add_executable(BookManagePlus
    src/main.cpp
    src/MySQLDB.cpp
    src/CLIEntry.cpp
    src/identities.cpp
    src/utils.cpp
    src/email_sender.cpp
)
target_compile_definitions(BookManagePlus PRIVATE _WIN32_WINNT=0x0601)
target_include_directories(BookManagePlus PRIVATE 
    ${PROJECT_SOURCE_DIR}/include
    ${CURL_INCLUDE_DIRS}
)
# target_compile_options(BookManagePlus PRIVATE "/std:c++20" "/Zc:__cplusplus")
target_link_libraries(BookManagePlus PRIVATE 
    Boost::system 
    Boost::filesystem
    Boost::mysql
    Boost::json
    CURL::libcurl
    ws2_32
    spdlog::spdlog
)