/*
** EPITECH PROJECT, 2022
** B-PDG-300-PAR-3-1-PDGD05-antoine.gavira-bottari
** File description:
** ex06
*/

#include "string.h"

int compare_s(const string_t *this, const string_t *str)
{
    return compare_c(this, str->str);
}

int compare_c(const string_t *this, const char *str)
{
    if (this == NULL || this->str == NULL || str == NULL)
        return -1;
    return strcmp(this->str, str);
}