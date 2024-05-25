/*
** EPITECH PROJECT, 2020
** convert
** File description:
** multiple convert function
*/

int convert_octal(int nb)
{
    int octal = 0;

    for (int i = 1; nb != 0; i *= 10) {
        octal = octal + ((nb % 8) * i);
        nb = nb / 8;
    }
    return (octal);
}