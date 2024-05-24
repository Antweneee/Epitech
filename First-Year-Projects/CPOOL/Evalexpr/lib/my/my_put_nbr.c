/*
** EPITECH PROJECT, 2020
** d
** File description:
** d
*/

#include <unistd.h>

int my_putchar(char c);

int my_put_nbr(int nb)
{
    if (nb < 0) {
        my_putchar(45);
        nb = nb *(-1);
    }
    if (nb >= 10) {
        my_put_nbr(nb / 10);
        my_put_nbr(nb % 10);
    }
    else {
        my_putchar(nb + '0');
    }
    return (0);
}
