/*
** EPITECH PROJECT, 2022
** B-NWP-400-PAR-4-1-myteams-antoine.gavira-bottari
** File description:
** use
*/

#include <stdio.h>
#include "server_commands.h"
#include "client.h"
int check_405(char **args, int limit);

int error_use(char **args, connected_client_t *clients)
{
    send_data_t post;

    if ((check_405(args, 1) == SUCCESS || check_405(args, 2) == SUCCESS
        || check_405(args, 3) == SUCCESS || check_405(args, 4) == SUCCESS)
        && clients->user_uuid)
        return SUCCESS;
    memset(&post, 0, sizeof(send_data_t));
    if (!clients->user_uuid) {
        post.status = 401;
        strcpy(post.response, "use Unauthorized");
    } else {
        post.status = 405;
        strcpy(post.response, "Too many arguments");
    }
    write(clients->_client_fd, &post, sizeof(send_data_t));
    return ERROR;

}

void use(send_data_t data, connected_client_t *clients)
{
    char **args = parse_args(strdup(data.msg));
    send_data_t post;

    if (error_use(args, clients) == ERROR)
        return;
    memset(&post, 0, sizeof(send_data_t));
    clients->use = malloc(sizeof(char) * SIZE);
    strcpy(clients->use, strdup(data.msg) + 1);
    strcpy(post.response, strdup(data.msg) + 1);
    if (check_405(args, 1) == SUCCESS)
        post.status = 300;
    else if (check_405(args, 2) == SUCCESS)
        post.status = 310;
    else if (check_405(args, 3) == SUCCESS)
        post.status = 320;
    else
        post.status = 330;
    write(clients->_client_fd, &post, sizeof(send_data_t));
}