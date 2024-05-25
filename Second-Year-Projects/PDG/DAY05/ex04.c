/*
** EPITECH PROJECT, 2022
** B-PDG-300-PAR-3-1-PDGD05-antoine.gavira-bottari
** File description:
** ex04
*/

#include "string.h"

void clear(string_t *this)
{
    free(this->str);
    free(this);
}