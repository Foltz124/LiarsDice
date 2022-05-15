#pragma once
#include <stdint.h>

#include "Hand.h"

// Types of poker hands
typedef enum PokerHand {
    HighestSingle,
    OnePair,
    TwoPair,
    ThreeOfAKind,
    LowStraight,
    HighStraight,
    FullHouse,
    FourOfAKind,
    FiveOfAKind
} PokerHand;

// Determines the result of the current hand.
PokerHand determineHand(Hand* hand);

