/*
** EPITECH PROJECT, 2020
** solver_h
** File description:
** sezd
*/

#ifndef MY_H
#define MY_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include "my.h"

char **malloc_array(int const x, int const y);
void fill_arr(char **map, int const x, int const y);
void print_array(char **arr, int x);
void algo_maze(char **map, int const x, int const y);

#endif