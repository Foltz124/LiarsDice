#pragma once

typedef struct Die {
    unsigned int maxValue;
    unsigned int currentValue;
} Die;

Die* buildDie(unsigned int maxValue);
void deleteDie(Die** die);
void rollDie(Die* die);

