#include <check.h>

#include "Die.h"

START_TEST(dieCreateDelete) {
    int maxValue = 8;
    Die* die = buildDie(maxValue);
    ck_assert_ptr_nonnull(die);
    ck_assert_int_eq(die->maxValue, maxValue);
    ck_assert_int_eq(die->currentValue, 1);
    deleteDie(&die);
    ck_assert_ptr_null(die);
}
END_TEST

START_TEST(rollDieSpread) {
    int maxValue = 6;
    int buckets[] = {0, 0, 0, 0, 0, 0};
    int totalRuns = 100000;
    Die* die = buildDie(maxValue);
    for (int run = 0; run < totalRuns; run++) {
        rollDie(die);
        ck_assert(die->currentValue >= 1 && die->currentValue <= die->maxValue);
        buckets[die->currentValue - 1] += 1;
    }
    int epsilon = 500;
    int expected = totalRuns / maxValue;
    for (int index = 0; index < sizeof(buckets) / sizeof(buckets[0]); index++) {
        ck_assert((buckets[index] <= (expected + epsilon)) &&
                  (buckets[index] >= (expected - epsilon)));
    }
    deleteDie(&die);
}
END_TEST

Suite* dieSuite(void) {
    Suite* suite;
    TCase* testCase;
    suite = suite_create("Die");
    testCase = tcase_create("Core");
    tcase_add_test(testCase, dieCreateDelete);
    tcase_add_test(testCase, rollDieSpread);
    suite_add_tcase(suite, testCase);
    return suite;
}
