#pragma once

typedef struct Player {
    char* name;
    unsigned int tokens;
} Player;

Player* buildPlayer(char* name, unsigned int tokens);
void deletePlayer(Player** player);
