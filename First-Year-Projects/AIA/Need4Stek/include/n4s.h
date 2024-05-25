/*
** EPITECH PROJECT, 2021
** n4s
** File description:
** n4s
*/

#ifndef N4S_H_
#define N4S_H_

// other lib

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <ctype.h>

// end

char **my_str_to_word_array(const char *str, char separator);

int get_direction(void);
int convert_direction(char **data, double direction);
int handle_direction(double val, const char *str);
int convert_speed(double val);
int get_speed(void);

int exec(const char *command);
int car_forward(double val);

int loop(void);
char *get_car_status(char *str);

int end(char *str);

char *readline(void);

#endif /* N4S_H_ */
