cmake_minimum_required(VERSION 2.8.12)

project(LiarsDice)

# Root Parameters
set(CMAKE_C_STANDARD 11)
set(SDK ${CMAKE_CURRENT_SOURCE_DIR}/playdate)
set(BUILD_TESTS ON)

#  Variables Required for Playdate CMake
set(COMPILER_PATH $ENV{PLAYDATE_SDK_PATH})
set(CMAKE_TOOLCHAIN_FILE ${SDK}/buildsupport/arm.cmake)
set(PLAYDATE_GAME_NAME liars_dice_game)
set(PLAYDATE_GAME_NAME_DEVICE liars_dice_device)

# Add project directories
add_subdirectory(include)
add_subdirectory(lib)
add_subdirectory(bin)

# Add test directory if building tests
if(BUILD_TESTS)
    enable_testing()
    add_subdirectory(test)
endif()
