#include <stdlib.h>

#include "DieList.h"

int pushDie(DieList* list, Die die) {
    int result = 1;
    DieNode* node = buildDieNode(die);
    if(node) {
        result = 0;
        if(list->head) {
            list->tail->next = node;
            node->previous = list->tail;
            list->tail = node;
        } else {
            list->head = node;
            list->tail = node;
        }
        list->size += 1;
    }
    return result;
}

DieList* buildDieList() {
    DieList* list = malloc(sizeof(DieList));
    if(list) {
        list->head = NULL;
        list->tail = NULL;
        list->size = 0;
    }
    return list;
}

void deleteDieList(DieList** list) {
    DieNode* current = (*list)->head;
    while(current) {
        DieNode* temp = current->next;
        deleteDieNode(&current);
        current = temp;
    }
    free(*list);
    *list = NULL;
}
