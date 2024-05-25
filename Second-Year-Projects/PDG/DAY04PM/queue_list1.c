/*
** EPITECH PROJECT, 2022
** B-PDG-300-PAR-3-1-PDGD04pm-antoine.gavira-bottari
** File description:
** queue_list
*/

#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "stack.h"

unsigned int queue_get_size(queue_t queue)
{
    unsigned int nb = 0;

    for (; queue != NULL; queue = queue->next)
        nb++;
    return nb;
}

bool queue_is_empty(queue_t queue)
{
    if (queue == NULL)
        return true;
    return false;
}

bool queue_push(queue_t *queue_ptr, void *elem)
{
    queue_t new_node = malloc(sizeof(node_t));

    if (!new_node)
        return false;
    new_node->value = elem;
    new_node->next = *queue_ptr;
    *queue_ptr = new_node;
    return true;
}

bool queue_pop(queue_t *queue_ptr)
{
    queue_t current = *queue_ptr;

    if (queue_is_empty(*queue_ptr))
        return false;
    if (queue_get_size(*queue_ptr) == 1)
        current = NULL;
    for (; current->next->next != NULL; current = current->next);
    free(current->next);
    current->next = NULL;
    return true;
}

void queue_clear(queue_t *queue_ptr)
{
    queue_t current = *queue_ptr;
    queue_t next = NULL;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    *queue_ptr = NULL;
}