/*
** EPITECH PROJECT, 2022
** server
** File description:
** set_id_teams
*/

#include "server.h"

void set_id_teams(server_t *server)
{
    teams_t *teams;
    size_t counter = 0;

    teams = server->teams;
    for (; teams != NULL; teams = teams->next) {
        for (linked_client_t *client = teams->clients; client != NULL
        ; client = client->next) {
            if (client->client->player == NULL)
                continue;
            client->client->player->team_id = counter;
        }
        counter = counter + 1;
    }
}