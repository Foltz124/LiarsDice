#include <stdlib.h>

#include "DieNode.h"

DieNode* buildDieNode(Die die) {
    DieNode* dieNode = malloc(sizeof(DieNode));
    if (dieNode) {
        dieNode->value = die;
        dieNode->next = NULL;
        dieNode->previous = NULL;
    }
    return dieNode;
}

void deleteDieNode(DieNode** dieNode) {
    free(*dieNode);
    *dieNode = NULL;
}
