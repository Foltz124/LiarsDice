cmake_minimum_required(VERSION 2.8.12)

project(game_logic)

set(CMAKE_C_STANDARD 11)

add_library(${PROJECT_NAME} INTERFACE)

add_subdirectory(poker_utils)
add_subdirectory(hand)
target_link_libraries(${PROJECT_NAME} INTERFACE poker_utils hand)
