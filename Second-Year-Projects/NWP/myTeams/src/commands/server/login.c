/*
** EPITECH PROJECT, 2022
** B-NWP-400-PAR-4-1-myteams-antoine.gavira-bottari
** File description:
** login
*/

#include <uuid/uuid.h>
#include "client.h"
#include "server_commands.h"
#include "../libs/myteams/logging_server.h"

char *uuid_generation(void)
{
    uuid_t uuid;
    char *uuid_str = malloc(sizeof(char) * 37);

    uuid_generate_time_safe(uuid);
    uuid_unparse_lower(uuid, uuid_str);
    return uuid_str;
}

int check_already_logged(char *name, connected_client_t *clients)
{
    connected_client_t *tmp = clients;

    for (; tmp->_prev; tmp = tmp->_prev);
    for (; tmp; tmp = tmp->_next) {
        if (!tmp->user_name)
            continue;
        if (strcmp(tmp->user_name, name) == 0) {
            return 1;
        }
    }
    return 0;
}

int error_logs(char **args, connected_client_t *clients)
{
    send_data_t post;

    if (args && args[0]
        && args[1] && !args[2] && strcmp(args[0], "/logout") &&
        strlen(args[1]) < 33 && !clients->user_uuid)
        return SUCCESS;
    if (args
        && args[0] && (strcmp(args[0], "/logout") == 0) &&
        !args[1] && clients->user_uuid)
        return SUCCESS;
    memset(&post, 0, sizeof(send_data_t));
    if (args && (clients->user_uuid)) {
        post.status = 401;
        strcpy(post.response, "login Unauthorize");
    }
    else if (args && strcmp(args[0], "/login") == 0
    && args[1] && strlen(args[1]) > 32) {
        post.status = 407;
        strcpy(post.response, "Login name too long");
    } else if (args && args[0] && (strcmp(args[0], "/logout") == 0)
    && !clients->user_uuid) {
        post.status = 406;
        strcpy(post.response, "Not logged in");
    } else {
        post.status = 405;
        strcpy(post.response, "Too many arguments");
    }
    write(clients->_client_fd, &post, sizeof(send_data_t));
    return ERROR;
}

send_data_t *create_log_user(send_data_t *post, char *client_name, \
connected_client_t *clients)
{
    char *client_uuid = uuid_generation();

    server_event_user_created(client_uuid, client_name);
    server_event_user_logged_in(client_uuid);
    strcpy(post->user_name, client_name);
    strcpy(post->user_uuid, client_uuid);
    clients->user_name = strdup(client_name);
    clients->user_uuid = strdup(client_uuid);
    write_new_client(CLIENT_LIST_PATH, client_name, client_uuid);
    return post;
}

void call_all_users_login(connected_client_t *clients)
{
    send_data_t post;

    connected_client_t *tmp = clients;
    memset(&post, 0, sizeof(send_data_t));
    for (; tmp->_prev; tmp = tmp->_prev);

    strcpy(post.response, "login successful");
    post.status = 299;
    strcpy(post.user_name, strdup(clients->user_name));
    strcpy(post.user_uuid, strdup(clients->user_uuid));
    for (; tmp; tmp = tmp->_next)
        if (tmp->user_uuid)
            write(tmp->_client_fd, &post, sizeof(send_data_t));
}

void call_all_users_logout(connected_client_t *clients)
{
    send_data_t post;

    connected_client_t *tmp = clients;
    memset(&post, 0, sizeof(send_data_t));
    for (; tmp->_prev; tmp = tmp->_prev);

    strcpy(post.response, "logout successful");
    post.status = 399;
    strcpy(post.user_name, strdup(clients->user_name));
    strcpy(post.user_uuid, strdup(clients->user_uuid));
    for (; tmp; tmp = tmp->_next)
        if (tmp->user_uuid)
            write(tmp->_client_fd, &post, sizeof(send_data_t));
}

void login(send_data_t data, connected_client_t *clients)
{
    char **args = parse_args(strdup(data.msg));

    if (error_logs(args, clients) == ERROR)
        return;
    send_data_t post;
    memset(&post, 0, sizeof(send_data_t));
    if (!check_client_file(args[1]))
        create_log_user(&post, args[1], clients);
    else if (check_client_file(args[1])) {
        clients->user_name = strdup(strdup(args[1]));
        clients->user_uuid = strdup(check_client_file(args[1]));
        strcpy(post.user_name, strdup(args[1]));
        strcpy(post.user_uuid, check_client_file(args[1]));
        server_event_user_logged_in(check_client_file(args[1]));
    }
    call_all_users_login(clients);
    post.status = 200;
    strcpy(post.response, "login successful");
    write(clients->_client_fd, &post, sizeof(send_data_t));
}

void logout(send_data_t data, connected_client_t *clients)
{
    char **args = parse_str(strdup(data.msg), 1, 0);
    send_data_t post;

    if (error_logs(args, clients) == ERROR)
        return;
    memset(&post, 0, sizeof(send_data_t));
    server_event_user_logged_out(data.user_uuid);
    call_all_users_logout(clients);
    clients->user_name = NULL;
    clients->user_uuid = NULL;
    strcpy(post.user_name, "");
    strcpy(post.user_uuid, "");
    post.status = 302;
    strcpy(post.response, "logout successful");
    write(clients->_client_fd, &post, sizeof(send_data_t));
}