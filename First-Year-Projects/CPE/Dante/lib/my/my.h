/*
** EPITECH PROJECT, 2020
** my.h
** File description:
** my.h
*/
#ifndef MY_H_
#define MY_H_

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
void my_putchar(char c);
char *my_strstr(char *str, char const *to_find);
int my_isneg(int nb);
int my_strcmp(char const *s1, char const *s2);
int my_put_nbr(int nb);
int my_strncmp(char const *s1, char const *s2, int n);
void my_swap(int *a, int *b);
char *my_strupcase(char *str);
void my_putstr(char const *str);
char *my_strlowcase(char *str);
int my_strlen(char const *str);
char *my_strcapitalize(char *str);
int my_getnbr(char const *str);
int my_str_isalpha(char const *str);
void my_sort_int_array(int *tab, int size);
int my_str_isnum(char const *str);
int my_compute_power_rec(int nb, int power);
int my_str_islower(char const *str);
int my_compute_square_root(int nb);
int my_str_isupper(char const *str);
int my_is_prime(int nb);
int my_str_isprintable(char const *str);
int my_find_prime_sup(int nb);
int my_showstr(char const *str);
char *my_strcpy(char *dest, char const *src);
int my_showmem(char const *str, int size);
char *my_strncpy(char *dest, char const *src, int n);
char *my_strcat(char *dest, char const *src);
char *my_revstr(char *str);
char *my_strncat(char *dest, char const *src, int nb);
char *my_strdup(char const *src);
int my_printf(char *param, ...);
void my_printf_mstring(char *param, char *str);
void my_printf_hexam(char *param, int i , int nb);
void my_printf_hexamin(char *param, int i, int nb);
int convert_octal(int nb);
int hexa_tab(int nb);
char intermediate(int nb, int i);
char *big_number(int nbr);
char *convert_hexa(int nbr);
int minhexa_tab(int nb);
char min_intermediate(int nb, int i);
char *big_numbermin(int nbr);
char *convert_hexamin(int nbr);
void my_put_error(char const *str);
char **turn_to_array(char const *str, char c);
void free_tab(char **arr);

#endif /* MY_H_ */
