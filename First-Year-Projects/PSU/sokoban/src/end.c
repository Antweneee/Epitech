/*
** EPITECH PROJECT, 2021
** B-PSU-200-PAR-2-1-mysokoban-antoine.gavira-bottari
** File description:
** end
*/

#include <stdio.h>
#include <stdlib.h>
#include "my.h"
#include "sokoban.h"

void free_all(char **arr, char *str, int **pos)
{
    for (int i = 0; pos[i]; i++)
        free(pos[i]);
    free_tab(arr);
    free(str);
}

int stuck(char **map, int i, int j)
{
    int nb = 0;

    if ((map[i][j - 1] == '#' || map[i][j - 1] == 'X') && (map[i - 1][j] == '#'
    || map[i - 1][j] == 'X'))
        nb += 1;
    if ((map[i - 1][j] == '#' || map[i - 1][j] == 'X') && (map[i][j + 1] == '#'
    || map[i][j + 1] == 'X'))
        nb += 1;
    if ((map[i][j + 1] == '#' || map[i][j + 1] == 'X') && (map[i + 1][j] == '#'
    || map[i + 1][j] == 'X'))
        nb += 1;
    if ((map[i + 1][j] == '#' || map[i + 1][j] == 'X') && (map[i][j - 1] == '#'
    || map[i][j - 1] == 'X'))
        nb += 1;
    return nb;
}

int loose(int result, char **map, char *str, int nb)
{
    int check = 0;

    for (int x = 0; x != tab_size(str, '\n'); x++)
        for (int y = 0; map[x][y] != '\0'; y++) {
            if (map[x][y] == 'X' && stuck(map, x ,y) == 1)
                check += 1;
    }
    if (check == nb)
        result = nb;
    return result;
}

int end(char **map, pos_t *posi, char *str)
{
    int nb = get_space(str);
    int result = 0;

    for (int x = 0; x != nb; x++)
        if (map[posi->pos_p[x][0]][posi->pos_p[x][1]] == 'X')
            result++;
    result = loose(result, map, str, nb);
    if (result == nb || result == 84)
        return (1);
    return (0);
}