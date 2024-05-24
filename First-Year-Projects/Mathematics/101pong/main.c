/*
** EPITECH PROJECT, 2020
** main
** File description:
** main
*/

#include "101pong.h"
#include "my.h"
#include <stdio.h>

int error(int ac, char **av)
{
    int y = 0;

    if (ac != 8)
        return (1);
    if (av[7][0] == '-')
        return (1);
    for (int i = 0; av[7][i] != '\0'; i++) {
        if (av[7][i] < '0' || av[7][i] > '9')
            return (1);
    }
    for (int x = 1; x != ac; x++) {
        for (; av[x][y] != '\0'; y++) {
            if (av[x][y] == '-' || av[x][y] == '.')
                y++;
            if (av[x][y] < '0' || av[x][y] > '9')
                return (1);
        }
        y = 0;
    }            
    return (0);
}

int main(int ac, char **av)
{
    if (error(ac, av) == 1)
        return (84);
    struct Variable var;
    var.x = atof(av[1]);
    var.y = atof(av[2]);
    var.z = atof(av[3]);
    var.x1 = atof(av[4]);
    var.y1 = atof(av[5]);
    var.z1 = atof(av[6]);
    var.n = atoi(av[7]);

    gestion(var);
    return (0);
}
