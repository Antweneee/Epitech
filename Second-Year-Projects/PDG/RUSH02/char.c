/*
** EPITECH PROJECT, 2022
** B-PDG-300-PAR-3-1-PDGRUSH2-illyas.chihi
** File description:
** char
*/


#include <stdio.h>
#include "new.h"
#include "char.h"

typedef struct
{
    Class base;
    char x;
} CharClass;

static void Char_ctor(CharClass *this, va_list args)
{
    if (!this || !args)
        raise("The class is empty");
    this->x = va_arg(args, int);
}

static void Char_dtor(CharClass *this)
{
    (void)this;
}

char *Char_str(CharClass *this)
{
    char str[100];

    if (!this)
        raise("Class empty");
    sprintf(str, "<Char (%c)>", this->x);
    return strdup(str);
}

CharClass *Char_addition(const CharClass *i1, const CharClass *i2)
{
    Object *tmp = new(Char, i1->x + i2->x);
    return tmp;
}

CharClass *Char_substraction(const CharClass *i1, const CharClass *i2)
{
    Object *tmp = new(Char, i1->x - i2->x);
    return tmp;
}

CharClass *Char_multiplication(const CharClass *i1, const CharClass *i2)
{
    Object *tmp = new(Char, i1->x * i2->x);
    return tmp;
}

CharClass *Char_division(const CharClass *i1, const CharClass *i2)
{
    Object *tmp = NULL;

    if (i2->x == 0)
        raise("cannot divide by zero");
    tmp = new(Char, i1->x / i2->x);
    return tmp;
}

bool Char_eq(const CharClass *i1, const CharClass *i2)
{
    if (i1->x == i2->x)
        return true;
    return false;
}

bool Char_gt(const CharClass *i1, const CharClass *i2)
{
    if (i1->x > i2->x)
        return true;
    return false;
}

bool Char_lt(const CharClass *i1, const CharClass *i2)
{
    if (i1->x < i2->x)
        return true;
    return false;
}

static const CharClass _description = {
    {
        .__size__ = sizeof(CharClass),
        .__name__ = "Char",
        .__ctor__ = (ctor_t)&Char_ctor,
        .__dtor__ = (dtor_t)&Char_dtor,
        .__str__ = (to_string_t)Char_str,
        .__add__ = (binary_operator_t)Char_addition,
        .__sub__ = (binary_operator_t)Char_substraction,
        .__mul__ = (binary_operator_t)Char_multiplication,
        .__div__ = (binary_operator_t)Char_division,
        .__eq__ = (binary_comparator_t)Char_eq,
        .__gt__ = (binary_comparator_t)Char_gt,
        .__lt__ = (binary_comparator_t)Char_lt
    },
    .x = 0
};

const Class *Char = (const Class *)&_description;