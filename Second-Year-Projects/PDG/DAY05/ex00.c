/*
** EPITECH PROJECT, 2022
** B-PDG-300-PAR-3-1-PDGD05-antoine.gavira-bottari
** File description:
** libstring
*/

#include "string.h"

void string_init(string_t *this, const char* s)
{
    if (this == NULL || s == NULL)
        return;
    this->str = strdup(s);
    this->assign_c = assign_c;
    this->assign_s = assign_s;
    this->append_c = append_c;
    this->append_s = append_s;
    this->at = at;
    this->clear = clear;
    this->length = length;
    this->compare_s = compare_s;
    this->compare_c = compare_c;
    this->c_str = c_str;
    this->empty = empty;
    this->copy = copy;
}

void string_destroy(string_t *this)
{
    free(this->str);
    this->str = NULL;
}