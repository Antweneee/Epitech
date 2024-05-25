/*
** EPITECH PROJECT, 2022
** server
** File description:
** gui_listening
*/

#include <stdio.h>
#include "server.h"

int gui_write(server_t *server)
{
    int fd;
    linked_client_t *parse;
    struct epoll_event ev;

    if (server == NULL)
        return EXIT_FAILURE;
    for (parse = server->data_gui; parse != NULL; parse = parse->next)
    {
        if (parse->client == NULL || parse->client->file == NULL)
            return EXIT_FAILURE;
        fd = fileno(parse->client->file);
        ev.data.ptr = parse->client;
        ev.events = EPOLLIN | EPOLLET | EPOLLOUT;
        if (epoll_ctl(server->events.epoll_fd, EPOLL_CTL_MOD, fd, &ev) == -1)
                return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}