/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** loop
*/

#include "const.h"
#include "n4s.h"

char *get_car_status(char *str)
{
    char *tmp = malloc(sizeof(char) * 1000);
    int pos = 0;
    int x = 0;

    if (tmp == NULL)
        return (NULL);
    for (int i = 0; i < 3;)
        if (str[x++] == ':')
            i++;
    for (; str[x]; x++)
        if ((str[x] >= '0' && str[x] <= '9') || str[x] == '.'
            || str[x] == ':') {
            tmp[pos] = str[x];
            pos++;
        }
    tmp[pos] = '\0';
    return (tmp);
}

int loop(void)
{
    int status = 0;

    while (true) {
        status = get_speed();
        if (status == 2)
            continue;
        if (status == 1)
            break;
        status = get_direction();
        if (status == 2)
			continue;
        if (status == 1)
            break;
	}
    exec(STOP);
    return 0;
}
