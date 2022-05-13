cmake_minimum_required(VERSION 2.8.12)

project(game_logic_test)

add_executable(${PROJECT_NAME} main.c)
target_link_libraries(${PROJECT_NAME} check game_logic)
target_include_directories(${PROJECT_NAME} PUBLIC ${CURRENT_SOURCE_DIRECTORY})
add_test(NAME ${PROJECT_NAME} COMMAND ${PROJECT_NAME})
