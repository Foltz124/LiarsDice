cmake_minimum_required(VERSION 2.8.12)

project(core)

set(CMAKE_C_STANDARD 11)

add_library(${PROJECT_NAME} INTERFACE)

add_subdirectory(player)
add_subdirectory(die)
add_subdirectory(poker_utils)
target_link_libraries(${PROJECT_NAME} INTERFACE player die poker_utils)
