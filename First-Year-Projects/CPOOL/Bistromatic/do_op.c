/*
** EPITECH PROJECT, 2020
** do_op
** File description:
** program must compute an opration*
*/

#include <stdio.h>
#include <unistd.h>
#include "my.h"

int do_op(char str, int nb1, int nb2)
{
    if (str == '-') {
        return (nb1 - nb2);
    }
    if (str == '+') {
        return (nb1 + nb2);
    }
    if (str == '*') {
        return (nb1 * nb2);
    }
    if (str == '/') {
        return (nb1 / nb2);
    }
    if (str == '%') {
        return (nb1 % nb2);
    }
    return(0);
}
