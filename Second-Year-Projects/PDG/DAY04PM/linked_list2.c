/*
** EPITECH PROJECT, 2022
** B-PDG-300-PAR-3-1-PDGD04pm-antoine.gavira-bottari
** File description:
** chain_list2
*/

#include <stdlib.h>
#include "int_list.h"

bool int_list_add_elem_at_position(int_list_t *front_ptr, int elem,
unsigned int position)
{
    int_node_t *tmp = malloc(sizeof(int_node_t));
    int_node_t *tmp2= NULL;

    if (!tmp || position > int_list_get_size(*front_ptr)) {
        free(tmp);
        return false;
    }
    tmp->value = elem;
    tmp->next = NULL;
    if (position == 0) {
        free(tmp);
        return int_list_add_elem_at_front(front_ptr, elem);
    }
    tmp2 = *front_ptr;
    for (int i = 0; i < (int) position - 1; i++)
        tmp2 = tmp2->next;
    tmp->next = tmp2->next;
    tmp2->next = tmp;
    return true;
}

int int_list_get_elem_at_front(int_list_t list)
{
    if (int_list_is_empty(list))
        return 0;
    return list->value;
}

int int_list_get_elem_at_back(int_list_t list)
{
    if (int_list_is_empty(list))
        return 0;
    for (; list->next != NULL; list = list->next);
    return list->value;
}

int int_list_get_elem_at_position(int_list_t list, unsigned int position)
{
    if (int_list_is_empty(list) || position >= int_list_get_size(list))
        return 0;
    for (int i = 0; i < (int) position; i++)
        list = list->next;
    return list->value;
}

bool int_list_del_elem_at_front(int_list_t *front_ptr)
{
    int_list_t tmp;

    if (int_list_is_empty(*front_ptr))
        return false;
    tmp = *front_ptr;
    *front_ptr = (*front_ptr)->next;
    free(tmp);
    return true;
}