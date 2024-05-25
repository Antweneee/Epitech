/*
** EPITECH PROJECT, 2020
** convert base
** File description:
** convert base
*/

#include "../../include/my.h"

int hexa_tab(int nb)
{
    if (nb <= 9)
        nb = nb + 48;
    if (nb == 10)
        nb = 65;
    if (nb == 11)
        nb = 66;
    if (nb == 12)
        nb = 67;
    if (nb == 13)
        nb = 68;
    if (nb == 14)
        nb = 69;
    if (nb == 15)
        nb = 70;
    return (nb);
}

char intermediate(int nb, int i)
{
    char inter;
    int in = 0;
    int r = 0;
    int x;

    in = nb / 16;
    r = in * 16;
    for (x = 0; r != nb; x++) {
        r++;
    }
    if (i == 0) {
        inter = hexa_tab(in);
        return (inter);
    }
    if (i == 1) {
        inter = hexa_tab(x);
        return (inter);
    }
    return ('\0');
}

char *big_number(int nbr)
{
    char *b_hexa = malloc(sizeof(char) + ((nbr * 2) + 1));
    int res = 0;
    int nb;

    res = nbr / 16;
    if (res > 15) {
        b_hexa[0] = intermediate(res, 0);
        b_hexa[1] = intermediate(res, 1);
    } else 
        b_hexa[0] = hexa_tab(res);
    res = res * 16;
    for (nb = 0; res != nbr; res++) {
        nb++;
    }
    b_hexa[2] = hexa_tab(nb);
    b_hexa[3] = '\0';
    return (b_hexa);
}

char *convert_hexa(int nbr)
{
    char *hexa_v = malloc(sizeof(char) + ((nbr * 2) + 1));
    int r = 0;
    int nb;

    if (nbr > 127)
        return (big_number(nbr));
    r = nbr / 16;
    hexa_v[0] = hexa_tab(r);
    r = r * 16;
    for (nb = 0; r != nbr; r++) {
        nb++;
    }
    hexa_v[1] = hexa_tab(nb);
    hexa_v[3] = '\0';
    return (hexa_v);
}
