/*
** EPITECH PROJECT, 2022
** B-PDG-300-PAR-3-1-PDGD04pm-antoine.gavira-bottari
** File description:
** generic_list2
*/

#include <stdlib.h>
#include <stdio.h>
#include "list.h"

void *list_get_elem_at_front(list_t list)
{
    if (list_is_empty(list))
        return 0;
    return list->value;
}

void *list_get_elem_at_back(list_t list)
{
    if (list_is_empty(list))
        return 0;
    for (; list->next != NULL; list = list->next);
    return list->value;
}

void *list_get_elem_at_position(list_t list, unsigned int position)
{
    if (list_is_empty(list) || position >= list_get_size(list))
        return 0;
    for (int i = 0; i < (int) position; i++)
        list = list->next;
    return list->value;
}

bool list_del_elem_at_front(list_t *front_ptr)
{
    list_t tmp = NULL;

    if (list_is_empty(*front_ptr))
        return false;
    tmp = *front_ptr;
    *front_ptr = (*front_ptr)->next;
    free(tmp);
    return true;
}

bool list_del_elem_at_back(list_t *front_ptr)
{
    list_t current = *front_ptr;
    list_t tmp = NULL;

    if (list_is_empty(*front_ptr))
        return false;
    if (list_get_size(*front_ptr) == 1)
        return list_del_elem_at_front(front_ptr);
    for (; current->next->next != NULL; current = current->next);
    tmp = current->next;
    current->next = current->next->next;
    free(tmp);
    return true;
}
