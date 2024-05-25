/*
** EPITECH PROJECT, 2020
** my_print array
** File description:
** print an array
*/

#include "../include/my.h"

void print_array(char **array, int size)
{
    int x = 0;

    for (; x != size; x++) {
        my_printf("%s\n", array[x]);
    }
}
