/*
** EPITECH PROJECT, 2022
** B-PDG-300-PAR-3-1-PDGD04am-antoine.gavira-bottari
** File description:
** print
*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "print.h"

void print_normal(const char *str)
{
    printf("%s\n", str);
}

void print_reverse(const char *str)
{
    int i = strlen(str);
    for (; i != -1; i--) {
        printf("%c", str[i]);
    }
    printf("\n");
}

void print_upper(char const *str)
{
    for (int i = 0; i < strlen(str); i++) {
        printf("%c", toupper((unsigned char) str[i]));
    }
    printf("\n");
}

void print_42(const char *str)
{
    printf("42\n");
}

void do_action(action_t action, const char *str)
{
    switch (action) {
    case PRINT_NORMAL:
        print_normal(str);
        break;
    case PRINT_REVERSE:
        print_reverse(str);
        break;
    case PRINT_UPPER:
        print_upper(str);
        break;
    case PRINT_42:
        print_42(str);
        break;
    default:
        return;
    }
}