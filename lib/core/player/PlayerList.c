#include <stdlib.h>
#include <stdio.h>

#include "PlayerList.h"
typedef struct PlayerNode {
    Player value;
    struct PlayerNode* next;
} PlayerNode;

PlayerNode* buildPlayerNode(Player player) {
    PlayerNode* node = malloc(sizeof(PlayerNode));
    if(node) {
        node->value = player;
        node->next = NULL;
    }
    return node;
}

void deletePlayerNode(PlayerNode* node) {
   free(node); 
}

typedef struct PlayerListInstance {
    PlayerNode* head;
    PlayerNode* tail;
    size_t size;
} PlayerListInstance;

PlayerList buildPlayerList() {
    PlayerListInstance* list = malloc(sizeof(PlayerListInstance));
    if(list) {
        list->head = NULL;
        list->tail = NULL;
        list->size = 0;
    }
    return (PlayerList*) list;
}

// Helper method to ensure consitent casting in all methods
static PlayerListInstance* castListToInstance(PlayerList list) {
    return (PlayerListInstance*) list;
}

void pushPlayer(PlayerList list, Player player) {
    PlayerListInstance* listInternal = castListToInstance(list);
    PlayerNode* node = buildPlayerNode(player);
    if (node) {
        if (listInternal->head) {
            listInternal->tail->next = node;
            listInternal->tail = node;
        } else {
            listInternal->head = node;
            listInternal->tail = node;
        }
        listInternal->size += 1;
    }
}

void deletePlayerList(PlayerList list) {
    PlayerListInstance* listInternal = castListToInstance(list);
    if(listInternal) {
        PlayerNode* current = listInternal->head;
        while (current) {
            PlayerNode* temp = current->next;
            deletePlayerNode(current);
            current = temp;
        }
        free(list);
    }
}

size_t sizePlayerList(PlayerList list) {
    return castListToInstance(list)->size;
}

PlayerListIterator beginPlayerIt(PlayerList list) {
    PlayerNode* head = NULL;
    PlayerListInstance* listInternal = castListToInstance(list);
    if(listInternal) {
        head = listInternal->head;
    }
    return (PlayerListIterator*) head;
}

// Helper method to ensure consitent casting in all methods
static PlayerNode* castIteratorToNode(PlayerListIterator it) {
   return (PlayerNode*) it;
}

bool hasNextPlayerIt(PlayerListIterator it) {
    return castIteratorToNode(it) != NULL;
}

PlayerListIterator nextPlayerIt(PlayerListIterator it) {
    PlayerNode* node = castIteratorToNode(it);
    if(node) {
        node = node->next;
    }
    return (PlayerListIterator*) node;
}

Player getPlayer(PlayerListIterator it) {
    Player player;
    PlayerNode* node = castIteratorToNode(it);
    if(node) {
       player = node->value; 
    }
    return player;
}

