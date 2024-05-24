/*
** EPITECH PROJECT, 2020
** check neg
** File description:
** check neg for infin add
*/

#include "my.h"
#include <stdlib.h>

char *negneg(char **av)
{
    char *nb1 = gestion_nb1(av);
    char *nb2 = gestion_nb2(av);
    char *result = malloc(sizeof(char) * (my_strlen(nb1) + my_strlen(nb2) + 1));
    int i = 0;
    int g = my_strlen(nb1);
    int ret = 0;

    for (; i != g; i++) {
        result[i] = ((nb1[i] - '0') + (nb2[i] - '0') + ret) %10 + '0';
        ret = rest(nb1[i], nb2[i], ret);
    }
    if (ret == 1) {
        result[i] = ret + '0';
        i = i + 1;
    }
    result[i] = '-';
    return (my_revstr(result));
}

char *plusneg(char **av)
{
    char *nb1 = gestion_nb1(av);
    char *nb2 = gestion_nb2(av);
    char *result = malloc(sizeof(char) * (my_strlen(nb1) + my_strlen(nb2) + 1));
    int i = 0;
    int g = my_strlen(nb1);

    for (; i != g; i++) {
        if (nb1[i] > nb2[i]) {
            result[i] = (nb1[i] - '0') - (nb2[i] - '0') % 10 + '0';
        } else {
            result[i] = (nb2[i] - '0') - (nb1[i] - '0') % 10 + '0';
        }
    }
    for (; result[i - 1] == '0'; i--) {
        result[i] = '\0';
    }
    if ((my_getnbr(av[1]) + my_getnbr(av[2])) < 0)
        result[i] = '-';
    return (my_revstr(result));
}

char *check(char **av)
{
    if (av[1][0] == '-' && av[2][0] != '-' || av[1][0] != '-'
        && av[2][0] == '-')
        return (plusneg(av));
    if (av[1][0] == '-' && av[2][0] == '-') {
        return (negneg(av));
    } else {
        return (0);
    }
}
