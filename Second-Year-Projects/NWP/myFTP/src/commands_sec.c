/*
** EPITECH PROJECT, 2022
** B-NWP-400-PAR-4-1-myftp-antoine.gavira-bottari
** File description:
** more_commands
*/

#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include "myftp.h"

char *cwd_handler(char *str, client_t *client, socket_t *s_socket)
{
    struct stat check = {0};

    (void) s_socket;
    if (client->_is_log == false)
        return "530\r\n";
    stat(str, &check);
    if (S_ISDIR(check.st_mode)) {
        free(client->_path);
        client->_path = strdup(str);
        return "250\r\n";
    }
    return "550\r\n";
}

char *cdup_handler(char *str, client_t *client, socket_t *s_socket)
{
    (void) str;
    (void) s_socket;
    if (client->_is_log == false)
        return "530\r\n";
    return "200\r\n";
}

char *quit_handler(char *str, client_t *client, socket_t *s_socket)
{
    (void) str;
    (void) s_socket;
    client->_is_log = false;
    client->_username = NULL;
    client->_pass = NULL;
    write(client->_client_fd, "221\r\n", strlen("221\r\n"));
    FD_CLR(client->_client_fd, &(s_socket->_reset));
    delete_client(&(s_socket->_clients), client->_client_fd);
    return "221\r\n";
}

char *dele_handler(char *str, client_t *client, socket_t *s_socket)
{
    (void) str;
    (void) s_socket;
    if (client->_is_log == false)
        return "530\r\n";
    return "XXX\r\n";
}

char *pwd_handler(char *str, client_t *client, socket_t *s_socket)
{
    (void) str;
    (void) s_socket;
    write(client->_client_fd, client->_path, strlen(client->_path));
    return "257\r\n";
}
