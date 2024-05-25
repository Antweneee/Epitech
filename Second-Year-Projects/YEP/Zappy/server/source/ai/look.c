/*
** EPITECH PROJECT, 2022
** server
** File description:
** look
*/

#include <stdio.h>
#include "server.h"
#include "functions.h"

static void writing_look(client_t *client, server_t *server
, map_t **map, char *result)
{
    display_case(&map[client->player->y][client->player->x]
    , result, false);
    if (client->player->oriented == 0)
        right_line(map, client, &server->info_server, result);
    if (client->player->oriented == 90)
        down_line(map, client, &server->info_server, result);
    if (client->player->oriented == 180)
        left_line(map, client, &server->info_server, result);
    if (client->player->oriented == 270)
        up_line(map, client, &server->info_server, result);
}

int look(client_t *client, server_t *server, map_t **map)
{
    char *result;

    if (client->player == NULL || map == NULL)
        return EXIT_FAILURE;
    result = malloc(sizeof(char) * LEVEL_CASE_LOOK_MAX(client->player->level));
    if (result == NULL)
        return EXIT_FAILURE;
    memset(result, 0, LEVEL_CASE_LOOK_MAX(client->player->level));
    writing_look(client, server, map, result);
    if (set_writable(client, server) == EXIT_FAILURE
    || message_chrono(client, result, 7.0 / server->info_server.freq)
     == EXIT_FAILURE) {
        free(result);
        return EXIT_FAILURE;
    }
    free(result);
    return EXIT_SUCCESS;
}