/*
** EPITECH PROJECT, 2022
** B-NWP-400-PAR-4-1-myteams-antoine.gavira-bottari
** File description:
** user
*/

#include <stdio.h>
#include "server_commands.h"
#include "client.h"

char *is_client_connected_file(char *data_message, connected_client_t *clients)
{
    char *aha = strdup(data_message);
    connected_client_t *tmp = clients;

    strsep(&aha, "]");
    aha += 1;
    for (; tmp; tmp = tmp->_next) {
        if (tmp->user_uuid && strcmp(aha, tmp->user_uuid) == 0)
            return "1";
    }
    return "0";
}

char *is_client_connected_uuid(char *uuid, connected_client_t *clients)
{
    connected_client_t *tmp = clients;

    for (; tmp; tmp = tmp->_next) {
        if (tmp->user_uuid && strcmp(uuid, tmp->user_uuid) == 0)
            return "1";
    }
    return "0";
}


int error_users(char *data_msg, int client_fd)
{
    char **args = parse_str(strdup(data_msg), 1, 0);
    send_data_t post;

    if (args && args[0] && !args[1])
        return SUCCESS;
    memset(&post, 0, sizeof(send_data_t));
    post.status = 405;
    strcpy(post.response, "Too many arguments");
    write(client_fd, &post, sizeof(send_data_t));
    return ERROR;
}

char *check_clients_connected(char *file_buffer,
connected_client_t *clients_struct)
{
    char **clients = parse_str(file_buffer, 0, 1);
    char *tmp = NULL;
    char *new_file = malloc(sizeof(char) * SIZE);

    for (int i = 0; clients[i]; i++) {
        tmp = malloc(sizeof(char) * strlen(clients[i]) + 4);
        strcpy(tmp, strdup(clients[i]));
        strcat(tmp, " ");
        strcat(tmp, is_client_connected_file(clients[i], clients_struct));
        strcat(tmp, "\n");
        if (i == 0)
            strcpy(new_file, tmp);
        else
            strcat(new_file, tmp);
    }
    return new_file;
}

void users(send_data_t data, connected_client_t *clients)
{
    send_data_t post;
    char *file_string = open_read_file(CLIENT_LIST_PATH);

    if (error_users(data.msg, clients->_client_fd) == ERROR)
        return;

    memset(&post, 0, sizeof(send_data_t));
    post.status = 202;
    strcpy(post.response, "users successful ");
    strcat(post.response, check_clients_connected(file_string, clients));

    write(clients->_client_fd, &post, sizeof(send_data_t));
}

char *get_uuid_from_str(char *string)
{
    char *uuid = strsep(&string, "]");

    string += 1;
    strcpy(uuid, strdup(string));
    return uuid;
}

int uuid_exist(char **client_file, char *uuid)
{
    int checked = 0;

    for (int i = 0; client_file[i]; i++) {
        if (!strncmp(get_uuid_from_str(strdup(client_file[i])),
        uuid, strlen(uuid)))
            checked = 1;
    }
    return checked;
}

int error_user(char **args, int client_fd, char **client_file)
{
    send_data_t post;
    char *user = malloc(sizeof(char) * 60);

    if (args && args[0] && args[1] && !args[2] &&
        uuid_exist(client_file, args[1]))
        return SUCCESS;
    memset(&post, 0, sizeof(send_data_t));
    strcpy(user, "user ");
    if (args[1] && uuid_exist(client_file, args[1]) == 0) {
        post.status = 404;
        strcat(user, strdup(args[1]));
        strcat(user, " Not Found");
        strcpy(post.response, strdup(user));
        free(user);
    } else {
        post.status = 405;
        strcpy(post.response, "Too many arguments");
    }
    write(client_fd, &post, sizeof(send_data_t));
    return ERROR;
}

char *get_user(char **args, char **client_file)
{
    for (int i = 0; client_file[i]; i++) {
        if (strstr(client_file[i], args[1]))
            return strdup(client_file[i]);
    }
    return "";
}

void user(send_data_t data, connected_client_t *clients)
{
    char *response = malloc(sizeof(char) * SIZE);
    char *file_string = open_read_file(CLIENT_LIST_PATH);
    char **client_file = parse_str(strdup(file_string), 0, 1);
    send_data_t post;

    if (error_user(parse_args(strdup(data.msg)), clients->_client_fd,
        client_file) == ERROR)
        return;
    memset(&post, 0, sizeof(send_data_t));
    post.status = 203;
    strcpy(response, "user successful ");
    strcat(response, get_user(parse_args(strdup(data.msg)), client_file));
    strcat(response, " ");
    strcat(response, is_client_connected_uuid(parse_args(strdup(data.msg))[1],
    clients));
    strcpy(post.response, response);
    write(clients->_client_fd, &post, sizeof(send_data_t));
}
