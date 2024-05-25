/*
** EPITECH PROJECT, 2022
** B-NWP-400-PAR-4-1-myteams-antoine.gavira-bottari
** File description:
** main
*/

#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include "server.h"

static int check_args(int const argc, char const *argv[])
{
    if (argc != 2)
        return ERROR;
    if (strcmp(argv[1], "-help") == 0) {
        printf("USAGE: ./myteams_server port\n\n\tport is\
        the port number on ");
        printf("which the server socket listens.\n");
        return ERROR;
    }
    for (size_t i = 0; i < strlen(argv[1]); i++)
        if (isdigit(argv[1][i]) == 0)
            return ERROR;
    return 0;
}

int main(int const argc, char const *argv[])
{
    if (check_args(argc, argv) == ERROR)
        return 84;
    if (init(argv[1]) == ERROR)
        return 84;
    return 0;
}