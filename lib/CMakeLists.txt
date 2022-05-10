cmake_minimum_required(VERSION 2.8.12)

project(lib)

add_subdirectory(core)
add_library(${PROJECT_NAME} INTERFACE)
target_link_libraries(${PROJECT_NAME} INTERFACE include core)

