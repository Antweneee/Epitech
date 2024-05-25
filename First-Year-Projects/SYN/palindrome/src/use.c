/*
** EPITECH PROJECT, 2021
** B-SYN-200-PAR-2-1-palindrome-antoine.gavira-bottari
** File description:
** use
*/

#include "palindrom.h"

char *rev_str(char const *str)
{
    int e = 0;
    char *res = malloc(sizeof(char) * (strlen(str) + 1));

    if (res == NULL)
        return NULL;
    for (int i = strlen(str) - 1; i != -1; e++) {
        res[e] = str[i];
        i--;
    }
    res[e] = '\0';
    return res;
}

int power_rec(int nb, int power)
{
    if (power == 0)
        return 1;
    if (power < 0)
        return 0;
    nb = nb * power_rec(nb, power - 1);
    return nb;
}

int revint(int nb)
{
    int rem = 0;
    int rev = 0;

    while (nb != 0) {
        rem = nb % 10;
        rev = rev * 10 + rem;
        nb /= 10;
    }
    return rev;
}