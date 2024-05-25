/*
** EPITECH PROJECT, 2022
** B-PDG-300-PAR-3-1-PDGD04pm-antoine.gavira-bottari
** File description:
** generic_list3
*/

#include <stdlib.h>
#include <stdio.h>
#include "list.h"


bool list_del_elem_at_position(list_t *front_ptr, unsigned int position)
{
    list_t current = *front_ptr;
    list_t tmp = NULL;

    if (list_is_empty(*front_ptr) ||
        position >= list_get_size(*front_ptr))
        return false;
    if (position == 0)
        return list_del_elem_at_front(front_ptr);
    for (int i = 0; i < (int) position - 1; i++)
        current = current->next;
    tmp = current->next;
    current->next = current->next->next;
    free(tmp);
    return true;
}

void list_clear(list_t *front_ptr)
{
    list_t current = *front_ptr;
    list_t next = NULL;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    *front_ptr = NULL;
}

typedef void (*value_displayer_t) (const void *value);
void list_dump(list_t list, value_displayer_t val_disp)
{
    for (; list != NULL; list = list->next)
        val_disp(list->value);
}