#include <check.h>

#include "PokerUtils.h"

START_TEST(checkHighestSingle) {
    int size = 6;
    uint8_t hand[] = {1, 1, 1, 0, 1, 1};
    ck_assert(determineHand(hand, 6) == HighestSingle);
    uint8_t handTwo[] = {1, 1, 1, 1, 0, 1};
    ck_assert(determineHand(handTwo, 6) == HighestSingle);
    uint8_t handThree[] = {1, 0, 1, 1, 1, 1};
    ck_assert(determineHand(handThree, 6) == HighestSingle);
}
END_TEST

START_TEST(checkOnePair) {
    int size = 6;
    uint8_t hand[] = {0, 2, 1, 1, 1, 0};
    ck_assert(determineHand(hand, 6) == OnePair);
    uint8_t handTwo[] = {2, 0, 1, 1, 1, 0};
    ck_assert(determineHand(handTwo, 6) == OnePair);
    uint8_t handThree[] = {0, 0, 1, 1, 2, 0};
    ck_assert(determineHand(handThree, 6) == OnePair);
}
END_TEST

START_TEST(checkTwoPair) {
    int size = 6;
    uint8_t hand[] = {2, 2, 0, 0, 1, 0};
    ck_assert(determineHand(hand, 6) == TwoPair);
    uint8_t handTwo[] = {0, 0, 2, 1, 2, 0};
    ck_assert(determineHand(handTwo, 6) == TwoPair);
    uint8_t handThree[] = {0, 2, 0, 2, 0, 0};
    ck_assert(determineHand(handThree, 6) == TwoPair);
}
END_TEST

START_TEST(checkThreeOfAKind) {
    int size = 6;
    uint8_t hand[] = {3, 1, 0, 0, 1, 0};
    ck_assert(determineHand(hand, 6) == ThreeOfAKind);
    uint8_t handTwo[] = {1, 0, 0, 1, 0, 3};
    ck_assert(determineHand(handTwo, 6) == ThreeOfAKind);
    uint8_t handThree[] = {0, 1, 0, 3, 0, 1};
    ck_assert(determineHand(handThree, 6) == ThreeOfAKind);
}
END_TEST

START_TEST(checkLowStraight) {
    int size = 6;
    uint8_t hand[] = {1, 1, 1, 1, 1, 0};
    ck_assert(determineHand(hand, 6) == LowStraight);
}
END_TEST

START_TEST(checkHighStraight) {
    int size = 6;
    uint8_t hand[] = {0, 1, 1, 1, 1, 1};
    ck_assert(determineHand(hand, 6) == HighStraight);
}
END_TEST

START_TEST(checkFourOfAKind) {
    int size = 6;
    uint8_t hand[] = {4, 0, 0, 0, 1, 0};
    ck_assert(determineHand(hand, 6) == FourOfAKind);
    uint8_t handTwo[] = {1, 0, 0, 0, 4, 0};
    ck_assert(determineHand(handTwo, 6) == FourOfAKind);
    uint8_t handThree[] = {0, 1, 4, 0, 0, 0};
    ck_assert(determineHand(handThree, 6) == FourOfAKind);
}
END_TEST

START_TEST(checkFiveOfAKind) {
    int size = 6;
    uint8_t hand[] = {5, 0, 0, 0, 0, 0};
    ck_assert(determineHand(hand, 6) == FiveOfAKind);
    uint8_t handTwo[] = {0, 0, 0, 0, 0, 5};
    ck_assert(determineHand(handTwo, 6) == FiveOfAKind);
    uint8_t handThree[] = {0, 0, 0, 5, 0, 0};
    ck_assert(determineHand(handThree, 6) == FiveOfAKind);
}
END_TEST

Suite* pokerSuite(void) {
    Suite* suite;
    TCase* testCase;
    suite = suite_create("PokerUtils");
    testCase = tcase_create("Core");
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
