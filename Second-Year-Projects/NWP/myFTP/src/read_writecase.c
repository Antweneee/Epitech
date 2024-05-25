/*
** EPITECH PROJECT, 2022
** B-NWP-400-PAR-4-1-myftp-antoine.gavira-bottari
** File description:
** read_writecase
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "myftp.h"

int write_case(socket_t *s_socket, int client_fd)
{
    (void) s_socket;
    write(client_fd, "220", strlen("220"));
    return 1;
}

char *read_case(client_t *client, socket_t *s_socket)
{
    char buffer[1024];
    size_t len = 0;
    char *ret_code = "220\r\n";

    len = read(client->_client_fd, buffer, sizeof(buffer));
    buffer[len] = '\0';
    if (len <= 0)
        exit(84);
    for (size_t i = 0; i < strlen(buffer); i++) {
        if (buffer[i] == '\n')
            buffer[i] = '\0';
    }
    ret_code = command_handler(buffer, s_socket, client);
    return ret_code;
}