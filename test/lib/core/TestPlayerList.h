#include <check.h>
#include <stdio.h>

#include "PlayerList.h"

Player buildPlayerTest(char* name, int tokens) {
    Player player;
    player.name = name;
    player.tokens = tokens;
    return player;
}

START_TEST(CreateDeleteListAndIterator) {
    PlayerList* list = buildPlayerList();
    ck_assert_ptr_nonnull(list);
    ck_assert_int_eq(sizePlayerList(list), 0);
    ck_assert_ptr_null(beginPlayerIt(list));
    deletePlayerList(list);
}
END_TEST

START_TEST(PushPlayerAndIterator) {
    char* name = "Player";
    int tokens = 40;
    PlayerList* list = buildPlayerList();
    ck_assert_ptr_nonnull(list);
    ck_assert_int_eq(sizePlayerList(list), 0);

    pushPlayer(list, buildPlayerTest(name, tokens));
    ck_assert_int_eq(sizePlayerList(list), 1);
    PlayerListIterator it = beginPlayerIt(list);
    ck_assert_ptr_nonnull(it);
    Player value = getPlayer(it);
    ck_assert_str_eq(value.name, name);
    ck_assert_int_eq(value.tokens, tokens);
    ck_assert_ptr_null(nextPlayerIt(it));

    char* nameTwo = "Player2";
    int tokensTwo = 20;
    pushPlayer(list, buildPlayerTest(nameTwo, tokensTwo));
    ck_assert_int_eq(sizePlayerList(list), 2);
    it = beginPlayerIt(list);
    ck_assert_ptr_nonnull(it);
    Player valueOne = getPlayer(it);
    ck_assert_str_eq(value.name, name);
    ck_assert_int_eq(value.tokens, tokens);

    it = nextPlayerIt(it);
    Player valueTwo = getPlayer(it);
    ck_assert_str_eq(valueTwo.name, nameTwo);
    ck_assert_int_eq(valueTwo.tokens, tokensTwo);

    deletePlayerList(list);
}
END_TEST

START_TEST(LoopThroughIterator) {
    char* name = "Player";
    int tokens = 40;
    PlayerList* list = buildPlayerList();
    ck_assert_ptr_nonnull(list);
    ck_assert_int_eq(sizePlayerList(list), 0);
    pushPlayer(list, buildPlayerTest(name, tokens));
    pushPlayer(list, buildPlayerTest(name, tokens));
    pushPlayer(list, buildPlayerTest(name, tokens));

    int count = 0;
    PlayerListIterator it = NULL;
    for (it = beginPlayerIt(list); hasNextPlayerIt(it); nextPlayerIt(it)) {
        Player current = getPlayer(it);
        ck_assert_str_eq(current.name, name);
        ck_assert_int_eq(current.tokens, tokens);
        count++;
    }
    ck_assert_int_eq(count, 3);
}
END_TEST

Suite* playerListSuite(void) {
    Suite* suite = suite_create("PlayerList");
    TCase* testCase = tcase_create("Core");
    tcase_add_test(testCase, CreateDeleteListAndIterator);
    tcase_add_test(testCase, PushPlayerAndIterator);
    tcase_add_test(testCase, LoopThroughIterator);
    suite_add_tcase(suite, testCase);
    return suite;
}
