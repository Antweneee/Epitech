/*
** EPITECH PROJECT, 2020
** do op
** File description:
** do op$
*/

#include "my.h"

int error(int ac, char **av)
{
    if (ac != 4)
        return (84);
    if (av[2][0] != '*' && av[2][0] != '/' && av[2][0] != '%' && av[2][0] != '+'
        && av[2][0] != '-') {
        write(1, "0\n", 2);
        return (84);
    }
    if (av[2][0] == '/' && av[3][0] == '0') {
        write(1, "Stop: division by zero\n", 23);
        return (84);
    }
    if (av[2][0] == '%' && av[3][0] == '0') {
        write(1, "Stop: modulo by zero\n", 21);
        return (84);
    }
    return (0);
}

int calcul(int ac, char **av)
{
    switch (av[2][0]) {
    case '+':
        return (my_getnbr(av[1]) + my_getnbr(av[3]));
    case '-':
        return (my_getnbr(av[1]) - my_getnbr(av[3]));
    case '*':
        return (my_getnbr(av[1]) * my_getnbr(av[3]));
    case '/':
        return (my_getnbr(av[1]) / my_getnbr(av[3]));                
    case '%':
        return (my_getnbr(av[1]) % my_getnbr(av[3]));
    }
    return (0);
}
