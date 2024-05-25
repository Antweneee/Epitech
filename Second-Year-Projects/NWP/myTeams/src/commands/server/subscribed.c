/*
** EPITECH PROJECT, 2022
** my_teams
** File description:
** subscribed
*/

#include <stdio.h>
#include <dirent.h>
#include "client.h"
#include "server_commands.h"
int check_405(char **args, int limit);
char *create_subscribe_path(char *team_uuid, bool description_file);

int check_subscribed_ok(char **args, connected_client_t *clients)
{
    if (check_405(args, 1) == SUCCESS && clients->user_uuid)
        return SUCCESS;
    else if (check_405(args, 2) == SUCCESS &&
        access(create_subscribe_path(args[1], 0), W_OK) == SUCCESS)
        return SUCCESS;
    return ERROR;
}

char *error_404_subscribed(char *uuid)
{
    char *error = malloc(sizeof(char) * SIZE);

    if (!error || !uuid)
        return "";
    strcpy(error, "subscribed team ");
    strcat(error, strdup(uuid));
    strcat(error, " Not Found");
    return error;
}

int error_subscribed(char **args, connected_client_t *clients)
{
    send_data_t post;

    if (check_subscribed_ok(args, clients) == SUCCESS && clients->user_uuid)
        return SUCCESS;
    memset(&post, 0, sizeof(send_data_t));
    if (!clients->user_uuid) {
        post.status = 401;
        strcpy(post.response, "subscribed Unauthorized");
    } else if (check_405(args, 2) == SUCCESS &&
    access(create_subscribe_path(args[1], 0), W_OK) == ERROR) {
        post.status = 404;
        strcpy(post.response, error_404_subscribed(args[1]));
    } else {
        post.status = 405;
        strcpy(post.response, "Too many arguments");
    }
    write(clients->_client_fd, &post, sizeof(send_data_t));
    return ERROR;
}

char *teams_subscribe_for_a_user(connected_client_t *clients)
{
    DIR *d;
    struct dirent *dir;
    char **tmp_array;
    char *tmp = malloc(sizeof(char) * 4000);
    memset(tmp, 0,sizeof(char) * 4000);

    d = opendir("conf/");
    if (!d)
        return "";
    while ((dir = readdir(d)) != NULL) {
        if (strlen(dir->d_name) == 36) {
            tmp_array =
            parse_str(open_read_file(create_subscribe_path(dir->d_name, true)),
            0, 1);
            for (int i = 3; tmp_array[i]; i++) {
                if (strstr(tmp_array[i], clients->user_uuid)) {
                    strcat(tmp, strdup(tmp_array[1]));
                    strcat(tmp, "\n");
                    strcat(tmp, strdup(tmp_array[0]));
                    strcat(tmp, "\n");
                    strcat(tmp, strdup(tmp_array[2]));
                    strcat(tmp, "\n");
                }
            }
        }
    }
    closedir(d);
    return tmp;
}

char *is_client_connected_subscribed(char *user_uuid,
connected_client_t *clients)
{
    connected_client_t *tmp = clients;

    for (; tmp; tmp = tmp->_next) {
        if (tmp->user_uuid && strcmp(user_uuid, tmp->user_uuid) == 0)
            return "1";
    }
    return "0";
}


char *users_subscribe_in_a_team(char *team_uuid, connected_client_t *clients)
{
    char **array = parse_str(open_read_file(create_subscribe_path(team_uuid,
    true)), 0, 1);
    char *ret = malloc(sizeof(char) * 4000);
    char *user_uuid = malloc(sizeof(char) * SIZE);
    char *user_name = malloc(sizeof(char) * SIZE);

    memset(ret, 0,sizeof(char) * 4000);
    for (int i = 3; array[i]; i++) {
        strcpy(user_name, strsep(&array[i], "]"));
        strcat(user_name, "]");
        array[i] += 1;
        strcpy(user_uuid, array[i]);
        strcat(ret, strdup(user_name));
        strcat(ret, " ");
        strcat(ret, strdup(user_uuid));
        strcat(ret, " ");
        strcat(ret, is_client_connected_subscribed(user_uuid, clients));
        strcat(ret, "\n");
    }
    return ret;
}

void subscribed(send_data_t data, connected_client_t *clients)
{
    char **array_data = parse_args(data.msg);
    send_data_t post;

    if (error_subscribed(array_data, clients) == ERROR)
        return;
    memset(&post, 0, sizeof(send_data_t));
    strcpy(post.response, "subscribed \n");
    if (check_405(array_data, 1) == SUCCESS) {
        strcat(post.response, teams_subscribe_for_a_user(clients));
        post.status = 207;
    } else {
        strcat(post.response, users_subscribe_in_a_team(strdup(array_data[1]),
        clients));
        post.status = 208;
    }
    write(clients->_client_fd, &post, sizeof(send_data_t));
}