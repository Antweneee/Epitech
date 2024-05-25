/*
** EPITECH PROJECT, 2021
** my_put
** File description:
** print function
*/

#include "use.h"
#include <unistd.h>

int my_strlen(char const *str)
{
    int f = 0;

    while (str[f] != '\0') {
        f++;
    }
    return (f);
}

int my_putstr(char const *str)
{
    write(1, str, my_strlen(str));
    return (0);
}