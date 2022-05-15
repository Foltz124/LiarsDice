#pragma once
#include <stdbool.h>
#include <stdlib.h>

#include "Player.h"

// Opaque pointer to list
typedef void* PlayerList;

// Opaque pointer to list iterator
typedef void* PlayerListIterator;

// Creates a PlayerList
PlayerList buildPlayerList();

// Deletes a PlayerList
void deletePlayerList(PlayerList list);

// Adds copy of a player to the list
void pushPlayer(PlayerList list, Player player);

// Gets the size of the list
size_t sizePlayerList(PlayerList list);

// Gets an iterator pointed at the beginning of the list
PlayerListIterator beginPlayerIt(PlayerList list);

// Checks if we have reached the end of the list
bool hasNextPlayerIt(PlayerListIterator it);

// Points iterator to the next element in the list
PlayerListIterator nextPlayerIt(PlayerListIterator it);

// Gets the value at the current iterator
Player getPlayer(PlayerListIterator it);

