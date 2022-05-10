#pragma once
#include "PlayerNode.h"

typedef struct PlayerList {
    PlayerNode* head;
    PlayerNode* tail;
    int size;
} PlayerList;

int push(PlayerList* list, Player player);
PlayerList* buildPlayerList();
void deletePlayerList(PlayerList* list);

