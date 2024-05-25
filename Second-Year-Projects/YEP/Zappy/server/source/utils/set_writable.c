/*
** EPITECH PROJECT, 2022
** server
** File description:
** set_writable
*/

#include "server.h"

int set_writable(client_t *client, server_t *server)
{
    int fd;
    struct epoll_event ev;

    if (client == NULL || server == NULL)
        return EXIT_FAILURE;
    fd = fileno(client->file);
    ev.data.ptr = client;
    ev.events = EPOLLIN | EPOLLET | EPOLLOUT;
    if (epoll_ctl(server->events.epoll_fd, EPOLL_CTL_MOD, fd, &ev) == -1)
        return EXIT_FAILURE;
    return EXIT_SUCCESS;
}