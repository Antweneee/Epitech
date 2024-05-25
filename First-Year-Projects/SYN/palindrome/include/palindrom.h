/*
** EPITECH PROJECT, 2021
** B-SYN-200-PAR-2-1-palindrome-antoine.gavira-bottari
** File description:
** palidrom
*/

#ifndef PALIDROM_H_
#define PALIDROM_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct prameters_s
{
    char *nb;
    int base;
    int min;
    int max;
    int parse;
    int parse_param;
} param_t;

/* palindrome */
int palindrom(char **av);

/* errors */
int error_handling(char **av);
int invalid_argument(char c);
int incompatible_flags(char **av);
int check_flags(char *check);

/* init */
param_t *init(void);

/* parseur */
int parse_param(char **av, param_t *params);
int get_uses(char **av, param_t *params);
void operation(param_t *params);

/* use */
char *rev_str(char const *str);
int power_rec(int nb, int power);

/* compute */
void get_palindrom(param_t *params);
int revint(int nb);
void to_obtain(param_t *params);

/* print */
void print_sentences(char *nb, char *try, int i, int base);
void print_intsentences(int nb, char *try, int i, int base);

/* base */
char *convert_deci_to_base(int base, int nb);
int base_to_decimal(char *nb, int base);

#endif /* !PALIDROM_H_ */