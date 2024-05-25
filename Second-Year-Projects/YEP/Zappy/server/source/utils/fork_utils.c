/*
** EPITECH PROJECT, 2022
** B-YEP-410-PAR-4-1-zappy-thomas.willson
** File description:
** fork_utils
*/

#include <string.h>
#include "server.h"

void generate_uuid(char *uuid)
{
    uuid_t binuuid;

    uuid_generate_random(binuuid);
    uuid_unparse(binuuid, uuid);
}

static forks_t *create_egg_node(int x, int y, time_t time)
{
    forks_t *fork = (forks_t *)malloc(sizeof(forks_t));
    char uuid[UUID_STR_LEN] = {0};

    if (NULL == fork)
        return NULL;
    generate_uuid(uuid);
    fork->uuid = strdup(uuid);
    fork->x = x;
    fork->y = y;
    fork->time = time;
    fork->hatched = false;
    fork->next = NULL;
    return fork;
}

bool add_egg_to_fork_list(forks_t **forks, int x, int y, time_t time)
{
    forks_t *tmp = NULL;
    forks_t *add = NULL;

    if (*forks == NULL) {
        tmp = create_egg_node(x, y, time);
        if (NULL == tmp)
            return false;
        *forks = tmp;
    } else {
        for (tmp = *forks; tmp->next; tmp = tmp->next);
        add = create_egg_node(x, y, time);
        if (NULL == add)
            return false;
        tmp->next = add;
    }
    return true;
}

void free_forks_in_team(forks_t **forks)
{
    forks_t *del = NULL;

    while (*forks != NULL) {
        del = *forks;
        *forks = (*forks)->next;
        free(del);
    }
}