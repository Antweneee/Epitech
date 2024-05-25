/*
** EPITECH PROJECT, 2022
** B-PDG-300-PAR-3-1-PDGD04pm-antoine.gavira-bottari
** File description:
** generic_list
*/

#include <stdlib.h>
#include <stdio.h>
#include "list.h"

unsigned int list_get_size(list_t list)
{
    unsigned int nb = 0;

    for (; list != NULL; list = list->next)
        nb++;
    return nb;
}

bool list_is_empty(list_t list)
{
    if (list == NULL)
        return true;
    return false;
}

bool list_add_elem_at_front(list_t *front_ptr, void *elem)
{
    list_t new_node = malloc(sizeof(node_t));

    if (!new_node)
        return false;
    new_node->value = elem;
    new_node->next = *front_ptr;
    *front_ptr = new_node;
    return true;
}

bool list_add_elem_at_back(list_t *front_ptr, void *elem)
{
    list_t new_node = malloc(sizeof(node_t));

    if (!new_node)
        return false;
    new_node->value = elem;
    new_node->next = NULL;
    if (list_is_empty(*front_ptr)) {
        *front_ptr = new_node;
        return true;
    }
    list_t temp = *front_ptr;
    for (; temp->next != NULL; temp = temp->next);
    temp->next = new_node;
    return true;
}

bool list_add_elem_at_position(list_t *front_ptr, void *elem,
unsigned int position)
{
    list_t tmp = malloc(sizeof(node_t));
    list_t tmp2 = NULL;

    if (!tmp || position > list_get_size(*front_ptr)) {
        free(tmp);
        return false;
    }
    tmp->value = elem;
    tmp->next = NULL;
    if (position == 0) {
        free(tmp);
        return list_add_elem_at_front(front_ptr, elem);
    }
    tmp2 = *front_ptr;
    for (int i = 0; i < (int) position - 1; i++)
        tmp2 = tmp2->next;
    tmp->next = tmp2->next;
    tmp2->next = tmp;
    return true;
}