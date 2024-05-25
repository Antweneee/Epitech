/*
** EPITECH PROJECT, 2021
** double
** File description:
** write
*/

#include <unistd.h>
#include "use.h"

void my_putstr(char const *str)
{
    write(1, str, my_strlen(str));
}