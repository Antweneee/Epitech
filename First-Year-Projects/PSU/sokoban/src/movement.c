/*
** EPITECH PROJECT, 2021
** B-PSU-200-PAR-2-1-mysokoban-antoine.gavira-bottari
** File description:
** movement
*/

#include <ncurses.h>
#include "my.h"
#include "sokoban.h"

char **up(char **map, int *player)
{
    if (map[player[0] - 1][player[1]] == 'X' &&
    map[player[0] - 2][player[1]] == '#')
        return (map);
    if (map[player[0] - 1][player[1]] == 'X' &&
    map[player[0] - 2][player[1]] == 'X')
        return map;
    map[player[0]][player[1]] = ' ';
    player[0] -= 1;
    if (map[player[0]][player[1]] == 'X' &&
    map[player[0] - 1][player[1]] != '#') {
        map[player[0] - 1][player[1]] = 'X';
    }
    map[player[0]][player[1]] = 'P';
    return (map);
}

char **down(char **map, int *player)
{
    if (map[player[0] + 1][player[1]] == 'X' &&
    map[player[0] + 2][player[1]] == '#')
        return (map);
    if (map[player[0] + 1][player[1]] == 'X' &&
    map[player[0] + 2][player[1]] == 'X')
        return map;
    map[player[0]][player[1]] = ' ';
    player[0] += 1;
    if (map[player[0]][player[1]] == 'X' &&
    map[player[0] + 1][player[1]] != '#') {
        map[player[0] + 1][player[1]] = 'X';
    }
    map[player[0]][player[1]] = 'P';
    return (map);
}

char **left(char **map, int *player)
{
    if (map[player[0]][player[1] - 1] == 'X' &&
    map[player[0]][player[1] - 2] == '#')
        return (map);
    if (map[player[0]][player[1] - 1] == 'X' &&
    map[player[0]][player[1] - 2] == 'X')
        return map;
    map[player[0]][player[1]] = ' ';
    player[1] -= 1;
    if (map[player[0]][player[1]] == 'X' &&
    map[player[0]][player[1] - 1] != '#') {
        map[player[0]][player[1] - 1] = 'X';
    }
    map[player[0]][player[1]] = 'P';
    return (map);
}

char **right(char **map, int *player)
{
    if (map[player[0]][player[1] + 1] == 'X' &&
    map[player[0]][player[1] + 2] == '#')
        return (map);
    if (map[player[0]][player[1] + 1] == 'X' &&
    map[player[0]][player[1] + 2] == 'X')
        return map;
    map[player[0]][player[1]] = ' ';
    player[1] += 1;
    if (map[player[0]][player[1]] == 'X' &&
    map[player[0]][player[1] + 1] != '#') {
        map[player[0]][player[1] + 1] = 'X';
    }
    map[player[0]][player[1]] = 'P';
    return (map);
}

char **move_p(int key, char **map, char *get, pos_t *posi)
{
    int *player = player_pos(map, get);

    if (key == KEY_DOWN && map[player[0] + 1][player[1]] != '#') {
        map = down(map, player);
    }
    if (key == KEY_UP && map[player[0] - 1][player[1]] != '#') {
        map = up(map, player);
    }
    if (key == KEY_LEFT && map[player[0]][player[1] - 1] != '#') {
        map = left(map, player);
    }
    if (key == KEY_RIGHT && map[player[0]][player[1] + 1] != '#') {
        map = right(map, player);
    }
    fix_o(map, posi);
    map[player[0]][player[1]] = 'P';
    free(player);
    return (map);
}