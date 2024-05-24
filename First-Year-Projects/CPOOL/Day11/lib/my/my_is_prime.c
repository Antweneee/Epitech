/*
** EPITECH PROJECT, 2020
** my is prime
** File description:
** function that returns1if the number is prime and0if not.
*/

int my_is_prime(int nb)
{
    if (nb <= 1) {
        return (0);
    }
    for (int t = 2; t < nb; t++) {
        if (nb / t * t == nb) {
            return (0);
        }
    }
    return (1);
}
