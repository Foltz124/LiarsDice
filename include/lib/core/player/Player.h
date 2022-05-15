#pragma once
#include <stdint.h>

typedef struct Player {
    char* name;
    uint8_t tokens;
} Player;

// Builds a pointer to a a player
Player* buildPlayer(char* name, uint8_t tokens);

// Frees memory for a Pointer to player.
void deletePlayer(Player* player);

