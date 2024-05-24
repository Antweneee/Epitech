/*
** EPITECH PROJECT, 2020
** my print revalpha
** File description:
** print reverse alphabet
*/

int my_print_revalpha(void)
{
    char a;

    for (a=122; a>96; a--) {
        my_putchar(a);
    }
    my_putchar('\n');
    return (0);
}
