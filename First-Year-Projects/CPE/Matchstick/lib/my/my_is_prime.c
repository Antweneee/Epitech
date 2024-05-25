/*
** EPITECH PROJECT, 2020
** my_is_prime
** File description:
** function that returns 1 if the number is prime and 0 if not
*/

int my_is_prime(int nb)
{
    int t = 2;

    if (nb <= 1) {
        return (0);
    }
    while (t < nb) {
        if (nb / t * t == nb) {
            return (0);
        }
        t++;
    }
    return (1);
}
