/*
** EPITECH PROJECT, 2020
** print.h
** File description:
** .h for my_printf
*/
#ifndef bsq_H_
#define bsq_H_

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
struct result_s
{
    int x;
    int y;
    int max;
};
void bsq(char *buffer);
int my_strlen_custom(char *str);
char **turn_to_array(char *str, int size);
void print_array(char **array, int size);
void print(char **array, struct result_s *pos, int len, int nb);

#endif /* bsq_H_ */
