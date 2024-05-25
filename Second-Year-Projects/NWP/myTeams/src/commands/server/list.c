/*
** EPITECH PROJECT, 2022
** B-NWP-400-PAR-4-1-myteams-antoine.gavira-bottari
** File description:
** list
*/

#include <stdio.h>
#include <dirent.h>
#include "client.h"
#include "server_commands.h"
int check_405(char **args, int limit);
char *create_subscribe_path(char *team_uuid, bool description_file);
char *create_concate_path(char **uuid, bool dir_file);
int check_use(char *use);
char *create_404_error_create(char *use);
int is_user_subscribed_team(char *user_uuid, char **uses);

char *list_all_teams(void)
{
    DIR *d;
    struct dirent *dir;
    char **tmp_array;
    char *tmp = malloc(sizeof(char) * 4000);

    strcpy(tmp, "list \n");
    d = opendir("conf/");
    if (!d)
        return "";
    while ((dir = readdir(d)) != NULL) {
        if (strlen(dir->d_name) >= 30) {
            printf("dir name = %s\n", dir->d_name);
            tmp_array =
            parse_str(open_read_file(create_subscribe_path(dir->d_name,
            true)), 0, 1);
            printf("path = %s\n", create_subscribe_path(dir->d_name, true));
            for (int i = 0; tmp_array[i]; i++)
                printf("tmp_array = %s\n", tmp_array[i]);
            strcat(tmp, strdup(tmp_array[1]));
            strcat(tmp, "\n");
            strcat(tmp, strdup(tmp_array[0]));
            strcat(tmp, "\n");
            strcat(tmp, strdup(tmp_array[2]));
            strcat(tmp, "\n");
        }
    }
    closedir(d);
    return tmp;
}

char *list_channels(char **uses)
{
    DIR *d;
    struct dirent *dir;
    char **tmp_array;
    char *tmp = malloc(sizeof(char) * 4000);
    char *path = malloc(sizeof(char) * SIZE);
    char *tmp_path = malloc(sizeof(char) * SIZE);

    strcpy(tmp, "list \n");
    strcpy(path, "conf/");
    for (int i = 0; uses[i]; i++) {
        strcat(path, uses[i]);
        strcat(path, "/");
    }
    d = opendir(path);
    if (!d)
        return "";
    while ((dir = readdir(d)) != NULL) {
        if (strlen(dir->d_name) >= 30) {
            strcpy(tmp_path, path);
            strcat(tmp_path, dir->d_name);
            strcat(tmp_path, "/chanel_description");
            tmp_array = parse_str(open_read_file(tmp_path), 0, 1);
            strcat(tmp, strdup(tmp_array[1]));
            strcat(tmp, "\n");
            strcat(tmp, strdup(tmp_array[0]));
            strcat(tmp, "\n");
            strcat(tmp, strdup(tmp_array[2]));
            strcat(tmp, "\n");
        }
    }
    closedir(d);
    return tmp;
}

char *create_path_2(char **uses)
{
    char *path = malloc(sizeof(char) * SIZE);

    strcpy(path, "conf/");
    for (int i = 0; uses[i]; i++) {
        strcat(path, uses[i]);
        strcat(path, "/");
    }
    return path;
}

char *list_threads(char **uses)
{
    DIR *d;
    struct dirent *dir;
    char **tmp_array;
    char *tmp = malloc(sizeof(char) * 4000);
    char *tmp_path = malloc(sizeof(char) * SIZE);
    char *path = create_path_2(uses);

    strcpy(tmp, "list \n");
    d = opendir(path);
    if (!d)
        return "";
    while ((dir = readdir(d)) != NULL) {
        if (strlen(dir->d_name) >= 30) {
            strcpy(tmp_path, path);
            strcat(tmp_path, dir->d_name);
            tmp_array = parse_str(open_read_file(tmp_path), 0, 1);
            sprintf(tmp, "%s\n%s\n%s\n%s\n%s\n", strdup(tmp_array[1]),
            strdup(tmp_array[4]), strdup(tmp_array[3]), strdup(tmp_array[0]),
            strdup(tmp_array[2]));
        }
    }
    closedir(d);
    return tmp;
}

char *path_create(char **uses)
{
    char *path = malloc(sizeof(char) * SIZE);

    strcpy(path, "conf/");
    for (int i = 0; uses[i]; i++) {
        strcat(path, strdup(uses[i]));
        if (uses[i + 1])
            strcat(path, "/");
    }
    return path;
}

char *list_reply(char **uses)
{
    char **file_array;
    char *tmp_buf = malloc(sizeof(char) * SIZE);
    char *body = malloc(sizeof(char) * SIZE);
    char *timestamp = malloc(sizeof(char) * SIZE);
    char *tmp = malloc(sizeof(char) * 4000);
    char *path = path_create(uses);

    strcpy(tmp, "list \n");
    file_array = parse_str(open_read_file(path), 0, 1);
    for (int i = 5; file_array[i]; i++) {
        strcpy(tmp_buf, strdup(file_array[i]));
        strcpy(body, strsep(&tmp_buf, "]") + 1);
        tmp_buf += 1;
        strcpy(timestamp, strsep(&tmp_buf, " "));
        sprintf(tmp, "%s\n%s\n%s\n%s\n", strdup(uses[2]), strdup(tmp_buf),
        strdup(timestamp), strdup(body));
    }
    return tmp;
}

char *create_404_error_list(char *use)
{
    char *error = malloc(sizeof(char) * SIZE);
    char **array_use = parse_args(use);
    char **path = malloc(sizeof(char *) * 5);
    int index = 0;

    strcpy(error, "list ");
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

int check_good_error(connected_client_t *clients, char **args_create)
{
    if (clients->use && check_use(strdup(clients->use)) == SUCCESS
        && check_405(args_create, 1) == SUCCESS
        && is_user_subscribed_team(clients->user_uuid,
        parse_args(strdup(clients->use))))
        return SUCCESS;
    return ERROR;
}

int error_list(char **args_create, connected_client_t *clients)
{
    send_data_t post;

    if (check_good_error(clients, args_create) == SUCCESS)
        return SUCCESS;
    memset(&post, 0, sizeof(send_data_t));
    if (!clients->use || !is_user_subscribed_team(clients->user_uuid,
    parse_args(strdup(clients->use)))) {
        post.status = 401;
        strcpy(post.response, "list Unauthorized");
    }
    else if (check_use(strdup(clients->use)) == ERROR) {
        post.status = 404;
        strcpy(post.response, create_404_error_list(clients->use));
    }
    else {
        post.status = 405;
        strcpy(post.response, "Too many arguments");
    }
    write(clients->_client_fd, &post, sizeof(send_data_t));
    return ERROR;
}

void do_the_if(send_data_t *post, char **uses, connected_client_t *clients)
{
    if (check_405(parse_args(strdup(clients->use)), 1) == SUCCESS) {
        strcpy(post->response, list_all_teams());
        post->status = 302;
    }
    if (check_405(parse_args(strdup(clients->use)), 2) == SUCCESS) {
        strcpy(post->response, list_channels(uses + 1));
        post->status = 312;
    }
    if (check_405(parse_args(strdup(clients->use)), 3) == SUCCESS) {
        strcpy(post->response, list_threads(uses + 1));
        post->status = 322;
    }
    if (check_405(parse_args(strdup(clients->use)), 4) == SUCCESS) {
        strcpy(post->response, list_reply(uses + 1));
        post->status = 332;
    }
}

void list(send_data_t data, connected_client_t *clients)
{
    send_data_t post;
    char **array = parse_args(strdup(data.msg));

    if (error_list(array, clients) == ERROR)
        return;
    char **uses = parse_args(strdup(clients->use));
    memset(&post, 0, sizeof(send_data_t));

    do_the_if(&post, uses, clients);

    write(clients->_client_fd, &post, sizeof(send_data_t));
    (void) data;
}