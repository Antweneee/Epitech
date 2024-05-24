/*
** EPITECH PROJECT, 2020
** print.h
** File description:
** .h for my_printf
*/
#ifndef architect_H_
#define architect_H_

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
struct Variable
{
    float x;
    float y;
    char *z;
    float i;
    float j;
    float a;
};
int calcul(struct Variable var);
  
#endif /* architect_H_ */
