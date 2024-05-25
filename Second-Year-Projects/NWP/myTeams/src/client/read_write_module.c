/*
** EPITECH PROJECT, 2022
** my_teams
** File description:
** read_write_module
*/

#include "client.h"
#include "../../libs/myteams/logging_client.h"
#include "client_array.h"

int read_from_server(int sockfd, client_t *client)
{
    send_data_t get;
    int use = 0;

    memset(&get, 0, sizeof(send_data_t));
    get.status = -1;
    strcpy(get.response, " ");
    if (read(sockfd, &get, sizeof(send_data_t)) <= 0)
        return ERROR;
    for (int i = 0; i < 14; i++) {
        if (!strncmp(_commands[i].str, get.response, strlen(_commands[i].str))
        && (get.response[strlen(_commands[i].str)] == ' '
        || !get.response[strlen(_commands[i].str)])) {
            _commands[i].handler(get, client);
            use = 1;
            break;
        }
    }
    if (use == 0)
        printf("%d %s\n", get.status, get.response);
    return SUCCESS;
}

int send_to_server(int sockfd, client_t *client)
{
    send_data_t post;
    char *buffer;
    size_t size = 0;

    memset(&post, 0, sizeof(send_data_t));
    strcpy(post.user_name, client->to_send.user_name);
    strcpy(post.user_uuid, client->to_send.user_uuid);
    if (getline(&buffer, &size, stdin) == EOF)
        return ERROR;
    if (buffer == NULL)
        return ERROR;
    if (strlen(buffer) == 0) {
        free(buffer);
        return ERROR;
    }
    buffer[strlen(buffer) - 1] = '\0';
    strcpy(post.msg, buffer);
    write(sockfd, &post, sizeof(send_data_t));
    if (buffer != NULL)
        free(buffer);
    return SUCCESS;
}