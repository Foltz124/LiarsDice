#include <stdlib.h>

#include "DieList.h"

typedef struct DieNode {
    Die value;
    struct DieNode* next;
    struct DieNode* previous;
} DieNode;

DieNode* buildDieNode(Die die) {
    DieNode* node = malloc(sizeof(DieNode));
    if(node) {
        node->value = die;
        node->next = NULL;
        node->previous = NULL;
    }
    return node;
}

void deleteDieNode(DieNode* node) {
    free(node);
}

typedef struct DieListInstance {
    DieNode* head;
    DieNode* tail;
    size_t size;
} DieListInstance;

DieList buildDieList() {
    DieListInstance* list = malloc(sizeof(DieListInstance));
    if(list) {
        list->head = NULL;
        list->tail = NULL;
        list->size = 0;
    }
    return (DieList*) list;
}

static DieListInstance* castListToInstance(DieList list) {
    return (DieListInstance*) (list);
}

void pushDie(DieList list, Die die) {
    DieListInstance* listInternal = (DieListInstance*) (list);
    DieNode* node = buildDieNode(die);
    if(node) {
        if(listInternal->head) {
            listInternal->tail->next = node;
            node->previous = listInternal->tail;
            listInternal->tail = node;
        } else {
            listInternal->head = node;
            listInternal->tail = node;
        }
        listInternal->size += 1;
    }
}

void deleteDieList(DieList* list) {
    DieListInstance* listInternal = (DieListInstance*) (list);
    if(listInternal) {
        DieNode* current = listInternal->head;
        while(current) {
            DieNode* temp = current->next;
            deleteDieNode(current);
            current = temp;
        }
        free(list);
    }
}

size_t sizeDieList(DieList list) {
    return castListToInstance(list)->size;
}

DieListIterator beginDieIt(DieList list) {
    DieNode* head = NULL;
    DieListInstance* listInternal = castListToInstance(list);
    if(listInternal) {
        head = listInternal->head;
    }
    return (DieListIterator*) head;
}

DieListIterator endDieIt(DieList list) {
    DieNode* tail = NULL;
    DieListInstance* listInternal = castListToInstance(list);
    if(listInternal) {
        tail = listInternal->tail;
    }
    return (DieListIterator*) tail;
}

static DieNode* castIteratorToNode(DieListIterator it) {
    return (DieNode*) it;
}

bool hasNextDieIt(DieListIterator it) {
    return castIteratorToNode(it) != NULL;
}

DieListIterator nextDieIt(DieListIterator it) {
    DieNode* node = (DieNode*) it;
    if(node) {
        node = node->next;
    }
    return (DieListIterator*) node;
}

bool hasPreviousDieIt(DieListIterator it) {
    return castIteratorToNode(it) != NULL;
}
DieListIterator previousDieIt(DieListIterator it) {
    DieNode* node = castIteratorToNode(it);
    if(node) {
        node = node->previous;
    }
    return (DieListIterator*) node;
}

Die* getDie(DieListIterator it) {
    Die die;
    DieNode* node = castIteratorToNode(it);
    if(node) {
        return &node->value;
    }
    return NULL;
}

