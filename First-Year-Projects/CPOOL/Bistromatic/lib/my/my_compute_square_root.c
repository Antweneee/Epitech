/*
** EPITECH PROJECT, 2020
** my_compute_square_root
** File description:
** function that returns the square root
*/

int my_compute_square_root(int nb)
{
    if (nb == 0 || nb == 1) {
        return (nb);
    }
    for (int r = 1; nb > 0; r++)
    {
        if (nb == r * r) {
            return (r);
        }
        if (r > nb) {
            return (0);
        }
    }
    return (0);
}
