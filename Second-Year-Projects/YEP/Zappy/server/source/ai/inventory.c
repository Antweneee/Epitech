/*
** EPITECH PROJECT, 2022
** server
** File description:
** inventory
*/

#include "server.h"
#include "functions.h"

int inventory(client_t *client, server_t *server
, __ATTRIBUTE_UNUSED__ map_t **map)
{
    if (set_writable(client, server) == EXIT_FAILURE)
        return EXIT_FAILURE;
    return message_chrono_style(client, ""
    , 1.0 / server->info_server.freq, INVENTORY);
}