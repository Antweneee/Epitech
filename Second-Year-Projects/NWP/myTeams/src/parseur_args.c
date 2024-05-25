/*
** EPITECH PROJECT, 2022
** parseur
** File description:
** parseur
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int count_args(char *str)
{
    int count = 0;

    if (str == NULL)
        return 0;
    for (unsigned int i = 0; str[i]; i += 1) {
        if (str[i] == '\"')
            count++;
    }
    if (count % 2 != 0)
        return (-1);
    count /= 2;
    count += 1;
    return count;
}

void do_the_loop(char **commands, char *str, char *tmp, int rank)
{
    commands[rank++] = strsep(&str, " ");
    if (str && str[0])
        str += 1;

    for (int j = 0;; j++) {
        if (str == NULL)
            break;
        tmp = strsep(&str, "\"");
        if (str == NULL || tmp == NULL || !tmp[0])
            break;
        if (tmp[0])
            commands[rank++] = tmp;
        if (str && str[0])
            str += 2;
    }
    commands[rank] = NULL;
}

char **parse_args(char *str)
{
    int nbr_args = count_args(str);
    int rank = 0;
    char **commands = malloc(sizeof(char *) * (nbr_args + 1));
    char *tmp = NULL;

    if (str == NULL || nbr_args == -1)
        return NULL;

    do_the_loop(commands, str, tmp, rank);

    for (int i = 0; commands[i]; i++)
        printf("commands[%d] = %s\n", i, commands[i]);
    return commands;
}