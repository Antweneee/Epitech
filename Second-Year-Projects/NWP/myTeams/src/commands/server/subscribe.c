/*
** EPITECH PROJECT, 2022
** B-NWP-400-PAR-4-1-myteams-antoine.gavira-bottari
** File description:
** subscribe
*/

#include <stdio.h>
#include "client.h"
#include "server_commands.h"
#include "../libs/myteams/logging_server.h"

char *error_404_subscribe(char *uuid)
{
    char *error = malloc(sizeof(char) * SIZE);

    if (!error || !uuid)
        return "";
    strcpy(error, "subscribe team ");
    strcat(error, strdup(uuid));
    strcat(error, " Not Found");
    return error;
}

char *create_subscribe_path(char *team_uuid, bool description_file)
{
    char *filepath = malloc(sizeof(char) * SIZE);

    if (!filepath || !team_uuid)
        return "";
    strcpy(filepath, "conf/");
    strcat(filepath, strdup(team_uuid));
    if (description_file == true)
        strcat(filepath, "/team_description");
    return filepath;
}

int check_405(char **args, int limit)
{
    int count = 0;

    if (!args)
        return ERROR;
    for (; args[count]; count++);
    if (limit != count)
        return ERROR;
    return SUCCESS;
}

int error_subscribe(char **args, connected_client_t *clients)
{
    send_data_t post;

    memset(&post, 0, sizeof(send_data_t));
    if (check_405(args, 2) == SUCCESS
        && access(create_subscribe_path(args[1], 0), W_OK) == 0
        && clients->user_uuid)
        return SUCCESS;
    if (check_405(args, 2) == ERROR) {
        post.status = 405;
        strcpy(post.response, "Too many arguments");
    } else if (!clients->user_uuid) {
        post.status = 401;
        strcpy(post.response, "subscribed Unauthorized");
    } else {
        post.status = 404;
        strcpy(post.response, error_404_subscribe(args[1]));
    }
    write(clients->_client_fd, &post, sizeof(send_data_t));
    return ERROR;
}

int check_if_already_subscribed(char *user_uuid, char *file_path)
{
    char *file = open_read_file(file_path);
    char **array_file = parse_str(file, 0, 1);

    for (int i = 0; array_file[i]; i++) {
        if (strstr(array_file[i], user_uuid))
            return 1;
    }
    return 0;
}

void subscribe_client_to_team(char *team_uuid, char *user_uuid,
char *user_name)
{
    char *file_path = create_subscribe_path(team_uuid, 1);
    char *user = malloc(sizeof(char) * NAME_LEN_MAX + UUID_LEN + 2);

    if (check_if_already_subscribed(user_uuid, file_path)) {
        free(file_path);
        return;
    }
    FILE *team_file = fopen(file_path, "a+");
    strcpy(user, "[");
    strcat(user, strdup(user_name));
    strcat(user, "]");
    strcat(user, " ");
    strcat(user, strdup(user_uuid));
    fprintf(team_file, "\n%s" , user);
    fclose(team_file);
    free(user);
    free(file_path);
    server_event_user_subscribed(team_uuid, user_uuid);
}

void subscribe(send_data_t data, connected_client_t *clients)
{
    send_data_t post;

    char **args = parse_args(data.msg);

    if (error_subscribe(args, clients) == ERROR)
        return;
    subscribe_client_to_team(args[1], data.user_uuid, data.user_name);
    memset(&post, 0, sizeof(send_data_t));
    post.status = 206;
    strcpy(post.response, "subscribe to ");
    strcat(post.response, strdup(args[1]));
    strcat(post.response, " successful");
    write(clients->_client_fd, &post, sizeof(send_data_t));
}