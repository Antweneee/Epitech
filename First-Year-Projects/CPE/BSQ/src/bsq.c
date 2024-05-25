/*
** EPITECH PROJECT, 2020
** bsq
** File description:
** bsq
*/

#include "../include/my.h"
#include "../include/bsq.h"

int **first_line(char **array, int len, int nb)
{
    int ln = len;
    int **result = malloc(sizeof(int *) * 10000);
    int x = 0;
    int y = 0;

    for (int i = 0; i < nb; i++)
        result[i] = malloc(sizeof(int) * 10000);
    for (;x < nb; y++) {
        if (array[x][y] == 'o')
            result[x][y] = 0;
        if (array[x][y] == '.')
            result[x][y] = 1;
        if (y == ln) {
            x += 1;
            y = -1;
        }
    }
    return (result);
}

int minimum(int **result, int x, int y)
{
    if (x == 0 || y == 0) {
        return (0);
    }
    if (result[x][y - 1] <= result[x - 1][y - 1]
        && result[x][y - 1] <= result[x-1][y]){
        return (result[x][y - 1]);
    } else if (result[x - 1][y - 1] <= result[x][y - 1]
               && result[x - 1][y - 1] <= result[x - 1][y]) {
        return (result[x - 1][y - 1]);
    } else {
        return (result[x - 1][y]);
    }
}

int **name(int **tab, int len, int nb)
{
    int x = 0;
    int y = 0;

    for (;x < nb; y++) {
        if (y == len) {
            x += 1;
            y = -1;
            continue;
        }
        if (tab[x][y] == 1) {
            tab[x][y] = tab[x][y] + minimum(tab, x, y);
        }
    }
    return (tab);
}

void get_max(int **tab, struct result_s *pos, int len, int nb)
{
    int j = 0;

    for (int i = 0; i < nb; j++) {
        if (j == len) {
            i += 1;
            j = -1;
            continue;
        }
        if (tab[i][j] > pos->max) {
            pos->max = tab[i][j];
            pos->x = i;
            pos->y = j;
        }
    }
}

void bsq(char *buffer)
{
    int nb = my_getnbr(buffer);
    int len = 0;
    char **array = NULL;
    int **result = NULL;
    struct result_s pos = {0, 0, 0};

    for (; buffer[0] != '\n'; buffer++);
    buffer++;
    len = my_strlen_custom(buffer);
    array = turn_to_array(buffer, nb);
    result = first_line(array, len, nb);
    result = name(result, len, nb);
    get_max(result, &pos, len, nb);
    print(array, &pos, len, nb);
}
