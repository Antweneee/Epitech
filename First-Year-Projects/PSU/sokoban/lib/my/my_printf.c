/*
** EPITECH PROJECT, 2020
** my_printf
** File description:
** function
*/

#include "my.h"

void my_printf_cases(char *param, va_list info, int i)
{
    if (param[i] == 's') {
        my_putstr(va_arg(info, char *));
    }
    if (param[i] == 'c') {
        my_putchar(va_arg(info, int));
    }
    if (param[i] == '%') {
        my_putchar('%');
    }
    if (param[i] == 'S') {
        my_printf_mstring(param, va_arg(info, char *));
    }
    if (param[i] == 'i') {
        my_put_nbr(va_arg(info, int));
    }
    if (param[i] == 'd') {
        my_put_nbr(va_arg(info, int));
    }
}

void my_printf_othercase(char *param, va_list info, int i)
{
    if (param[i] == 'X') {
        my_printf_hexam(param, i, va_arg(info, int));
    }
    if (param[i] == 'x') {
        my_printf_hexamin(param, i, va_arg(info, int));
    }
    if (param[i] == 'o') {
        my_printf("%d", convert_octal(va_arg(info, int)));
    }
}

int send_to_case(char *param, va_list info, int i)
{
    if ((param[i] == '%' && param[i + 3] == 'X')
        || (param[i] == '%' && param[i + 3] == 'x')) {
        i += 3;
        my_printf_othercase(param, info, i);
        i += 1;
        return (i);
    }
    if ((param[i] == '%' && param[i + 2] == 'X') ||
        (param[i] == '%' && param[i + 2] == 'x')) {
        i += 2;
        my_printf_othercase(param, info, i);
        i += 1;
        return (i);
    }
    return (i);
}

int my_printf(char *param, ...)
{
    va_list info;
    va_start(info, param);

    for (int i = 0; param[i] != '\0'; i++)
    {
        i = send_to_case(param, info, i);
        if (param[i] == '%') {
            i++;
            my_printf_cases(param, info, i);
            my_printf_othercase(param, info, i);
            continue;
        } else
            my_putchar(param[i]);
    }
    return (0);
}
