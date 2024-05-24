/*
** EPITECH PROJECT, 2020
** test
** File description:
** test
*/

#include <criterion/criterion.h>

Test(my_revstr, reverse_string)
{
    char *str = strdup("hello");

    my_revstr(str);
    cr_assert_str_eq(str, "olleh");
}
