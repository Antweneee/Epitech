/*
** EPITECH PROJECT, 2021
** B-CPE-200-PAR-2-1-matchstick-antoine.gavira-bottari
** File description:
** game
*/

#include <stdio.h>
#include "my.h"
#include "matchstick.h"
#include "const.h"

int select_line(char *buffer)
{
    int nb = 0;
    size_t bufsize = 0;

    my_printf("Line: ");
    if (getline(&buffer, &bufsize, stdin) == -1){
        nb = 84;
        return nb;
    }
    nb = my_getnbr(buffer);
    if (my_str_isnum(buffer) == 1)
        nb = 85;
    return (nb);
}

int number_match(char *buffer)
{
    int nb = 0;
    size_t bufsize = 0;

    my_printf("Matches: ");
    if (getline(&buffer, &bufsize, stdin) == -1) {
        nb = 84;
        return nb;
    }
    nb = my_getnbr(buffer);
    if (my_str_isnum(buffer) == 1)
        nb = 85;
    return (nb);
}

void get_check_line(char **match, data_t *data)
{
    while (get_match_number(match, data->size) != 0) {
        data->line = select_line(data->c_line);
        if (data->line == 84 || check_line(match, data) == TRUE)
            return;
        data->matches = number_match(data->c_matches);
        if (data->matches == 84 || check_matches(match, data) == TRUE)
            return;
        match = update_map(match, data->line, data->matches);
        my_printf("Player removed %d match(es) from line %d\n", data->matches,
        data->line);
        print_map(data->size, match);
        data->turn = PLAYER;
        if (get_match_number(match, data->size) == 0)
            break;
        match = ia_turn(match, data);
        game_process(match, data);
    }
}

void game_process(char **match, data_t *data)
{
    if (data->status == 1)
        return;
    if (get_match_number(match, data->size) != 0)
        my_printf("\nYour turn:\n");
    get_check_line(match, data);
    if (data->status == 1)
        return;
    if (get_match_number(match, data->size) == 0) {
        ending(data);
        return;
    }
}