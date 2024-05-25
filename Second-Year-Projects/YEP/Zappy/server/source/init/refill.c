/*
** EPITECH PROJECT, 2022
** server
** File description:
** refill
*/

#include "server.h"
    #define TAKING(base) base->base - base->inventory;

static const float resource_stock[] = {
    [FOOD] = 0.5,
    [LINEMATE] = 0.3,
    [DERAUMERE] = 0.15,
    [SIBUR] = 0.1,
    [MENDIANE] = 0.1,
    [PHIRAS] = 0.08,
    [THYSTAME] = 0.05
};

static void resource_spot(map_t **map, info_server_t *info, size_t quantity
, resource_e resource)
{
    size_t random_x;
    size_t random_y;

    srand(time(NULL));
    for (size_t i = 0; i < quantity; ++i) {
        random_y = rand() % info->height;
        random_x = rand() % info->width;
        put_in_map(&map[random_y][random_x], resource);
    }
}

int refill(map_t **map, base_inventory_t *base, info_server_t *info)
{
    resource_spot(map, info
    , base->base.deraumere - base->inventory.deraumere, DERAUMERE);
    resource_spot(map, info, base->base.linemate - base->inventory.linemate, LINEMATE);
    resource_spot(map, info, base->base.food - base->inventory.food, FOOD);
    resource_spot(map, info, base->base.sibur - base->inventory.sibur, SIBUR);
    resource_spot(map, info, base->base.phiras - base->inventory.phiras, PHIRAS);
    resource_spot(map, info, base->base.thystame - base->inventory.thystame, THYSTAME);
    base->base = base->inventory;
}