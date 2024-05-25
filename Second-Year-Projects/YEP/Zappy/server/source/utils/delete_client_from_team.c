/*
** EPITECH PROJECT, 2022
** B-YEP-410-PAR-4-1-zappy-thomas.willson
** File description:
** delete_client_from_team
*/

#include "server.h"
#include "functions.h"

static bool delete_client_from_team(linked_client_t **clients, int fd)
{
    linked_client_t *curr = NULL;
    client_t *client = NULL;

    if (*clients == NULL)
        return false;
    client = (*clients)->client;
    if (fd == fileno(client->file)) {
        curr = *clients;
        *clients = (*clients)->next;
        free(curr);
        free(client->team_name);
        client->team_name = NULL;
        return true;
    }
    return delete_client_from_team(&(*clients)->next, fd);
}

int handle_disconnection(teams_t **teams, int fd)
{
    bool deleted = false;

    for (team_t *team = *teams; team; team = team->next) {
        deleted = delete_client_from_team(&team->clients, fd);
        if (deleted == true) {
            free_forks_in_team(&team->forks);
            team->clients_nb--;
            break;
        }
    }
    dprintf(1, "disconnected\n");
    return EXIT_SUCCESS;
}