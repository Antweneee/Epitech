/*
** EPITECH PROJECT, 2022
** B-YEP-410-PAR-4-1-zappy-thomas.willson
** File description:
** socket_info
*/

#ifndef SOCKET_INFO_H_
    #define SOCKET_INFO_H_
    #include <stdint.h>
    #include <sys/types.h>
    #include <sys/socket.h>
    #include <arpa/inet.h>
    #include <sys/select.h>

struct socket_info {
    int client_fd;
    int port;
    char ip[8];
    struct sockaddr_in servaddr;
    fd_set set_read;
    fd_set set_write;
    fd_set set_exeption;
};

#endif /* !SOCKET_INFO_H_ */
