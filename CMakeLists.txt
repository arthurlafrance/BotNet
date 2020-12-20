# Set CMake minimum required version
cmake_minimum_required(VERSION 3.10)

# Set C++ standard to use
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Create main executable
project(botnet VERSION 0.1)
add_executable(botnet 
    app/main.cpp
    app/cli.cpp
) # Add src files to executable

target_include_directories(botnet PUBLIC app/include) # include headers

# Add subdirectories
add_subdirectory(mancala)

# Link executable with libraries from src
target_link_libraries(botnet mancala)


# Tests
# Download & install GoogleTest
configure_file(tests/CMakeLists.txt gtest-download/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
    RESULT_VARIABLE result
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/gtest-download
)
if(result)
    message(FATAL_ERROR "gtest cmake step failed: ${result}")
endif()

execute_process(COMMAND ${CMAKE_COMMAND} --build .
    RESULT_VARIABLE result
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/gtest-download
)
if(result)
    message(FATAL_ERROR "gtest build step failed: ${result}")
endif()

# Add GoogleTest subdirectories to project
add_subdirectory(
    ${CMAKE_CURRENT_BINARY_DIR}/gtest-src
    ${CMAKE_CURRENT_BINARY_DIR}/gtest-build

    EXCLUDE_FROM_ALL
)

# Create test executable & link w/ gtest, src libraries
file(GLOB_RECURSE TEST_SRC_FILES ${CMAKE_SOURCE_DIR}/tests/**/*.cpp)
add_executable(botnet_tests ${TEST_SRC_FILES})
target_link_libraries(botnet_tests mancala gtest gtest_main)
add_test(botnet_tests COMMAND botnet_tests)
