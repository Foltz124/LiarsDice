
cmake_minimum_required(VERSION 2.8.12)

project(images)

set(CMAKE_C_STANDARD 11)

add_library(${PROJECT_NAME} INTERFACE)
target_include_directories(${PROJECT_NAME} INTERFACE ${CURRENT_SOURCE_DIRECTORY})

