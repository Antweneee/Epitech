/*
** EPITECH PROJECT, 2022
** parseur
** File description:
** parseur
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int count_spaces(char *str, int do_space, int do_ret)
{
    int count = 0;

    if (str == NULL)
        return 0;

    for (unsigned int i = 0; str[i]; i += 1) {
        if (do_space && str[i + 1] && str[i] == ' ' && str[i + 1] != ' ')
            count++;
        if (do_ret && str[i] == '\n')
            count++;
    }
    count += 1;
    return count;
}

char **parse_str(char *str, int do_space, int do_ret)
{
    int nbr_words = count_spaces(str, do_space, do_ret);
    int rank = 0;
    char **commands = malloc(sizeof(char *) * (nbr_words + 1));
    char *tmp;

    if (str == NULL)
        return NULL;
    for (int j = 1;; j++) {
        if (do_space)
            tmp = strsep(&str, " ");
        if (do_ret)
            tmp = strsep(&str, "\n");

        if (tmp == NULL)
            break;
        if (tmp[0])
            commands[rank++] = tmp;
    }
    commands[rank] = NULL;
    return commands;
}