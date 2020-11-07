cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

project(botnet VERSION 0.1)
add_executable(botnet main.cpp)

add_library(cli cli.cpp)
list(APPEND EXTRA_LIBS cli)

target_link_libraries(botnet PUBLIC ${EXTRA_LIBS})

target_include_directories(botnet PUBLIC 
    "${PROJECT_BINARY_DIR}"
)
