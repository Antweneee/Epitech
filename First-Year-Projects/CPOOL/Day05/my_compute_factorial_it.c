/*
** EPITECH PROJECT, 2020
** my compute factorial it
** File description:
** dzezefze
*/

int my_compute_factorial_it(int nb)
{
    int i = 1;
    int r = 1;

    if (nb == 0) {
        return (1);
    }
    if (nb > 12 || nb < 0) {
        return (0);
    } else {
        while (i <= nb) {
            r = r * i;
            i++;
        }
        return (r);
    }
}
