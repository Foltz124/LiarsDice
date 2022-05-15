#pragma once
#include <stdint.h>

typedef struct Die {
    uint8_t maxValue;
    uint8_t currentValue;
} Die;

// Creates a pointer to a die struct.
Die* buildDiePointer(uint8_t maxValue);

// Creates a die struct.
Die buildDie(uint8_t maxValue);

// Deletes die struct.
void deleteDie(Die* die);

// Rolls the die and sets current value to a random value within [1, maxRange].
void rollDie(Die* die);

