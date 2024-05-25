/*
** EPITECH PROJECT, 2022
** B-PDG-300-PAR-3-1-PDGD04pm-antoine.gavira-bottari
** File description:
** stack_list2
*/

#include <stdlib.h>
#include "stack.h"

void *stack_top(stack_t stack)
{
    if (stack_is_empty(stack))
        return NULL;
    return stack->value;
}