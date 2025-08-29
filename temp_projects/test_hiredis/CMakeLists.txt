cmake_minimum_required(VERSION 3.20)
project(test_hiredis)

# 设置C++标准
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 设置vcpkg工具链
set(CMAKE_TOOLCHAIN_FILE "D:/Program/vcpkg/scripts/buildsystems/vcpkg.cmake" CACHE STRING "")

# 查找并链接hiredis库
find_package(hiredis CONFIG REQUIRED)

# 查找并链接redis++库
find_package(redis++ CONFIG REQUIRED)

# 添加可执行文件
add_executable(test_hiredis main.c)
add_executable(redis_test redis_test.cpp)
add_executable(redispp_test redispp_test.cpp)

# 链接hiredis库
target_link_libraries(test_hiredis PRIVATE hiredis::hiredis)
target_link_libraries(redis_test PRIVATE hiredis::hiredis)
target_link_libraries(redispp_test PRIVATE redis++::redis++)
