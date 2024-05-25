/*
** EPITECH PROJECT, 2022
** bs_ftp
** File description:
** main
*/

#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include "client.h"

static int check_args(int const argc, char const *argv[])
{
    int nb = 0;

    if (argc != 3)
        return ERROR;
    if (strcmp(argv[1], "-help") == 0) {
        printf("USAGE: ./myteams_cli ip port\n\tip is\
        the server ip address on");
        printf("which the server socket listens\n\tport is the port number ");
        printf("on which the server socket listens\n");
        return ERROR;
    }
    for (size_t i = 0; i < strlen(argv[1]); i++)
        if (argv[1][i] == '.')
            nb++;
    if (nb != 3)
        return ERROR;
    for (size_t i = 0; i < strlen(argv[2]); i++)
        if (isdigit(argv[2][i]) == 0)
            return ERROR;
    return SUCCESS;
}

int main(int argc, char const *argv[])
{
    if (check_args(argc, argv) == ERROR)
        return 84;
    return init_client(argv[1], argv[2]);
}