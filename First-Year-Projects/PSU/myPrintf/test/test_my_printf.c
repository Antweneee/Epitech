/*
** EPITECH PROJECT, 2020
** test
** File description:
** test
*/

#include "../include/my.h"
#include "../include/my_printf.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

void redirect_stdout(void)
{
        cr_redirect_stdout();
}

Test(my_printf, printf_string, .init = redirect_stdout)
{
    my_printf("%s\n", "antoine");
    cr_assert_stdout_eq_str("antoine\n");
}

Test(my_printf, printf_stringspace, .init = redirect_stdout)
{
    my_printf("%s \n", "antoine");
    cr_assert_stdout_eq_str("antoine \n");
}

Test(my_printf, printf_char, .init = redirect_stdout)
{
    my_printf("%c\n", 'a');
    cr_assert_stdout_eq_str("a\n");
}

Test(my_printf, printf_sentence, .init = redirect_stdout)
{
    my_printf("je m'appelle %s\n", "antoine");
    cr_assert_stdout_eq_str("je m'appelle antoine\n");
}

Test(my_printf, printf_int, .init = redirect_stdout)
{
    my_printf("%i\n", 123);
    cr_assert_stdout_eq_str("123\n");
}

Test(my_printf, printf_deci, .init = redirect_stdout)
{
    my_printf("%d\n", 123);
    cr_assert_stdout_eq_str("123\n");
}

Test(my_printf, printf_mix, .init = redirect_stdout)
{
    my_printf("je suis %s et j'ai %d ans\n", "fatigue", 18);
    cr_assert_stdout_eq_str("je suis fatigue et j'ai 18 ans\n");
}

Test(my_printf, printf_testmouli, .init = redirect_stdout)
{
    my_printf("%s\n", "astek", "moulinette");
    cr_assert_stdout_eq_str("astek\n");
}

Test(my_printf, printf_hexa_maj, .init = redirect_stdout)
{
    my_printf("%X\n", 1000);
    cr_assert_stdout_eq_str("3E8\n");
}

Test(my_printf, printf_hexa_majzerosp, .init = redirect_stdout)
{
    my_printf("%05X\n", 1000);
    cr_assert_stdout_eq_str("003E8\n");
}

Test(my_printf, printf_hexa_majspace, .init = redirect_stdout)
{
    my_printf("%5X\n", 1000);
    cr_assert_stdout_eq_str("  3E8\n");
}

Test(my_printf, printf_hexa_minzero, .init = redirect_stdout)
{
    my_printf("%05x\n", 1000);
    cr_assert_stdout_eq_str("003e8\n");
}

Test(my_printf, printf_hexa_minspace, .init = redirect_stdout)
{
    my_printf("%5x\n", 1000);
    cr_assert_stdout_eq_str("  3e8\n");
}

Test(my_printf, printf_fullmix, .init = redirect_stdout)
{
    my_printf("je %s %d %c %05X\n", "test", 12, 'a', 1000);
    cr_assert_stdout_eq_str("je test 12 a 003E8\n");
}

Test(my_printf, printfdualstring$, .init = redirect_stdout)
{
    my_printf("%s%s\n", "^astek","moulinette");
    cr_assert_stdout_eq_str("^astekmoulinette\n");
}
