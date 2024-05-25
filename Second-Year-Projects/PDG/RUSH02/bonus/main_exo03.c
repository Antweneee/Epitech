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

    if (str[0] == '1' && strlen(str) == 1)
    {
        Object  *p1 = new(Point, 12, 13);
        Object  *p2 = new(Point, 2, 2);

        printf("%s + %s = %s\n", str(p1), str(p2), str(addition(p1, p2)));
        printf("%s - %s = %s\n", str(p1), str(p2), str(subtraction(p1, p2)));

        Object  *v1 = new(Vertex, 1, 2, 3);
        Object  *v2 = new(Vertex, 4, 5, 6);

        printf("%s + %s = %s\n", str(v1), str(v2), str(addition(v1, v2)));
        printf("%s - %s = %s\n", str(v1), str(v2), str(subtraction(v1, v2)));
    }
    else if (str[0] == '2' && strlen(str) == 1)
    {
        Object  *p1 = new(Point, 0, 0);
        Object  *p2 = new(Point, 2, 2);

        printf("%s + %s = %s\n", str(p1), str(p2), str(addition(p1, p2)));
        printf("%s - %s = %s\n", str(p1), str(p2), str(subtraction(p1, p2)));

        Object  *v1 = new(Vertex, 1, 2, 3);
        Object  *v2 = new(Vertex, 4, 5, 6);

        printf("%s + %s = %s\n", str(v1), str(v2), str(addition(v1, v2)));
        printf("%s - %s = %s\n", str(v1), str(v2), str(subtraction(v1, v2)));
    }
    else if (str[0] == '3' && strlen(str) == 1)
    {
        Object  *p1 = new(Point, 12, 13);
        Object  *p2 = new(Point, 0, 0);

        printf("%s + %s = %s\n", str(p1), str(p2), str(addition(p1, p2)));
        printf("%s - %s = %s\n", str(p1), str(p2), str(subtraction(p1, p2)));

        Object  *v1 = new(Vertex, 1, 2, 3);
        Object  *v2 = new(Vertex, 4, 5, 6);

        printf("%s + %s = %s\n", str(v1), str(v2), str(addition(v1, v2)));
        printf("%s - %s = %s\n", str(v1), str(v2), str(subtraction(v1, v2)));
    }
    else if (str[0] == '4')
    {
        Object  *p1 = new(Point, 1000, 1000);
        Object  *p2 = new(Point, 1000, 1000);

        printf("%s + %s = %s\n", str(p1), str(p2), str(addition(p1, p2)));
        printf("%s - %s = %s\n", str(p1), str(p2), str(subtraction(p1, p2)));

        Object  *v1 = new(Vertex, 1, 2, 3);
        Object  *v2 = new(Vertex, 4, 5, 6);

        printf("%s + %s = %s\n", str(v1), str(v2), str(addition(v1, v2)));
        printf("%s - %s = %s\n", str(v1), str(v2), str(subtraction(v1, v2)));
    }
    else if (str[0] == '5')
    {
        Object  *p1 = new(Point, -100, 1000);
        Object  *p2 = new(Point, 1000, 1000);

        printf("%s + %s = %s\n", str(p1), str(p2), str(addition(p1, p2)));
        printf("%s - %s = %s\n", str(p1), str(p2), str(subtraction(p1, p2)));

        Object  *v1 = new(Vertex, 1, 2, 3);
        Object  *v2 = new(Vertex, 4, 5, 6);

        printf("%s + %s = %s\n", str(v1), str(v2), str(addition(v1, v2)));
        printf("%s - %s = %s\n", str(v1), str(v2), str(subtraction(v1, v2)));
    }
    else if (str[0] == '6')
    {
        Object  *p1 = new(Point, 1000, 1000);
        Object  *p2 = new(Point, -100, 1000);

        printf("%s + %s = %s\n", str(p1), str(p2), str(addition(p1, p2)));
        printf("%s - %s = %s\n", str(p1), str(p2), str(subtraction(p1, p2)));

        Object  *v1 = new(Vertex, 1, 2, 3);
        Object  *v2 = new(Vertex, 4, 5, 6);

        printf("%s + %s = %s\n", str(v1), str(v2), str(addition(v1, v2)));
        printf("%s - %s = %s\n", str(v1), str(v2), str(subtraction(v1, v2)));
    }
    else if (str[0] == '7')
    {
        Object  *p2 = new(Point, 1000, -100);
        Object  *p1 = new(Point, 1000, 1000);

        printf("%s + %s = %s\n", str(p1), str(p2), str(addition(p1, p2)));
        printf("%s - %s = %s\n", str(p1), str(p2), str(subtraction(p1, p2)));

        Object  *v1 = new(Vertex, 1, 2, 3);
        Object  *v2 = new(Vertex, 4, 5, 6);

        printf("%s + %s = %s\n", str(v1), str(v2), str(addition(v1, v2)));
        printf("%s - %s = %s\n", str(v1), str(v2), str(subtraction(v1, v2)));
    }
    else if (str[0] == '8')
    {
        Object  *p2 = new(Point, 1000, 1000);
        Object  *p1 = new(Point, 1000, -100);

        printf("%s + %s = %s\n", str(p1), str(p2), str(addition(p1, p2)));
        printf("%s - %s = %s\n", str(p1), str(p2), str(subtraction(p1, p2)));

        Object  *v1 = new(Vertex, 1, 2, 3);
        Object  *v2 = new(Vertex, 4, 5, 6);

        printf("%s + %s = %s\n", str(v1), str(v2), str(addition(v1, v2)));
        printf("%s - %s = %s\n", str(v1), str(v2), str(subtraction(v1, v2)));
    }
    else if (str[0] == '9')
    {
        Object  *p2 = new(Point, 0, 0);
        Object  *p1 = new(Point, 0, 0);

        printf("%s + %s = %s\n", str(p1), str(p2), str(addition(p1, p2)));
        printf("%s - %s = %s\n", str(p1), str(p2), str(subtraction(p1, p2)));

        Object  *v1 = new(Vertex, 0, 0, 0);
        Object  *v2 = new(Vertex, 0, 0, 0);

        printf("%s + %s = %s\n", str(v1), str(v2), str(addition(v1, v2)));
        printf("%s - %s = %s\n", str(v1), str(v2), str(subtraction(v1, v2)));
    }
    else if (strlen(str) != 1 && str[0] == '1' && (str[1] && str[1] == '0'))
    {
        Object  *p2 = new(Point, 0, 0);
        Object  *p1 = new(Point, 0, 0);

        printf("%s + %s = %s\n", str(p1), str(p2), str(addition(p1, p2)));
        printf("%s - %s = %s\n", str(p1), str(p2), str(subtraction(p1, p2)));

        Object  *v1 = new(Vertex, 1, 1, 1);
        Object  *v2 = new(Vertex, 1, 1, 1);

        printf("%s + %s = %s\n", str(v1), str(v2), str(addition(v1, v2)));
        printf("%s - %s = %s\n", str(v1), str(v2), str(subtraction(v1, v2)));
    }
    else if (strlen(str) != 1 && str[0] == '1' && (str[1] && str[1] == '1'))
    {
        Object  *p2 = new(Point, 0, 0);
        Object  *p1 = new(Point, 0, 0);

        printf("%s + %s = %s\n", str(p1), str(p2), str(addition(p1, p2)));
        printf("%s - %s = %s\n", str(p1), str(p2), str(subtraction(p1, p2)));

        Object  *v1 = new(Vertex, 100000, 100000, 100000);
        Object  *v2 = new(Vertex, 1, 1, 1);

        printf("%s + %s = %s\n", str(v1), str(v2), str(addition(v1, v2)));
        printf("%s - %s = %s\n", str(v1), str(v2), str(subtraction(v1, v2)));
    }
    else if (strlen(str) != 1 && str[0] == '1' && (str[1] && str[1] == '2'))
    {
        Object  *p2 = new(Point, 0, 0);
        Object  *p1 = new(Point, 0, 0);

        printf("%s + %s = %s\n", str(p1), str(p2), str(addition(p1, p2)));
        printf("%s - %s = %s\n", str(p1), str(p2), str(subtraction(p1, p2)));

        Object  *v1 = new(Vertex, 1, 1, 1);
        Object  *v2 = new(Vertex, 100000, 100000, 100000);

        printf("%s + %s = %s\n", str(v1), str(v2), str(addition(v1, v2)));
        printf("%s - %s = %s\n", str(v1), str(v2), str(subtraction(v1, v2)));
    }
    return (0);
}