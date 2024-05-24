/*
** EPITECH PROJECT, 2020
** prio
** File description:
** prio
*/

#include "include/my.h"
#include <stdlib.h>

char *check_num(char *str)
{
    int y = 0;
    char *num = malloc(sizeof(char) * (my_strlen(str)));

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= '0' && str[i] <= '9') {
            num[y] = str[i];
            y++;
        }
    }
    num[y] = '\0';
    return (num);
}

char *check_sign(char *str)
{
    int y = 0;
    char *sign = malloc(sizeof(char) * (my_strlen(str)));

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '+' || str[i] == '-' || str[i] == '*'
            || str[i] == '/' || str[i] == '%') {
            sign[y] = str[i];
            y++;
        }
    }
    sign[y] = '\0';
    return (sign);
}

int gestion(char *str)
{
    char *num = check_num(str);
    char *sign = check_sign(str);
    int i = 0;
    int x = 0;
    int result = 0;

    for (int c = my_strlen(sign); i != c; i++) {
        if (i == 0) {
            result = do_op(sign[x], (num[x] - '0'), (num[x + 1] - '0'));
            x = x + 2;
        } else {
            result = do_op(sign[i], result, (num[x] - '0'));
            x++;
        }
    }
    my_put_nbr(result);
    my_putchar('\n');
    return (result);
}
