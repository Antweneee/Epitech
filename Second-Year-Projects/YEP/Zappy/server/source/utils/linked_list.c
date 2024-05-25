/*
** EPITECH PROJECT, 2022
** zappy_server
** File description:
** linked_list
*/

#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "server.h"

static team_t *add_team(const char *name)
{
    team_t *node = (team_t *)malloc(sizeof(team_t));

    if (node == NULL)
        return NULL;
    memset(node, 0, sizeof(teams_t));
    node->name = strdup(name);
    node->clients_nb = 0;
    node->forks_nb = 0;
    node->forks = NULL;
    node->clients = NULL;
    node->next = NULL;
    return node;
}

bool add_existing_teams(teams_t **teams, const char *name)
{
    team_t *tmp = NULL;
    team_t *add = NULL;

    if (*teams == NULL) {
        tmp = add_team(name);
        if (!tmp)
            return false;
        *teams = tmp;
    } else {
        tmp = *teams;
        for (; tmp->next; tmp = tmp->next);
        add = add_team(name);
        if (!add)
            return false;
        tmp->next = add;
    }
    return true;
}

void free_teams_list(teams_t **teams)
{
    team_t *tmp = (*teams);

    while ((*teams)) {
        tmp = (*teams);
        (*teams) = (*teams)->next;
        free(tmp->name);
        free(tmp);
    }
}
