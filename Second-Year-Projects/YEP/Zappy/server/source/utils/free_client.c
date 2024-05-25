/*
** EPITECH PROJECT, 2022
** server
** File description:
** free_client
*/

#include <stdio.h>
#include "server.h"

void free_client(client_t *client)
{
    fclose(client->file);
    free(client);
}
