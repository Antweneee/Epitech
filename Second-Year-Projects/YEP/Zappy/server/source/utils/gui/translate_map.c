/*
** EPITECH PROJECT, 2022
** server
** File description:
** translate_map
*/

#include "server.h"

static void load_case(cases_data_t *one, map_t *stock, int y, int x)
{
    one->nb_deraumere = stock->deraumere;
    one->nb_food = stock->food;
    one->nb_linemate = stock->linemate;
    one->nb_mendiane = stock->mendiane;
    one->nb_phiras = stock->phiras;
    one->nb_sibur = stock->sibur;
    one->nb_thystame = stock->thystame;
    one->pos_x = x;
    one->pos_y = y;
}

void translate_map(data_server_to_gui_t *gui, map_t **map
, info_server_t *info)
{
    size_t i = 0;
    size_t y = 0;
    size_t x = 0;

    for (; y < info->height; ++y)
        for (x = 0; x < info->width; ++x) {
            if (i == MAX_CASES)
                break;
            load_case(&gui->cases[i], &map[y][x], y, x);
            ++i;
        }
    gui->number_cases = y * x;
}