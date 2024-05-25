/*
** EPITECH PROJECT, 2022
** B-NWP-400-PAR-4-1-myteams-antoine.gavira-bottari
** File description:
** link_commad
*/

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "mydata.h"
#include "server_array.h"
#include "server.h"

void call_not_found(connected_client_t *clients)
{
    send_data_t post;

    memset(&post, 0, sizeof(send_data_t));
    post.status = 400;
    strcpy(post.response, "Bad Request");
    if (clients->user_name && clients->user_uuid) {
        strcpy(post.user_name, clients->user_name);
        strcpy(post.user_uuid, clients->user_uuid);
    }
    write(clients->_client_fd, &post, sizeof(send_data_t));
}

void check_commands(send_data_t data, connected_client_t *clients)
{
    int use = 0;

    for (int i = 0; i < 14; i++) {
        if (!strncmp(_commands[i].str, data.msg, strlen(_commands[i].str))
        && (data.msg[strlen(_commands[i].str)] == ' '
        || !data.msg[strlen(_commands[i].str)])) {
            printf("%s\n", _commands[i].str);
            _commands[i].handler(data, clients);
            use = 1;
            break;
        }
    }
    if (use == 0)
        call_not_found(clients);
}