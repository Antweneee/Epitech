/*
** EPITECH PROJECT, 2022
** B-NWP-400-PAR-4-1-myftp-antoine.gavira-bottari
** File description:
** commands
*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "commands.h"
#include "myftp.h"

bool check_log(client_t *client)
{
    int cond = 0;

    if (client->_username == NULL)
        return false;
    if (strcmp(client->_username, "Anonymous") == 0)
        cond++;
    if (client->_pass == NULL)
        cond++;
    if (cond == 2)
        return true;
    return false;
}

char *user_handler(char *str, client_t *client, socket_t *s_socket)
{
    (void) s_socket;
    client->_is_log = false;
    if (client->_username)
        free(client->_username);
    client->_username = strdup(str);
    return "331\r\n";
}

char *password_handler(char *str, client_t *client, socket_t *s_socket)
{
    bool checker = false;

    (void) s_socket;
    client->_pass = str;
    checker = check_log(client);
    if (checker == false) {
        client->_username = NULL;
        client->_pass = NULL;
        return "332\r\n";
    }
    client->_is_log = checker;
    return "230\r\n";
}

char **check_cmd(char **parsed)
{
    for (int i = 0; parsed[i] != NULL; i++) {
        if(strlen(parsed[i]) == 0)
            parsed[i] = NULL;
    }
    return parsed;
}

char *command_handler(char *str, socket_t *s_socket, client_t *client)
{
    (void) s_socket;
    char *ret = "220\r\n";
    char **parsed = turn_to_array(str, ' ');

    parsed = check_cmd(parsed);
    for (int i = 0; i < 13; i++) {
        if (strcmp(parsed[0], _commands[i].str) == 0)
            ret = _commands[i].handler(parsed[1], client, s_socket);
    }
    free_tab(parsed);
    return ret;
}