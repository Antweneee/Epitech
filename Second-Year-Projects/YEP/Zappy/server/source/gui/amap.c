/*
** EPITECH PROJECT, 2022
** server
** File description:
** amap
*/

#include <stdio.h>
#include <string.h>
#include "server.h"
#include "functions.h"

int amap(__ATTRIBUTE_UNUSED__ client_t *client, server_t *server, map_t **map)
{
    strcpy(server->send_gui.code, "AMAP");
    translate_map(&server->send_gui, map, &server->info_server);
    server->send_gui.number_players = 0;
    return gui_write(server);
}