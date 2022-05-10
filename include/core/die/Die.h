#pragma once

typedef struct Die {
    int maxValue;
    int currentValue;
} Die;

void rollDie(Die* die);

