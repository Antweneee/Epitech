/*
** EPITECH PROJECT, 2022
** B-NWP-400-PAR-4-1-myteams-antoine.gavira-bottari
** File description:
** user
*/

#include <stdio.h>
#include "../libs/myteams/logging_client.h"
#include "client_commands.h"
#include "client.h"

void print_all_clients(char *str_clients)
{
    char **clients = parse_str(str_clients, 0, 1);
    char *user_name = malloc(sizeof(char) * SIZE);
    char *user_uuid = malloc(sizeof(char) * SIZE);
    char *status = malloc(sizeof(char) * SIZE);

    for (int i = 0; clients[i]; i++) {
        strcpy(user_name, strsep(&clients[i], "]") + 1);
        clients[i] += 1;
        strcpy(user_uuid, strsep(&clients[i], " "));
        strcpy(status, clients[i]);
        client_print_users(user_uuid, user_name, status[0] - '0');
    }
    free(user_name);
    free(user_uuid);
    free(status);
    return;
}

void users(send_data_t data, client_t *clients)
{
    print_all_clients(strdup(data.response) + 17);
    (void) clients;
}

void parse_call_user(char *response)
{
    char *real_response = strdup(response + strlen("user successful "));
    char *user_name = malloc(sizeof(char) * SIZE);
    char *user_uuid = malloc(sizeof(char) * SIZE);
    char *status = malloc(sizeof(char) * SIZE);

    strcpy(user_name, strsep(&real_response, "]") + 1);
    real_response += 1;
    strcpy(user_uuid, strsep(&real_response, " "));
    strcpy(status, real_response);
    client_print_user(user_uuid, user_name, status[0] - '0');
    free(user_name);
    free(user_uuid);
    free(status);
}

void user(send_data_t data, client_t *clients)
{
    (void) clients;
    char *response = strdup(data.response);
    char *tmp = NULL;

    if (data.status == 404) {
        strsep(&response, " ");
        tmp = strsep(&response, " ");
        client_error_unknown_user(tmp);
    } else if (data.status == 203)
        parse_call_user(data.response);
}