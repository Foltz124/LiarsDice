#pragma once
#include <stdbool.h>
#include <stdlib.h>

#include "Die.h"

// Opaque Pointer to Die List
typedef void* DieList;

// Opaque Pointer to Die List Iterator
typedef void* DieListIterator;

// Builds a Die List
DieList buildDieList();

// Deletes die list
void deleteDieList(DieList*);

// Push copy of die to a list
void pushDie(DieList list, Die die);

// Get size of the list
size_t sizeDieList(DieList list);

// Get iterator to beginning of the list
DieListIterator beginDieIt(DieList list);

// Get iterator to end of the list
DieListIterator endDieIt(DieList list);

// Check to see if we are at the end of the list
bool hasNextDieIt(DieListIterator it);

// Check to see if we are at the start of the list
bool hasPreviousDieIt(DieListIterator it);

// Get next element in the list
DieListIterator nextDieIt(DieListIterator it);

// Get previous element in the list
DieListIterator previousDieIt(DieListIterator it);

// Get value of current element
Die* getDie(DieListIterator it);

