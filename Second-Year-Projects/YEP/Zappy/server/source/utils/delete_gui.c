/*
** EPITECH PROJECT, 2022
** server
** File description:
** delete_gui
*/

#include <string.h>
#include "server.h"

static int handle_first_delete(server_t *server)
{
    linked_client_t *to_free = server->data_gui;

    server->data_gui = server->data_gui->next;
    free(to_free);
    return EXIT_SUCCESS;
}

int delete_gui(client_t *client, server_t *server)
{
    linked_client_t *to_free = NULL;

    if (client == NULL || server == NULL || server->data_gui == NULL)
        return EXIT_FAILURE;
    if (client->type != GUI)
        return EXIT_SUCCESS;
    if (server->data_gui->client == client)
        return handle_first_delete(server);
    for (linked_client_t *parse = server->data_gui; parse->next != NULL
    ; parse = parse->next) {
        if (parse->next->client == client) {
            to_free = parse->next;
            parse->next = parse->next->next;
            break;
        }
    }
    if (to_free != NULL)
        free(to_free);
    return EXIT_SUCCESS;
}