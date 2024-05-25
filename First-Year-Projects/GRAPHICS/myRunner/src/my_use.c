/*
** EPITECH PROJECT, 2021
** my_use
** File description:
** my_use
*/

#include "my.h"
#include <unistd.h>

int my_strlen(char const *str)
{
    int f = 0;
    while (str[f] != '\0') {
        f++;
    }
    return (f);
}

int my_putstr(char const *str)
{
    write(1, str, my_strlen(str));
    return (0);
}

int get_obstacle(struct movement *move)
{
    int ob = 0;

    for (int i = 0; move->map[i] != '\0'; i++) {
        if (move->map[i] == '2' || move->map[i] == '3') {
            ob++;
        }
    }
    //printf("%d\n", ob);
    return (ob);
}
