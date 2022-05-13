#include <check.h>

#include "PlayerNode.h"

START_TEST(playerNodeCreateDelete) {
    Player player;
    char* name = "Player";
    int tokens = 20;
    player.name = name;
    player.tokens = tokens;
    PlayerNode* node = buildPlayerNode(player);
    ck_assert_ptr_nonnull(node);
    ck_assert_str_eq(node->value.name, name);
    ck_assert_int_eq(node->value.tokens, tokens);
    ck_assert_ptr_null(node->next);
    deletePlayerNode(&node);
    ck_assert_ptr_null(node);
}
END_TEST

Suite* playerNodeSuite(void) {
    Suite* suite;
    TCase* testCase;
    suite = suite_create("PlayerNode");
    testCase = tcase_create("Core");
    tcase_add_test(testCase, playerNodeCreateDelete);
    suite_add_tcase(suite, testCase);
    return suite;
}
