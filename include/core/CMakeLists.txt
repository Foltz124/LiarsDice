cmake_minimum_required(VERSION 2.8.12)

project(core_include)

add_library(${PROJECT_NAME} INTERFACE)

add_subdirectory(player)
add_subdirectory(die)
target_link_libraries(${PROJECT_NAME} INTERFACE player_include die_include)
