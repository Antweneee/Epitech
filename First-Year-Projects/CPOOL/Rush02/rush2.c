/*
** EPITECH PROJECT, 2020
** rush 2
** File description:
** dzeezdaz
*/

#include <my.h>

char minMAJ(char **av)
{
    char str = 0;
    
    if (av[2][0] >= 'A' && av[2][0] <= 'Z') {
        str = av[2][0] + 32;
    } else if (av[2][0] >= 'a' && av[2][0] <= 'z') {
        str = av[2][0] - 32;
    }
    return (str);
}

int rush2(int ac, char **av)
{
    int c = 0;
    int nb = 0;
    char conc = av[2][0];
    char uppercase = minMAJ(av);

    while (av[1][c] != '\0') {
        if (av[1][c] == conc || av[1][c] == uppercase) {
            nb++;
            c++;
        } else {
            c++;
        }
    }
    my_putchar(conc);
    my_putchar(':');
    my_put_nbr(nb);
    my_putchar('\n');
    return (0);
}

int main(int ac, char **av)
{
    if (ac < 3) {
        return (84);
    } else {
        rush2(ac, av);
        return (0);
    }
}
