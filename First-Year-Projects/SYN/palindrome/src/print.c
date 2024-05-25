/*
** EPITECH PROJECT, 2021
** B-SYN-200-PAR-2-1-palindrome-antoine.gavira-bottari
** File description:
** print
*/

#include "palindrom.h"

void print_intsentences(int nb, char *try, int i, int base)
{
    printf("%d leads to %d in %i iteration(s) in base %d\n", nb,
    base_to_decimal(try, base), i, base);
}

void print_sentences(char *nb, char *try, int i, int base)
{
    printf("%s leads to %d in %i iteration(s) in base %d\n", nb,
    base_to_decimal(try, base), i, base);
}
