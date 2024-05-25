/*
** EPITECH PROJECT, 2020
** my_str_isnum
** File description:
** isnum
*/

#include <stdio.h>

int my_str_isnum(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '\n' || str[i] == '\0')
            continue;
        if (str[i] >= '0' && str[i] <= '9')
            continue;
        else
            return 1;
    }
    return 0;
}
