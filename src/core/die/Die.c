#include <stdlib.h>

#include "Die.h"

/*
 * Returns a number between [min, max).
 * May experience some mod bias when reaching RAND_MAX.
 */
unsigned int getRandomNumber(unsigned int min, unsigned int max) {
    return rand() % (max + 1 - min) + min;
}

Die* buildDie(unsigned int maxValue) {
    Die* die = malloc(sizeof(Die)); 
    if(die) {
        die->maxValue = maxValue;
        die->currentValue = 1;
    }
    return die;
}

void deleteDie(Die** die) {
    free(*die);
    *die = NULL;
}

void rollDie(Die* die) {
    die->currentValue = getRandomNumber(1, die->maxValue);
}
