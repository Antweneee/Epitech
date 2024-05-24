/*
** EPITECH PROJECT, 2020
** rush3
** File description:
** rush3 
*/

#include "my.h"
#include <unistd.h>

int cases(char *buff)
{
    if (buff[0] == '/' || buff[0] == '*')
        return (1);
    if (buff[0] == 'B')
        return (0);
}

int size1(char *buff)
{
    int x = 0;

    for (int i = 0; buff[i] != '\n'; i++) {
        x++;
    }
    return (x);
}

int size2(char *buff)
{
    int y = 0;

    for (int i = 0; buff[i] != '\0'; i++) {
        if (buff[i] == '\n')
            y++;
    }
    return (y);
}

void rush3(char *buff)
{
    int x = size1(buff);
    int y = size2(buff);
    int last = my_strlen(buff) - 2;

    if (cases(buff) == 1)
        write(1,"[rush1-2] ", 10);
    else if (cases(buff) == 0)
        write(1,"[rush1-3] [rush1-4] [rush1-5] ", 30);
    if (buff[0] == 'o')
        write(1,"[rush1-1] ", 10);
    if (buff[0] == 'A' && buff[x - 1] == 'A') {
        write(1,"[rush1-3] ", 10);
        return (1);
    }
    if (buff[0] == 'A' && buff[last] == 'C')
        write(1,"[rush1-4] ", 10);
    if (buff[0] == 'A' && buff[last] == 'A')
        write(1,"[rush1-5] ", 10);
}
