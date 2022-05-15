cmake_minimum_required(VERSION 2.8.12)

project(include)

# Paths
set(INCLUDE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/lib)

set(CORE_PATH ${INCLUDE_PATH}/core)
set(GAME_LOGIC_PATH ${INCLUDE_PATH}/game_logic)

set(PLAYER_PATH ${CORE_PATH}/player)
set(DIE_PATH ${CORE_PATH}/die)
set(POKER_PATH ${GAME_LOGIC_PATH}/poker_utils)
set(HAND_PATH ${GAME_LOGIC_PATH}/hand)

# Currently only including headers so use interface
add_library(${PROJECT_NAME} INTERFACE)
target_include_directories(${PROJECT_NAME} INTERFACE 
    ${PLAYER_PATH}
    ${DIE_PATH}
    ${POKER_PATH}
    ${HAND_PATH}
)

