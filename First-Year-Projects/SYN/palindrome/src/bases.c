/*
** EPITECH PROJECT, 2021
** B-SYN-200-PAR-2-1-palindrome-antoine.gavira-bottari
** File description:
** bases
*/

#include "palindrom.h"

int base_to_decimal(char *nb, int base)
{
    int res = 0;

    for (int i = 0; nb[i] != '\0'; i++) {
        res += ((nb[strlen(nb) - i - 1] - '0') * power_rec(base, i));
    }
    return res;
}

char *convert_deci_to_base(int base, int nb)
{
    char *res = malloc(sizeof(char) * 1000);
    int i = 0;

    while (nb > 0) {
        res[i] = nb % base + '0';
        nb = nb / base;
        i++;
    }
    res[i] = '\0';
    res = rev_str(res);
    return res;
}