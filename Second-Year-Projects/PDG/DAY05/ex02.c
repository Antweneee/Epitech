/*
** EPITECH PROJECT, 2022
** B-PDG-300-PAR-3-1-PDGD05-antoine.gavira-bottari
** File description:
** ex03
*/

#include "string.h"

void append_s(string_t *this, const string_t *ap)
{
    if (this == NULL || ap == NULL) {
        this->str = NULL;
        return;
    }
    append_c(this, this->str);
}

void append_c(string_t *this, const char *ap)
{
    char *tmp;
    char *temp;
    int len = 0;

    if (this == NULL || ap == NULL)
        return;
    len = strlen(this->str);
    temp = strdup(this->str);
    string_destroy(this);
    tmp = malloc(sizeof(char) * (len + strlen(ap) + 1));
    *tmp = '\0';
    tmp = strcat(tmp, temp);
    tmp = strcat(tmp, ap);
    this->str = tmp;
    free(temp);
}