/*
** EPITECH PROJECT, 2020
** my print digits
** File description:
** print all the digits on a single line
*/

int my_print_digits(void)
{
    char a;
    
    for (a=48; a<=57; a++) {
        my_putchar(a);
    }
    my_putchar('\n');
    return (0);
}
