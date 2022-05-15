#pragma once
#include <stdbool.h>
#include <stdlib.h>

#include "Die.h"

typedef void* DieList;
typedef void* DieListIterator;

DieList buildDieList();
void deleteDieList(DieList*);
void pushDie(DieList list, Die die);
size_t sizeDieList(DieList list);

DieListIterator beginDieIt(DieList list);
DieListIterator endDieIt(DieList list);
bool hasNextDieIt(DieListIterator it);
bool hasPreviousDieIt(DieListIterator it);
DieListIterator nextDieIt(DieListIterator it);
DieListIterator previousDieIt(DieListIterator it);
Die getDie(DieListIterator it);

