/*
** EPITECH PROJECT, 2022
** B-PDG-300-PAR-3-1-PDGRUSH2-illyas.chihi
** File description:
** int
*/

#include <stdio.h>
#include "new.h"
#include "int.h"

typedef struct
{
    Class base;
    int x;
} IntClass;

static void Int_ctor(IntClass *this, va_list args)
{
    if (!this || !args)
        raise("The class is empty");
    this->x = va_arg(args, int);
}

static void Int_dtor(IntClass *this)
{
    (void)this;
}

char *Int_str(IntClass *this)
{
    char str[100];

    if (!this)
        raise("Class empty");
    sprintf(str, "<Int (%d)>", this->x);
    return strdup(str);
}

IntClass *Int_addition(const IntClass *i1, const IntClass *i2)
{
    Object *tmp = new(Int, i1->x + i2->x);
    return tmp;
}

IntClass *Int_substraction(const IntClass *i1, const IntClass *i2)
{
    Object *tmp = new(Int, i1->x - i2->x);
    return tmp;
}

IntClass *Int_multiplication(const IntClass *i1, const IntClass *i2)
{
    Object *tmp = new(Int, i1->x * i2->x);
    return tmp;
}

IntClass *Int_division(const IntClass *i1, const IntClass *i2)
{
    Object *tmp = NULL;

    if (i2->x == 0)
        raise("cannot divide by zero");
    tmp = new(Int, (i1->x / i2->x));
    return tmp;
}

bool Int_eq(const IntClass *i1, const IntClass *i2)
{
    if (i1->x == i2->x)
        return true;
    return false;
}

bool Int_gt(const IntClass *i1, const IntClass *i2)
{
    if (i1->x > i2->x)
        return true;
    return false;
}

bool Int_lt(const IntClass *i1, const IntClass *i2)
{
    if (i1->x < i2->x)
        return true;
    return false;
}

static const IntClass _description = {
    {
        .__size__ = sizeof(IntClass),
        .__name__ = "int",
        .__ctor__ = (ctor_t)&Int_ctor,
        .__dtor__ = (dtor_t)&Int_dtor,
        .__str__ = (to_string_t)&Int_str,
        .__add__ = (binary_operator_t)&Int_addition,
        .__sub__ = (binary_operator_t)&Int_substraction,
        .__mul__ = (binary_operator_t)&Int_multiplication,
        .__div__ = (binary_operator_t)&Int_division,
        .__eq__ = (binary_comparator_t)&Int_eq,
        .__gt__ = (binary_comparator_t)&Int_gt,
        .__lt__ = (binary_comparator_t)&Int_lt
    },
    .x = 0
};

const Class *Int = (const Class *)&_description;