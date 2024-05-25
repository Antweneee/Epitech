/*
** EPITECH PROJECT, 2022
** B-NWP-400-PAR-4ERROR-myteams-antoine.gavira-bottari
** File description:
** engine
*/

#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <sys/select.h>
#include "server.h"


fd_set set_fdsets(server_t *s_server)
{
    FD_ZERO(&(s_server->_reset));
    FD_SET(s_server->_socket_fd, &(s_server->_reset));
    return s_server->_reset;
}

server_t *setup_struct(char const *port)
{
    server_t *fill = malloc(sizeof(server_t));

    if (!fill)
        return NULL;
    fill->_port = port;
    fill->_local_host = "127.0.0.1";
    fill->_socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (fill->_socket_fd == ERROR)
        return NULL;
    fill->addrserver.sin_addr.s_addr = inet_addr(fill->_local_host);
    fill->addrserver.sin_family = AF_INET;
    fill->addrserver.sin_port = htons(atoi(fill->_port));
    fill->_csize = sizeof(fill->addrserver);
    fill->_s_clients = NULL;
    return fill;
}

int server_setup(server_t *s_server)
{
    int checker = 0;

    checker = bind(s_server->_socket_fd, (const struct sockaddr *)
    &s_server->addrserver, sizeof(s_server->addrserver));
    if (checker == ERROR)
        return ERROR;
    checker = listen(s_server->_socket_fd, 1);
    if (checker == ERROR)
        return ERROR;
    return SUCCESS;
}

int init(char const *port)
{
    server_t *s_server = setup_struct(port);

    if (s_server == NULL)
        return ERROR;
    if (server_setup(s_server) == ERROR)
        return ERROR;
    s_server->_reset = set_fdsets(s_server);
    if (run(s_server) == ERROR)
        return ERROR;
    return SUCCESS;
}
