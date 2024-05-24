/*
** EPITECH PROJECT, 2020
** my putstr
** File description:
** display one by one all the caracters of a string
*/

int my_putstr(char const *str)
{
    int n;

    while (str[n] != '\0') {
        my_putchar(str[n]);
        n = n + 1;
    }
    return (0);
}
