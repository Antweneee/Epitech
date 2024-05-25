/*
** EPITECH PROJECT, 2022
** B-PDG-300-PAR-3-1-PDGD05-antoine.gavira-bottari
** File description:
** module
*/

#ifndef MODULE_H_
#define MODULE_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct string_s string_t;
struct string_s
{
    char *str;
    void (*assign_s)(string_t *this, const string_t *str);
    void (*assign_c)(string_t *this, const char *s);
    void (*string_init)(string_t *this, const char* s);
    void (*string_destroy)(string_t *this);
    void (*append_s)(string_t *this, const string_t *ap);
    void (*append_c)(string_t *this, const char *ap);
    char (*at)(const string_t *this, size_t pos);
    void (*clear)(string_t *this);
    int (*length)(const string_t *this);
    int (*compare_s)(const string_t *this, const string_t *str);
    int (*compare_c)(const string_t *this, const char *str);
    size_t (*copy)(const string_t *this, char *s, size_t n, size_t pos);
    const char *(*c_str)(const string_t *this);
    int (*empty)(const string_t *this);
};

void string_init(string_t *this, const char* s);
void string_destroy(string_t *this);
void assign_s(string_t *this, const string_t *str);
void assign_c(string_t *this, const char *s);
void append_s(string_t *this, const string_t *ap);
void append_c(string_t *this, const char *ap);
char at(const string_t *this, size_t pos);
void clear(string_t *this);
int length(const string_t *this);
int compare_s(const string_t *this, const string_t *str);
int compare_c(const string_t *this, const char *str);
size_t copy(const string_t *this, char *s, size_t n, size_t pos);
const char *c_str(const string_t *this);
int empty(const string_t *this);

#endif /* !MODULE_H_ */