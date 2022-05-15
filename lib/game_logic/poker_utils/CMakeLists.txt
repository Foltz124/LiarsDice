cmake_minimum_required(VERSION 2.8.12)

project(poker_utils)

set(CMAKE_C_STANDARD 11)

add_library(${PROJECT_NAME} PokerUtils.c)
target_link_libraries(${PROJECT_NAME} include)
target_include_directories(${PROJECT_NAME} PRIVATE ${CURRENT_SOURCE_DIRECTORY})

