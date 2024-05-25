/*
** EPITECH PROJECT, 2022
** B-PDG-300-PAR-3-1-PDGRUSH2-illyas.chihi
** File description:
** vvertex
*/

#include <stdio.h>
#include "new.h"
#include "vertex.h"

typedef struct
{
    Class base;
    int x, y, z;
}   VertexClass;

static void Vertex_ctor(VertexClass *this, va_list args)
{
    if (!this || !args)
        raise("The class is empty");
    this->x = va_arg(args, int);
    this->y = va_arg(args, int);
    this->z = va_arg(args, int);
}

static void Vertex_dtor(VertexClass *this)
{
    (void)this;
}

char *Vertex_str(VertexClass *this)
{
    char str[100];

    if (!this)
        raise("Class empty");
    sprintf(str, "<%s (%d, %d, %d)>", this->base.__name__,
    this->x, this->y, this->z);
    return strdup(str);
}

VertexClass *Vertex_addition(const VertexClass *v1, const VertexClass *v2)
{
    Object *tmp = new(Vertex, v1->x + v2->x, v1->y + v2->y, v1->z + v2->z);
    return tmp;
}

VertexClass *Vertex_substraction(const VertexClass *v1, const VertexClass *v2)
{
    Object *tmp = new(Vertex, v1->x - v2->x, v1->y - v2->y, v1->z - v2->z);
    return tmp;
}

static const VertexClass _description = {
    {
        .__size__ = sizeof(VertexClass),
        .__name__ = "Vertex",
        .__ctor__ = (ctor_t)&Vertex_ctor,
        .__dtor__ = (dtor_t)&Vertex_dtor,
        .__str__ = (to_string_t)Vertex_str,
        .__add__ = (binary_operator_t)Vertex_addition,
        .__sub__ = (binary_operator_t)Vertex_substraction,
        .__mul__ = NULL,
        .__div__ = NULL,
        .__eq__ = NULL,
        .__gt__ = NULL,
        .__lt__ = NULL
    },
    .x = 0,
    .y = 0,
    .z = 0
};

const Class *Vertex = (const Class *)&_description;