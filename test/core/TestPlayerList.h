#include <check.h>

#include "PlayerList.h"

Player buildPlayerTest(char* name, int tokens) {
    Player player;
    player.name = name;
    player.tokens = tokens;
    return player;
}

START_TEST(playerListCreateDelete) {
    PlayerList* list = buildPlayerList();
    ck_assert_ptr_nonnull(list);
    ck_assert_int_eq(list->size, 0);
    ck_assert_ptr_null(list->head);
    ck_assert_ptr_null(list->tail);
    deletePlayerList(&list);
    ck_assert_ptr_null(list);
}
END_TEST

START_TEST(pushPlayerList) {
    char* playerOne = "Player";
    int playerOneTokens = 20;
    char* playerTwo = "Player2";
    int playerTwoTokens = 10;
    PlayerList* list = buildPlayerList();
    ck_assert_ptr_nonnull(list);
    push(list, buildPlayerTest(playerOne, playerOneTokens));
    // Check that head/tail + size are handled correctly on first push
    ck_assert_int_eq(list->size, 1);
    ck_assert(list->head == list->tail);
    ck_assert_ptr_null(list->head->next);
    ck_assert_ptr_null(list->tail->next);
    ck_assert_str_eq(list->head->value.name, playerOne);
    ck_assert_int_eq(list->head->value.tokens, playerOneTokens);

    // Check that head/tail + size are handled on subsequent pushes
    push(list, buildPlayerTest(playerTwo, playerTwoTokens));
    ck_assert_int_eq(list->size, 2);
    ck_assert(list->head != list->tail);
    ck_assert_str_eq(list->head->value.name, playerOne);
    ck_assert_int_eq(list->head->value.tokens, playerOneTokens);
    ck_assert_str_eq(list->tail->value.name, playerTwo);
    ck_assert_int_eq(list->tail->value.tokens, playerTwoTokens);
    ck_assert(list->head->next == list->tail);
    deletePlayerList(&list);
}
END_TEST

Suite* playerListSuite(void) {
    Suite* suite = suite_create("PlayerList");
    TCase* testCase = tcase_create("Core");
    tcase_add_test(testCase, playerListCreateDelete);
    tcase_add_test(testCase, pushPlayerList);
    suite_add_tcase(suite, testCase);
    return suite;
}
