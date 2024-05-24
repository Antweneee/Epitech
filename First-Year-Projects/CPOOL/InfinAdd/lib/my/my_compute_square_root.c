/*
** EPITECH PROJECT, 2020
** my compute square root
** File description:
** square root a number
*/

int my_compute_square_root(int nb)
{
    if (nb == 0 || nb ==1) {
        return (nb);
    }
    for (int t = 1; t * t <= nb; t++) {
        if (t * t == nb) {
            return (t);
        }
    }
    return (0);
}
