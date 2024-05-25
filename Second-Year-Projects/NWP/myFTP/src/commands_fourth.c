/*
** EPITECH PROJECT, 2022
** B-NWP-400-PAR-4-1-myftp-antoine.gavira-bottari
** File description:
** commands_fourth
*/

#include "myftp.h"

char *stor_handler(char *str, client_t *client, socket_t *s_socket)
{
    (void) str;
    (void) s_socket;
    if (client->_is_log == false)
        return "530\r\n";
    return "XXX\r\n";
}

char *list_handler(char *str, client_t *client, socket_t *s_socket)
{
    (void) str;
    (void) s_socket;
    if (client->_is_log == false)
        return "530\r\n";
    return "XXX\r\n";
}
