#pragma once
#include <stdbool.h>
#include <stdlib.h>

#include "Player.h"

typedef void* PlayerList;
typedef void* PlayerListIterator;

PlayerList buildPlayerList();
void deletePlayerList(PlayerList list);
void pushPlayer(PlayerList list, Player player);
size_t sizePlayerList(PlayerList list);

PlayerListIterator beginPlayerIt(PlayerList list);
bool hasNextPlayerIt(PlayerListIterator it);
PlayerListIterator nextPlayerIt(PlayerListIterator it);
Player getPlayer(PlayerListIterator it);

