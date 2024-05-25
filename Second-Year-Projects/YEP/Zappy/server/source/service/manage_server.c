/*
** EPITECH PROJECT, 2022
** zappy_server
** File description:
** manage_server
*/

#include <stdbool.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>
#include "functions.h"
#include "constant.h"
#include "server.h"

static void sig_handler(__ATTRIBUTE_UNUSED__ int _)
{
    keep_running = false;
}

static int number_file_descriptor(server_t *server, int nfds, map_t **map)
{
    int exit_value = 0;

    for (int i = 0; i < nfds; i += 1) {
        exit_value = server->events.events[i].data.fd == server->fd
        ? accept_client(server)
        : manage_operation_on_client(server->events.events[i].data.ptr,
        server, map, server->events.events[i].events & EPOLLIN);
        if (exit_value == EXIT_FAILURE)
            return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

static int init_server(server_t *server)
{
    struct epoll_event ev;

    server->events.epoll_fd = epoll_create1(0);
    if (server->events.epoll_fd == -1)
        handle_error("epoll_create1()");
    ev.events = EPOLLIN;
    ev.data.fd = server->fd;
    if (epoll_ctl(server->events.epoll_fd, EPOLL_CTL_ADD, server->fd,
                  &ev) == -1)
        handle_error("epoll_ctl()");
    return EXIT_SUCCESS;
}

static int dead_client(client_t *client, server_t *server)
{
    if (set_writable(client, server) == EXIT_FAILURE)
        return EXIT_FAILURE;
    return message_chrono(client, "dead\n", 0);
}

static int diminue_eat(server_t *server)
{
    teams_t *teams = server->teams;
    int to_return = EXIT_SUCCESS;

    if (teams == NULL)
        return EXIT_SUCCESS;
    for (; teams != NULL; teams = teams->next)
        for (linked_client_t *linked = teams->clients; linked != NULL; linked = linked->next) {
            if (linked->client == NULL || linked->client->player == NULL )
                continue;
            linked->client->player->inventory.food -= 1;
            if (linked->client->player->inventory.food <= 0) {
                if (dead_client(linked->client, server) == EXIT_FAILURE)
                    return EXIT_FAILURE;
                to_return = -1;
            }
        }
    return to_return;
}

static int handle_server_loop(server_t *server, map_t **map)
{
    int nfds = 0;
    int diminue = 0;

    while (keep_running) {
        nfds = epoll_wait(server->events.epoll_fd, server->events.events,
            MAX_EVENTS, (126 / server->info_server.freq) * 1000);
        if (nfds == 0) {
            printf("%d\n", nfds);
            diminue = diminue_eat(server);
            if (diminue == EXIT_FAILURE)
                return EXIT_FAILURE;
            if (diminue == -1)
                continue;
        }
        if (!keep_running)
            break;
        if (nfds == -1)
            handle_error("epoll_wait()");
        if (number_file_descriptor(server, nfds, map) == EXIT_FAILURE)
            return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

int manage_server(server_t *server)
{
    map_t **map;

    if (init_server(server) == EXIT_FAILURE)
        return EXIT_FAILURE;
    map = create_map(&server->info_server, &server->base_inventory.base);
    if (map == NULL)
        return EXIT_FAILURE;
    server->base_inventory.inventory = server->base_inventory.base;
    if (signal(SIGINT, sig_handler) == SIG_ERR)
        handle_error("signal()");
    if (handle_server_loop(server, map) == EXIT_FAILURE)
        return EXIT_FAILURE;
    return EXIT_SUCCESS;
}
