#include <check.h>

#include "Hand.h"
#include "PokerUtils.h"

Hand* hand;

void setup(void) { hand = buildHand(6); }

void teardown(void) {
    deleteHand(hand);
    hand = NULL;
}

void populateHand(Hand* hand, uint8_t* handArray) {
    DieListIterator it = beginDieIt(hand->dice);
    for (int index = 0; index < sizeDieList(hand->dice); index++) {
        Die* current = getDie(it);
        current->currentValue = handArray[index];
        it = nextDieIt(it);
    }
}

START_TEST(checkHighestSingle) {
    uint8_t hands[3][5] = {{1, 2, 4, 5, 6}, {1, 3, 4, 5, 6}, {1, 2, 3, 5, 6}};
    for (int index = 0; index < 3; index++) {
        populateHand(hand, hands[index]);
        ck_assert(determineHand(hand) == HighestSingle);
    }
}
END_TEST

START_TEST(checkOnePair) {
    uint8_t hands[3][5] = {{2, 2, 4, 5, 6}, {1, 6, 4, 5, 6}, {1, 2, 5, 5, 6}};
    for (int index = 0; index < 3; index++) {
        populateHand(hand, hands[index]);
        ck_assert(determineHand(hand) == OnePair);
    }
}

END_TEST

START_TEST(checkTwoPair) {
    uint8_t hands[3][5] = {{2, 2, 4, 6, 6}, {1, 6, 5, 5, 6}, {1, 2, 5, 5, 1}};
    for (int index = 0; index < 3; index++) {
        populateHand(hand, hands[index]);
        ck_assert(determineHand(hand) == TwoPair);
    }
}
END_TEST

START_TEST(checkThreeOfAKind) {
    uint8_t hands[3][5] = {{1, 6, 4, 6, 6}, {1, 3, 5, 5, 5}, {1, 2, 1, 5, 1}};
    for (int index = 0; index < 3; index++) {
        populateHand(hand, hands[index]);
        ck_assert(determineHand(hand) == ThreeOfAKind);
    }
}
END_TEST

START_TEST(checkLowStraight) {
    uint8_t hands[5] = {1, 2, 3, 4, 5};
    populateHand(hand, hands);
    ck_assert(determineHand(hand) == LowStraight);
}
END_TEST

START_TEST(checkHighStraight) {
    uint8_t hands[5] = {2, 3, 4, 5, 6};
    populateHand(hand, hands);
    ck_assert(determineHand(hand) == HighStraight);
}
END_TEST

START_TEST(checkFourOfAKind) {
    uint8_t hands[3][5] = {{4, 4, 4, 4, 6}, {1, 3, 1, 1, 1}, {1, 2, 2, 2, 2}};
    for (int index = 0; index < 3; index++) {
        populateHand(hand, hands[index]);
        ck_assert(determineHand(hand) == FourOfAKind);
    }
}
END_TEST

START_TEST(checkFiveOfAKind) {
    uint8_t hands[3][5] = {{6, 6, 6, 6, 6}, {1, 1, 1, 1, 1}, {3, 3, 3, 3, 3}};
    for (int index = 0; index < 3; index++) {
        populateHand(hand, hands[index]);
        ck_assert(determineHand(hand) == FiveOfAKind);
    }
}
END_TEST

Suite* pokerUtilsSuite(void) {
    Suite* suite;
    TCase* testCase;
    suite = suite_create("PokerUtils");
    testCase = tcase_create("Core");
    tcase_add_checked_fixture(testCase, setup, teardown);
    tcase_add_test(testCase, checkHighestSingle);
    tcase_add_test(testCase, checkOnePair);
    tcase_add_test(testCase, checkTwoPair);
    tcase_add_test(testCase, checkThreeOfAKind);
    tcase_add_test(testCase, checkLowStraight);
    tcase_add_test(testCase, checkHighStraight);
    tcase_add_test(testCase, checkFourOfAKind);
    tcase_add_test(testCase, checkFiveOfAKind);
    suite_add_tcase(suite, testCase);
    return suite;
}
