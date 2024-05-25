/*
** EPITECH PROJECT, 2022
** B-NWP-400-PAR-4-1-myteams-antoine.gavira-bottari
** File description:
** message
*/

#include <stdio.h>
#include "client_commands.h"
#include "../libs/myteams/logging_client.h"
#include "client.h"

void my_send(send_data_t data, client_t *clients)
{
    char *tmp = strdup(data.response);
    char *user_uuid = malloc(sizeof(char) * UUID_LEN);

    strsep(&tmp, " ");
    strsep(&tmp, " ");
    strcpy(user_uuid, strsep(&tmp, " "));
    strsep(&tmp, ":");
    if (data.status == 404) {
        client_error_unknown_user(user_uuid);
    } else if (data.status == 210)
        client_event_private_message_received(user_uuid, tmp);
    (void) clients;
}

void messages_404(char *tmp, char *user_uuid)
{
    strsep(&tmp, " ");
    strsep(&tmp, " ");
    strcpy(user_uuid, strsep(&tmp, " "));
    client_error_unknown_user(user_uuid);
}

void messages(send_data_t data, client_t *clients)
{
    char *tmp = strdup(data.response);
    char *user_uuid = malloc(sizeof(char) * UUID_LEN);
    char *message = malloc(sizeof(char) * MAX_DESCRIPTION_LENGTH);
    char *msg_body = malloc(sizeof(char) * MAX_DESCRIPTION_LENGTH);
    time_t timestamp = 0;

    if (data.status == 404)
        messages_404(tmp, user_uuid);
    else if (data.status == 205) {
        strsep(&tmp, "\n");
        while ((message = strsep(&tmp, "\n")) != NULL) {
            strcpy(user_uuid, strsep(&message, ":"));
            strcpy(msg_body, strsep(&message, "["));
            timestamp = atoi(strsep(&message, "]"));
            client_private_message_print_messages(user_uuid, timestamp,
            msg_body);
        }
    }
    (void) clients;
}