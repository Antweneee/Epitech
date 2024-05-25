/*
** EPITECH PROJECT, 2021
** B-PSU-200-PAR-2-1-mysokoban-antoine.gavira-bottari
** File description:
** fix_o
*/

#include "sokoban.h"

void fix_o(char **map, pos_t *posi)
{
    for (int y = 0; y < posi->nb; y++) {
        if (map[posi->pos_p[y][0]][posi->pos_p[y][1]] == ' ')
            map[posi->pos_p[y][0]][posi->pos_p[y][1]] = 'O';
    }
}