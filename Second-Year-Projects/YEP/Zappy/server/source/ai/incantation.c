/*
** EPITECH PROJECT, 2022
** server
** File description:
** incantation
*/

#include "elevation.h"
#include "server.h"
#include "functions.h"

static size_t number_player(map_t *cases)
{
    size_t i = 0;
    linked_player_t *players = cases->players;

    for (; players != NULL; players = players->next)
        i += players->player != NULL;
    return i;
}

static bool check_inventory(map_t *tile , const elevation_t *leveling)
{
    return tile->deraumere >= leveling->deraumere
    && tile->linemate >= leveling->linemate
    && tile->sibur >= leveling->sibur
    && tile->mendiane >= leveling->mendiane
    && tile->phiras >= leveling->phiras
    && tile->thystame >= leveling->thystame;
}

static void delete_inventory(map_t *tile, const elevation_t *leveling)
{
    tile->deraumere -= leveling->deraumere;
    tile->linemate -= leveling->linemate;
    tile->sibur -= leveling->sibur;
    tile->mendiane -= leveling->mendiane;
    tile->phiras -= leveling->phiras;
    tile->thystame -= leveling->thystame;
}

static void sub_base(server_t *server, const elevation_t *leveling)
{
    inventory_t *inventory = &server->base_inventory.inventory;

    inventory->deraumere -= leveling->deraumere;
    inventory->linemate -= leveling->linemate;
    inventory->sibur -= leveling->sibur;
    inventory->mendiane -= leveling->mendiane;
    inventory->phiras -= leveling->phiras;
    inventory->thystame -= leveling->thystame;
}

bool check_cases(map_t *tile, player_t *player, server_t *server)
{
    size_t nb_players = number_player(tile);

    if (player->level == 8)
        return false;
    if (nb_players != elevation[player->level].nb_players)
        return false;
    if (check_inventory(tile, &elevation[player->level]) == true) {
        delete_inventory(tile, &elevation[player->level]);
        sub_base(server, &elevation[player->level]);
        return true;
    }
    return false;
}

int incantation(client_t *client, server_t *server, map_t **map)
{
    char number[36] = {0};

    if (client->player == NULL)
        return EXIT_SUCCESS;
    if (set_writable(client, server) == EXIT_FAILURE)
        return EXIT_FAILURE;
    if (check_cases(&map[client->player->y][client->player->x], client->player
    , server) == false)
        return message_chrono(client, "ko\n", 0);
    client->player->level += 1;
    if (message_chrono(client, number, 300.0 / server->info_server.freq)
    == EXIT_FAILURE)
        return EXIT_FAILURE;
    strcpy(server->send_gui.code, "MPLA");
    sprintf(number, "%s%d\n", ELEVATION_MESSAGE, client->player->level);
    message_chrono(client, "Elevation underway\n", 0);
    message_chrono(client, number, 300.0 / server->info_server.freq);
    translate_mod_player(&server->send_gui, client->player, INCANTATION);
    translate_mod_map(&server->send_gui, map, client->player->y, client->player->x);
    return gui_write(server);
}
