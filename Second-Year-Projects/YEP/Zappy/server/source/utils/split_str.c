/*
** EPITECH PROJECT, 2022
** client
** File description:
** split_str
*/

#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "functions.h"

static size_t count_delim(const char *str, const char *delim)
{
    size_t count = 0;

    for (size_t i = 0; str[i] != '\0'; ++i)
        count += (strncmp(&str[i], delim, strlen(delim)) == 0);
    return count;
}

char **split_str(const char *str, const char *delim)
{
    size_t len = 0;
    char **array = NULL;
    char *line = strdup(str);

    if (line == NULL)
        return NULL;
    change_quote(line);
    len = count_delim(line, delim);
    array = malloc(sizeof(char *) * (len + 2));
    if (array == NULL)
        return NULL;
    line = strtok(line, delim);
    for (size_t i = 0; line != NULL; ++i) {
        array[i] = line;
        fix_space(array[i]);
        line = strtok(NULL, delim);
    }
    array[len + 1] = NULL;
    return array;
}

size_t size_array(char **array)
{
    size_t i = 0;

    for (; array[i] != NULL; ++i);
    return i;
}

void free_2d_array(char **array)
{
    if (array != NULL && *array != NULL)
        free(*array);
    if (array != NULL)
        free(array);
}
