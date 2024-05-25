/*
** EPITECH PROJECT, 2022
** B-YEP-410-PAR-4-1-zappy-thomas.willson
** File description:
** check_connection
*/

#include <string.h>
#include "server.h"
#include "functions.h"

static bool delete_fork_from_team(forks_t **forks, const char *uuid)
{
    forks_t *curr = NULL;

    if (*forks == NULL)
        return false;
    if ((*forks)->uuid && strcmp((*forks)->uuid, uuid) == 0) {
        curr = *forks;
        *forks = (*forks)->next;
        free(curr);
        return true;
    }
    return delete_fork_from_team(&(*forks)->next, uuid);
}

static bool founded_player_to_connect_in(forks_t **forks, uint32_t freq)
{
    uint32_t max = (600 / freq);
    double elapsed = 0.0;
    char *uuid = NULL;

    for (forks_t *fork = *forks; fork != NULL; fork = fork->next) {
        elapsed = (time(NULL) - fork->time);
        if (elapsed > max) {
            uuid = strdup(fork->uuid);
            break;
        }
    }
    if (uuid) {
        if (delete_fork_from_team(forks, uuid) == true) {
            free(uuid);
            return true;
        }
    }
    return false;
}

int check_if_player_can_connect(team_t *team, server_t *server)
{
    if (team->clients_nb == server->info_server.clients_nb) {
        if (team->forks_nb == 0) {
            return -1;
        } else {
            if (founded_player_to_connect_in(&team->forks,
            server->info_server.freq) == true)
                return 1;
            return -1;
        }
    }
    return 0;
}
