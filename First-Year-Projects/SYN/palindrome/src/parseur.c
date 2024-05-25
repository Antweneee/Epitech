/*
** EPITECH PROJECT, 2021
** B-SYN-200-PAR-2-1-palindrome-antoine.gavira-bottari
** File description:
** parse
*/

#include "palindrom.h"

int parse_param(char **av, param_t *params)
{
    for (int i = 0; av[i]; i++) {
        if (strcmp(av[i], "-b") == 0) {
            params->base = atoi(av[i + 1]);
        }
        if (strcmp(av[i], "-imin") == 0) {
            params->min = atoi(av[i + 1]);
        }
        if (strcmp(av[i], "-imax") == 0) {
            params->max = atoi(av[i + 1]);
        }
    }
    if (params->min > params->max || params->max < params->min)
        return 84;
    if (params->min < 0 || params->max < 0)
        return 84;
    return 0;
}

int get_uses(char **av, param_t *params)
{
    for (int i = 0; av[i]; i++) {
        if (strcmp(av[i], "-n") == 0) {
            params->nb = strdup(av[i + 1]);
            return 1;
        }
        if (strcmp(av[i], "-p") == 0) {
            params->nb = strdup(av[i + 1]);
            return 2;
        }
    }
    return 84;
}

void operation(param_t *params)
{
    if (params->parse == 1)
        get_palindrom(params);
    if (params->parse == 2)
        to_obtain(params);
}