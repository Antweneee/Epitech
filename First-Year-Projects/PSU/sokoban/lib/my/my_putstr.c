/*
** EPITECH PROJECT, 2020
** my_putstr
** File description:
** function that displays, one-by-one, the characters of a string
*/

#include <unistd.h>
#include "my.h"

void my_putchar(char c);

void my_putstr(char const *str)
{
    write(1, str, my_strlen(str));
}
