/*
** EPITECH PROJECT, 2021
** my_str_to_word_array.c
** File description:
** str_to_word_array
*/

#include <stdlib.h>
#include <string.h>
#include "n4s.h"

int tab_size(char const *str, char c)
{
    int nb = 1;

    for (int i = 0; str[i]; i++)
        if (str[i] == c)
            nb++;
    return (nb);
}

char **fill_arr(char const *str, char **arr, char c)
{
    int x = 0;
    int y = 0;

    for (int p = 0; str[p] != '\0'; p++) {
        if (str[p] != c) {
            arr[x][y] = str[p];
            y++;
        }
        else {
            arr[x][y] = '\0';
            x++;
            y = 0;
        }
    }
    arr[x][y] = '\0';
    arr[x + 1] = NULL;
    return (arr);
}

char **my_str_to_word_array(char const *str, char c)
{
    char **arr = NULL;
    int row = tab_size(str, c);
    int size = strlen(str);

    arr = malloc(sizeof(char *) * (row + 1));
    if (arr == NULL)
        return (NULL);
    for (int i = 0; i < row; i++) {
        arr[i] = malloc(sizeof(char) * (size + 1));
        if (arr[i] == NULL)
            return (NULL);
    }
    arr = fill_arr(str, arr, c);
    return (arr);
}