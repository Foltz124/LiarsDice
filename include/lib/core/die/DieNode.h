#pragma once
#include "Die.h"

typedef struct DieNode {
    Die value;
    struct DieNode* previous;
    struct DieNode* next;
} DieNode;

DieNode* buildDieNode(Die die);
void deleteDieNode(DieNode** dieNode);
