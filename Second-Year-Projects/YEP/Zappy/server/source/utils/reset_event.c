/*
** EPITECH PROJECT, 2022
** server
** File description:
** reset_event
*/

#include <stdio.h>
#include "server.h"

int reset_ev(client_t *client, server_t *server)
{
    struct epoll_event ev;
    int fd;
    
    if (client == NULL)
        return EXIT_FAILURE;
    fd = fileno(client->file);
    ev.events = EPOLLIN | EPOLLET;
    ev.data.ptr = client;
    if (epoll_ctl(server->events.epoll_fd, EPOLL_CTL_MOD, fd, &ev) == -1)
        return EXIT_FAILURE;
    return EXIT_SUCCESS;
}