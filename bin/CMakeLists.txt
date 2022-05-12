cmake_minimum_required(VERSION 2.8.12)

project(bin)

add_executable(${PROJECT_NAME} main.c)
target_link_libraries(${PROJECT_NAME} include lib)

project(${PLAYDATE_GAME_NAME} C ASM)
if (TOOLCHAIN STREQUAL "armgcc")
	add_executable(${PLAYDATE_GAME_DEVICE} ${SDK}/C_API/buildsupport/setup.c main.c)
    target_link_libraries(${PLAYDATE_GAME_NAME_DEVICE} include lib)
    target_include_directories(${PLAYDATE_GAME_NAME_DEVICE} PUBLIC ${SDK} ${SDK}/pd_api/)
else()
	add_library(${PLAYDATE_GAME_NAME} SHARED main.c)
    target_link_libraries(${PLAYDATE_GAME_NAME} include lib)
endif()

include(${SDK}/C_API/buildsupport/playdate_game.cmake)
