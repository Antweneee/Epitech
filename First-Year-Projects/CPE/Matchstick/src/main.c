/*
** EPITECH PROJECT, 2020
** main
** File description:
** main function
*/

#include "matchstick.h"
#include "my.h"
#include "const.h"

int mainerror_handler(int ac, char const **av)
{
    if (ac != 3)
        return (TRUE);
    if (my_getnbr(av[1]) < 1 || my_getnbr(av[1]) > 100)
        return (TRUE);
    if (my_getnbr(av[2]) <= 0)
        return (TRUE);
    return (FALSE);
}

data_t *initialize(char const **av)
{
    data_t *fill = malloc(sizeof(data_t));

    if (fill == NULL)
        return (NULL);
    fill->size = my_getnbr(av[1]);
    fill->max = my_getnbr(av[2]);
    fill->line = 0;
    fill->matches = 0;
    fill->turn = PLAYER;
    fill->c_line = NULL;
    fill->c_matches = NULL;
    fill->status = 0;
    return fill;
}

int main(int ac, char const **av)
{
    data_t *data = NULL;

    if (mainerror_handler(ac, av) == TRUE)
        return (84);
    data = initialize(av);
    if (data == NULL)
        return 84;
    setup(data);
    return (0);
}
