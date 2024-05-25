/*
** EPITECH PROJECT, 2020
** print.h
** File description:
** .h for my_printf
*/
#ifndef print_H_
#define print_H_

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
int my_printf(char *param, ...);
void my_printf_mstring(char *param, char *str);
void my_printf_hexam(char *param, int i , int nb);
void my_printf_hexamin(char *param, int i, int nb);
int hexa_tab(int nb);
char intermediate(int nb, int i);
char *big_number(int nbr);
char *convert_hexa(int nbr);
int minhexa_tab(int nb);
char min_intermediate(int nb, int i);
char *big_numbermin(int nbr);
char *convert_hexamin(int nbr);
int convert_octal(int nb);

#endif /* print_H_ */
