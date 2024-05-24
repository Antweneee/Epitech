/*
** EPITECH PROJECT, 2020
** 101pong
** File description:
** .h of 101pong
*/

#ifndef pong_H_
#define pong_H_ 

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h> 
struct Variable
{
    float x;
    float y;
    float z;
    float x1;
    float y1;
    float z1;
    int n;
};
int gestion(struct Variable var);

#endif /* pong_H_ */
