/*
** EPITECH PROJECT, 2022
** B-PDG-300-PAR-3-1-PDGD05-antoine.gavira-bottari
** File description:
** ex01
*/

#include "string.h"

void assign_c(string_t *this, const char *s)
{
    if (this == NULL || s == NULL)
        return;
    string_destroy(this);
    this->str = strdup(s);
}

void assign_s(string_t *this, const string_t *str)
{
    if (this == NULL || str == NULL || str->str == NULL)
        return;
    string_destroy(this);
    this->str = strdup(str->str);
}