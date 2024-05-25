/*
** EPITECH PROJECT, 2022
** server
** File description:
** eject
*/

#include "server.h"
#include "functions.h"
#include "command.h"

static void move_forward(client_t *client, map_t **map, info_server_t *info
, int oriented)
{
    player_t *player = client->player;

    eject_player(&map[player->y][player->x], player);
    player->x = player->x + (oriented == 0) - (oriented == 180);
    if ((player->x >= (int)info->width))
        player->x = 0;
    if (player->x < 0)
        player->x = info->width - 1;
    player->y = player->y - (oriented == 270) + (oriented == 90);
    if ((player->y >= (int)info->height))
        player->y = 0;
    if (player->y < 0)
        player->y = info->height - 1;
    assign_player(&map[player->y][player->x], player);
}

static client_t *get_client(player_t *player, server_t *server)
{
    teams_t *teams = server->teams;

    for (; teams != NULL; teams = teams->next) {
        for (linked_client_t *linked = teams->clients; linked != NULL
        ; linked = linked->next) {
            if (linked->client == NULL || linked->client->player == NULL
            || linked->client->player != player)
                continue;
            return linked->client;
        }
    }
    return NULL;
}

static int message_eject_to_player(client_t *client, server_t *server
, player_t *player, map_t **map)
{
    char message[10] = {0};

    if (set_writable(client, server) == EXIT_FAILURE)
        return EXIT_FAILURE;
    sprintf(message, "eject: %d\n", 0);
    move_forward(client, map, &server->info_server, player->oriented);
    if (message_chrono(client, message, 7 / server->info_server.freq)
    == EXIT_FAILURE)
        return EXIT_FAILURE;
    strcpy(server->send_gui.code, "MPLA");
    translate_mod_player(&server->send_gui, client->player, EJECT);
    return gui_write(server);
}

static int eject_players(client_t *client, linked_player_t *linked
, server_t *server, map_t **map)
{
    bool ok = false;

    for (client_t *get; linked != NULL; linked = linked->next) {
        if (linked->player == NULL ||
        linked->player == client->player)
            continue;
        get = get_client(client->player, server);
        if (get == NULL)
            continue;
        if (message_eject_to_player(get, server, client->player, map)
        == EXIT_FAILURE)
            return EXIT_FAILURE;
        ok = true;
    }
    if (CHOOSE_CHRONO(ok, client, server) == true)
        return EXIT_FAILURE;
    return EXIT_SUCCESS;
}

int eject(client_t *client, server_t *server, map_t **map)
{
    return eject_players(client
    , map[client->player->y][client->player->x].players, server, map);
}
