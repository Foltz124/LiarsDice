cmake_minimum_required(VERSION 2.8.12)

project(includes)

add_subdirectory(core)
add_library(${PROJECT_NAME} INTERFACE)
target_link_libraries(${PROJECT_NAME} INTERFACE core_include)

