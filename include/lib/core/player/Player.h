#pragma once

#include <stdint.h>

typedef struct Player {
    char* name;
    uint8_t tokens;
} Player;

Player* buildPlayer(char* name, uint8_t tokens);
void deletePlayer(Player** player);
