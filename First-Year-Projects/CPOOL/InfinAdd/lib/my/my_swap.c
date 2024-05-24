/*
** EPITECH PROJECT, 2020
** my swap
** File description:
** swap the content of of two integers
*/

void my_swap(int *a, int *b)
{
    int ptr = *a;
    *a = *b;
    *b = ptr;
}
