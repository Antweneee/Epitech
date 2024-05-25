/*
** EPITECH PROJECT, 2022
** server
** File description:
** map
*/

#include <string.h>
#include <time.h>
#include "server.h"

static const float resource_stock[] = {
    [FOOD] = 0.5,
    [LINEMATE] = 0.3,
    [DERAUMERE] = 0.15,
    [SIBUR] = 0.1,
    [MENDIANE] = 0.1,
    [PHIRAS] = 0.08,
    [THYSTAME] = 0.05
};

static const resource_e list_resource[] = {
    FOOD,
    LINEMATE,
    DERAUMERE,
    SIBUR,
    MENDIANE,
    PHIRAS,
    THYSTAME
};

void put_in_map(map_t *map, resource_e resource)
{
    map->food += resource == FOOD;
    map->deraumere += resource == DERAUMERE;
    map->linemate += resource == LINEMATE;
    map->mendiane += resource == MENDIANE;
    map->phiras += resource == PHIRAS;
    map->sibur += resource == SIBUR;
    map->thystame += resource == THYSTAME;
}

static void resource_spot(map_t **map, uint32_t width, uint32_t height
, resource_e resource)
{
    size_t random_x;
    size_t random_y;
    size_t quantity = width * height * resource_stock[resource];

    srand(time(NULL));
    for (size_t i = 0; i < quantity; ++i) {
        random_y = rand() % height;
        random_x = rand() % width;
        put_in_map(&map[random_y][random_x], resource);
    }
}

static map_t **init_map(uint32_t width, uint32_t height)
{
    map_t **map = malloc(sizeof(map_t *) * (height + 1));

    if (map == NULL)
        return NULL;
    for (size_t i = 0; i < height; ++i) {
        map[i] = malloc(sizeof(map_t) * (width + 1));
        if (map[i] == NULL)
            return NULL;
        memset(map[i], 0, sizeof(map_t) * width);
        map[i]->players = NULL;
    }
    map[height] = NULL;
    return map;
}

static void set_initial(inventory_t *inventory, int width, int height)
{
    inventory->deraumere = width * height * resource_stock[DERAUMERE];
    inventory->food = width * height * resource_stock[FOOD];
    inventory->linemate = width * height * resource_stock[LINEMATE];
    inventory->sibur = width * height * resource_stock[SIBUR];
    inventory->mendiane = width * height * resource_stock[MENDIANE];
    inventory->phiras = width * height * resource_stock[PHIRAS];
    inventory->thystame = width * height * resource_stock[THYSTAME];
}

map_t **create_map(info_server_t *info, inventory_t *inventory)
{
    map_t **map = init_map(info->width, info->height);

    if (map == NULL)
        return NULL;
    set_initial(inventory, info->width, info->height);
    for (size_t i = 0; i < sizeof(list_resource) / sizeof(resource_e); ++i)
        resource_spot(map, info->width, info->height, list_resource[i]);
    return map;
}