#include <check.h>

#include "Hand.h"
START_TEST(CreateDelete) {
    Hand* hand = buildHand(5);
    ck_assert_ptr_nonnull(hand);
    ck_assert_ptr_nonnull(hand->dice);
    ck_assert_int_eq(sizeDieList(hand->dice), 5);
    ck_assert_int_eq(hand->maxValue, 5);
    deleteHand(hand);
}
END_TEST

Suite* handSuite(void) {
    Suite* suite;
    TCase* testCase;
    suite = suite_create("Hand");
    testCase = tcase_create("Core");
    tcase_add_test(testCase, CreateDelete);
    suite_add_tcase(suite, testCase);
    return suite;
}
