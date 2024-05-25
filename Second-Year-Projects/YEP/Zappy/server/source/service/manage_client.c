/*
** EPITECH PROJECT, 2022
** zappy_server
** File description:
** manage_client
*/

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "functions.h"
#include "constant.h"
#include "server.h"

static void delete_line(char *buffer)
{
    for (size_t i = 0; buffer[i] != '\0'; ++i) {
        if (buffer[i] == '\n')
            buffer[i] = '\0';
    }
}

static int delete_client(client_t *client, server_t *server)
{
    int fd = fileno(client->file);

    if (handle_disconnection(&server->teams, fd) == EXIT_FAILURE)
        return EXIT_FAILURE;
    if (epoll_ctl(server->events.epoll_fd, EPOLL_CTL_DEL, fd,
    NULL) == -1) {
        delete_gui(client, server);
        free_client(client);
        return EXIT_FAILURE;
    }
    delete_gui(client, server);
    free_client(client);
    return EXIT_SUCCESS;
}

int manage_operation_on_client(client_t *client, server_t *server,
map_t **map, bool read)
{
    char *lineptr = NULL;
    size_t n = 0;
    ssize_t rd = 0;

    if (client == NULL || client->file == NULL)
        return EXIT_FAILURE;
    client->read = read;
    if (read == false) {
        client->command = NULL;
        return command_server(client, server, map);
    }
    rd = getline(&lineptr, &n, client->file);
    if (rd == -1)
        return delete_client(client, server);
    delete_line(lineptr);
    client->command = split_str(lineptr, " ");
    if (client->command == NULL)
        return EXIT_FAILURE;
    if (client->command[0] == NULL)
        return EXIT_SUCCESS;
    dprintf(1, "Client: [%d] => [%s]\n", fileno(client->file), lineptr);
    return command_server(client, server, map);
}
