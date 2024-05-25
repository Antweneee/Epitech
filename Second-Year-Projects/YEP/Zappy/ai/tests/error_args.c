/*
** EPITECH PROJECT, 2022
** B-YEP-410-PAR-4-1-zappy-thomas.willson
** File description:
** error_args
*/

#include "prototypes.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <criterion/assert.h>
#include <criterion/output.h>
#include <stdlib.h>

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(test_is_num, isnum, .init=redirect_all_std)
{
    const char* str = "3232";

    cr_assert_eq(is_num(str), 1);
}

Test(test_is_num_failed, is_num_failed, .init=redirect_all_std)
{
    const char* str = "caca";

    cr_assert_eq(is_num(str), 0);
}

Test(check_args, check_args1, .init=redirect_all_std)
{
    int argc = 3;
    const char* argv[] = { 0 };

    cr_assert_eq(check_args(argc, argv), 0);
}

Test(check_args, check_args2, .init=redirect_all_std)
{
    int argc = 3;
    const char* argv[] = { 0 };

    cr_assert_eq(check_args(argc, argv), 0);
}

Test(check_args, check_args3, .init=redirect_all_std)
{
    int argc = 7;
    const char* argv[] = {"./zappy_ui", "-p", "3232", "-n", "caca_team", "-h", "127.0.0.1"};

    cr_assert_eq(check_args(argc, argv), 1);
}

Test(check_args, check_args4, .init=redirect_all_std)
{
    int argc = 7;
    const char* argv[] = {"./zappy_ui", "-p", "toto", "-n", "caca_team", "-h", "127.0.0.1"};

    cr_assert_eq(check_args(argc, argv), 0);
}

Test(check_args, check_args5, .init=redirect_all_std)
{
    int argc = 7;
    const char* argv[] = {"./zappy_ui", "-p", "3232", "-r", "tuti", "-h", "127.0.0.1"};

    cr_assert_eq(check_args(argc, argv), 0);
}

Test(check_args, check_args6, .init=redirect_all_std)
{
    int argc = 7;
    const char* argv[] = {"./zappy_ui", "-p", "3232", "-n", "tuti", "-s", "127.0.0.1"};

    cr_assert_eq(check_args(argc, argv), 0);
}