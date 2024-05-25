/*
** EPITECH PROJECT, 2021
** B-SYN-200-PAR-2-1-palindrome-antoine.gavira-bottari
** File description:
** palindrom
*/

#include "palindrom.h"

int palindrom(char **av)
{
    param_t *params = init();
    char *nb = NULL;

    params->parse = get_uses(av, params);
    params->parse_param = parse_param(av, params);
    nb = convert_deci_to_base(params->base, atoi(params->nb));
    if (strcmp(nb, rev_str(nb)) != 0 && params->parse == 2) {
        printf("invalid argument\n");
        return 84;
    }
    if (params->parse == 0 || params->parse_param == 84) {
        printf("invalid argument\n");
        return 84;
    }
    operation(params);
    return 0;
}