/*
** EPITECH PROJECT, 2021
** B-SYN-200-PAR-2-1-palindrome-antoine.gavira-bottari
** File description:
** main
*/

#include "palindrom.h"

int usage(void)
{
    printf("USAGE\n./palindrome ");
    printf("-n number -p palindrome [-b base] [-imin i] [-imax i]");
    return 0;
}

int main(int ac, char **av)
{
    if (ac == 2 && strcmp(av[1], "-h") == 0)
        return (usage());
    if (error_handling(av) == 84) {
        printf("invalid argument\n");
        return 84;
    }
    return (palindrom(av));
}