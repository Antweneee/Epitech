/*
** EPITECH PROJECT, 2020
** my_print_alpha
** File description:
** print alphabet
*/

int my_print_alpha(void)
{
    char a;

    for (a=97; a<=122; a++) {
        my_putchar(a);
    }
    my_putchar('\n');
    return (0);
}
