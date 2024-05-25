/*
** EPITECH PROJECT, 2022
** my_teams
** File description:
** unsubscribe
*/

#include <stdio.h>
#include "client_commands.h"
#include "client.h"
#include "../libs/myteams/logging_client.h"

void unsubscribe(send_data_t data, client_t *clients)
{
    char *tmp = strdup(data.response);
    char *team_uuid = malloc(sizeof(char) * UUID_LEN);

    strsep(&tmp, " ");
    strsep(&tmp, " ");
    strcpy(team_uuid, strsep(&tmp, " "));
    if (data.status == 404)
        client_error_unknown_team(team_uuid);
    else if (data.status == 401)
        client_error_unauthorized();
    if (data.status == 209)
        client_print_unsubscribed(clients->to_send.user_uuid, team_uuid);
    free(team_uuid);
}