/*
** EPITECH PROJECT, 2020
** main
** File description:
** main
*/

#include "my.h"

int main(int ac, char **av)
{
    if (error(ac, av) == 84) {
        return (84);
    }
    my_putstr(infin_add(av));
    return (0);
}