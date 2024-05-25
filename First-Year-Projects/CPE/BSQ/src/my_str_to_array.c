/*
** EPITECH PROJECT, 2020
** my str to array
** File description:
** turn char* into char**
*/

#include "../include/my.h"

int my_strlen_custom(char *str)
{
    int mem = 0;

    for (; str[mem] != '\n'; mem++);
    return (mem);
}

char **turn_to_array(char *str, int size)
{
    int len = my_strlen_custom(str);
    char **arr = malloc(sizeof(char *) * size + 1);
    int x = 0;
    int p = 0;

    for (int i = 0; i < size; i++) {
        arr[i] = malloc(sizeof(char) * (len + 1));
    }
    for (int y = 0; x != size; x++) {
        for (; str[p] != '\n'; y++) {
            arr[x][y] = str[p];
            p++;
        }
        arr[x][y] = '\0';
        p++;
        y = 0;
    }
    return (arr);
}
