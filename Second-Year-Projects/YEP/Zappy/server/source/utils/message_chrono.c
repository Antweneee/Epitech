/*
** EPITECH PROJECT, 2022
** server
** File description:
** message_chrono
*/

#include <string.h>
#include <time.h>
#include <stdio.h>
#include "command.h"
#include "functions.h"
#include "server.h"

static const style_writing_t writing[] = {
    [STANDARD] = {writing_default},
    [INVENTORY] = {writing_inventory}
};

int message_chrono(client_t *client, const char *message, float delay)
{
    chrono_buffer_t *last;

    if (client == NULL)
        return EXIT_FAILURE;
    last = add_chrono(client, message);
    if (last == NULL)
        return EXIT_FAILURE;
    last->type = STANDARD;
    last->time = time(NULL);
    last->stop = delay;
    return EXIT_SUCCESS;
}

int message_chrono_style(client_t *client, const char *message, float delay
, message_e style)
{
    chrono_buffer_t *last;

    if (client == NULL)
        return EXIT_FAILURE;
    last = add_chrono(client, message);
    if (last == NULL)
        return EXIT_FAILURE;
    last->type = style;
    last->time = time(NULL);
    last->stop = delay;
    return EXIT_SUCCESS;
}

int write_chrono(client_t *client)
{
    chrono_buffer_t *parse;

    for (parse = client->chrono; parse != NULL; parse = parse->next) {
        if (parse->stop <= time(NULL) - parse->time) {
            if (writing[parse->type].function(client, parse) == EXIT_FAILURE)
                return EXIT_FAILURE;
            if (delete_chrono(client, parse) == EXIT_FAILURE)
                return EXIT_FAILURE;
            return EXIT_SUCCESS;
        }
    }
    return EXIT_SUCCESS;
}