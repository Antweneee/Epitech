/*
** EPITECH PROJECT, 2022
** my_teams
** File description:
** unsubscribe
*/

#include <stdio.h>
#include "client.h"
#include "server_commands.h"
#include "../libs/myteams/logging_server.h"

char *create_subscribe_path(char *team_uuid, bool description_file);
int check_405(char **args, int limit);
int check_if_already_subscribed(char *user_uuid, char *file_path);

char *error_404_unsubscribe(char *uuid)
{
    char *error = malloc(sizeof(char) * SIZE);

    if (!error || !uuid)
        return "";
    strcpy(error, "unsubscribe team ");
    strcat(error, strdup(uuid));
    strcat(error, " Not Found");
    return error;
}

int error_unsubscribe(char **args, char *uuid, connected_client_t *clients)
{
    char *filepath = create_subscribe_path(uuid, 0);
    char *error = error_404_unsubscribe(uuid);
    send_data_t post;

    memset(&post, 0, sizeof(send_data_t));
    if (access(filepath, W_OK) == 0 && check_405(args, 2) == SUCCESS
    && clients->user_uuid) {
        free(filepath);
        free(error);
        return SUCCESS;
    }
    if (check_405(args, 2) == ERROR) {
        post.status = 405;
        strcpy(post.response, "Too many arguments");
    } else if (!clients->user_uuid) {
        post.status = 401;
        strcpy(post.response, "subscribed Unauthorized");
    } else {
        post.status = 404;
        strcpy(post.response, error);
    }
    write(clients->_client_fd, &post, sizeof(send_data_t));
    free(filepath);
    free(error);
    return ERROR;
}

int check_if_already_unsubscribed(char *user_uuid, char *file_path)
{
    char *file = open_read_file(file_path);
    char **array_file = parse_str(file, 0, 1);

    for (int i = 0; array_file[i]; i++) {
        if (strstr(array_file[i], user_uuid))
            return 1;
    }
    return 0;
}

void unsubscribe_client_to_team(char *team_uuid, char *user_uuid)
{
    char *file_path = create_subscribe_path(team_uuid, 1);
    char *file = open_read_file(file_path);
    char **array = parse_str(file, 0, 1);
    FILE *team_file = fopen(file_path, "w+");

    if (check_if_already_subscribed(user_uuid, file_path) == 0) {
        free(file_path);
        return;
    }
    for (int i = 0; array[i]; i++) {
        if (strstr(array[i], user_uuid))
            continue;
        else if (array[i + 1])
            fprintf(team_file, "%s\n", array[i]);
        else
            fprintf(team_file, "%s", array[i]);
    }
    fclose(team_file);
    server_event_user_unsubscribed(team_uuid, user_uuid);
}

void unsubscribe(send_data_t data, connected_client_t *clients)
{
    send_data_t post;
    char **args = parse_args(data.msg);

    if (error_unsubscribe(args, args[1], clients) == ERROR)
        return;
    unsubscribe_client_to_team(args[1], data.user_uuid);
    memset(&post, 0, sizeof(send_data_t));
    post.status = 209;
    strcpy(post.response, "unsubscribe to ");
    strcat(post.response, args[1]);
    strcat(post.response, " successful");
    write(clients->_client_fd, &post, sizeof(send_data_t));
}