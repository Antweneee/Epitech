/*
** EPITECH PROJECT, 2022
** B-YEP-410-PAR-4-1-zappy-thomas.willson
** File description:
** shit_queued
*/

#include "ai_info.h"
#include "socket_info.h"
#include <string.h>

/**
 * @brief shift_element in the queue after each write
 * 
 * @param ai 
 */
void shift_element(struct ai_info *ai)
{
    if (ai->buf->incoming_message[0] == NULL)
        return;
    memcpy(ai->buf->incoming_message, &ai->buf->incoming_message[1], ((ai->buf->nb_messages) * sizeof(char*)));
}