/*
** EPITECH PROJECT, 2022
** server
** File description:
** print
*/

#include <stdio.h>
#include "server.h"

void display_map(map_t *cases)
{
    printf("[d:%d, f:%d, l:%d, m:%d, p:%d, pl:%s, s:%d, t:%d] ",
           cases->deraumere, cases->food, cases->linemate, cases->mendiane, cases->phiras
           , cases->players != NULL ? "\033[0;31mP\033[0;37m" : "N", cases->sibur, cases->thystame);
}

int print(__ATTRIBUTE_UNUSED__ client_t *client, server_t *server, map_t **map)
{
    for (size_t i = 0; i < server->info_server.height; ++i)
    {
        for (size_t j = 0; j < server->info_server.width; ++j) {
            display_map(&map[i][j]);
        }
        printf("\n");
    }
    return EXIT_SUCCESS;
}