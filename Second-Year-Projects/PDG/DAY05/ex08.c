/*
** EPITECH PROJECT, 2022
** B-PDG-300-PAR-3-1-PDGD05-antoine.gavira-bottari
** File description:
** ex08
*/

#include "string.h"

const char *c_str(const string_t *this)
{
    if (this == NULL || this->str == NULL)
        return NULL;
    return this->str;
}