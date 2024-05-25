/*
** EPITECH PROJECT, 2022
** zappy_server
** File description:
** accept_client
*/

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"
#include "constant.h"
#include "server.h"

static bool setnonblocking(int socketfd)
{
    int set = fcntl(socketfd, F_SETFL,
        fcntl(socketfd, F_GETFL, 0) | O_NONBLOCK);

    if (set == -1)
        return false;
    return true;
}

static int create_client(epoll_data_t *data, server_t *server, int assign_fd)
{
    client_t *client = malloc(sizeof(client_t));

    if (client == NULL)
        return EXIT_FAILURE;
    memset(client, 0, sizeof(client_t));
    client->file = fdopen(assign_fd, "r+");
    if (client->file == NULL)
        return EXIT_FAILURE;
    client->type = UNDEFINED;
    client->command = NULL;
    client->player = NULL;
    client->connected = false;
    client->team_name = NULL;
    client->welcome = true;
    client->chrono = NULL;
    server->number_connected = server->number_connected + 1;
    data->ptr = client;
    return EXIT_SUCCESS;
}

int accept_client(server_t *server)
{
    int accept_fd = 0;
    struct sockaddr_in addr;
    socklen_t addrlen = sizeof(addr);
    struct epoll_event ev;

    accept_fd = accept(server->fd, (struct sockaddr *)&addr, &addrlen);
    if (accept_fd == -1)
        handle_error("accept()");
    if (setnonblocking(accept_fd) == false)
        handle_error("setnonblocking()");
    ev.events = EPOLLIN | EPOLLET | EPOLLOUT;
    if (create_client(&ev.data, server, accept_fd) == EXIT_FAILURE)
        handle_error("create client()");
    if (epoll_ctl(server->events.epoll_fd, EPOLL_CTL_ADD, accept_fd,
    &ev) == -1)
        handle_error("epoll_ctl()");
    dprintf(1, "fd %ptr Client [%d] on IP => [%s]\n", ev.data.ptr
    , ntohs(addr.sin_port), inet_ntoa(addr.sin_addr));
    return EXIT_SUCCESS;
}
