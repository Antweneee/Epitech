/*
** EPITECH PROJECT, 2020
** main
** File description:
** main function for the final
*/

#include <unistd.h>
#include "my.h"
#define BUFF_SIZE (32000)

int main(void)
{
    char buff[BUFF_SIZE];
    int offset = 0;
    int len = read(0 , buff + offset , BUFF_SIZE - offset);

    if (error(buff) == 84)
        return (84);
    else {
        offset = offset + len;
        while (len  > 0) {
            len = read(0 , buff + offset , BUFF_SIZE - offset);
            offset = offset + len;
        }
        buff[offset] = '\0';
        if (len < 0)
            return (84) ;
        gestion(buff);
        return (0);
    }
}
