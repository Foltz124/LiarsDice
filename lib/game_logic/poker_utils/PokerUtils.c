#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "DieList.h"
#include "Hand.h"
#include "PokerUtils.h"

typedef struct HandStats {
    uint8_t pairCount;
    bool hasTrio;
    bool hasFour;
    bool hasFive;
    bool hasLowStraight;
    bool hasHighStraight;
} HandStats;

HandStats buildHandStats() {
    HandStats hand;
    hand.pairCount = 0;
    hand.hasTrio = false;
    hand.hasFour = false;
    hand.hasFive = false;
    hand.hasLowStraight = false;
    hand.hasHighStraight = false;
    return hand;
}

HandStats populateHandStats(Hand* hand) {
    size_t size = hand->maxValue;
    HandStats stats = buildHandStats();
    int rollCount[size];
    // Might be contentious since this is a string function. Seems standard though.
    memset(rollCount, 0, sizeof(rollCount));
    // Reduce to count array
    DieList list = hand->dice;
    for(DieListIterator it = beginDieIt(list); hasNextDieIt(it); it = nextDieIt(it)) {
        rollCount[getDie(it)->currentValue - 1] += 1;
    }

    //
    // Loop through and determine multi roll values
    bool straightPossible = true;
    for(size_t index = 0; index < size; index++) {
        uint8_t current = rollCount[index];
        if(current == 2) {
            stats.pairCount++;
            straightPossible = false;
        } else if(current == 3) {
            stats.hasTrio = true;
            straightPossible = false;
        } else if(current == 4) {
            stats.hasFour = true;
            straightPossible = false;
            break;
        } else if(current == 5) {
            stats.hasFive = true;
            straightPossible = false;
            break;
        }
    }

    // If we have nothing else, we know we have only ones.
    // Check first and last position to confirm straight.
    int firstCount = rollCount[0];
    int lastCount = rollCount[size - 1];
    if(straightPossible) {
        if(firstCount == 1 && lastCount == 0) {
            stats.hasLowStraight = true;
        } else if(firstCount == 0 && lastCount == 1) {
            stats.hasHighStraight = true;
        }
    }
    return stats;
}

PokerHand determineHand(Hand* hand) {
    PokerHand pokerHand = HighestSingle;
    HandStats stats = populateHandStats(hand);
    if(stats.hasTrio && stats.pairCount == 1) {
        pokerHand = FullHouse;
    } else if(stats.pairCount == 1) {
        pokerHand = OnePair;
    } else if(stats.pairCount == 2) {
        pokerHand = TwoPair;
    } else if(stats.hasTrio) {
        pokerHand = ThreeOfAKind;
    } else if(stats.hasFour) {
        pokerHand = FourOfAKind;
    } else if(stats.hasFive) {
        pokerHand = FiveOfAKind;
    } else if(stats.hasLowStraight) {
        pokerHand = LowStraight;
    } else if(stats.hasHighStraight) {
        pokerHand = HighStraight;
    }
    return pokerHand;
}

