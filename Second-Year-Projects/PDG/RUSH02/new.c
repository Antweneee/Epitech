/*
** EPITECH PROJECT, 2022
** B-PDG-300-PAR-3-1-PDGRUSH2-illyas.chihi
** File description:
** my_new
*/

#include "new.h"
#include "player.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

Object *va_new(const Class *class, va_list *args)
{
    Class *obj = malloc(class->__size__);

    if (!class)
        raise("The class has not be passed");
    if (!obj)
        raise("Cannot allocate memory for class");
    if (memcpy(obj, class, class->__size__) == NULL)
        raise("Out  of memory");
    if ((Class *)obj->__ctor__)
        ((Class *)obj)->__ctor__(obj, args);
    return obj;
}

Object *new(const Class *class, ...)
{
    Object *obj;

    va_list list;
    if (!class)
        raise("The class has not be passed");
    va_start(list, class);
    obj = va_new(class, &list);
    va_end(list);
    return obj;
}

void delete(Object *ptr)
{
    if (!ptr)
        raise("No object passed");
    if (((Class *)ptr)->__dtor__)
        ((Class *)ptr)->__dtor__(ptr);
    free(ptr);
}