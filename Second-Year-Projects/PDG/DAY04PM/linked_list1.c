/*
** EPITECH PROJECT, 2022
** B-PDG-300-PAR-3-1-PDGD04pm-antoine.gavira-bottari
** File description:
** chain_list1
*/

#include <stdlib.h>
#include <stdio.h>
#include "int_list.h"

unsigned int int_list_get_size(int_list_t list)
{
    unsigned int nb = 0;

    for (; list != NULL; list = list->next)
        nb++;
    return nb;
}

bool int_list_is_empty(int_list_t list)
{
    if (list == NULL)
        return true;
    return false;
}

void int_list_dump(int_list_t list)
{
    for (; list != NULL; list = list->next)
        printf("%d\n", list->value);
}

bool int_list_add_elem_at_front(int_list_t *front_ptr, int elem)
{
    int_list_t new_node = malloc(sizeof(int_node_t));

    if (!new_node)
        return false;
    new_node->value = elem;
    new_node->next = *front_ptr;
    *front_ptr = new_node;
    return true;
}

bool int_list_add_elem_at_back(int_list_t *front_ptr, int elem)
{
    int_list_t new_node = malloc(sizeof(int_node_t));

    if (!new_node)
        return false;
    new_node->value = elem;
    new_node->next = NULL;
    if (int_list_is_empty(*front_ptr)) {
        *front_ptr = new_node;
        return true;
    }
    int_list_t temp = *front_ptr;
    for (; temp->next != NULL; temp = temp->next);
    temp->next = new_node;
    return true;
}