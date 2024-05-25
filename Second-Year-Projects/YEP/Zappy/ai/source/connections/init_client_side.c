/*
** EPITECH PROJECT, 2022
** B-YEP-410-PAR-4-1-zappy-thomas.willson
** File description:
** init_client_side
*/

#include "socket_info.h"
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <stdlib.h>

/**
 * @brief init the client socket and return it
 * 
 * @return the actual socket, in case of error this return -1
 */
int init_socket(void)
{
    int sock = 0;

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("socket:");
        return (-1);
    }
    return (sock);
}

/**
 * @brief init the struct sockaddr_in to have the good info for the client
 * 
 * @param port to connect to the server
 * @param ip of the server to connect
 * @return struct sockaddr_in is the struct that will contain client socket info
 */
struct sockaddr_in init_sock_struct(uint32_t port, const char* ip)
{
    struct sockaddr_in addr = { 0 };

    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr(ip);
    addr.sin_port = htons(port);

    return (addr);
}

/**
 * @brief 
 * 
 * @param socket to connect to catch the connection to the server
 * @param servaddr coorespond to the serveraddr of the struct sockaddr_in and fill info like port and ip
 * @return 0 on success and 1 on failure
 */
int connect_to_server(int socket, struct sockaddr_in servaddr)
{
    if (connect(socket, (struct sockaddr*)&servaddr, sizeof(servaddr)) == -1) {
        perror("connect:");
        return (EXIT_FAILURE);
    }
    return (EXIT_SUCCESS);
}

/**
 * @brief init the struct socket_info structure and fill it with argv data
 * 
 * @param port correspond to the server port number
 * @param ip correspond to the server ip address
 * @return struct socket_info 
 */
struct socket_info init_socket_info(int port, const char* ip)
{
    struct socket_info info = { 0 };

    info.client_fd = init_socket();
    if (info.client_fd == -1)
        return (info);
    info.port = port;
    strcpy(info.ip, ip);
    info.servaddr = init_sock_struct(port, ip);

    return (info);
}