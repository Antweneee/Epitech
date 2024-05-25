/*
** EPITECH PROJECT, 2022
** lkz,ef
** File description:
** ze
*/

#include "../new.h"
#include "../point.h"
#include "../vertex.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char **argv)
{
    char *str = argv[argc - 1];

    if (str[0] == '1')
    {
        Object  *point = new(Point, 42, -42);
        Object  *vertex = new(Vertex, 0, 1, 2);

        printf("point = %s\n", str(point));
        printf("vertex = %s\n", str(vertex));

        delete(point);
        delete(vertex);
    }
    else if (str[0] == '2')
    {
        Object  *point = new(Point, 42, 42);
        Object  *vertex = new(Vertex, 10, 1, 2);

        printf("point = %s\n", str(point));
        printf("vertex = %s\n", str(vertex));

        delete(point);
        delete(vertex);
    }
    else if (str[0] == '3')
    {
        Object  *point = new(Point, 0, 0);
        Object  *vertex = new(Vertex, 0, 0, 0);

        printf("point = %s\n", str(point));
        printf("vertex = %s\n", str(vertex));

        delete(point);
        delete(vertex);
    }
    else if (str[0] == '4')
    {
        Object  *point = new(Point, 10000, 10000);
        Object  *vertex = new(Vertex, 550, 551, 552);

        printf("point = %s\n", str(point));
        printf("vertex = %s\n", str(vertex));

        delete(point);
        delete(vertex);
    }
    else if (str[0] == '5')
    {
        Object  *point = new(Point, 2, -999992);
        Object  *vertex = new(Vertex, 0, 1, 2);

        printf("point = %s\n", str(point));
        printf("vertex = %s\n", str(vertex));

        delete(point);
        delete(vertex);
    }
    else if (str[0] == '6')
    {
        Object  *point = new(Point, 98765432, -98765432);
        Object  *vertex = new(Vertex, 98765432, 98765432, 98765432);

        printf("point = %s\n", str(point));
        printf("vertex = %s\n", str(vertex));

        delete(point);
        delete(vertex);
    }
    return (0);
}