/*
** EPITECH PROJECT, 2022
** server
** File description:
** handling_chrono
*/

#include <string.h>
#include <time.h>
#include <stdio.h>
#include "command.h"
#include "functions.h"
#include "server.h"

chrono_buffer_t *init_new(const char *message)
{
    chrono_buffer_t *last = malloc(sizeof(chrono_buffer_t));

    if (last == NULL)
        return NULL;
    last->buffer = strdup(message);
    if (last->buffer == NULL)
        return NULL;
    last->next = NULL;
    return last;
}

chrono_buffer_t *add_chrono(client_t *client, const char *message)
{
    chrono_buffer_t *parse;
    chrono_buffer_t *last;

    if (client == NULL)
        return NULL;
    last = init_new(message);
    if (last == NULL)
        return NULL;
    if (client->chrono == NULL)
    {
        client->chrono = last;
        return last;
    }
    for (parse = client->chrono; parse->next != NULL; parse = parse->next)
        ;
    parse->next = last;
    return last;
}

int delete_chrono(client_t *client, chrono_buffer_t *del)
{
    chrono_buffer_t *parse;

    if (client == NULL || del == NULL)
        return EXIT_FAILURE;
    if (client->chrono == del)
    {
        client->chrono = client->chrono->next;
        if (del->buffer != NULL)
            free(del->buffer);
        free(del);
        return EXIT_SUCCESS;
    }
    for (parse = client->chrono; parse->next != NULL; parse = parse->next)
    {
        if (parse->next == del)
        {
            parse->next = parse->next->next;
            if (del->buffer != NULL)
                free(del->buffer);
            free(del);
            return EXIT_SUCCESS;
        }
    }
    return EXIT_SUCCESS;
}