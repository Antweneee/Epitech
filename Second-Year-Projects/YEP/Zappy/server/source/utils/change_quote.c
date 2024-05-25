/*
** EPITECH PROJECT, 2022
** client
** File description:
** change_quote
*/

#include <stdlib.h>

static size_t get_size_line(const char *line)
{
    for (size_t i = 0; line[i] != '\0'; ++i)
        if (line[i] == '\"')
            return i;
    return 0;
}

static void replace_space(char *line, size_t index)
{
    for (size_t i = 0; i < index; ++i)
        if (line[i] == ' ')
            line[i] = 2;
}

void fix_space(char *line)
{
    for (size_t i = 0; line[i] != '\0'; ++i)
        if (line[i] == 2)
            line[i] = ' ';
}

void change_quote(char *line)
{
    size_t replace = 0;

    for (size_t i = 0; line[i] != '\0'; ++i) {
        if (line[i] == '\"' && (replace = get_size_line(&line[i + 1])) == 0)
            continue;
        if (line[i] == '\"') {
            replace_space(&line[i + 1], replace);
            i = i + replace + 1;
        }
    }
}
