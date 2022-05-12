#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

#include "PokerUtils.h"

typedef struct HandStats {
    uint8_t pairCount;
    bool hasTrio;
    bool hasFour;
    bool hasFive;
    bool hasStraight;
} HandStats;

HandStats* buildHandStats() {
    HandStats* hand = malloc(sizeof(HandStats));
    if(hand) {
        hand->pairCount = 0;
        hand->hasTrio = false;
        hand->hasFour = false;
        hand->hasFive = false;
    }
    return hand;
}

void deleteHandStats(HandStats* stats) {
    free(stats);
}

HandStats* populateHandStats(uint8_t* hand, uint8_t size) {
    HandStats* stats = buildHandStats();
    for(int index = 0; index < size; index++) {
        uint8_t current = hand[index];
        if(current == 2) {
            stats->pairCount++;
        } else if(current == 3) {
            stats->hasTrio = true;
        } else if(current == 4) {
            stats->hasFour = true;
            break;
        } else if(current == 5) {
            stats->hasFive = true;
            break;
        }
    }
    return stats;
}

PokerHand determineHand(uint8_t* hand, uint8_t size) {
    PokerHand pokerHand = HighestSingle;
    HandStats* stats = populateHandStats(hand, size);
    int lastIndex = size - 1;
    if(stats->hasTrio && stats->pairCount == 1) {
        pokerHand = FullHouse;
    } else if(stats->pairCount == 1) {
        pokerHand = OnePair;
    } else if(stats->pairCount == 2) {
        pokerHand = TwoPair;
    } else if(stats->hasTrio) {
        pokerHand = ThreeOfAKind;
    } else if(stats->hasFour) {
        pokerHand = FourOfAKind;
    } else if(stats->hasFive) {
        pokerHand = FiveOfAKind;
    } else if((hand[0] == 0 && hand[lastIndex] == 1) 
        || (hand[0] == 1 && hand[lastIndex] == 0)) {
        pokerHand = (hand[0] == 1) ? LowStraight : HighStraight;
    }
    deleteHandStats(stats);
    return pokerHand;
}

