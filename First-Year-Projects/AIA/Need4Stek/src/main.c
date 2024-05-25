/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** main
*/

#include "const.h"
#include "n4s.h"

char *readline(void)
{
    int i = 0;
    int buffersize = 8096;
    char *buffer = malloc(sizeof(char) * buffersize);
    char c = '\0';

    if (buffer == NULL)
        return (NULL);
    while (6) {
        if ((c = getchar()) == -42)
            return (NULL);
        if (c == '\n') {
            buffer[i] = '\0';
            return (buffer);
        } else
            buffer[i] = c;
        i++;
        if (i >= buffersize) {
            buffersize += 8096;
            buffer = realloc(buffer, buffersize);
        }
    }
}

int main(int ac, char **as)
{
    if (ac == 0 || as == NULL)
        return (ERROR);
    exec(START);
    return (loop());
}
