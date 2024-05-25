/*
** EPITECH PROJECT, 2022
** B-PDG-300-PAR-3-1-PDGD05-antoine.gavira-bottari
** File description:
** ex07
*/

#include "string.h"

size_t copy(const string_t *this, char *s, size_t n, size_t pos)
{
    size_t i;
    size_t len = 0;

    if (this == NULL || this->str == NULL || s == NULL)
        return 0;
    len = strlen(this->str);
    for (i = 0; (i + pos < len) && (i < n); i++)
        s[i] = this->str[i + pos];
    if (strlen(s) < n)
        s[i++] = 0;
    return i;
}