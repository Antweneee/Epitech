/*
** EPITECH PROJECT, 2022
** lkz,ef
** File description:
** ze
*/

#include "../new.h"
#include "../player.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char **argv)
{
    char *str = argv[argc - 1];

    if (str[0] == '1')
    {
        Object *player = new(Player, NULL);
        delete(player);
    }
    else if (str[0] == '2')
    {
        Object *player = new(Player, NULL);
        delete(player);
    }
    else if (str[0] == '3')
    {
        Object *player = new(Player, NULL);
        delete(player);
    }
    return (0);
}