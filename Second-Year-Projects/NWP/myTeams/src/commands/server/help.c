/*
** EPITECH PROJECT, 2022
** B-NWP-400-PAR-4-1-myteams-antoine.gavira-bottari
** File description:
** help
*/

#include <stdio.h>
#include "help_array.h"
#include "client.h"

send_data_t help_login(send_data_t data)
{
    char *str = "help login : /login ['user_name'] : \
    set the user_name used by client";

    strcpy(data.response, str);
    return data;
}

send_data_t help_logout(send_data_t data)
{
    char *str = "help logout : \
    disconnect the client from the server";

    strcpy(data.response, str);
    return data;
}

send_data_t help_users(send_data_t data)
{
    char *str = "help users : get the list of \
    all users that exist on the domain";

    strcpy(data.response, str);
    return data;
}

send_data_t help_user(send_data_t data)
{
    char *str = "help user : /user [“user_uuid”] : \
    get information about a user";

    strcpy(data.response, str);
    return data;
}

void help(send_data_t data, connected_client_t *clients)
{
    send_data_t post;
    char **args = parse_args(strdup(data.msg));

    if (!args[1])
        return;
    memset(&post, 0, sizeof(send_data_t));
    for (int i = 0; i < 13; i++) {
        if (strcmp(_command[i].str, args[1]) == 0)
            post = _command[i].function(data);
    }
    printf("[%s]\n", post.response);
    post.status = 911;
    write(clients->_client_fd, &post, sizeof(send_data_t));
}