/*
** EPITECH PROJECT, 2022
** B-PDG-300-PAR-3-1-PDGD04am-antoine.gavira-bottari
** File description:
** mul_div
*/

#include <stdlib.h>

void mul_div_long(int a, int b, int *mul, int *div)
{
    *mul = a * b;
    if (b == 0)
        *div = 42;
    else
        *div = a / b;
}

void mul_div_short(int *a , int *b)
{
    int c;
    int d;

    c = *a;
    d = *b;
    *a = c * d;
    if (d == 0)
        *b = 42;
    else
        *b = c / d;
}