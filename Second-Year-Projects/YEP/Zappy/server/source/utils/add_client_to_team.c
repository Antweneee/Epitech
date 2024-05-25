/*
** EPITECH PROJECT, 2022
** B-YEP-410-PAR-4-1-zappy-thomas.willson
** File description:
** add_client_to_team
*/

#include <string.h>
#include "server.h"
#include "functions.h"

static bool add_client_to_team(linked_client_t **clients, client_t *client)
{
    linked_client_t *tmp = NULL;
    linked_client_t *add = NULL;

    if (*clients == NULL) {
        tmp = (linked_client_t *)malloc(sizeof(linked_client_t));
        if (!tmp)
            return false;
        tmp->client = client;
        tmp->next = NULL;
        *clients = tmp;
    } else {
        for (tmp = *clients; tmp->next; tmp = tmp->next);
        add = (linked_client_t *)malloc(sizeof(linked_client_t));
        if (!add)
            return false;
        add->client = client;
        add->next = NULL;
        tmp->next = add;
    }
    return true;
}

static team_t *get_team(teams_t **teams, const char *lineptr)
{
    team_t *team = NULL;

    for (team_t *tmp = *teams; tmp; tmp = tmp->next) {
        if (tmp->name && strcmp(lineptr, tmp->name) == 0)
            team = tmp;
    }
    return team;
}

int connection_for_team_from_client(client_t *client, server_t *server,
char *lineptr)
{
    team_t *team = get_team(&server->teams, lineptr);
    int from_fork = 0;
    char result[33] = {0};
    
    if (set_writable(client, server) == EXIT_FAILURE)
        return EXIT_FAILURE;
    if (NULL == team)
        return message_chrono(client, "ko\n", 0);
    from_fork = check_if_player_can_connect(team, server);
    if (from_fork == -1)
        return message_chrono(client, "ko\n", 0);
    client->connected = true;
    client->team_name = strdup(team->name);
    if (add_client_to_team(&team->clients, client) == false)
        return EXIT_FAILURE;
    if (from_fork == 0)
        team->clients_nb++;
    if (from_fork == 1)
        team->forks_nb--;
    sprintf(result, "%d\n%d %d\n", server->info_server.clients_nb
    - team->clients_nb, server->info_server.width, server->info_server.height);
    return message_chrono(client, result, 0);
}