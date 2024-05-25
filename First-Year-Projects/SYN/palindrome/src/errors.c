/*
** EPITECH PROJECT, 2021
** B-SYN-200-PAR-2-1-palindrome-antoine.gavira-bottari
** File description:
** errors
*/

#include "palindrom.h"

int check_flags(char *check)
{
    if (strcmp(check, "-n") == 0 || strcmp(check, "-p") == 0 ||
        strcmp(check, "-b") == 0 || strcmp(check, "-imin") == 0 ||
        strcmp(check, "-imax") == 0)
        return 0;
    return 84;
}

int incompatible_flags(char **av)
{
    int parse = 0;

    for (int i = 0; av[i]; i++) {
        if ((strcmp(av[i], "-b") == 0 && av[i + 1] != NULL)
            && (atoi(av[i + 1]) < 2 || atoi(av[i + 1]) > 10))
            return 84;

        if (strcmp(av[i], "-n") == 0 || strcmp(av[i], "-p") == 0) {
            parse = 1;
            continue;
        }
        if (parse == 1 && (strcmp(av[i], "-p") == 0
            || strcmp(av[i], "-n") == 0))
            return 84;
    }
    if (parse == 0)
        return 84;
    return 0;
}

int invalid_argument(char c)
{
    if ((c < '0' || c > '9') && c != '\0')
        return 84;
    return 0;
}

int error_handling(char **av)
{
    int j = 0;

    for (int i = 1; av[i]; j++) {
        if (av[i][j] == '\0') {
            i++;
            j = 0;
        }
        if (av[i] == NULL)
            break;
        if (av[i][j] == '-' && check_flags(av[i]) == 84) {
            return 84;
        } else if (av[i][j] == '-' && check_flags(av[i]) == 0)
            i++;
        if (av[i] == NULL)
            return 84;
        if (invalid_argument(av[i][j]) == 84)
            return 84;
    }
    if (incompatible_flags(av) == 84)
        return 84;
    return 0;
}
