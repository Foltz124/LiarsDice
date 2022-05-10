#include <stdlib.h>
#include <stdio.h>

#include "Player.h"

Player* buildPlayer(char* name, unsigned int tokens) {
    Player* player = malloc(sizeof(Player));
    if(player) {
        player->name = name;
        player->tokens = tokens;
    }
    return player;
}

void deletePlayer(Player** player) {
    free(*player);
    *player = NULL;
}
