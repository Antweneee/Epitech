/*
** EPITECH PROJECT, 2022
** B-PDG-300-PAR-3-1-PDGD04pm-antoine.gavira-bottari
** File description:
** linked_list3
*/

#include <stdlib.h>
#include <stdio.h>
#include "int_list.h"

bool int_list_del_elem_at_back(int_list_t *front_ptr)
{
    int_list_t current = *front_ptr;
    int_list_t tmp = NULL;

    if (int_list_is_empty(*front_ptr))
        return false;
    if (int_list_get_size(*front_ptr) == 1)
        return int_list_del_elem_at_front(front_ptr);
    for (; current->next->next != NULL; current = current->next);
    tmp = current->next;
    current->next = current->next->next;
    free(tmp);
    return true;
}

bool int_list_del_elem_at_position(int_list_t *front_ptr, unsigned int position)
{
    int_list_t current = *front_ptr;
    int_list_t tmp = NULL;

    if (int_list_is_empty(*front_ptr) ||
        position >= int_list_get_size(*front_ptr))
        return false;
    if (position == 0)
        return int_list_del_elem_at_front(front_ptr);
    for (int i = 0; i < (int) position - 1; i++)
        current = current->next;
    tmp = current->next;
    current->next = current->next->next;
    free(tmp);
    return true;
}

void int_list_clear(int_list_t *front_ptr)
{
    int_list_t current = *front_ptr;
    int_list_t next = NULL;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    *front_ptr = NULL;
}