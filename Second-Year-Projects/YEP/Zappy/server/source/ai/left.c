/*
** EPITECH PROJECT, 2022
** server
** File description:
** left
*/

#include <string.h>
#include "server.h"
#include "functions.h"

static void move_left(player_t *player)
{
    player->oriented = (player->oriented == 0) ? 270 :
    (player->oriented - 90);
}

int left(client_t *client, server_t *server, __ATTRIBUTE_UNUSED__ map_t **map)
{
    if (client->player == NULL)
        return EXIT_SUCCESS;
    if (set_writable(client, server) == EXIT_FAILURE)
        return EXIT_FAILURE;
    if (message_chrono(client, "ok\n", 7.0 / server->info_server.freq) == EXIT_FAILURE)
        return EXIT_FAILURE;
    move_left(client->player);
    strcpy(server->send_gui.code, "MPLA");
    translate_mod_player(&server->send_gui, client->player, LEFT);
    return gui_write(server);
}