#include <stdlib.h>

#include "PlayerList.h"

int push(PlayerList* list, Player player) {
    int result = 1;
    PlayerNode* node = buildPlayerNode(player);
    if (node) {
        result = 0;
        if (list->head) {
            list->tail->next = node;
            list->tail = node;
        } else {
            list->head = node;
            list->tail = node;
        }
        list->size += 1;
    }
    return result;
}

PlayerList* buildPlayerList() {
    PlayerList* list = malloc(sizeof(PlayerList));
    if(list) {
        list->head = NULL;
        list->tail = NULL;
        list->size = 0;
    }
    return list;
}

void deletePlayerList(PlayerList** list) {
    PlayerNode* current = (*list)->head;
    while (current) {
        PlayerNode* temp = current->next;
        deletePlayerNode(&current);
        current = temp;
    }
    free(*list);
    *list = NULL;
}

