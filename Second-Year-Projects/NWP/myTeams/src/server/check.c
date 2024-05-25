/*
** EPITECH PROJECT, 2022
** B-NWP-400-PAR-4-1-myteams-antoine.gavira-bottari
** File description:
** check
*/

#include <stdlib.h>
#include <string.h>
#include "../libs/myteams/logging_server.h"
#include "server.h"

void check_if_server_loaded(void)
{
    char *client_file = open_read_file(CLIENT_LIST_PATH);
    char **clients_array = NULL;
    char *user_name = malloc(sizeof(char) * 32);
    char *user_uuid = malloc(sizeof(char) * 37);

    if (!client_file || !client_file[0])
        return;
    clients_array = parse_str(client_file, 0, 1);
    for (int i = 0; clients_array[i]; i++) {
        strcpy(user_name, strdup(strsep(&clients_array[i], "]")) + 1);
        strcpy(user_uuid, strdup(clients_array[i]) + 1);
        server_event_user_loaded(user_uuid, user_name);
    }
    free(user_name);
    free(user_uuid);
    free(client_file);
    free(clients_array);
}