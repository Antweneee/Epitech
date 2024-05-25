/*
** EPITECH PROJECT, 2022
** B-YEP-410-PAR-4-1-zappy-thomas.willson
** File description:
** help
*/

#include <string.h>
#include "server.h"
#include "functions.h"

int help_ai(client_t *client, server_t *server,
__ATTRIBUTE_UNUSED__ map_t **map)
{
    if (set_writable(client, server) == EXIT_FAILURE)
        return EXIT_FAILURE;
    if (message_chrono(client, "HELP FOR AI SEROUISLY? BRO ITS NOT THAT HARD\n"
    , 1) == EXIT_FAILURE)
        return EXIT_FAILURE;
    return EXIT_SUCCESS;
}