/*
** EPITECH PROJECT, 2021
** new_dante
** File description:
** setup
*/

#include "generator.h"

void fill_arr(char **map, int const x, int const y)
{
    for (int i = 0; i < x; i++)
        for (int j = 0; j < y; j++) {
            if (i == 0 || j == 0)
                map[i][j] = '*';
            else
                map[i][j] = 'X';
        }
}

char **malloc_array(int const x, int const y)
{
    char **map = malloc(sizeof(char *) * (x + 1));
    int i = 0;

    if (!map)
        return NULL;
    for (; i < x; ++i) {
        map[i] = malloc(sizeof(char) * (y + 1));
        map[i][y] = '\0';
        if (!map[i])
            return NULL;
    }
    map[i] = NULL;
    return (map);
}

int randomize_maze(int randomize)
{
    int expect_random = rand() % 100;

    if (expect_random >= randomize)
        return 1;
    return 0;
}

void algo_maze(char **map, int const x, int const y)
{
    for (int i = 2; i < x; i += 2) {
        for (int j = 2; j < y; j += 2) {
            map[i][j] = '*';
            if (j > 0 && map[i - 1][j] == 'X' && randomize_maze(50) == 1)
                map[i - 1][j] = '*';
            else
                map[i][j - 1] = '*';
        }
    }
    map[x - 1][y - 1] = '*';
    map[x - 1][y - 2] = '*';
}
