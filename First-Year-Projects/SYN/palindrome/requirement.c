/*
** EPITECH PROJECT, 2021
** B-SYN-200-PAR-2-1-palindrome-antoine.gavira-bottari
** File description:
** requirement
*/

int my_factrec_synthesis(int nb)
{
    if (nb < 0 || nb > 12)
        return 0;
    if (nb == 0 || nb == 1)
        return 1;
    return (nb = nb * my_factrec_synthesis(nb - 1));
}

int my_squareroot_synthesis(int nb)
{
    int res = 0;

    if (nb == 0)
        return 0;
    if (nb == 1)
        return 1;
    for (int i = 0; i < nb; ++i) {
        if (res * res >= 46340)
            return -1;
        if (res * res == nb)
            return res;
        res++;
    }
    return (-1);
}