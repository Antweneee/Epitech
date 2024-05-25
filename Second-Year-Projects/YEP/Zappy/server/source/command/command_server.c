/*
** EPITECH PROJECT, 2022
** B-YEP-410-PAR-4-1-zappy-thomas.willson
** File description:
** command_server
*/

#include "functions.h"
#include "command.h"


static const server_command_t server_command[] = {
    [UNDEFINED] = {command_type},
    [AI] = {command_ai},
    [GUI] = {command_gui}
};

int command_server(client_t *client, server_t *server, map_t **map)
{
    int return_value = server_command[client->type].function(client, server, map);
    if (client->command != NULL)
        free_2d_array(client->command);
    client->command = NULL;
    return return_value;
}