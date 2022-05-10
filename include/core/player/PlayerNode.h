#pragma once
#include "Player.h"

typedef struct PlayerNode {
    Player value;
    struct PlayerNode* next;
} PlayerNode;

PlayerNode* buildPlayerNode(Player player);
void deletePlayerNode(PlayerNode** playerNode);

