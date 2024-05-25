/*
** EPITECH PROJECT, 2022
** B-YEP-410-PAR-4-1-zappy-thomas.willson
** File description:
** update_look_and_inventory
*/

#include "ai_info.h"
#include "define.h"
#include <string.h>

/**
 * @brief update the look and inventory by pushing LOOK and INVENTORY
 * into the queue
 * 
 * @param ai 
 * @return void
 */
void update_look_and_inventory(struct ai_info * ai)
{
    ai->buf->incoming_message[ai->buf->nb_messages++] = strdup(LOOK);
    ai->buf->incoming_message[ai->buf->nb_messages++] = strdup(INVENTORY);
}