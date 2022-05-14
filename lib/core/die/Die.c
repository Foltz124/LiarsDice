#include <stdlib.h>

#include "Die.h"

/*
 * Returns a number between [min, max).
 * May experience some mod bias when reaching RAND_MAX.
 */
uint8_t getRandomNumber(uint8_t min, uint8_t max) {
    return rand() % (max + 1 - min) + min;
}

Die* buildDie(uint8_t maxValue) {
    Die* die = malloc(sizeof(Die)); 
    if(die) {
        die->maxValue = maxValue;
        die->currentValue = 1;
    }
    return die;
}

void deleteDie(Die* die) {
    free(die);
}

void rollDie(Die* die) {
    die->currentValue = getRandomNumber(1, die->maxValue);
}

