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
    ck_assert_int_eq(list->size, 0);
    ck_assert_ptr_null(list->head);
    ck_assert_ptr_null(list->tail);
    deleteDieList(&list);
    ck_assert_ptr_null(list);
}
END_TEST

START_TEST(pushDieList) {
    int firstMax = 6;
    int secondMax = 8;
    DieList* list = buildDieList();
    ck_assert_ptr_nonnull(list);
    pushDie(list, buildDieTest(firstMax, firstMax));
    // Check that head/tail + size are handled correctly on first push
    ck_assert_int_eq(list->size, 1);
    ck_assert(list->head == list->tail);
    ck_assert_ptr_null(list->head->next);
    ck_assert_ptr_null(list->head->previous);
    ck_assert_int_eq(list->head->value.maxValue, firstMax);
    ck_assert_int_eq(list->head->value.currentValue, firstMax);

    // Check that head/tail + size are handled on subsequent pushes
    pushDie(list, buildDieTest(secondMax, secondMax));
    ck_assert_int_eq(list->size, 2);
    ck_assert(list->head != list->tail);
    ck_assert_int_eq(list->head->value.maxValue, firstMax);
    ck_assert_int_eq(list->head->value.currentValue, firstMax);
    ck_assert_ptr_null(list->head->previous);
    ck_assert(list->head->next == list->tail);
    ck_assert_int_eq(list->tail->value.maxValue, secondMax);
    ck_assert_int_eq(list->tail->value.currentValue, secondMax);
    ck_assert_ptr_null(list->tail->next);
    ck_assert(list->tail->previous == list->head);
    ck_assert(list->tail->previous == list->head);
}
END_TEST

Suite* dieListSuite(void) {
    Suite* suite = suite_create("DieList");
    TCase* testCase = tcase_create("Core");
    tcase_add_test(testCase, dieListCreateDelete);
    tcase_add_test(testCase, pushDieList);
    suite_add_tcase(suite, testCase);
    return suite;
}
