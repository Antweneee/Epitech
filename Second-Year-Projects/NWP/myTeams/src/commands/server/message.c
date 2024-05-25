/*
** EPITECH PROJECT, 2022
** B-NWP-400-PAR-4-1-myteams-antoine.gavira-bottari
** File description:
** message
*/

#include <stdio.h>
#include <time.h>
#include "client.h"
#include "server_commands.h"
#include "../libs/myteams/logging_server.h"
#include "server.h"

void write_in_conversation(char *filename, char *uuid, char *message)
{
    time_t timestamp = time(NULL);
    FILE *file = fopen(filename, "a+");
    char *user_message = malloc(sizeof(char) *
    (strlen(uuid) + 1 + strlen(message) + 1));

    strcpy(user_message, strdup(uuid));
    user_message = strcat(user_message, ":");
    strcat(user_message, message);
    if (!open_read_file(filename)[0]) {
        fprintf(file, "%s[%ld]", user_message, timestamp);
    } else
        fprintf(file, "\n%s[%ld]", user_message, timestamp);
    fclose(file);
}

static char *errors_message(char *uuid, char *text, char *context)
{
    char *error = malloc(sizeof(char) * SIZE);

    if (!error)
        return "";
    strcpy(error, text);
    strcat(error, strdup(uuid));
    if (context != NULL)
        strcat(error, context);
    return error;
}

char *check_filenames(char *uuid1, char *uuid2)
{
    char *tmp = malloc(sizeof(char) * SIZE);

    strcpy(tmp , strdup("conf/"));
    tmp = strcat(tmp, strdup(uuid1));
    strcat(tmp, "_");
    strcat(tmp, strdup(uuid2));
    if (open_fd(tmp) != -1)
        return tmp;
    else {
        free(tmp);
        tmp = malloc(sizeof(char) * SIZE);
        strcpy(tmp , strdup("conf/"));
        tmp = strcat(tmp, strdup(uuid2));
        strcat(tmp, "_");
        strcat(tmp, strdup(uuid1));
    }
    return tmp;
}

void send_messages(connected_client_t *client, char *message, char *uuid1)
{
    send_data_t post;
    char *send_message = " with message:";
    char *error_msg = NULL;

    memset(&post, 0, sizeof(send_data_t));
    post.status = 210;
    error_msg = errors_message(uuid1, "send from ", NULL);
    strcat(error_msg, send_message);
    strcat(error_msg, message);
    strcpy(post.response, error_msg);
    write(client->_client_fd, &post, sizeof(send_data_t));
}

void create_conversation(char *uuid1, char *uuid2, char *message, \
connected_client_t *clients)
{
    char *filename = check_filenames(uuid1, uuid2);
    connected_client_t *tmp = clients;

    write_in_conversation(filename, uuid1, message);
    if (tmp->_prev) {
        for (; tmp->_prev; tmp = tmp->_prev);
        if (tmp->_prev)
            tmp = tmp->_prev;
    }
    for (; tmp; tmp = tmp->_next) {
        if (tmp->user_uuid && strcmp(tmp->user_uuid, uuid2) == 0) {
            send_messages(tmp, message, uuid1);
            break;
        }
    }
}

int check_uuid(char *filepath, char *uuid)
{
    char *tmp = open_read_file(filepath);
    char **args = parse_str(tmp, 1, 1);

    for (int i = 0; args[i]; i++)
        if (strcmp(args[i], uuid) == 0)
            return 1;
    return -1;
}

void my_send(send_data_t data, connected_client_t *clients)
{
    send_data_t post;
    char **args = parse_args(strdup(data.msg));
    char *error_msg = NULL;

    memset(&post, 0, sizeof(send_data_t));
    if (clients->user_uuid == NULL) {
        post.status = 406;
        strcpy(post.response, "Not logged in");
        write(clients->_client_fd, &post, sizeof(send_data_t));
        return;
    }
    if (!args[1] || !args[2]) {
        post.status = 405;
        strcpy(post.response, "Too many arguments");
    } else if (check_uuid("conf/client_list", args[1]) == -1) {
        post.status = 404;
        error_msg = errors_message(args[1], "send user", " not found");
        strcpy(post.response, error_msg);
    } else {
        create_conversation(data.user_uuid, args[1], args[2], clients);
        post.status = 204;
        error_msg = errors_message(args[1], "send to ", NULL);
        strcpy(post.response, error_msg);
        server_event_private_message_sended(data.user_uuid, args[1], args[2]);
    }
    write(clients->_client_fd, &post, sizeof(send_data_t));
}

void messages(send_data_t data, connected_client_t *clients)
{
    send_data_t post;
    char **args = parse_args(strdup(data.msg));
    char *file_content = NULL;
    char *filepath = check_filenames(data.user_uuid, args[1]);
    char *error_msg = NULL;

    memset(&post, 0, sizeof(send_data_t));
    if (clients->user_uuid == NULL) {
        post.status = 406;
        strcpy(post.response, "Not logged in");
        write(clients->_client_fd, &post, sizeof(send_data_t));
        return;
    }
    if (check_uuid("conf/client_list", args[1]) == -1) {
        post.status = 404;
        error_msg = errors_message(args[1], "messages of ", " does not exist");
        strcpy(post.response, error_msg);
    } else if (open_read_file(filepath) == NULL) {
        post.status = 401;
        strcpy(post.response, "Unauthorized can't see other's conversation");
    } else if (args[1]) {
        file_content = open_read_file(filepath);
        post.status = 205;
        char *send = malloc(sizeof(char) * (strlen(file_content) + 20));
        strcpy(send, "messages \n");
        strcat(send, strdup(file_content));
        printf("%s\n", send);
        strcpy(post.response, send);
    } else {
        post.status = 405;
        strcpy(post.response, "Too many arguments");
    }
    write(clients->_client_fd, &post, sizeof(send_data_t));
}