/*
** EPITECH PROJECT, 2022
** server
** File description:
** add_player
*/

#include <time.h>
#include <string.h>
#include <stdlib.h>
#include "game.h"
#include "functions.h"

player_t *add_player(map_t **map, uint32_t width, uint32_t height)
{
    uint32_t y = 0;
    uint32_t x = 0;
    player_t *player = malloc(sizeof(player_t));

    if (player == NULL)
        return NULL;
    memset(player, 0, sizeof(player_t));
    srand(time(NULL));
    y = rand() % height;
    x = rand() % width;
    player->x = x;
    player->y = y;
    player->oriented = 0;
    player->inventory.food = 10;
    assign_player(&map[y][x], player);
    return player;
}