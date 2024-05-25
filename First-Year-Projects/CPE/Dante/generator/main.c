/*
** EPITECH PROJECT, 2020
** main
** File description:
** main
*/

#include "generator.h"

void print_array(char **arr, int x)
{
    for (int i = 0; arr[i]; i++)
        (i != (x - 1) ? printf("%s\n", arr[i]) : printf("%s", arr[i]));
}

int init_game(char **av)
{
    int x = 0;
    int y = 0;
    char **map = NULL;

    x = atoi(av[2]);
    y = atoi(av[1]);
    if (x == 0 || y == 0)
        return 84;
    map = malloc_array(x, y);
    fill_arr(map, x, y);
    srand(time(NULL));
    algo_maze(map, x, y);
    print_array(map, x);
    free_tab(map);
    return (0);
}

int main(int ac, char **av)
{
    if (ac < 3 || ac > 4)
        return 84;
    if (ac == 4) {
        if (!strcmp(av[3], "perfect"))
            init_game(av);
    }
    return (0);
}
