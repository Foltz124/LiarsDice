#pragma once
#include <stdint.h>

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

PokerHand determineHand(uint8_t* hand, uint8_t size);

