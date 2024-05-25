/*
** EPITECH PROJECT, 2022
** B-YEP-410-PAR-4-1-zappy-thomas.willson
** File description:
** command_ia
*/

#include <string.h>
#include "command.h"
#include "functions.h"

static const client_command_t ai_command[] = {
    {
        .command = "/help",
        .function = help_ai
    },
    {
        .command = "Right",
        .function = right,
    },
    {
        .command = "Left",
        .function = left
    },
    {
        .command = "Forward",
        .function = forward
    },
    {
        .command = "Inventory",
        .function = inventory
    },
    {
        .command = "Take",
        .function = take_object
    },
    {
        .command = "Set",
        .function = set_object
    },
    {
        .command = "Broadcast",
        .function = broadcast
    },
    {
        .command = "Connect_nbr",
        .function = connect_nbr
    },
    {
        .command = "Look",
        .function = look
    },
    {
        .command = "Incantation",
        .function = incantation
    },
    {
        .command = "Fork",
        .function = xfork
    },
    {
        .command = "Eject",
        .function = eject
    }
};

static int write_ai(client_t *client, server_t *server)
{
    if (write_chrono(client) == EXIT_FAILURE)
        return EXIT_FAILURE;
    return client->chrono == NULL ? reset_ev(client, server)
    : set_writable(client, server);
}

static int set_client_player(client_t *client, server_t *server, map_t **map)
{
    if (client->connected == false || client->player != NULL)
        return EXIT_SUCCESS;
    client->player =
    add_player(map, server->info_server.width, server->info_server.height);
    if (client->player == NULL)
        return EXIT_FAILURE;
    return EXIT_SUCCESS;
}

int command_ai(client_t *client, server_t *server, map_t **map)
{
    if (client->read == false)
        return write_ai(client, server);
    if (set_client_player(client, server, map) == EXIT_FAILURE)
        return EXIT_FAILURE;
    for (size_t i = 0; client->command != NULL && client->command[0] != NULL
    && i < sizeof_arr(ai_command); ++i)
        if (strcmp(client->command[0], ai_command[i].command) == 0)
            return ai_command[i].function(client, server, map);
    if (set_writable(client, server) == EXIT_FAILURE)
        return EXIT_FAILURE;
    return message_chrono(client, "ko\n", 0);
}
