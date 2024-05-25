/*
** EPITECH PROJECT, 2021
** commands.c
** File description:
** Run commands
*/

#include "n4s.h"

int exec(const char *command)
{
    char *line = NULL;

    dprintf(1, "%s", command);
    if ((line = readline()) == NULL)
        return (3);
    if (end(line) == 1)
        return (1);
    return (3);
}

int car_forward(double val)
{
    const char *forward = "CAR_FORWARD:";
    char *line = NULL;

    dprintf(1, "%s%f\n", forward, val);
    if ((line = readline()) == NULL)
        return (3);
    if (end(line) == 1)
        return (1);
    return (3);
}