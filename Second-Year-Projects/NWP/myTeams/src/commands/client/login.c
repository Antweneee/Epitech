/*
** EPITECH PROJECT, 2022
** B-NWP-400-PAR-4-1-myteams-antoine.gavira-bottari
** File description:
** login
*/

#include <uuid/uuid.h>
#include "../libs/myteams/logging_client.h"
#include "client_commands.h"
#include "client.h"

void login(send_data_t data, client_t *client)
{
    if (!strcmp(data.response, "login successful") && data.status == 200) {
        strcpy(client->to_send.user_name, data.user_name);
        strcpy(client->to_send.user_uuid, data.user_uuid);
    }
    if (data.status == 299)
        client_event_logged_in(data.user_uuid, data.user_name);
    if (data.status == 401)
        client_error_unauthorized();
}

void logout(send_data_t data, client_t *client)
{
    if (!strcmp(data.response, "logout successful") && data.status == 302) {
        strcpy(client->to_send.user_name, "");
        strcpy(client->to_send.user_uuid, "");
    }
    if (data.status == 399)
        client_event_logged_out(data.user_uuid,
        data.user_name);
    if (data.status == 401)
        client_error_unauthorized();
}