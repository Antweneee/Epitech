/*
** EPITECH PROJECT, 2022
** server
** File description:
** style_writing
*/

#include "server.h"

int writing_default(client_t *client, chrono_buffer_t *message)
{
    if (dprintf(fileno(client->file), "%s", message->buffer) == -1)
        return EXIT_FAILURE;
    return EXIT_SUCCESS;
}

int writing_inventory(client_t *client
, __ATTRIBUTE_UNUSED__ chrono_buffer_t *message)
{
    inventory_t *inventory;

    if (client->player == NULL)
        return EXIT_SUCCESS;
    inventory = &client->player->inventory;
    if (dprintf(fileno(client->file) , INVENTORY_FORMAT,
    inventory->food, inventory->linemate, inventory->deraumere
    , inventory->sibur, inventory->mendiane
    , inventory->phiras, inventory->thystame) == -1)
        return EXIT_FAILURE;
    return EXIT_SUCCESS;
}