/*
** EPITECH PROJECT, 2020
** 102 architect
** File description:
** 102 architect
*/

#include "../include/my.h"
#include "../include/architect.h"

float translation(struct Variable var, int nb)
{
    float x1 = 0;
    float y1 = 0;

    if (nb == 1) {
        printf("Translation along vector (%.0f, %.0f)\n", var.i, var.j);
        printf("1.00\t0.00\t%.2f\n", var.i);
        printf("0.00\t1.00\t%.2f\n", var.j);
        printf("0.00\t0.00\t1.00\n");
        x1 = ((var.x * 1) + (var.y * 0) + (var.i * 1));
        return (x1);
    } else {
        y1 = ((var.x * 0) + (var.y * 1) + (var.j * 1));
        return (y1);
    }
}

float rotation(struct Variable var, int nb)
{
    float co = cosf((var.a * M_PI) / 180);
    float si = sinf((var.a * M_PI) / 180);

    if (nb == 1) {
        printf("Rotation by a %.0f degree angle\n", var.a);
        printf("%.2f\t%.2f\t%.2f\n", co, (si * -1), 0.00);
        printf("%.2f\t%.2f\t%.2f\n", si, co * -1, 0.00);
        printf("0.00\t0.00\t1.00\n");
        return ((var.x * co) + (var.y * (si * -1)) + 0);
    } else {
        return ((var.x * si) + (var.y * co) + 0);
    }
}

float reflexion(struct Variable var, int nb)
{
    float co = cosf(2 *(var.a * M_PI) / 180);
    float si = sinf(2 *(var.a * M_PI) / 180);

    if (nb == 1) {
        printf("Reflection over an axis with an inclination angle of %.0f degrees\n", var.a);
        printf("%.2f\t%.2f\t%.2f\n", co, si, 0.00);
        printf("%.2f\t%.2f\t%.2f\n", si, co * -1, 0.00);
        printf("0.00\t0.00\t1.00\n");
        return ((var.x * co) + (var.y * si) + 0);
    } else {
        return ((var.x * si) + (var.y * (co * -1)) + 0);
    }
}

float scaling(struct Variable var, int nb)
{
    float x1 = 0;
    float y1 = 0;

    if (nb == 1) {
        printf("Translation along vector (%.0f, %.0f)\n", var.i, var.j);
        printf("%.2f", var.i);
        if (var.i < 0)
            printf("   0.00    0.00\n");
        else {
            printf("    0.00    0.00\n");
        }
        printf("0.00    %.2f", var.j);
        if (var.j < 0)
            printf("   0.00\n");
        else {
            printf("    0.00\n");
        }
        printf("0.00    0.00    1.00\n");
        x1 = ((var.x * var.i) + (var.y * 0) + (var.i * 0));
        return (x1);
    } else {
        y1 = ((var.x * 0) + (var.y * var.j) + (1 * 0));
        return (y1);
    }
}

int calcul(struct Variable var)
{
    int i = 0;

    if (var.z[1] == 't') {
        printf("(%.2f, %.2f) => (%.2f, %.2f)\n", var.x, var.y, translation(var, 1), translation(var, 0));
        i++;
    }
    if (var.z[1] == 'z') {
        printf("(%.2f, %.2f) => (%.2f, %.2f)\n", var.x, var.y, scaling(var, 1), scaling(var, 0));
        i++;
    }
    if (var.z[1] == 'r') {
        printf("(%.2f, %.2f) => (%.2f, %.2f)\n", var.x, var.y, rotation(var, 1), rotation(var, 0));
        i++;
    }
    if (var.z[1] == 's') {
        printf("(%.2f, %.2f) => (%.2f, %.2f)\n", var.x, var.y, reflexion(var, 1), reflexion(var, 0));
        i++;
    }
    if (i == 0)
        return (84);
    return (0);
}
