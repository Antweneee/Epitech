/*
** EPITECH PROJECT, 2022
** B-PDG-300-PAR-3-1-PDGD05-antoine.gavira-bottari
** File description:
** ex03
*/

#include "string.h"

char at(const string_t *this, size_t pos)
{
    if (this == NULL || this->str == NULL)
        return -1;
    if (pos <= strlen(this->str) - 1)
        return (this->str[pos]);
    return -1;
}