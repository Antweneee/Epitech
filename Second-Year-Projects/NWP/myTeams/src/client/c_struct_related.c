/*
** EPITECH PROJECT, 2022
** B-NWP-400-PAR-4-1-myftp-antoine.gavira-bottari
** File description:
** c_struct_related
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "client.h"

int c_init_struct(client_t *c_socket, char const *ip, char const *port)
{
    c_socket->_socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (c_socket->_socket_fd == ERROR)
        return ERROR;
    c_socket->addrserver.sin_addr.s_addr = inet_addr(ip);
    c_socket->addrserver.sin_family = AF_INET;
    c_socket->addrserver.sin_port = htons(atoi(port));
    c_socket->_ip = inet_ntoa(c_socket->addrserver.sin_addr);
    c_socket->_csize = sizeof(c_socket->addrserver);
    memset(&c_socket->to_send, 0, sizeof(send_data_t));
    return SUCCESS;
}

void c_free_struct(client_t *c_socket)
{
    if (c_socket != NULL) {
        close(c_socket->_socket_fd);
        free(c_socket);
    }
}