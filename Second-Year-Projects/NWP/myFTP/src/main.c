/*
** EPITECH PROJECT, 2022
** B-NWP-400-PAR-4-1-myftp-antoine.gavira-bottari
** File description:
** main
*/

#include <string.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include "myftp.h"

void usage()
{
    printf("USAGE: ./myftp port path\n");
    printf("\tport is the port number on which the server socket listens\n");
    printf("\tpath is the path to the home directory for the Anonymous user\n");
}

int check_param(int argc, char const *argv[])
{
    struct stat check;
    int r_value = 0;

    if (argc < 3)
        return -1;
    r_value = stat(argv[2], &check);
    if (r_value == -1)
        return -1;
    if (S_ISREG(check.st_mode) != 0)
        return -1;
    return 0;
}

int main(int argc, char const *argv[])
{
    if (argc == 2 && strcmp(argv[1], "-help") == 0) {
        usage();
        return 0;
    } if (check_param(argc, argv) == -1)
        return 84;
    return server_engine(argv[1], argv[2]);
}