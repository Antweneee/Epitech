/*
** EPITECH PROJECT, 2021
** my_use
** File description:
** my_use
*/

#include <stdlib.h>
#include "use.h"

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i++;
    }
    return (i);
}

char *my_strcat(char *dest, char *src)
{
    int	i = my_strlen(dest);
    int	j = 0;
    int x = 0;
    int i2 = my_strlen(src);
    char *new = malloc(sizeof(char)*(i + i2 + 1));

    for (; x < (i + i2); x++) {
        if (x < i)
            new[x] = dest[x];
        else {
            new[x] = src[j];
            j++;
        }
    }
    new[x] = '\0';
    return new;
}

int my_strcmp(const char *str_o, const char *str_c)
{
    int i = 0;
    int result = 0;

    while ((str_o[i] == str_c[i]) && (str_o[i] != '\0')
    && (str_c[i] != '\0')) {
        i++;
    }
    result = str_o[i] - str_c[i];
    return (result);
}

char *my_strdup(char const *src)
{
    char *str = malloc(sizeof(char) * (my_strlen(src) + 1));

    my_strcpy(str, src);
    return (str);
}

char *my_strcpy(char *dest, char const *src)
{
    int i;

    for (i = 0; src[i] != '\0'; i++) {
        dest[i] = src[i];
    }
    dest[i] = '\0';
    return dest;
}