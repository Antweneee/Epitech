/*
** EPITECH PROJECT, 2020
** my_compute_power_rec
** File description:
** function
*/

int my_compute_power_rec(int nb, int p)
{
    int r = 0;

    if (p == 0) {
        return (1);
    }
    if (p < 0) {
        return (0);
    }
    r = nb * my_compute_power_rec(nb, p - 1);
    return (r);
}
