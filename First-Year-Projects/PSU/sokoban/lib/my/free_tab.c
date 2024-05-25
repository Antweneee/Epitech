/*
** EPITECH PROJECT, 2021
** B-PSU-200-PAR-2-1-mysokoban-antoine.gavira-bottari
** File description:
** free_tab
*/

#include "my.h"

void free_tab(char **arr)
{
    for (int i = 0; arr[i]; i++)
        free(arr[i]);
}