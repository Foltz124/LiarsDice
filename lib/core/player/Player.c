#include <stdlib.h>
#include <stdio.h>

#include "Player.h"

Player* buildPlayer(char* name, uint8_t tokens) {
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
