/*
** EPITECH PROJECT, 2020
** main 
** File description:
** main function for the final
*/

#include <stdio.h>
#include <unistd.h>
#include "my.h"
#define BUFF_SIZE (32000)

int size1(char *buff);

int size2(char *buff);

int main(void)
{
    char buff[BUFF_SIZE + 1];
    int offset = 0;
    int len = read(0 , buff + offset , BUFF_SIZE - offset);
    int x = 0;
    int y = 0;
    
    offset = offset + len;
    while (len  > 0) {
        len = read(0 , buff + offset , BUFF_SIZE - offset);
        offset = offset + len;
    }
    buff[offset] = '\0';
    if (len < 0)
        return (84) ;
    rush3(buff) ;
    my_put_nbr(size1(buff));
    my_putchar(' ');
    my_put_nbr(size2(buff));
    my_putchar('\n');
    return (0) ;
}
