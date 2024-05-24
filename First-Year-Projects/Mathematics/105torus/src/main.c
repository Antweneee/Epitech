/*
** EPITECH PROJECT, 2020
** main
** File description:
** main function
*/

#include "my.h"
#include <stdio.h>
#include <math.h>

void print(void)
{
    printf("%s\n","USAGE");
    printf("%s\n", "\t./105torus opt a0 a1 a2 a3 a4 n\n");
    printf("%s\n", "DESCRIPTION");
    printf("%s\n", "\topt \tmethod option:");
    printf("%s\n","\t\t\t1 for the bisection method");
    printf("%s\n", "\t\t\t2 for Newton's method");
    printf("%s\n", "\t\t\tp 3 for the secant method");
    printf("%s\n","\ta[0-4] \tcoefficients of the equation");
    printf("%s\n", "\tn \tprecision (the application of the polynomial to the solution should");
    printf("%s\n", "\t\tbe smaller than 10^-n)");
}

int error_handling(int ac, char **av)
{
    int j = 0;
    int x = 0;
    int z = 0;

    if (ac != 8)
        return (1);
    if (atof(av[1]) < 1 || atof(av[1]) > 3)
        return (1);
    for (int i = 1; i != 8; j++) {
        if (av[i][j] == '\0') {
            j = -1;
            i += 1;
            continue;
        }
        if (av[i][j] == '-') {
            continue;
        }
        if (av[i][j] < '0' || av[i][j] > '9') {
            return (1);
        }
    }
    while (z < ac) {
        while (av[z][x] != '\0') {
            if (av[z][x] < 43 || av[z][x] > 57 || av[z][x] == 44
                || av[z][x] == 47 || av[z][x] == 46)
                return (1);
            x += 1;
        }
        x = 0;
        z++;
    }
    return (0);
}

int main(int ac, char **av)
{
    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h' && av[1][2] == '\0') {
        print();
        return (0);
    }
    if (error_handling(ac, av) == 1)
        return (84);
    int opt = atof(av[1]);
    float a0 = atoi(av[2]);
    float a1 = atoi(av[3]);
    float a2 = atoi(av[4]);
    float a3 = atoi(av[5]);
    float a4 = atoi(av[6]);
    float n = atoi(av[7]);
    int x = 1;
    float result = 0;

//exo 1 bs

    result = pow((a4 * x), 4) + pow((a3 * x), 3) + pow((a2 * x), 2) + (a1 * x) + a0;
    printf("%f\n", result);

//end

//exo 1 bs

    result = pow((a4 * x), 4) + pow((a3 * x), 3) + pow((a2 * x), 2) + (a1 * x) + a0;
    printf("%f\n", result);

//end
    return (0);
}
