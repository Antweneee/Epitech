/*
** EPITECH PROJECT, 2021
** my_use
** File description:
** my_use
*/

#include <unistd.h>
#include "use.h"

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i++;
    }
    return (i);
}

void my_putstr(char const *str)
{
    write(1, str, my_strlen(str));
}