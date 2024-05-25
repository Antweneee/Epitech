/*
** EPITECH PROJECT, 2022
** B-PDG-300-PAR-3-1-PDGD04am-antoine.gavira-bottari
** File description:
** array_1d_to_2d
*/

#include <stdio.h>
#include <stdlib.h>


void array_1d_to_2d(const int *array, size_t height, size_t width, int ***res)
{
    int x = 0;

    int **tmp = malloc(sizeof(int *) * (height));
    for (int i = 0; i < (int) height; i++) {
        tmp[i] = malloc(sizeof(int) * (width));
        for (int j = 0; j < (int) width; j++) {
            tmp[i][j] = array[x];
            x++;
        }
    }
    *res = tmp;
}

void array_2d_free(int **array, size_t height, size_t width)
{
    for (int i = 0; i < (int) height; i++) {
        free(array[i]);
    }
    free(array);
}