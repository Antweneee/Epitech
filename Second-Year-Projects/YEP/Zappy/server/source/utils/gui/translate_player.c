/*
** EPITECH PROJECT, 2022
** server
** File description:
** translate_player
*/

#include "server.h"

static void load_player(player_data_t *player_data, player_t *player)
{
    player_data->level = player->level;
    player_data->pos_x = player->x;
    player_data->pos_y = player->y;
    player_data->player_id = player->id;
    player_data->team_id = player->team_id;
}

static void handle_players(data_server_to_gui_t *gui, map_t *map
, size_t *player)
{
    linked_player_t *players = map->players;

    if (players == NULL)
        return;
    for (; players != NULL; players = players->next) {
        load_player(&gui->players[*player], players->player);
        *player = *player + 1;
    }
}

void translate_player(data_server_to_gui_t *gui, map_t **map, info_server_t *info)
{
    size_t y = 0;
    size_t x = 0;
    size_t player = 0;

    for (; y < info->height; ++y)
        for (x = 0; x < info->width; ++x) {
            if (player == MAX_PLAYERS)
                break;
            handle_players(gui, &map[y][x], &player);
        }
    gui->number_players = player;
}