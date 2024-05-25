/*
** EPITECH PROJECT, 2022
** server
** File description:
** handle_look
*/

#include "server.h"
#include "functions.h"

void display_case(map_t *map, char *buffer, bool last)
{
    if (strlen(buffer) == 0) {
        sprintf(buffer, "[");
    } else
        sprintf(&buffer[strlen(buffer)], ",");
    sprintf(&buffer[strlen(buffer)], "%s%s%s%s%s%s%s", \
    map->players != NULL ? " player" : ""
    , map->food > 0 ? " food" : ""
    , map->mendiane > 0 ? " mendiane" : ""
    , map->linemate > 0 ? " linemate" : ""
    , map->deraumere > 0 ? " deraumere" : "", map->sibur > 0 ? " sibur" : ""
    , map->thystame > 0 ? " thystame" : "");
    if (last == true)
        sprintf(&buffer[strlen(buffer)], " ]\n");
}

void up_line(map_t **map, client_t *client, info_server_t *info
, char *buffer)
{
    player_t *player = client->player;
    size_t level = player->level;
    bool last = false;

    for (size_t i = 0; i < level; ++i) {
            for (size_t j = 0; j < (level * 2) + 1; ++j) {
            last = i + 1 == level && j + 1 == (level * 2) + 1;
            display_case(&map[UP_Y_ABS(info, player, level, i)]
            [UP_X_ABS(info, player, level, j)]
            , buffer, last);
            }
    }
}

void down_line(map_t **map, client_t *client, info_server_t *info
, char *buffer)
{
    player_t *player = client->player;
    size_t level = player->level;
    bool last = false;

    for (size_t i = 0; i < level; ++i) {
            for (size_t j = 0; j < (level * 2) + 1; ++j) {
            last = i + 1 == level && j + 1 == (level * 2) + 1;
            display_case(&map[DOWN_Y_ABS(info, player, level, i)]
            [DOWN_X_ABS(info, player, level, j)]
            , buffer, last);
            }
    }
}

void right_line(map_t **map, client_t *client, info_server_t *info
, char *buffer)
{
    player_t *player = client->player;
    size_t level = player->level;
    bool last = false;

    for (size_t i = 0; i < level; ++i) {
        for (size_t j = 0; j < (level * 2) + 1; ++j) {
            last = i + 1 == level && j + 1 == (level * 2) + 1;
            display_case(&map[RIGHT_Y_ABS(info, player, level, j)]
            [RIGHT_X_ABS(info, player, level, i)]
            , buffer, last);
        }
    }
}

void left_line(map_t **map, client_t *client, info_server_t *info
, char *buffer)
{
    player_t *player = client->player;
    size_t level = player->level;
    bool last = false;

    for (size_t i = 0; i < level; ++i)
    {
        for (size_t j = 0; j < (level * 2) + 1; ++j) {
            last = i + 1 == level && j + 1 == (level * 2) + 1;
            display_case(&map[LEFT_Y_ABS(info, player, level, j)]
            [LEFT_X_ABS(info, player, level, i)]
            , buffer, last);
        }
    }
}