/*
** EPITECH PROJECT, 2022
** B-NWP-400-PAR-4-1-myteams-antoine.gavira-bottari
** File description:
** run
*/

#include "client.h"
#include <signal.h>

char *clear_getline(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '\n') {
            str[i] = '\0';
            break;
        }
    }
    return str;
}

int connect_client(client_t *c_socket)
{
    if (connect(c_socket->_socket_fd, (const struct sockaddr *)\
        &c_socket->addrserver, c_socket->_csize) == -1)
        return -1;
    return 0;
}

int message_part(client_t *c_socket, char *str)
{
    send_data_t post;

    memset(&post, 0, sizeof(send_data_t));
    str = clear_getline(str);
    strcpy(post.msg, str);
    write(c_socket->_socket_fd, &post, sizeof(send_data_t));
    return 0;
}

static int run_client(client_t *c_socket)
{
    fd_set current_socket;

    FD_SET(c_socket->_socket_fd, &current_socket);
    while (1) {
        FD_ZERO(&current_socket);
        FD_SET(STDIN_FILENO, &current_socket);
        FD_SET(c_socket->_socket_fd, &current_socket);
        if (select(FD_SETSIZE, &current_socket, NULL, NULL, NULL) == -1)
            return ERROR;
        if (FD_ISSET(c_socket->_socket_fd, &current_socket)
            && read_from_server(c_socket->_socket_fd, c_socket) == -1)
            break;
        if (FD_ISSET(0, &current_socket)
            && send_to_server(c_socket->_socket_fd, c_socket) == ERROR)
            break;
    }
    c_free_struct(c_socket);
    return 0;
}

int init_client(char const *ip, char const *port)
{
    client_t *c_socket = malloc(sizeof(client_t));

    if (c_init_struct(c_socket, ip, port) == -1)
        return 84;
    if (connect_client(c_socket) == -1)
        return 84;
    if (run_client(c_socket))
        return 84;
    return 0;
}