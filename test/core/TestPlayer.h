#include <check.h>

#include "Player.h"

START_TEST(playerCreateDelete) {
    char* name = "Player";
    int tokens = 20;
    Player* player = buildPlayer(name, tokens);
    ck_assert_ptr_nonnull(player);
    ck_assert_str_eq(player->name, name);
    ck_assert_int_eq(player->tokens, tokens);
    deletePlayer(&player);
    ck_assert_ptr_null(player);
}
END_TEST

Suite* playerSuite(void) {
    Suite* suite;
    TCase* testCase;
    suite = suite_create("Player");
    testCase = tcase_create("Core");
    tcase_add_test(testCase, playerCreateDelete);
    suite_add_tcase(suite, testCase);
    return suite;
}
