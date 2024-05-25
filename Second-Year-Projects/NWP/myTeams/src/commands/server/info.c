/*
** EPITECH PROJECT, 2022
** B-NWP-400-PAR-4-1-myteams-antoine.gavira-bottari
** File description:
** info
*/

#include <stdio.h>
#include "client.h"
#include "server_commands.h"
int check_405(char **args, int limit);
int check_use(char *use);
char *create_concate_path(char **uuid, bool dir_file);
char *create_subscribe_path(char *team_uuid, bool description_file);
char *get_user(char **args, char **client_file);
int is_user_subscribed_team(char *user_uuid, char **uses);

char *info_team(char **uses)
{
    char *path = malloc(sizeof(char) * SIZE);
    char *to_send = malloc(sizeof(char) * SIZE);
    char **args;

    strcpy(path, "conf/");
    strcat(path, uses[0]);
    strcat(path, "/team_description");
    args = parse_str(open_read_file(path), 0, 1);
    strcpy(to_send, strdup(args[1]));
    strcat(to_send, "\n");
    strcat(to_send, strdup(args[0]));
    strcat(to_send, "\n");
    strcat(to_send, strdup(args[2]));
    return to_send;
}

char *info_channel(char **uses)
{
    char *path = malloc(sizeof(char) * SIZE);
    char *to_send = malloc(sizeof(char) * SIZE);
    char **args;

    strcpy(path, "conf/");
    strcat(path, uses[0]);
    strcat(path, "/");
    strcat(path, uses[1]);
    strcat(path, "/chanel_description");
    args = parse_str(open_read_file(path), 0, 1);
    strcpy(to_send, strdup(args[1]));
    strcat(to_send, "\n");
    strcat(to_send, strdup(args[0]));
    strcat(to_send, "\n");
    strcat(to_send, strdup(args[2]));
    return to_send;
}

char *info_thread(char **uses)
{
    char *path = malloc(sizeof(char) * SIZE);
    char *to_send = malloc(sizeof(char) * SIZE);
    char **args;

    strcpy(path, "conf/");
    strcat(path, uses[0]);
    strcat(path, "/");
    strcat(path, uses[1]);
    strcat(path, "/");
    strcat(path, uses[2]);

    args = parse_str(open_read_file(path), 0, 1);
    strcpy(to_send, strdup(args[1]));
    strcat(to_send, "\n");
    strcat(to_send, strdup(args[4]));
    strcat(to_send, "\n");
    strcat(to_send, strdup(args[3]));
    strcat(to_send, "\n");
    strcat(to_send, strdup(args[0]));
    strcat(to_send, "\n");
    strcat(to_send, strdup(args[2]));
    return to_send;
}

char *create_404_error_info(char *use)
{
    char *error = malloc(sizeof(char) * SIZE);
    char **array_use = parse_args(use);
    char **path = malloc(sizeof(char *) * 5);
    int index = 0;

    strcpy(error, "info ");
    for (int i = 1; array_use[i]; i++) {
        path[index++] = strdup(array_use[i]);
        path[index] = NULL;
        if (access(create_concate_path(path, true), W_OK) != 0)
            break;
    }
    if (index == 1)
        strcat(strcat(error, "team "), array_use[1]);
    if (index == 2)
        strcat(strcat(error, "channel "), array_use[2]);
    if (index == 3)
        strcat(strcat(error, "thread "), array_use[3]);
    strcat(error, " Not Found");
    return error;
}

int error_info(char **args_create, connected_client_t *clients)
{
    send_data_t post;

    if (clients->use
    && check_use(strdup(clients->use)) == SUCCESS
    && check_405(args_create, 1) == SUCCESS
    && is_user_subscribed_team(clients->user_uuid,
    parse_args(strdup(clients->use))))
        return SUCCESS;
    memset(&post, 0, sizeof(send_data_t));
    if (!clients->use || !is_user_subscribed_team(clients->user_uuid,
    parse_args(strdup(clients->use)))) {
        post.status = 401;
        strcpy(post.response, "info Unauthorized");
    }
    else if (check_use(strdup(clients->use)) == ERROR) {
        post.status = 404;
        strcpy(post.response, create_404_error_info(clients->use));
    }
    else {
        post.status = 405;
        strcpy(post.response, "Too many arguments");
    }
    write(clients->_client_fd, &post, sizeof(send_data_t));
    return ERROR;
}


void info(send_data_t data, connected_client_t *clients)
{
    send_data_t post;
    char **array = parse_args(strdup(data.msg));
    char **client_file = parse_str(strdup(open_read_file(CLIENT_LIST_PATH)),
    0, 1);

    if (error_info(array, clients) == ERROR)
        return;
    char **uses = parse_args(strdup(clients->use));
    memset(&post, 0, sizeof(send_data_t));
    if (check_405(parse_args(strdup(clients->use)), 1) == SUCCESS) {
        strcpy(post.response, "info \n");
        strcat(post.response, get_user((char *[3]){clients->user_uuid,
        clients->user_uuid, NULL}, client_file));
        post.status = 303;
    }
    if (check_405(parse_args(strdup(clients->use)), 2) == SUCCESS) {
        strcpy(post.response, "info \n");
        strcat(post.response, info_team(uses + 1));
        post.status = 313;
    }
    if (check_405(parse_args(strdup(clients->use)), 3) == SUCCESS) {
        strcpy(post.response, "info \n");
        strcat(post.response, info_channel(uses + 1));
        post.status = 323;
    }
    if (check_405(parse_args(strdup(clients->use)), 4) == SUCCESS) {
        strcpy(post.response, "info \n");
        strcat(post.response, info_thread(uses + 1));
        post.status = 333;
    }
    write(clients->_client_fd, &post, sizeof(send_data_t));
}