/*
** EPITECH PROJECT, 2021
** B-SYN-200-PAR-2-1-palindrome-antoine.gavira-bottari
** File description:
** compute
*/

#include "palindrom.h"

void to_obtain_palindrom(param_t *params, int nb, int *sol)
{
    char *compute = convert_deci_to_base(params->base, nb);
    char *rev = NULL;
    int nbr = 0;

    for (int i = 0; i <= params->max; ++i) {
        if (strcmp(compute, convert_deci_to_base(params->base,
        atoi(params->nb))) == 0 && i >= params->min) {
            *sol += 1;
            print_intsentences(nb, compute, i, params->base);
            break;
        }
        rev = rev_str(compute);
        nbr = base_to_decimal(compute, params->base) +
        base_to_decimal(rev, params->base);
        if (nbr < 0)
            break;
        compute = convert_deci_to_base(params->base, nbr);
    }
}

void to_obtain(param_t *params)
{
    int sol = 0;

    for (int i = 1; i <= atoi(params->nb); ++i)
        to_obtain_palindrom(params, i, &sol);
    if (sol == 0)
        printf("no solution\n");
}

void get_palindrom(param_t *params)
{
    char *compute = convert_deci_to_base(params->base, atoi(params->nb));
    char *rev = NULL;
    int nbr = 0;
    int sol = 0;

    for (int i = 0; i <= params->max; ++i) {
        if (strcmp(rev_str(compute), compute) == 0 && i >= params->min) {
            sol++;
            print_sentences(params->nb, compute, i, params->base);
            break;
        }
        rev = rev_str(compute);
        nbr = base_to_decimal(compute, params->base) +
        base_to_decimal(rev, params->base);
        if (nbr < 0)
            break;
        compute = convert_deci_to_base(params->base, nbr);
    }
    if (sol == 0)
        printf("no solution\n");
}