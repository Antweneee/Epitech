/*
** EPITECH PROJECT, 2020
** My print comb
** File description:
** print in ascending order all the numbers composed by tree different digits
*/

int my_print_comb (void)
{
    int a = 0;
    int b = 1;
    int c = 2;

    while (a <= 7)
    {
            while (b <= 8)
            {
                while (c <= 9)
                {
                    my_putchar(a+48);
                    my_putchar(b+48);
                    my_putchar(c+48);
                    my_putchar(',');
                    my_putchar(' ');
                    c++;
                }
                b++;
                c = b+1;
            }
            b = a+1;
            a++;
    }
}
