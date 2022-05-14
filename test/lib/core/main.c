#include <check.h>
#include <stdlib.h>

#include "TestDie.h"
#include "TestDieList.h"
#include "TestPlayer.h"
#include "TestPlayerList.h"

int main(void) {
    int numberFailed = 0;
    Suite* mainSuite = suite_create("Core");
    SRunner* suiteRunner;

    suiteRunner = srunner_create(mainSuite);
    srunner_add_suite(suiteRunner, dieSuite());
    srunner_add_suite(suiteRunner, dieListSuite());
    srunner_add_suite(suiteRunner, playerSuite());
    srunner_add_suite(suiteRunner, playerListSuite());

    srunner_run_all(suiteRunner, CK_NORMAL);
    numberFailed = srunner_ntests_failed(suiteRunner);
    srunner_free(suiteRunner);
    return (numberFailed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
