/*
** EPITECH PROJECT, 2022
** B-NWP-400-PAR-4-1-myftp-antoine.gavira-bottari
** File description:
** init
*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "myftp.h"

int s_init_struct(socket_t *s_socket, char const *port, char const *path)
{
    s_socket->_port = strdup(port);
    s_socket->_server_path = strdup(path);
    s_socket->_local_host = "127.0.0.1";
    s_socket->_socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (s_socket->_socket_fd == -1)
        return -1;
    s_socket->addrserver.sin_addr.s_addr = inet_addr(s_socket->_local_host);
    s_socket->addrserver.sin_family = AF_INET;
    s_socket->addrserver.sin_port = htons(atoi(s_socket->_port));
    s_socket->_csize = sizeof(s_socket->addrserver);
    s_socket->_is_log = false;
    s_socket->_clients = NULL;
    return 0;
}

void s_free_struct(socket_t *s_socket)
{
    close(s_socket->_socket_fd);
    free(s_socket->_server_path);
    free(s_socket->_port);
    free(s_socket);
}

