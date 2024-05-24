/*
** EPITECH PROJECT, 2020
** my put numbers
** File description:
** display a given number even if it's  positive or negative$
*/

int my_put_nbr(int nb)
{
    int nbr;

    if (nb < 0) {
        my_putchar('-');
        nb = nb * (-1);
    }
    if (nb >= 0) {
        if (nb > 9) {
            nbr = (nb % 10);
            nb = (nb - nbr) / 10;
            my_put_nbr(nb);
            my_putchar(nbr + 48);
            return (nb);
        } else {
            my_putchar(48 + nb % 10);
        }
    }
}
