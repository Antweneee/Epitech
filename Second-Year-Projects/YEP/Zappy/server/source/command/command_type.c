/*
** EPITECH PROJECT, 2022
** B-YEP-410-PAR-4-1-zappy-thomas.willson
** File description:
** set_type
*/

#include <stdio.h>
#include <string.h>
#include "functions.h"
#include "command.h"
#include "constant.h"

static int help_type(client_t *client, server_t *server, map_t **map);
static int set_type(client_t *client, server_t *server, map_t **map);

static const type_command_t type_command[] = {
    {
        .command = "/help",
        .function = help_type
    },
    {
        .command = "/type",
        .function = set_type
    }
};

static int help_type(client_t *client, __ATTRIBUTE_UNUSED__ server_t *server,
__ATTRIBUTE_UNUSED__ map_t **map)
{
    if (dprintf(fileno(client->file), "HELP BUT TYPE NOT SET\n") == -1)
        return EXIT_FAILURE;
    return EXIT_SUCCESS;
}

static int set_type(client_t *client, server_t *server, map_t **map)
{
    type_e type = UNDEFINED;

    if (client->command[1] == NULL) {
        dprintf(fileno(client->file), "INVALID ARGUMENT FOR TYPE\n");
        return EXIT_SUCCESS;
    }
    if (strcmp(client->command[1], "AI") == 0)
        type = AI;
    else if (strcmp(client->command[1], "GUI") == 0) {
        if (add_gui(client, server) == EXIT_FAILURE
        || amap(client, server, map) == EXIT_FAILURE)
            return EXIT_FAILURE;
        type = GUI;
    } else
        dprintf(fileno(client->file), "UNKNOW TYPE\n");
    client->type = type;
    return EXIT_SUCCESS;
}

static int send_welcome(client_t *client, server_t *server)
{
    if (client->welcome == true) {
        if (dprintf(fileno(client->file), "WELCOME\n") == -1)
            return EXIT_FAILURE;
        client->welcome = false;
        return reset_ev(client, server);
    }
    if (write_chrono(client) == EXIT_FAILURE)
        return EXIT_FAILURE;
    return client->chrono == NULL ? reset_ev(client, server)
    : set_writable(client, server);
}

static int connect_team(client_t *client, server_t *server, map_t **map)
{
    if (client->connected == true)
        return EXIT_SUCCESS;
    if (client->command[0] == NULL || client->command[1] != NULL)
        return EXIT_SUCCESS;
    if (connection_for_team_from_client(client, server, client->command[0])
    == EXIT_FAILURE)
        return EXIT_FAILURE;
    if (client->connected == true) {
        client->player =
            add_player(map, server->info_server.width, server->info_server.height);
            client->type = AI;
        if (client->player == NULL)
            return EXIT_FAILURE;
        client->player->id = server->id;
        server->id = server->id + 1;
        client->player->level = 1;
        set_id_teams(server);
        return apla(client, server, map);
    } else if (set_writable(client, server) == EXIT_FAILURE)
        return EXIT_FAILURE;
    return EXIT_SUCCESS;
}

int command_type(client_t *client, server_t *server, map_t **map)
{
    if (client->read == false)
        return send_welcome(client, server);
    for (size_t i = 0; client->command != NULL && client->command[0]
    && i < sizeof_arr(type_command); ++i)
        if (strcmp(client->command[0], type_command[i].command) == 0)
            return type_command[i].function(client,server, map);
    return connect_team(client, server, map);
}