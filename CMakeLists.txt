cmake_minimum_required(VERSION 2.8.12)

project(LiarsDice)

set(CMAKE_C_STANDARD 11)
set(CMAKE_BUILD_TYPE Debug)

add_subdirectory(include)
add_subdirectory(src)
add_subdirectory(bin)
