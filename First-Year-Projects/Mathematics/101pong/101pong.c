/*
** EPITECH PROJECT, 2020
** 101 pong
** File description:
** 101pong game
*/

#include "my.h"
#include "101pong.h"

float position_x(struct Variable var, int i)
{
    float coef = 1.75;
    float r1 = 0;
    float r = 0;

    if (i == 0)
        r = var.x1 - var.x;
    if (var.x1 < 0 || var.x < 0)
        coef = coef * -1;
    if (i == 1) {
        r1 = var.x1 - var.x;
        r = (r1 * var.n) + (coef * var.n);
    }
    return(r);
}

float position_y(struct Variable var, int i)
{
    float coef = 2.25;
    float r = 0;
    float r1 = 0;

    if (i == 0)
        r = var.y1 - var.y;
    if (var.y1 < 0 || var.y < 0)
        coef = coef * -1; 
    if (i == 1) {
        r1 = var.y1 - var.y;
        r = (r1 * var.n) + (coef * var.n);
    }
    return (r);
}

float position_z(struct Variable var, int i)
{
    float coef = 0.5;
    float r = 0;
    float r1 = 0;

    if (i == 0)
        r = var.z1 - var.z;
    if (var.z1 < 0 || var.z < 0)
        coef = coef * -1; 
    if (i == 1) {
        r1 = var.z1 - var.z;
        r = (r1 * var.n) + (coef * var.n);
    }
    return (r);
}

int gestion(struct Variable var)
{
    float px = position_x(var, 0);
    float py = position_y(var, 0);
    float pz = position_z(var, 0);

    printf("The velocity vector of the ball is:\n");
    printf("(%.2f, %.2f, %.2f)\n", px, py, pz);
    px = position_x(var, 1);
    py = position_y(var, 1);
    pz = position_z(var, 1);
    printf("At time t + %d, ball coordinates will be:\n", var.n);
    printf("(%.2f, %.2f, %.2f)\n", px, py, pz);
    return (0);
}
