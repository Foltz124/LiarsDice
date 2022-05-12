#pragma once
#include "DieNode.h"

typedef struct DieList {
    DieNode* head;
    DieNode* tail;
    int size;
} DieList;

int pushDie(DieList* list, Die die);
DieList* buildDieList();
void deleteDieList(DieList** list);
