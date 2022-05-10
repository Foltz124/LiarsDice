#include <stdlib.h>

#include "PlayerNode.h"

PlayerNode* buildPlayerNode(Player player) {
    PlayerNode* playerNode = malloc(sizeof(PlayerNode));
    if(playerNode) {
        playerNode->value = player;
        playerNode->next = NULL;
    }
    return playerNode;
}

void deletePlayerNode(PlayerNode** playerNode) {
    free(*playerNode);
    *playerNode = NULL;
}
