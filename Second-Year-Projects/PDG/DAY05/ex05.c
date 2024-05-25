/*
** EPITECH PROJECT, 2022
** B-PDG-300-PAR-3-1-PDGD05-antoine.gavira-bottari
** File description:
** ex05
*/

#include "string.h"

int length(const string_t *this)
{
    if (this == NULL || this->str == NULL)
        return -1;
    return strlen(this->str);
}