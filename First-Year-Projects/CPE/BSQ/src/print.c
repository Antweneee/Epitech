/*
** EPITECH PROJECT, 2020
** print
** File description:
** print
*/

#include "my.h"
#include "bsq.h"

void print(char **array, struct result_s *pos, int len, int nb)
{
    char **arr = array;

    for (int i = 0; i < nb; i++) {
        for (int j = 0; j < len; j++) {
            if (j > (pos->y - pos->max) && j <= pos->y
                && i > (pos->x - pos->max) && i <= pos->x) {
                arr[i][j] = 'x';
            }
        }
    }
    print_array(arr, nb);
}
