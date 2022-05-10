cmake_minimum_required(VERSION 2.8.12)

project(die_include)

add_library(${PROJECT_NAME} INTERFACE)
target_include_directories(${PROJECT_NAME} INTERFACE .)

