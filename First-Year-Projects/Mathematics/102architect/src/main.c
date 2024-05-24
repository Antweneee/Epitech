/*
** EPITECH PROJECT, 2020
** main
** File description:
** main fuction of bsq
*/

#include "../include/my.h"
#include "../include/architect.h"

int error(int ac, char **av)
{
    int x = 1;

    if (ac == 1)
        return (1);
    if (av[3][1] == 't' || av[3][1] == 'z') {
        if (ac != 6)
            return (1);
    }
    if (av[3][1] == 'r' || av[3][1] == 's') {
        if (ac != 5)
            return (1);
    }
    for (int y = 0; x != ac; y++) {
        if (av[x][y] == '\0') {
            y = 0;
            x++;
        }
        if (x == ac)
            break;
        if (av[x][y] < '0' || av[x][y] > '9') {
            if (x == 3) {
                continue;
            }
            if (av[x][y] == '.' || av[x][y] == '-') {
                continue;
            } else {
                return (1);
            }
        }
    }
    if (av[3][1] == 't' || av[3][1] == 'z') {
        if (ac != 6)
            return (1);
    }
    if (av[3][1] == 'r' || av[3][1] == 's') {
        if (ac != 5)
            return (1);
    }
    return (0);
}

int main(int ac, char **av)
{
    struct Variable var;

    if (error(ac, av) == 1) {
        return (84);
    }
    if (ac == 6) {
        var.z = (av[3]);
        var.x = atof(av[1]);
        var.y = atof(av[2]);
        var.i = atof(av[4]);
        var.j = atof(av[5]);
    }
    if (ac == 5) {
        var.z = (av[3]);
        var.x = atof(av[1]);
        var.y = atof(av[2]);
        var.a = atof(av[4]);
    }
    calcul(var);
    return (0);
}
