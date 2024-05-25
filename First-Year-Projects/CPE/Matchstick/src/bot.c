/*
** EPITECH PROJECT, 2021
** B-CPE-200-PAR-2-1-matchstick-antoine.gavira-bottari
** File description:
** ia
*/

#include <stdlib.h>
#include "matchstick.h"
#include "my.h"
#include "const.h"

int bot_check_line(char ** match)
{
    int i = 1;

    for (; match[i] != NULL; i++) {
        if (check_matche_line(match, i) > 0)
            return i;
    }
    return i;
}

char **ia_turn(char **match, data_t *data)
{
    int nb = 1;
    int lin = 0;

    my_printf("\nAI's turn...\n");
    lin = bot_check_line(match);
    match = update_map(match, lin, nb);
    my_printf("AI removed %d match(es) from line %d\n", nb, lin);
    data->turn = IA;
    print_map(data->size, match);
    return (match);
}