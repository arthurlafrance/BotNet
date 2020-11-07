cmake_minimum_required(VERSION 3.10)

project(botnet VERSION 0.1)
add_executable(botnet main.cpp)

configure_file(config.h.in config.h)

target_include_directories(botnet PUBLIC "${PROJECT_BINARY_DIR}")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
