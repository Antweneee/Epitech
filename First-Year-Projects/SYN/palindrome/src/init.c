/*
** EPITECH PROJECT, 2021
** B-SYN-200-PAR-2-1-palindrome-antoine.gavira-bottari
** File description:
** init
*/

#include "palindrom.h"

param_t *init(void)
{
    param_t *fill = malloc(sizeof(param_t));

    fill->nb = NULL;
    fill->base = 10;
    fill->min = 0;
    fill->max = 100;
    fill->parse = 0;
    fill->parse_param = 0;
    return fill;
}