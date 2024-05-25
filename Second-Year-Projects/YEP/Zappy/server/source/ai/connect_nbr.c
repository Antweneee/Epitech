/*
** EPITECH PROJECT, 2022
** B-YEP-410-PAR-4-1-zappy-thomas.willson
** File description:
** connect_nbr
*/

#include <string.h>
#include "server.h"
#include "functions.h"

static uint32_t get_client_connect_nbr(const char *team_name, teams_t **teams)
{
    uint32_t client_connect_nbr = 0;

    for (team_t *team = *teams; team; team = team->next) {
        if (team->name && strcmp(team->name, team_name) == 0)
            client_connect_nbr = team->clients_nb;
    }
    return client_connect_nbr;
}

int connect_nbr(client_t *client, server_t *server,
__ATTRIBUTE_UNUSED__ map_t **map)
{
    uint32_t client_connect_nbr = 0;
    char number[11] = {0};

    if (set_writable(client, server) == EXIT_FAILURE)
        return EXIT_FAILURE;
    client_connect_nbr = get_client_connect_nbr(client->team_name,
    &server->teams);
    sprintf(number, "%d\n"
    , server->info_server.clients_nb - client_connect_nbr);
    message_chrono(client, number, 0);
    return EXIT_SUCCESS;
}
