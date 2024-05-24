/*
** EPITECH PROJECT, 2020
** my print comb 2
** File description:
** dsfzzf
*/

int my_print_comb2(void)
{
    int a = 0; //9
    int b = 0; //8
    int c = 0; //9
    int d = 1; //9

    while (a <= 9)
    {
        while (b <= 8)
        {
            while (c <= 9 )
            {
                while (d <= 9)
                {
                    my_putchar(a+48);
                    my_putchar(b+48);
                    my_putchar(' ');
                    my_putchar(c+48);
                    my_putchar(d+48);
                    my_putchar(',');
                    d++;
                }
                c++;
                d = 0;
            }
            b++;
            c = 0;
        }
        b = 0;
        a++;
    }
}
