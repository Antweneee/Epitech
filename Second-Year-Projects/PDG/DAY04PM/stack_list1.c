/*
** EPITECH PROJECT, 2022
** B-PDG-300-PAR-3-1-PDGD04pm-antoine.gavira-bottari
** File description:
** stack_list1
*/

#include <stdlib.h>
#include <stdio.h>
#include "stack.h"
#include "list.h"

unsigned int stack_get_size(stack_t stack)
{
    unsigned int nb = 0;

    for (; stack != NULL; stack = stack->next)
        nb++;
    return nb;
}

bool stack_is_empty(stack_t stack)
{
    if (stack == NULL)
        return true;
    return false;
}

bool stack_push(stack_t *stack_ptr, void *elem)
{
    stack_t new_node = malloc(sizeof(node_t));

    if (!new_node)
        return false;
    new_node->value = elem;
    new_node->next = *stack_ptr;
    *stack_ptr = new_node;
    return true;
}

bool stack_pop(stack_t *stack_ptr)
{
    stack_t tmp = *stack_ptr;

    if (stack_is_empty(*stack_ptr))
        return false;
    *stack_ptr = (*stack_ptr)->next;
    free(tmp);
    return true;
}

void stack_clear(stack_t *stack_ptr)
{
    stack_t current = *stack_ptr;
    stack_t next = NULL;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    *stack_ptr = NULL;
}