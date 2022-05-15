#pragma once
#include <stdint.h>

#include "DieList.h"

typedef struct Hand {
    DieList dice;
    uint8_t maxValue;
} Hand;

// Builds a pointer to a hand with the provided max value.
Hand* buildHand(uint8_t maxValue);

// Deletes pointer to hand.
void deleteHand(Hand* hand);
