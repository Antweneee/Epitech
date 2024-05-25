/*
** EPITECH PROJECT, 2022
** B-PDG-300-PAR-3-1-PDGD04pm-antoine.gavira-bottari
** File description:
** queue_list2
*/

#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "stack.h"

void *queue_front(queue_t queue)
{
    if (queue_is_empty(queue)) {
        return NULL;
    }
    if (queue->next != NULL) {
        return queue->next->value;
    } else {
        return NULL;
    }
}