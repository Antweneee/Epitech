/*
** EPITECH PROJECT, 2022
** B-PDG-300-PAR-3-1-PDGD05-antoine.gavira-bottari
** File description:
** ex09
*/

#include "string.h"

int empty(const string_t *this)
{
    if (this != NULL && this->str != NULL && this->str[0] == '\0')
        return 1;
    return -1;
}