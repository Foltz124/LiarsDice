#pragma once

typedef struct Player {
    char* name;
    int tokens;
} Player;

Player* buildPlayer(char* name, int tokens);
void deletePlayer(Player* player);
