/*
** EPITECH PROJECT, 2022
** B-NWP-400-PAR-4-1-myftp-antoine.gavira-bottari
** File description:
** engine
*/

#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "myftp.h"

fd_set set_fdsets(socket_t *s_socket)
{
    FD_ZERO(&(s_socket->_reset));
    FD_SET(s_socket->_socket_fd, &(s_socket->_reset));
    return s_socket->_reset;
}

int get_rightaccept(socket_t *s_socket)
{
    int fd = 0;

    for (int i = 0; i < FD_SETSIZE; i++ ) {
        if (FD_ISSET(i, &(s_socket->_r_set))) {
            if (i == s_socket->_socket_fd) {
                fd = accept(i, (struct sockaddr *) &s_socket->addrserver, &s_socket->_csize);
                new_client(&(s_socket->_clients), fd, s_socket->_server_path);
                FD_SET(fd, &(s_socket->_reset));
                write(fd, "220\r\n", 5);
            } else {
                checkreadable_client(&(s_socket->_clients), s_socket, i);
            }
        }
    }
    if (fd == -1)
        return -1;
    return 0;
}

int loop(socket_t *s_socket)
{
    int code = 1;
    int checker = 0;
    s_socket->_reset = set_fdsets(s_socket);

    while (code) {
        s_socket->_w_set = s_socket->_reset;
        s_socket->_r_set = s_socket->_reset;
        checker = select(FD_SETSIZE, &(s_socket->_r_set), &(s_socket->_w_set)\
            , NULL, NULL);
        if (checker == -1) {
            perror("select");
            return -1;
        }
        checker = get_rightaccept(s_socket);
        if (checker == -1)
            return -1;
    }
    return code;
}

int setup_server(socket_t *s_socket)
{
    int checker = 0;

    checker = bind(s_socket->_socket_fd, (const struct sockaddr *)\
        &s_socket->addrserver, sizeof(s_socket->addrserver));
    if (checker == -1) {
        perror("bind");
        return -1;
    }
    checker = listen(s_socket->_socket_fd, 1);
    if (checker == -1) {
        perror("listen");
        return -1;
    }
    return 0;
}

int server_engine(char const *port, char const *path)
{
    socket_t *s_socket = malloc(sizeof(socket_t));
    int checker = 0;

    checker = s_init_struct(s_socket, port, path);
    if (checker == -1)
        return 84;
    if (setup_server(s_socket) == -1)
        return 84;
    if (loop(s_socket) == -1)
        return 84;
    s_free_struct(s_socket);
    return 0;
}