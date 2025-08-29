cmake_minimum_required(VERSION 3.20)
project(boost_redis_client CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 设置 vcpkg 工具链
set(CMAKE_TOOLCHAIN_FILE "D:/Program/vcpkg/scripts/buildsystems/vcpkg.cmake" CACHE STRING "")

# 需要更多组件
find_package(Boost REQUIRED COMPONENTS system redis)

add_executable(${PROJECT_NAME} src/main.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE 
    Boost::redis 
    Boost::system
)
target_compile_definitions(${PROJECT_NAME} PRIVATE 
    BOOST_BEAST_USE_STD_ASYNC_RECEIVE
    _WIN32_WINNT=0x0601
)
set_target_properties(${PROJECT_NAME} PROPERTIES CXX_EXTENSIONS OFF)
