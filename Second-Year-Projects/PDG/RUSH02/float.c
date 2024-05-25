/*
** EPITECH PROJECT, 2022
** B-PDG-300-PAR-3-1-PDGRUSH2-illyas.chihi
** File description:
** float
*/

#include <stdio.h>
#include "new.h"
#include "float.h"

typedef struct
{
    Class base;
    float x;
} FloatClass;

static void Float_ctor(FloatClass *this, va_list args)
{
    if (!this || !args)
        raise("The class is empty");
    this->x = va_arg(args, double);
}

static void Float_dtor(FloatClass *this)
{
    (void)this;
}

char *Float_str(FloatClass *this)
{
    char str[100];

    if (!this)
        raise("Class empty");
    sprintf(str, "<Float (%f)>", this->x);
    return strdup(str);
}

FloatClass *Float_addition(const FloatClass *i1, const FloatClass *i2)
{
    Object *tmp = new(Float, i1->x + i2->x);
    return tmp;
}

FloatClass *Float_substraction(const FloatClass *i1, const FloatClass *i2)
{
    Object *tmp = new(Float, i1->x - i2->x);
    return tmp;
}

FloatClass *Float_multiplication(const FloatClass *i1, const FloatClass *i2)
{
    Object *tmp = new(Float, i1->x * i2->x);
    return tmp;
}

FloatClass *Float_division(const FloatClass *i1, const FloatClass *i2)
{
    Object *tmp;

    if (i2->x == 0)
        raise("cannot divide by zero");
    tmp = new(Float, i1->x / i2->x);
    return tmp;
}

bool Float_eq(const FloatClass *i1, const FloatClass *i2)
{
    if (i1->x == i2->x)
        return true;
    return false;
}

bool Float_gt(const FloatClass *i1, const FloatClass *i2)
{
    if (i1->x > i2->x)
        return true;
    return false;
}

bool Float_lt(const FloatClass *i1, const FloatClass *i2)
{
    if (i1->x < i2->x)
        return true;
    return false;
}

static const FloatClass _description = {
    {
        .__size__ = sizeof(FloatClass),
        .__name__ = "float",
        .__ctor__ = (ctor_t)&Float_ctor,
        .__dtor__ = (dtor_t)&Float_dtor,
        .__str__ = (to_string_t)Float_str,
        .__add__ = (binary_operator_t)Float_addition,
        .__sub__ = (binary_operator_t)Float_substraction,
        .__mul__ = (binary_operator_t)Float_multiplication,
        .__div__ = (binary_operator_t)Float_division,
        .__eq__ = (binary_comparator_t)Float_eq,
        .__gt__ = (binary_comparator_t)Float_gt,
        .__lt__ = (binary_comparator_t)Float_lt
    },
    .x = 0
};

const Class *Float = (const Class *)&_description;