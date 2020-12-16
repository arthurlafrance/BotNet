cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

project(mancala)

add_library(mancala
    models/Board.cpp
)

target_include_directories(mancala PUBLIC include)
