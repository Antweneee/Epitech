/*
** EPITECH PROJECT, 2020
** infin add
** File description:
** program that performs infinite add
*/

#include <stdlib.h>
#include "my.h"

int error(int ac, char **av)
{
    if (ac != 3) {
        return (84);
    }
    return (0);
}

int rest(char nb1, char nb2, int ret)
{
    int rest = 0;

    if (nb1 == '\0' || nb2 == '\0') {
        rest = 0;
    } else if (((nb1 - '0') + (nb2 - '0') + ret) > 9) {
        rest = 1;
    }
    return (rest);
}

char *gestion_nb1(char **av)
{
    char *a = malloc(sizeof(char) * (my_strlen(av[2] + 1)));
    int i = my_strlen(av[1]);
    int p = my_strlen(av[2]);

    a = my_strcpy(a, av[1]);
    if (a[0] == '-') {
        if (av[2][0] == '-')
            p = p - 1;
        i = i - 1;
        a = a + 1;
    }
    a = my_revstr(a);
    if (i < p) {
        for (; i != p; i++) {
            a[i] = '0';
        }
        return (a);
    } else {
        return (a);
    }
}

char *gestion_nb2(char **av)
{
    char *b = malloc(sizeof(char) * (my_strlen(av[1])));
    int p = my_strlen(av[2]);
    int i = my_strlen(av[1]);

    b = my_strcpy(b, av[2]);
    if (b[0] == '-') {
        if (av[1][0] == '-')
            i = i - 1;
        p = p - 1;
        b = b + 1;
    }
    b = my_revstr(b);
    if (my_strlen(av[1]) > my_strlen(b)) {
        for (; p != i; p++) {
            b[p] = '0';
        }
        return (b);
    } else {
        return (b);
    }
}

char *infin_add(char **av)
{
    char *nb1 = gestion_nb1(av);
    char *nb2 = gestion_nb2(av);
    char *result = malloc(sizeof(char) * (my_strlen(nb1) + my_strlen(nb2) + 1));
    int i = 0;
    int g = my_strlen(nb1);
    int ret = 0;

    if (av[1][0] == '-' || av[2][0] == '-') {
        return (check(av));
    }
    for (; i != g; i++) {
        result[i] = ((nb1[i] - '0') + (nb2[i] - '0') + ret)% 10 + '0';
        ret = rest(nb1[i], nb2[i], ret);
    }
    if (ret == 1) {
        result[i] = ret + '0';
        i = i + 1;
    }
    result[i + 1] = '\0';
    return (my_revstr(result));
}
