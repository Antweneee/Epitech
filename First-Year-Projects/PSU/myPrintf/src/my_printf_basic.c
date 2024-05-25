/*
** EPITECH PROJECT, 2020
** basic print
** File description:
** basic case
*/

#include "my.h"
#include "my_printf.h"

char *flag(char *param, int i)
{
    char *flg = malloc(sizeof(char) + my_strlen(param));
    int x;

    if ((param[i] == 'X' && param[i - 1] != '%')
        || (param[i] == 'x' && param[i - 1] != '%')) {
        i--;
        for (x = 0; param[i] != '\0'; i--) {
            if (param[i] == '%')
                break;
            flg[x] = param[i];
            x++;
        }
        flg[x] = '\0';
        my_revstr(flg);
    }
    return (flg);
}

void my_printf_mstring(char *param, char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 32 && str[i] <= 126) {
            my_putchar(str[i]);
        } else {
            my_putchar(92);
            my_printf("%d", convert_octal(str[i]));
        }
    }
}

void my_printf_hexam(char *param, int i, int nb)
{
    int y = my_strlen(convert_hexa(nb));
    char *flg = flag(param, i);

    if (my_getnbr(flg) > y) {
        for (y = my_getnbr(flg) - y; y != 0; y--) {
            if (flg[0] == '0' && flg[1] > '0')
                my_putchar('0');
            else
                my_putchar(' ');
        }
    }
    my_putstr(convert_hexa(nb));
}

void my_printf_hexamin(char *param, int i, int nb)
{
    int y = my_strlen(convert_hexa(nb));
    char *flg = flag(param, i);

    if (my_getnbr(flg) > y) {
        for (y = my_getnbr(flg) - y; y != 0; y--) {
            if (flg[0] == '0' && flg[1] > '0')
                my_putchar('0');
            else
                my_putchar(' ');
        }
    }
    my_putstr(convert_hexamin(nb));
}
