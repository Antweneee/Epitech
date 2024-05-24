/*
** EPITECH PROJECT, 2020
** my_printf
** File description:
** function printf
*/

#include "../../include/my.h"

void my_printf_cases(char *param, va_list info, int i)
{
    switch (param[i])
    {
    case 's': {
        my_putstr(va_arg(info, char*));
        break;
    }
    case 'c': {
        my_putchar(va_arg(info, int));
        break;
    }
    case '%': {
        my_putchar('%');
        break;
    }
    case 'S': {
        my_printf_mstring(param, va_arg(info, char*));
        break;
    }
    }
}

void my_printf_othercase(char *param, va_list info, int i)
{
    switch (param[i])
    {
    case 'i': {
        my_put_nbr(va_arg(info, int));
        break;
    }
    case 'd': {
        my_put_nbr(va_arg(info, int));
        break;
    }
    case 'X': {
        my_printf_hexam(param, i, va_arg(info, int));
        break;
    }
    case 'x': {
        my_printf_hexamin(param, i, va_arg(info, int));
        break;
    }
    }
}

int send_to_case(char *param, va_list info, int i)
{
    if ((param[i] == '%' && param[i + 3] == 'X')
        || (param[i] == '%' && param[i + 3] == 'x')) {
        i = i + 3;
        my_printf_othercase(param, info, i);
        i++;
        return (i);
    }
    if ((param[i] == '%' && param[i + 2] == 'X') ||
        (param[i] == '%' && param[i + 2] == 'x')) {
        i = i + 2;
        my_printf_othercase(param, info, i);
        i++;
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
            i++;
        }
        if (param[i] == '%')
            i--;
        else
            my_putchar(param[i]);
    }
    return (0);
}
