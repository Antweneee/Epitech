/*
** EPITECH PROJECT, 2022
** B-NWP-400-PAR-4-1-myftp-antoine.gavira-bottari
** File description:
** str_array
*/

#include <stdlib.h>
#include <string.h>
#include "myftp.h"

void free_tab(char **arr)
{
    for (int i = 0; arr[i]; i++)
        free(arr[i]);
    free(arr);
}

char **clean_arr(char **arr)
{
    for (int i = 0; arr[i]; i++) {
        for (int j = 0; arr[i][j] != '\0'; j++)
            if (arr[i][j] == '\r' || arr[i][j] == '\n') {
                arr[i][j] = '\0';
                break;
            }
    }
    return arr;
}

char **fill_arr(char const *str, char **arr, char c)
{
    int x = 0;
    int y = 0;
    int sep = 0;

    for (size_t p = 0; p != strlen(str); p++) {
        if (str[p] != c) {
            arr[x][y] = str[p];
            y++;
        } else if (sep == 0 && str[p] == c) {
            arr[x][y] = '\0';
            x++;
            y = 0;
            sep++;
        }
    }
    arr[x][y] = '\0';
    arr[x + 1] = NULL;
    return (arr);
}

char **turn_to_array(char const *str, char c)
{
    char **arr = NULL;
    int row = 2;
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
    arr = clean_arr(arr);
    return (arr);
}