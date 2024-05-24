/*
** EPITECH PROJECT, 2020
** my put numbers
** File description:
** display a given number even if it's  positive or negative$
*/

int my_put_nbr(int nb)
{
    nb = nb+48;
    if (nb >= 0)
    {
        my_putchar(nb);
        my_putchar('\n');
    }else {
        my_putchar('-');
        my_putchar(nb);
        my_putchar('\n');
    }        
}
