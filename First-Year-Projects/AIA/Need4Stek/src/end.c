/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** end
*/

#include "const.h"
#include "n4s.h"

int end(char *str)
{
    int i = strlen(str) - 1;
    int j = 0;
    char *tmp = malloc(sizeof(char) * (strlen(str) + 1));

    if (tmp == NULL)
        return (1);
    for (; str[i] && str[i] != ':'; i--);
    i--;
    for (; str[i] && str[i] != ':'; i--);
    i++;
    for (; str[i] && str[i] != ':';)
        tmp[j++] = str[i++];
    tmp[j] = '\0';
    if (strcmp("Track Cleared", tmp) == 0)
    {
        free(tmp);
        exec(STOP);
        return (1);
    }
    free(tmp);
    return (3);
}