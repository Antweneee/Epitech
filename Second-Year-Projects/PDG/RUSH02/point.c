/*
** EPITECH PROJECT, 2021
** Paradigms Seminar
** File description:
** Exercice 02
*/

#include <stdio.h>
#include "new.h"
#include "point.h"

typedef struct
{
    Class   base;
    int     x, y;
}   PointClass;

static void Point_ctor(PointClass *this, va_list *args)
{
    if (!this || !args)
        raise("Class empty");
    this->x = va_arg(*args, int);
    this->y = va_arg(*args, int);
}

static void Point_dtor(PointClass *this)
{
    (void)this;
}

char *Point_str(PointClass *this)
{
    char str[100];

    if (!this)
        raise("Class empty");
    sprintf(str, "<%s (%d, %d)>", this->base.__name__, this->x, this->y);
    return strdup(str);
}

PointClass *Point_addition(const PointClass *c1, const PointClass *c2)
{
    Object *tmp = new(Point, c1->x + c2->x, c1->y + c2->y);
    return tmp;
}

PointClass *Point_substraction(const PointClass *c1, const PointClass *c2)
{
    Object *tmp = new(Point, c1->x - c2->x, c1->y - c2->y);
    return tmp;
}

static const PointClass _description = {
    {
        .__size__ = sizeof(PointClass),
        .__name__ = "Point",
        .__ctor__ = (ctor_t)&Point_ctor,
        .__dtor__ = (dtor_t)&Point_dtor,
        .__str__ = (to_string_t)Point_str,
        .__add__ = (binary_operator_t)Point_addition,
        .__sub__ = (binary_operator_t)Point_substraction,
        .__mul__ = NULL,
        .__div__ = NULL,
        .__eq__ = NULL,
        .__gt__ = NULL,
        .__lt__ = NULL
    },
    .x = 0,
    .y = 0
};

const Class   *Point = (const Class *)&_description;
