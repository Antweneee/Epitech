/*
** EPITECH PROJECT, 2022
** B-NWP-400-PAR-4-1-myteams-antoine.gavira-bottari
** File description:
** info
*/

#include <stdio.h>
#include "client_commands.h"
#include "client.h"
#include "../libs/myteams/logging_client.h"
void handle_404_client_list(char *data);

void info_user(char *buffer)
{
    char *user_name = malloc(sizeof(char) * SIZE);
    char *tmp = malloc(sizeof(char) * SIZE);

    strcpy(tmp, strdup(buffer));
    strcpy(user_name, strsep(&tmp, "]") + 1);
    tmp += 1;
    client_print_user(tmp, user_name, 1);
}

void info_team(char *buffer)
{
    char **args = parse_str(buffer, 0, 1);

    client_print_team(args[0], args[1], args[2]);
}

void info_channel(char *buffer)
{
    char **args = parse_str(buffer, 0, 1);

    client_print_channel(args[0], args[1], args[2]);
}

void info_thread(char *buffer)
{
    char **args = parse_str(buffer, 0, 1);

    client_print_thread(args[0], args[1],
    atoi(args[2]), args[3], args[4]);
}

void info(send_data_t data, client_t *clients)
{
    if (data.status == 401)
        client_error_unauthorized();
    if (data.status == 404)
        handle_404_client_list(strdup(data.response) + 5);
    if (data.status == 303)
        info_user(strdup(data.response) + 6);
    if (data.status == 313)
        info_team(strdup(data.response) + 6);
    if (data.status == 323)
        info_channel(strdup(data.response) + 6);
    if (data.status == 333)
        info_thread(strdup(data.response) + 6);
    (void) clients;
}