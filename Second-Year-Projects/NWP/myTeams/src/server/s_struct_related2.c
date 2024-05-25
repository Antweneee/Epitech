/*
** EPITECH PROJECT, 2022
** B-NWP-400-PAR-4-1-myteams-antoine.gavira-bottari
** File description:
** s_struct_related2
*/

#include <stdlib.h>
#include "server.h"

void free_node(connected_client_t *to_free)
{
    if (to_free->user_name)
        free(to_free->user_name);
    if (to_free->user_uuid)
        free(to_free->user_uuid);
    free(to_free);
}
