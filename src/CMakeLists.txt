cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Create executable
project(botnet VERSION 0.1)
add_executable(botnet 
    main/main.cpp
    main/cli.cpp
)

# Add subdirectories
add_subdirectory(mancala)

target_include_directories(botnet PUBLIC 
    "${PROJECT_BINARY_DIR}"
)

