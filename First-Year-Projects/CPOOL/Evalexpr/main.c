/*
** EPITECH PROJECT, 2020
** main
** File description:
** main
*/

#include "include/my.h"

int eval_expr(char *str);

int main(int ac, char ** av)
{
    if (ac == 2) {
        my_put_nbr(eval_expr(av[1]));
        my_putchar('\n');
        return (0);
    }
}
