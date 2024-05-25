/*
** EPITECH PROJECT, 2022
** server
** File description:
** forward
*/

#include <string.h>
#include "server.h"
#include "functions.h"

static void move_forward(client_t *client, map_t **map, info_server_t *info)
{
    player_t *player = client->player;

    eject_player(&map[player->y][player->x], player);
    player->x = player->x + (player->oriented == 0) - (player->oriented == 180);
    if ((player->x >= (int)info->width))
        player->x = 0;
    if (player->x < 0)
        player->x = info->width - 1;
    player->y = player->y - (player->oriented == 270) + (player->oriented == 90);
    if ((player->y >= (int)info->height))
        player->y = 0;
    if (player->y < 0)
        player->y = info->height - 1;
    assign_player(&map[player->y][player->x], player);
}

int forward(client_t *client, server_t *server, map_t **map)
{
    if (client->player == NULL)
        return EXIT_SUCCESS;
    if (set_writable(client, server) == EXIT_FAILURE)
        return EXIT_FAILURE;
    if (message_chrono(client, "ok\n", 7.0 / server->info_server.freq)
    == EXIT_FAILURE)
        return EXIT_FAILURE;
    move_forward(client, map, &server->info_server);
    strcpy(server->send_gui.code, "MPLA");
    translate_mod_player(&server->send_gui, client->player, MOVE_FORWARD);
    return gui_write(server);
}