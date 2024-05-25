/*
** EPITECH PROJECT, 2022
** B-NWP-400-PAR-4-1-myteams-antoine.gavira-bottari
** File description:
** create
*/

#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <time.h>
#include <sys/types.h>
#include "server_commands.h"
#include "server.h"
#include "../libs/myteams/logging_server.h"
#include "client.h"
int check_405(char **args, int limit);
char *create_subscribe_path(char *team_uuid, bool description_file);
char *uuid_generation(void);
int check_if_already_subscribed(char *user_uuid, char *file_path);
int is_user_subscribed_team(char *user_uuid, char **uses);

char *create_concate_path(char **uuid, bool dir_file)
{
    char *filepath = malloc(sizeof(char) * SIZE);
    int i = 0;

    if (!filepath || !uuid)
        return "";
    strcpy(filepath, "conf/");
    for (; uuid[i]; i++) {
        strcat(filepath, strdup(uuid[i]));
        if (uuid[i + 1])
            strcat(filepath, "/");
    }
    if (i == 1 && dir_file == true)
        strcat(filepath, "/team_description");
    else if (i == 2 && dir_file == true)
        strcat(filepath, "/chanel_description");
    return filepath;
}

int check_use(char *use)
{
    char **array_use;

    if (strcmp(use, "use") == 0)
        return SUCCESS;
    array_use = parse_args(use);
    if ((check_405(array_use, 2) == SUCCESS
        || check_405(array_use, 3) == SUCCESS
        || check_405(array_use, 4) == SUCCESS)
        && access(create_concate_path(array_use + 1, true), W_OK) == -1)
        return ERROR;
    return SUCCESS;
}

int check_create_405(char **args_use, char **args_create)
{
    if ((check_405(args_use, 1) == SUCCESS
        || check_405(args_use, 2) == SUCCESS
        || check_405(args_use, 3) == SUCCESS)
        && check_405(args_create, 3) == ERROR)
        return ERROR;
    if (check_405(args_use, 4) == SUCCESS
        && (check_405(args_create, 2) == ERROR))
        return ERROR;
    return SUCCESS;
}

DIR *return_good_dir(char **args_use)
{
    char *filepath = malloc(sizeof(char) * SIZE);

    if (check_405(args_use, 1) == SUCCESS)
        return (opendir("conf/"));
    if (check_405(args_use, 2) == SUCCESS) {
        strcpy(filepath, "conf/");
        strcat(filepath, strdup(args_use[1]));
        return (opendir(filepath));
    }
    if (check_405(args_use, 3) == SUCCESS) {
        strcpy(filepath, "conf/");
        strcat(filepath, strdup(args_use[1]));
        strcat(filepath, "/");
        strcat(filepath, strdup(args_use[2]));
        return (opendir(filepath));
    }
    return NULL;
}

int check_equal_name(char **args_use, char **args_create, char *dir_name)
{
    if (check_405(args_use, 1) == SUCCESS && strcmp(args_create[1],
    parse_str(open_read_file(create_subscribe_path(dir_name, true)),
    0, 1)[0]) == 0)
        return ERROR;
    if (check_405(args_use, 2) == SUCCESS
    && strcmp(args_create[1],
    parse_str(open_read_file(create_concate_path(
        (char *[3]){strdup(args_use[1]), strdup(dir_name), NULL}, true)),
        0, 1)[0]) == 0)
        return ERROR;
    if (check_405(args_use, 3) == SUCCESS
        && strcmp(args_create[1], parse_str(open_read_file(create_concate_path(
        (char *[4]){strdup(args_use[1]), strdup(args_use[2]),
        strdup(dir_name), NULL}, true)), 0, 1)[0]) == 0)
        return ERROR;
    return SUCCESS;
}

int check_403_create(char **args_use, char **args_create)
{
    DIR *d;
    struct dirent *dir;

    if (check_405(args_use, 4) == SUCCESS)
        return SUCCESS;
    d = return_good_dir(args_use);
    if (!d)
        return ERROR;
    while ((dir = readdir(d)) != NULL) {
        if (strlen(dir->d_name) == 36
            && check_equal_name(args_use, args_create, dir->d_name) == ERROR)
            return ERROR;
    }
    closedir(d);
    return SUCCESS;
}

char *create_404_error_create(char *use)
{
    char *error = malloc(sizeof(char) * SIZE);
    char **array_use = parse_args(use);
    char **path = malloc(sizeof(char *) * 5);
    int index = 0;

    strcpy(error, "create ");
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

int error_create(char **args_create, connected_client_t *clients)
{
    send_data_t post;

    if (clients->use && check_use(strdup(clients->use)) == SUCCESS
        && check_create_405(parse_args(strdup(clients->use)),
        args_create) == SUCCESS
        && check_403_create(parse_args(strdup(clients->use)),
        args_create) == SUCCESS
        && is_user_subscribed_team(clients->user_uuid,
        parse_args(strdup(clients->use))))
        return SUCCESS;
    memset(&post, 0, sizeof(send_data_t));
    if (!clients->use || !is_user_subscribed_team(clients->user_uuid,
    parse_args(strdup(clients->use)))) {
        post.status = 401;
        strcpy(post.response, "create Unauthorized");
    }
    else if (check_use(strdup(clients->use)) == ERROR) {
        post.status = 404;
        strcpy(post.response, create_404_error_create(clients->use));
    } else if (check_create_405(parse_args(strdup(clients->use)),
        args_create) == ERROR) {
        post.status = 405;
        strcpy(post.response, "Too many arguments");
    } else if (check_403_create(parse_args(strdup(clients->use)),
        args_create) == ERROR) {
        post.status = 403;
        strcpy(post.response, "already exist");
    }
    write(clients->_client_fd, &post, sizeof(send_data_t));
    return ERROR;
}

char *create_response_team_channel(char *uuid, char *name, char *description)
{
    char *response = malloc(sizeof(char) * SIZE);

    strcpy(response, "create ");
    strcat(response, uuid);
    strcat(response, " [");
    strcat(response, name);
    strcat(response, "]");
    strcat(response, " [");
    strcat(response, description);
    strcat(response, "]");
    return response;
}

char *create_team(char **create, connected_client_t *clients)
{
    char *new_uuid = uuid_generation();
    FILE *f;

    if (mkdir(create_subscribe_path(new_uuid, false), 0777) == -1)
        return "";
    f = fopen(create_concate_path((char*[2]){new_uuid, NULL}, true), "a+");
    server_event_team_created(new_uuid, create[1], clients->user_uuid);
    if (!f)
        return "";
    fprintf(f, "%s\n%s\n%s", create[1], new_uuid, create[2]);
    fclose(f);
    return create_response_team_channel(new_uuid, create[1], create[2]);
}

char *create_channel(char **create, char **use)
{
    char *new_uuid = uuid_generation();
    FILE *f;

    if (mkdir(create_concate_path((char *[3]){use[1], new_uuid, NULL},
    false), 0777) == -1)
        return "";
    f = fopen(create_concate_path((char *[3]){strdup(use[1]),
    new_uuid, NULL}, true), "a+");
    server_event_channel_created(use[1], new_uuid, create[1]);
    if (!f)
        return "";
    fprintf(f, "%s\n%s\n%s", create[1], new_uuid, create[2]);
    fclose(f);
    return create_response_team_channel(new_uuid, create[1], create[2]);
}

char *create_response_thread_2(char *response, char *description, char *name)
{
    strcat(response, " [");
    strcat(response, name);
    strcat(response, "]");
    strcat(response, " [");
    strcat(response, description);
    strcat(response, "]");
    return response;
}

char *create_response_thread(char *thread_uuid, char *name, char *description,
char *timestamp, char *user_uuid)
{
    char *response = malloc(sizeof(char) * SIZE);

    strcpy(response, "create ");
    strcat(response, thread_uuid);
    strcat(response, " [");
    strcat(response, user_uuid);
    strcat(response, "]");
    strcat(response, " [");
    strcat(response, timestamp);
    strcat(response, "]");
    return create_response_thread_2(response, description, name);
}


char *create_tread(char **args_create, char **args_use,
connected_client_t *clients)
{
    time_t timestamp = time(NULL);
    char *new_uuid = uuid_generation();
    FILE *file = fopen(create_concate_path((char *[4]){strdup(args_use[1]),
    strdup(args_use[2]), new_uuid, NULL}, false), "a+");
    char *timest = malloc(sizeof(char) * SIZE);

    server_event_thread_created(strdup(args_use[2]), new_uuid,
    clients->user_uuid,
    args_create[1], args_create[2]);
    if (!file)
        return "";
    fprintf(file, "%s\n%s\n%s\n%ld\n%s", args_create[1], new_uuid,
    args_create[2],
    timestamp, clients->user_uuid);
    fclose(file);
    sprintf(timest, "%ld", timestamp);
    return create_response_thread(new_uuid, args_create[1], args_create[2],
    timest, clients->user_uuid);
}

char *create_response_reply(char *thread_uuid, char *description,
char *timestamp, char *user_uuid)
{
    char *response = malloc(sizeof(char) * SIZE);

    strcpy(response, "create ");
    strcat(response, thread_uuid);
    strcat(response, " [");
    strcat(response, user_uuid);
    strcat(response, "]");
    strcat(response, " [");
    strcat(response, timestamp);
    strcat(response, "]");
    strcat(response, " [");
    strcat(response, description);
    strcat(response, "]");
    return response;
}

char *create_reply(char **args_create, char **args_use,
connected_client_t *clients)
{
    time_t timestamp = time(NULL);
    FILE *file = fopen(create_concate_path((char *[4]){strdup(args_use[1]),
    strdup(args_use[2]), strdup(args_use[3]), NULL}, false), "a");
    char *timest = malloc(sizeof(char) * SIZE);

    server_event_reply_created(strdup(args_use[3]), clients->user_uuid,
    args_create[1]);
    if (!file)
        return "";
    fprintf(file, "\n[%s] %ld %s", args_create[1], timestamp,
    clients->user_uuid);
    sprintf(timest, "%ld", timestamp);
    fclose(file);
    return create_response_reply(strdup(args_use[3]), args_create[1],
    timest, clients->user_uuid);
}

void call_all_users_create_team(char *response, connected_client_t *clients)
{
    send_data_t post;

    connected_client_t *tmp = clients;
    memset(&post, 0, sizeof(send_data_t));
    for (; tmp->_prev; tmp = tmp->_prev);

    strcpy(post.response, response);
    post.status = 501;
    for (; tmp; tmp = tmp->_next) {
        if (tmp->user_uuid)
            write(tmp->_client_fd, &post, sizeof(send_data_t));
    }
}

int is_user_subscribed_team(char *user_uuid, char **uses)
{
    char *file_path;


    if (!uses || !uses[0])
        return 0;

    if (!uses[1])
        return 1;
    file_path = create_subscribe_path(uses[1], 1);

    if (check_if_already_subscribed(user_uuid, file_path)) {
        free(file_path);
        return 1;
    }
    return 0;
}

void call_all_users_create_channel(char *response, connected_client_t *clients,
char **uses)
{
    send_data_t post;

    connected_client_t *tmp = clients;
    memset(&post, 0, sizeof(send_data_t));
    for (; tmp->_prev; tmp = tmp->_prev);

    strcpy(post.response, response);
    post.status = 511;
    for (; tmp; tmp = tmp->_next) {
        if (!tmp->user_uuid)
            continue;
        if (is_user_subscribed_team(strdup(tmp->user_uuid), uses))
            write(tmp->_client_fd, &post, sizeof(send_data_t));
    }
}

void call_all_users_create_thread(char *response, connected_client_t *clients,
char **uses)
{
    send_data_t post;

    connected_client_t *tmp = clients;
    memset(&post, 0, sizeof(send_data_t));
    for (; tmp->_prev; tmp = tmp->_prev);

    strcpy(post.response, response);
    post.status = 521;
    for (; tmp; tmp = tmp->_next)
        if (tmp->user_uuid && is_user_subscribed_team(strdup(tmp->user_uuid),
        uses))
            write(tmp->_client_fd, &post, sizeof(send_data_t));
}

void call_all_users_create_reply(char **array, connected_client_t *clients,
char **uses)
{
    send_data_t post;

    connected_client_t *tmp = clients;
    memset(&post, 0, sizeof(send_data_t));
    for (; tmp->_prev; tmp = tmp->_prev);

    char *test = malloc(sizeof(char) * SIZE);
    strcpy(test, "conf/");
    for (int i = 1; uses[i]; i++) {
        strcat(test, uses[i]);
        if (uses[i + 1])
            strcat(test, "/");
    }

    char **tmp2 = parse_str(open_read_file(test), 1, 0);

    char *response = malloc(sizeof(char) * SIZE);

    strcpy(response, "create ");
    strcat(response, uses[1]);
    strcat(response, " [");
    strcat(response, uses[3]);
    strcat(response, "]");
    strcat(response, " [");
    strcat(response, tmp2[0]);
    strcat(response, "]");
    strcat(response, " [");
    strcat(response, array[1]);
    strcat(response, "]");

    strcpy(post.response, response);
    post.status = 531;
    for (; tmp; tmp = tmp->_next)
        if (tmp->user_uuid && is_user_subscribed_team(strdup(tmp->user_uuid),
        uses))
            write(tmp->_client_fd, &post, sizeof(send_data_t));
}

void create(send_data_t data, connected_client_t *clients)
{
    send_data_t post = {0};
    char **array = parse_args(strdup(data.msg));

    if (error_create(array, clients) == ERROR)
        return;
    if (check_405(parse_args(strdup(clients->use)), 1) == SUCCESS) {
        strcpy(post.response, create_team(array, clients));
        post.status = 301;
        write(clients->_client_fd, &post, sizeof(send_data_t));
        call_all_users_create_team(strdup(post.response), clients);
    }
    if (check_405(parse_args(strdup(clients->use)), 2) == SUCCESS) {
        strcpy(post.response, create_channel(array,
        parse_args(strdup(clients->use))));
        post.status = 311;
        write(clients->_client_fd, &post, sizeof(send_data_t));
        call_all_users_create_channel(strdup(post.response), clients,
        parse_args(strdup(clients->use)));
    }
    if (check_405(parse_args(strdup(clients->use)), 3) == SUCCESS) {
        strcpy(post.response, create_tread(array,
        parse_args(strdup(clients->use)), clients));
        post.status = 321;
        write(clients->_client_fd, &post, sizeof(send_data_t));
        call_all_users_create_thread(strdup(post.response), clients,
        parse_args(strdup(clients->use)));
    }
    if (check_405(parse_args(strdup(clients->use)), 4) == SUCCESS) {
        strcpy(post.response, create_reply(array,
        parse_args(strdup(clients->use)), clients));
        post.status = 331;
        write(clients->_client_fd, &post, sizeof(send_data_t));
        call_all_users_create_reply(array, clients,
        parse_args(strdup(clients->use)));
    }
}