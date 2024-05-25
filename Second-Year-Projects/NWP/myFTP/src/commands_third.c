/*
** EPITECH PROJECT, 2022
** B-NWP-400-PAR-4-1-myftp-antoine.gavira-bottari
** File description:
** commands_third
*/

#include "myftp.h"

char *pasv_handler(char *str, client_t *client, socket_t *s_socket)
{
    (void) str;
    (void) s_socket;
    if (client->_is_log == false)
        return "530\r\n";
    return "227\r\n";
}

char *port_handler(char *str, client_t *client, socket_t *s_socket)
{
    (void) str;
    (void) s_socket;
    if (client->_is_log == false)
        return "530\r\n";
    return "200\r\n";
}

char *help_handler(char *str, client_t *client, socket_t *s_socket)
{
    (void) str;
    (void) client;
    (void) s_socket;
    return "214\r\n";
}

char *noop_handler(char *str, client_t *client, socket_t *s_socket)
{
    (void) str;
    (void) s_socket;
    if (client->_is_log == false)
        return "530\r\n";
    return "200\r\n";
}

char *retr_handler(char *str, client_t *client, socket_t *s_socket)
{
    (void) str;
    (void) s_socket;
    if (client->_is_log == false)
        return "530\r\n";
    return "XXX\r\n";
}
