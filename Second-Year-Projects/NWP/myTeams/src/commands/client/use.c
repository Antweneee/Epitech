/*
** EPITECH PROJECT, 2022
** B-NWP-400-PAR-4-1-myteams-antoine.gavira-bottari
** File description:
** use
*/

#include <stdio.h>
#include "client_commands.h"
#include "client.h"
#include "../libs/myteams/logging_client.h"

void use(send_data_t data, client_t *clients)
{
    char *tmp = malloc(sizeof(char) * SIZE);

    if (data.status == 401) {
        client_error_unauthorized();
        free(tmp);
        return;
    }
    if (data.status == 300)
        strcpy(tmp, "use");
    else if (data.status == 310 || data.status == 320 || data.status == 330)
        strcpy(tmp, data.response + 4);
    strcpy(clients->to_send.use, tmp);
    free(tmp);
}