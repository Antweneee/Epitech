/*
** EPITECH PROJECT, 2022
** server
** File description:
** take_object
*/

#include <string.h>
#include "functions.h"
#include "server.h"

static void update_base(server_t *server, resource_e resource)
{
    inventory_t *inventory = &server->base_inventory.inventory;

    inventory->deraumere -= DERAUMERE == resource;
    inventory->food -= FOOD == resource;
    inventory->linemate -= LINEMATE == resource;
    inventory->mendiane -= MENDIANE == resource;
    inventory->phiras -= PHIRAS == resource;
    inventory->sibur -= SIBUR == resource;
    inventory->thystame -= THYSTAME == resource;
}

static void load_object(inventory_t *inventory, resource_e resource)
{
    inventory->deraumere += DERAUMERE == resource;
    inventory->food += FOOD == resource;
    inventory->linemate += LINEMATE == resource;
    inventory->mendiane += MENDIANE == resource;
    inventory->phiras += PHIRAS == resource;
    inventory->sibur += SIBUR == resource;
    inventory->thystame += THYSTAME == resource;
}

static char get_second_object(player_t *player, map_t **map
, const char *object)
{
    if (map[player->y][player->x].mendiane > 0
    && strcmp(object, "mendiane") == 0) {
        map[player->y][player->x].mendiane -= 1;
        return MENDIANE;
    }
    if (map[player->y][player->x].phiras > 0
    && strcmp(object, "phiras") == 0) {
        map[player->y][player->x].phiras -= 1;
        return PHIRAS;
    }
    if (map[player->y][player->x].sibur > 0
    && strcmp(object, "sibur") == 0) {
        map[player->y][player->x].sibur -= 1;
        return SIBUR;
    }
    if (map[player->y][player->x].thystame > 0
    && strcmp(object, "thystame") == 0) {
        map[player->y][player->x].thystame -= 1;
        return THYSTAME;
    }
    return -1;
}

static char get_first_object(player_t *player, map_t **map, const char *object)
{
    if (object == NULL)
        return -1;
    if (map[player->y][player->x].deraumere > 0
    && strcmp(object, "deraumere") == 0) {
        map[player->y][player->x].deraumere -= 1;
        return DERAUMERE;
    }
    if (map[player->y][player->x].linemate > 0
    && strcmp(object, "linemate") == 0) {
        map[player->y][player->x].linemate -= 1;
        return LINEMATE;
    }
    if (map[player->y][player->x].food > 0
    && strcmp(object, "food") == 0) {
        map[player->y][player->x].food -= 1;
        return FOOD;
    }
    return get_second_object(player, map, object);
}

int take_object(client_t *client, server_t *server, map_t **map)
{
    char ressource;

    if (client == NULL || client->player == NULL)
        return EXIT_SUCCESS;
    ressource = get_first_object(client->player, map, client->command[1]);
    if (set_writable(client, server) == EXIT_FAILURE)
        return EXIT_FAILURE;
    if (ressource == -1)
        return message_chrono(client, "ko\n", 0);
    update_base(server, ressource);
    load_object(&client->player->inventory, ressource);
    if (message_chrono(client, "ok\n", 7.0 / server->info_server.freq)
     == EXIT_FAILURE)
        return EXIT_FAILURE;
    strcpy(server->send_gui.code, "MMAP");
    translate_mod_map(&server->send_gui, map, client->player->y
    , client->player->x);
    return gui_write(server);
}
