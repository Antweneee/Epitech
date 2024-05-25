/*
** EPITECH PROJECT, 2022
** B-NWP-400-PAR-4-1-myteams-antoine.gavira-bottari
** File description:
** list
*/

#include <stdio.h>
#include "client_commands.h"
#include "client.h"
#include "../libs/myteams/logging_client.h"
#include "../libs/myteams/logging_client.h"
void print_all_teams(char *response);

void print_all_channels(char *response)
{
    char **array;

    if (!response)
        return;
    array = parse_str(response, 0, 1);
    if (!array || !array[1] || !array[2])
        return;
    for (int i = 0; array[i + 2]; i += 3) {
        client_print_channel(array[i], array[i + 1], array[i + 2]);
        if (!array[i + 3])
            break;
    }
}

void print_all_threads(char *response)
{
    char **array;

    if (!response)
        return;
    array = parse_str(response, 0, 1);
    if (!array || !array[0] || !array[1] || !array[2]
        || !array[3] || !array[4])
        return;
    for (int i = 0; array[i + 4]; i += 5) {
        client_channel_print_threads(array[i],
        array[i + 1],
        atoi(array[i + 2]),
        array[i + 3],
        array[i + 4]);
        if (!array[i + 5])
            break;
    }
}

void print_all_reply(char *response)
{
    char **array;
    char *reply_body = malloc(sizeof(char) * SIZE * 3);

    if (!response)
        return;
    array = parse_str(response, 0, 1);
    if (!array || !array[0] || !array[1] || !array[2] || !array[3])
        return;
    for (int i = 0; array[i + 3]; i += 4) {
        strcpy(reply_body, strdup(array[i + 3]));
        client_thread_print_replies(array[i], array[i + 1],
        atoi(array[i + 2]), array[i + 3]);
        if (!array[i + 4])
            break;
    }
    free(reply_body);
}

void handle_404_client_list(char *data)
{
    char **args = parse_str(data, 1, 0);

    if (strcmp(args[0], "team") == 0)
        client_error_unknown_team(args[1]);
    if (strcmp(args[0], "channel") == 0)
        client_error_unknown_channel(args[1]);
    if (strcmp(args[0], "thread") == 0)
        client_error_unknown_thread(args[1]);
}

void list(send_data_t data, client_t *clients)
{
    if (data.status == 401)
        client_error_unauthorized();
    if (data.status == 404)
        handle_404_client_list(strdup(data.response) + 5);
    if (data.status == 302)
        print_all_teams(strdup(data.response) + 6);
    if (data.status == 312)
        print_all_channels(strdup(data.response) + 6);
    if (data.status == 322)
        print_all_threads(strdup(data.response) + 6);
    if (data.status == 332)
        print_all_reply(strdup(data.response) + 6);
    (void) clients;
}