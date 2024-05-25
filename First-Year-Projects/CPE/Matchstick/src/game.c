/*
** EPITECH PROJECT, 2021
** B-CPE-200-PAR-2-1-matchstick-antoine.gavira-bottari
** File description:
** game
*/

#include "matchstick.h"
#include "my.h"
#include "const.h"

void ending(data_t *data)
{
    if (data->status == 1)
        return;
    if (data->turn == PLAYER) {
        my_printf("You lost, too bad...\n");
    } else {
        my_printf("I lost... snif... but I'll get you next time!!\n");
    }
    data->status = 1;
}

char **update_map(char **match, int const line, int const nb)
{
    int i = 0;
    int check = nb;

    i = my_strlen(match[line]) - 1;
    for (; i != 0; i--) {
        if (match[line][i] != '|')
            continue;
        else {
            match[line][i] = ' ';
            check--;
        }
        if (check == 0)
        break;
    }
    return (match);
}

int get_match_number(char **match, int size)
{
    int nb = 0;

    for (int i = 0; i != (size + 2); i++) {
        for (int j = 0; match[i][j] != '\0'; j++) {
            if (match[i][j] == '|')
                nb++;
        }
    }
    return (nb);
}