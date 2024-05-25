/*
** EPITECH PROJECT, 2021
** B-PSU-100-PAR-1-1-myls-antoine.gavira-bottari
** File description:
** my_strdup
*/

#include "my.h"
#include <stdlib.h>

char *my_strdup(char const *src)
{
    int i = 0;
    char *str = malloc(sizeof(char) * (my_strlen(src) + 1));

    for (; src[i] != '\0'; i++) {
        str[i] = src[i];
    }
    str[i] = '\0';
    return (str);
}