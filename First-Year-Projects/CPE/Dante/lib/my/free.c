/*
** EPITECH PROJECT, 2021
** new_dante
** File description:
** free
*/

#include "my.h"

void free_tab(char **arr)
{
    for (int i = 0; arr[i]; i++) {
        free(arr[i]);
    }
    free(arr);
}