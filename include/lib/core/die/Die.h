#pragma once

#include <stdint.h>

typedef struct Die {
    uint8_t maxValue;
    uint8_t currentValue;
} Die;

Die* buildDie(uint8_t maxValue);
void deleteDie(Die** die);
void rollDie(Die* die);

