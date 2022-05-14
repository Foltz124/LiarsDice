#include <check.h>

#include "DieList.h"

Die buildDieTest(uint8_t maxValue, uint8_t currentValue) {
    Die die;
    die.maxValue = maxValue;
    die.currentValue = currentValue;
    return die;
}

START_TEST(dieListCreateDelete) {
    DieList* list = buildDieList();
    ck_assert_ptr_nonnull(list);
    ck_assert_int_eq(sizeDieList(list), 0);
    ck_assert_ptr_null(beginDieIt(list));
    ck_assert_ptr_null(endDieIt(list));
    deleteDieList(list);
}
END_TEST

START_TEST(pushDieListOneElement) {
    int maxValue = 6;
    int currentValue = 8;
    DieList* list = buildDieList();
    ck_assert_ptr_nonnull(list);
    ck_assert_int_eq(sizeDieList(list), 0);

    // Check begin iterator
    pushDie(list, buildDieTest(maxValue, currentValue));
    ck_assert_int_eq(sizeDieList(list), 1);
    DieListIterator it = beginDieIt(list);
    ck_assert_ptr_nonnull(it);
    Die value = getDie(it);
    ck_assert_int_eq(value.maxValue, maxValue);
    ck_assert_int_eq(value.currentValue, currentValue);

    // Check end iterator
    it = endDieIt(list);
    ck_assert_ptr_nonnull(it);
    value = getDie(it);
    ck_assert_int_eq(value.maxValue, maxValue);
    ck_assert_int_eq(value.currentValue, currentValue);
}
END_TEST

START_TEST(pushDieListTwoElement) {
    int maxValueOne = 6;
    int currentValueOne = 8;
    int maxValueTwo = 8;
    int currentValueTwo = 6;
    DieList* list = buildDieList();
    ck_assert_ptr_nonnull(list);
    ck_assert_int_eq(sizeDieList(list), 0);

    // Check begin iterator
    pushDie(list, buildDieTest(maxValueOne, currentValueOne));
    pushDie(list, buildDieTest(maxValueTwo, currentValueTwo));
    ck_assert_int_eq(sizeDieList(list), 2);
    DieListIterator it = beginDieIt(list);
    ck_assert_ptr_nonnull(it);
    Die value = getDie(it);
    ck_assert_int_eq(value.maxValue, maxValueOne);
    ck_assert_int_eq(value.currentValue, currentValueOne);

    ck_assert(nextDieIt(it) == endDieIt(list));

    // Check end iterator
    it = endDieIt(list);
    ck_assert_ptr_nonnull(it);
    value = getDie(it);
    ck_assert_int_eq(value.maxValue, maxValueTwo);
    ck_assert_int_eq(value.currentValue, currentValueTwo);

    ck_assert(previousDieIt(it) == beginDieIt(list));
}
END_TEST

START_TEST(loopThroughIterator) {
    int maxValue = 6;
    int currentValue = 8;
    DieList* list = buildDieList();
    ck_assert_ptr_nonnull(list);
    ck_assert_int_eq(sizeDieList(list), 0);

    // Check begin iterator
    pushDie(list, buildDieTest(maxValue, currentValue));
    pushDie(list, buildDieTest(maxValue, currentValue));
    pushDie(list, buildDieTest(maxValue, currentValue));

    int count = 0;
    DieListIterator it = NULL;
    for (it = beginDieIt(list); hasNextDieIt(it); it = nextDieIt(it)) {
        Die current = getDie(it);
        ck_assert_int_eq(current.maxValue, maxValue);
        ck_assert_int_eq(current.currentValue, currentValue);
        count++;
    }
    ck_assert_int_eq(count, 3);

    count = 0;
    for (it = endDieIt(list); hasPreviousDieIt(it); it = previousDieIt(it)) {
        Die current = getDie(it);
        ck_assert_int_eq(current.maxValue, maxValue);
        ck_assert_int_eq(current.currentValue, currentValue);
        count++;
    }
    ck_assert_int_eq(count, 3);
}
END_TEST

Suite* dieListSuite(void) {
    Suite* suite = suite_create("DieList");
    TCase* testCase = tcase_create("Core");
    tcase_add_test(testCase, dieListCreateDelete);
    tcase_add_test(testCase, pushDieListOneElement);
    tcase_add_test(testCase, pushDieListTwoElement);
    tcase_add_test(testCase, loopThroughIterator);
    suite_add_tcase(suite, testCase);
    return suite;
}
