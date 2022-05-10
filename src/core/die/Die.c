#include <stdlib.h>

#include "Die.h"

/*
 * Returns a number between [min, max).
 * May experience some mod bias when reaching RAND_MAX.
 */
int getRandomNumber(int min, int max) {
    return rand() % (max + 1 - min);
}

void rollDie(Die* die) {
    die->currentValue = getRandomNumber(1, die->maxValue + 1);
}
