#include "DieList.h"
#include "Hand.h"

#define HAND_SIZE 5

Hand* buildHand(uint8_t maxValue) {
    Hand* hand = malloc(sizeof(Hand));
    if (hand) {
        hand->dice = buildDieList();
        hand->maxValue = maxValue;
        if(hand->dice) {
            for (uint8_t index = 0; index < HAND_SIZE; index++) {
                pushDie(hand->dice, buildDie(maxValue));
            }
        } else {
            free(hand);
            hand = NULL;
        }
    }
    return hand;
}

void deleteHand(Hand* hand) {
    deleteDieList(hand->dice);
    free(hand);
}
