/*
** EPITECH PROJECT, 2022
** server
** File description:
** add_gui
*/

#include "server.h"

int add_gui(client_t *client, server_t *server)
{
    linked_client_t *parse;
    linked_client_t *new;

    if (client == NULL || server == NULL)
        return EXIT_SUCCESS;
    new = malloc(sizeof(linked_client_t));
    if (new == NULL)
        return EXIT_FAILURE;
    new->client = client;
    new->next = NULL;
    if (server->data_gui == NULL) {
        server->data_gui = new;
        return EXIT_SUCCESS;
    }
    for (parse = server->data_gui; parse->next != NULL; parse = parse->next);
    parse->next = new;
    return EXIT_SUCCESS;
}