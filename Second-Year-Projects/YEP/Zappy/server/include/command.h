/*
** EPITECH PROJECT, 2022
** B-YEP-410-PAR-4-1-zappy-thomas.willson
** File description:
** command
*/

#ifndef COMMAND_H_
#define COMMAND_H_

    #include "server.h"
    #include "game.h"

typedef struct server_command_s
{
    int (*function)(client_t *client, server_t *server, map_t **map);
} server_command_t;

typedef struct client_command_s
{
    const char *command;
    int (*function)(client_t *client, server_t *server, map_t **map);
} client_command_t;

typedef struct type_command_s
{
    const char *command;
    int (*function)(client_t *client, server_t *server, map_t **map);
} type_command_t;

typedef struct style_writing_s
{
    int (*function)(client_t *client, chrono_buffer_t *message);
} style_writing_t;

typedef struct elevation_s
{
    size_t nb_players;
    uint8_t linemate;
    uint8_t deraumere;
    uint8_t sibur;
    uint8_t mendiane;
    uint8_t phiras;
    uint8_t thystame;
} elevation_t;

typedef struct map_int_s {
    int angle;
    uint8_t asscociate;
} map_int_t;

#endif /* !COMMAND_H_ */