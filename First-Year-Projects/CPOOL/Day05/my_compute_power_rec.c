/*
** EPITECH PROJECT, 2020
** my compute power rec
** File description:
** display numbers power but in rec
*/

int my_compute_power_rec(int nb, int p)
{
    int r;

    if (p == 0) {
        return (1);
    }
    if (p < 0) {
        return (0);
    }
    r = nb * my_compute_power_rec(nb, p - 1);
    return (r);
}
