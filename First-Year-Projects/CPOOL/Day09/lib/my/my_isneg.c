/*
** EPITECH PROJECT, 2020
** My isneg
** File description:
** print if an integer sis positive or negative
*/

int my_isneg(int n)
{
    if (n >= 0) {
        my_putchar('P');
        my_putchar('\n');
    } else {
        my_putchar('N');
        my_putchar('\n');
    }
}
