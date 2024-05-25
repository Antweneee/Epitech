/*
** EPITECH PROJECT, 2021
** B-CPE-200-PAR-2-1-matchstick-antoine.gavira-bottari
** File description:
** check
*/

#include "matchstick.h"
#include "my.h"
#include "const.h"

int check_matche_line(char **match, int line)
{
    int nb = 0;

    for (int i = 0; match[line][i] != '\0'; i++)
        if (match[line][i] == '|')
            nb++;
    return nb;
}

int matches_error_handler(char **match, data_t *data)
{
    if (data->matches == 85 || data->matches < 0) {
        my_printf("Error: invalid input (positive number expected)\n");
        return TRUE;
    }
    if (data->matches > data->max) {
        my_printf("Error: you cannot remove more than %d matches per turn\n"
        , data->max);
        return TRUE;
    }
    if (data->matches == 0) {
        my_printf("Error: you have to remove at least one match\n");
        return TRUE;
    }
    if (check_matche_line(match, data->line) < data->matches) {
        my_printf("Error: not enough matches on this line\n");
        return TRUE;
    }
    return FALSE;
}

int line_error_handler(data_t *data)
{
    if (data->line < 0 || data->line == 85) {
        my_printf("Error: invalid input (positive number expected)\n");
        return TRUE;
    }
    if (data->line > data->size || data->line == 0) {
        my_printf("Error: this line is out of range\n");
        return TRUE;
    }
    return FALSE;
}

int check_line(char **match, data_t *data)
{
    if (line_error_handler(data) == TRUE) {
        get_check_line(match, data);
        return (TRUE);
    }
    return (FALSE);
}

int check_matches(char **match, data_t *data)
{
    if (matches_error_handler(match, data) == TRUE) {
        get_check_line(match, data);
        return (TRUE);
    }
    return (FALSE);
}