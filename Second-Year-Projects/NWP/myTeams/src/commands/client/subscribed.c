/*
** EPITECH PROJECT, 2022
** my_teams
** File description:
** subscribed
*/

#include <stdio.h>
#include "client_commands.h"
#include "client.h"
#include "../libs/myteams/logging_client.h"

void print_all_teams(char *response)
{
    char **array = parse_str(response, 0, 1);

    for (int i = 0; array[i + 2]; i += 3) {
        client_print_teams(array[i], array[i + 1], array[i + 2]);
        if (!array[i + 3])
            break;
    }
}

void print_users_in_team(char *response)
{
    char **array = parse_str(response, 0, 1);
    char *user_name = malloc(sizeof(char) * SIZE);
    char *user_uuid = malloc(sizeof(char) * SIZE);
    char *status = malloc(sizeof(char) * SIZE);

    for (int i = 0; array[i]; i++) {
        strcpy(user_name, strsep(&array[i], "]") + 1);
        array[i] += 1;
        strcpy(user_uuid, strsep(&array[i], " "));
        strcpy(status, array[i]);
        client_print_users(user_uuid, user_name, status[0] - '0');
    }
}

void unknow_team(char *response)
{
    client_error_unknown_team(strsep(&response, " "));
}

void subscribed(send_data_t data, client_t *clients)
{
    char *tmp = malloc(sizeof(char) * SIZE);

    if (data.status == 207)
        print_all_teams(strdup(data.response) + 12);
    if (data.status == 208)
        print_users_in_team(strdup(data.response) + 12);
    if (data.status == 404) {
        strcpy(tmp, (strdup(data.response) + 16));
        client_error_unknown_team(strsep(&tmp, " "));
    }
    if (data.status == 401)
        client_error_unauthorized();
    (void)clients;
}