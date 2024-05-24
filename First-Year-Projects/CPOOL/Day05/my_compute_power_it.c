/*
** EPITECH PROJECT, 2020
** my compute power it
** File description:
** Write an iterative function that returns the first argument raised to the powerp, wherepis the second argument.
*/

int my_compute_power_it(int nb, int p)
{
    int t= 1;
    
    if (p == 0) {
        return (1);
    }
    if (p < 0) {
        return (0);
    }
    while (p != 0) {
        t = t * nb;
        p--;
    }
    return (t);
}
