/*
** EPITECH PROJECT, 2022
** server
** File description:
** translate_mod
*/

#include <string.h>
#include "server.h"

void translate_mod_player(data_server_to_gui_t *gui, player_t *player
, player_actions action_id)
{
    gui->players[gui->number_players].level = player->level;
    gui->players[gui->number_players].pos_x = player->x;
    gui->players[gui->number_players].pos_y = player->y;
    gui->players[gui->number_players].action_id = action_id;
    gui->players[gui->number_players].player_id = player->id;
    gui->number_players += 1;
}

void translate_mod_map(data_server_to_gui_t *gui, map_t **a_map, int y, int x)
{
    map_t *map = &a_map[y][x];

    gui->cases[gui->number_cases].nb_deraumere = map->deraumere;
    gui->cases[gui->number_cases].nb_food = map->food;
    gui->cases[gui->number_cases].nb_mendiane = map->mendiane;
    gui->cases[gui->number_cases].nb_linemate = map->linemate;
    gui->cases[gui->number_cases].nb_phiras = map->phiras;
    gui->cases[gui->number_cases].nb_thystame = map->thystame;
    gui->cases[gui->number_cases].nb_sibur = map->sibur;
    gui->cases[gui->number_cases].pos_y = y;
    gui->cases[gui->number_cases].pos_x = x;
    gui->number_cases += 1;
}