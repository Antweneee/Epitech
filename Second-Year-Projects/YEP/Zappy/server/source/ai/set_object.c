/*
** EPITECH PROJECT, 2022
** server
** File description:
** set_object
*/


#include <string.h>
#include "functions.h"
#include "server.h"

static void update_base(server_t *server, resource_e resource)
{
    inventory_t *inventory = &server->base_inventory.inventory;

    inventory->deraumere += DERAUMERE == resource;
    inventory->food += FOOD == resource;
    inventory->linemate += LINEMATE == resource;
    inventory->mendiane += MENDIANE == resource;
    inventory->phiras += PHIRAS == resource;
    inventory->sibur += SIBUR == resource;
    inventory->thystame += THYSTAME == resource;
}

void load_object(map_t *cases, resource_e resource)
{
    cases->deraumere += DERAUMERE == resource;
    cases->food += FOOD == resource;
    cases->linemate += LINEMATE == resource;
    cases->mendiane += MENDIANE == resource;
    cases->phiras += PHIRAS == resource;
    cases->sibur += SIBUR == resource;
    cases->thystame += THYSTAME == resource;
}

char get_second_object(inventory_t *inventory, const char *object)
{
    if (inventory->mendiane > 0
    && strcmp(object, "mendiane") == 0) {
        inventory->mendiane -= 1;
        return MENDIANE;
    }
    if (inventory->phiras > 0
    && strcmp(object, "phiras") == 0) {
        inventory->phiras -= 1;
        return PHIRAS;
    }
    if (inventory->sibur > 0
    && strcmp(object, "sibur") == 0) {
        inventory->sibur -= 1;
        return SIBUR;
    }
    if (inventory->thystame > 0
    && strcmp(object, "thystame") == 0) {
        inventory->thystame -= 1;
        return THYSTAME;
    }
    return -1;
}

char get_first_object(inventory_t *inventory, const char *object)
{
    if (object == NULL)
        return -1;
    if (inventory->deraumere > 0
    && strcmp(object, "deraumere") == 0) {
        inventory->deraumere -= 1;
        return DERAUMERE;
    }
    if (inventory->linemate > 0
    && strcmp(object, "linemate") == 0) {
        inventory->linemate -= 1;
        return LINEMATE;
    }
    if (inventory->food > 0
    && strcmp(object, "food") == 0) {
        inventory->food -= 1;
        return FOOD;
    }
    return get_second_object(inventory, object);
}

int set_object(client_t *client, server_t *server, map_t **map)
{
    char ressource;

    if (client == NULL || client->player == NULL)
        return EXIT_SUCCESS;
    ressource = get_first_object(&client->player->inventory, client->command[1]);
    if (set_writable(client, server) == EXIT_FAILURE)
        return EXIT_FAILURE;
    if (ressource == -1)
        return message_chrono(client, "ko\n", 0);
    update_base(server, ressource);
    load_object(&map[client->player->y][client->player->x], ressource);
    if (message_chrono(client, "ok\n", 7.0 / server->info_server.freq) == EXIT_FAILURE)
        return EXIT_FAILURE;
    strcpy(server->send_gui.code, "MMAP");
    translate_mod_map(&server->send_gui, map, client->player->y
    , client->player->x);
    return gui_write(server);
}
