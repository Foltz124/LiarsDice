cmake_minimum_required(VERSION 2.8.12)

project(player)

set(CMAKE_C_STANDARD 11)

add_library(${PROJECT_NAME} Player.c PlayerNode.c PlayerList.c)
target_link_libraries(${PROJECT_NAME} includes)
target_include_directories(${PROJECT_NAME} PRIVATE ${CURRENT_SOURCE_DIRECTORY})

