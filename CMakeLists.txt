cmake_minimum_required(VERSION 2.8.12)

project(LiarsDice)

# Root Parameters
set(CMAKE_C_STANDARD 11)
set(CMAKE_BUILD_TYPE Debug)
set(BUILD_TESTS ON)

# Add project directories
add_subdirectory(include)
add_subdirectory(src)
add_subdirectory(bin)

# Add test directory if building tests
if(BUILD_TESTS)
    enable_testing()
    add_subdirectory(test)
endif()
