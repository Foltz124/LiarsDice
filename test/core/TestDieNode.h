#include <check.h>

#include "DieNode.h"

START_TEST(dieNodeCreateDelete) {
    Die die;
    uint8_t maxValue = 8;
    uint8_t currentValue = 4;
    die.maxValue = maxValue;
    die.currentValue = currentValue;
    DieNode* node = buildDieNode(die);
    ck_assert_ptr_nonnull(node);
    ck_assert_int_eq(node->value.maxValue, maxValue);
    ck_assert_int_eq(node->value.currentValue, currentValue);
    ck_assert_ptr_null(node->next);
    ck_assert_ptr_null(node->previous);
    deleteDieNode(&node);
    ck_assert_ptr_null(node);
}
END_TEST

Suite* dieNodeSuite(void) {
    Suite* suite;
    TCase* testCase;
    suite = suite_create("DieNode");
    testCase = tcase_create("Core");
    tcase_add_test(testCase, dieNodeCreateDelete);
    suite_add_tcase(suite, testCase);
    return suite;
}
