/*
** EPITECH PROJECT, 2020
** infin add
** File description:
** program that performs infinite add
*/

#include <stdio.h>
#include <stdlib.h>
#include "my.h"

int error(int ac, char **av)
{
    if (ac != 3) {
        return (84);
    }
    return (0);
}

int rest(char nb1, char nb2)
{
    int rest = 0;

    if (nb1 == '\0' || nb2 == '\0') {
        rest = 0;
    } else {
        rest = (((nb1 - '0') + (nb2 - '0')) / 10);
    }
    return (rest);
}

char *infin_add(char **av)
{
    char *nb1 = my_revstr(av[1]);
    char *nb2 = my_revstr(av[2]);
    char *result = malloc(sizeof(char) * (my_strlen(nb1) + my_strlen(nb2) + 1));
    int i = 0;
    int ret = 0;

    while (i != my_strlen(nb1)) {
        result[i] = (((nb1[i] - '0') + (nb2[i] - '0') + ret) % 10) + '0';
        ret = rest(nb1[i], nb2[i]);
        i = i + 1;
    }
    if (ret == 1)
        result[i] = ret + '0';
    result[i + 1] = '\0';
    return (my_revstr(result));
}
