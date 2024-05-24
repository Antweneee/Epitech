/*
** EPITECH PROJECT, 2020
** my compute factorial rec
** File description:
** my compute factorial rec
*/

int my_compute_factorial_rec(int nb)
{
    int r;

    if (nb > 12 || nb < 0) {
        return (0);
    }
    if (nb == 0) {
        return (1);
    }
    r = nb * my_compute_factorial_rec(nb - 1);
    return (r);
}
