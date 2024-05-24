/*
** EPITECH PROJECT, 2020
** error
** File description:
** error function
*/

#include <unistd.h>

int error(char *buff)
{
    for (int i = 0; buff[i] != '\0'; i++) {
        if (buff[i] == ' ') {
            return (84);
        }
        if ((buff[i] == '/' && buff[i + 1] == '0') ||
            (buff[i] == '%' && buff[i + 1] == '0')) {
            return (84);
        }
    }
    return (0);
}
