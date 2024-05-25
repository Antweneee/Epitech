/*
** EPITECH PROJECT, 2022
** B-PDG-300-PAR-3-1-PDGD04am-antoine.gavira-bottari
** File description:
** concat
*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "concat.h"

void concat_strings(const char *str1, const char *str2, char **res)
{
    *res = malloc(sizeof(char) * (strlen(str1) + strlen(str2) + 1));
    strcpy(*res, str1);
    strcat(*res, str2);
}

void concat_struct(concat_t *str)
{
    int length = strlen(str->str2) + strlen(str->str1);
    char *tmp = malloc(sizeof(char) * (length + 1));

    *tmp = '\0';
    strcat(tmp, str->str1);
    strcat(tmp, str->str2);
    str->res = strdup(tmp);
    free(tmp);
}