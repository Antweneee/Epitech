/*
** EPITECH PROJECT, 2022
** B-NWP-400-PAR-4-1-myftp-antoine.gavira-bottari
** File description:
** check_clients
*/

#include <string.h>
#include <stdio.h>
#include "myftp.h"

void checkreadable_client(client_t **head, socket_t *s_socket, int i)
{
    client_t *tmp = *head;
    char *ret_code = NULL;

    if (s_socket->_clients == NULL)
        return;
    for (; tmp; tmp = tmp->_next) {
        if (i == tmp->_client_fd) {
            ret_code = read_case(tmp, s_socket);
            if (strcmp(ret_code, "221\r\n") != 0)
                write(tmp->_client_fd, ret_code, strlen(ret_code));
        }
    }
}

int check_writable(socket_t *s_socket, fd_set *w_set, int i)
{
    int fd = 0;

    if (FD_ISSET(i, w_set)) {
        if (i == s_socket->_socket_fd) {
            fd = accept(i, (struct sockaddr *)\
                &s_socket->addrserver, &s_socket->_csize);
                write_case(s_socket, i);
        }
        if (fd == -1)
            return -1;
    }
    return 0;
}
