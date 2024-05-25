/*
** EPITECH PROJECT, 2020
** my_isneg
** File description:
** Function
*/

void my_putchar(char c);

int my_isneg(int n)
{
    if (n >= 0)
    {
        my_putchar('P');
        my_putchar('\n');
    }   else
    {
        my_putchar('N');
        my_putchar('\n');
    }
}
