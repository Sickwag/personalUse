cmake_minimum_required(VERSION 3.10.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_TOOLCHAIN_FILE "$ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake"
    CACHE STRING "Vcpkg toolchain file")

project(cmake-test VERSION 0.1.0 LANGUAGES C CXX)

# 查找Boost库并指定需要的组件
find_package(Boost REQUIRED COMPONENTS filesystem system algorithm)

add_executable(cmake-test 
    src/main.cpp
    src/InputValidator.cpp
    include/InputValidator.h
)
target_link_libraries(cmake-test PRIVATE 
    Boost::boost 
    Boost::algorithm 
    Boost::filesystem 
    Boost::system
    )

target_include_directories(cmake-test PRIVATE 
    ${Boost_INCLUDE_DIRS}
    include
)
