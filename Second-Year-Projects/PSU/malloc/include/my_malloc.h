/*
** EPITECH PROJECT, 2022
** B-PSU-400    -PAR-4-1-malloc-antoine.gavira-bottari
** File description:
** malloc
*/

#ifndef MY_MALLOC_H_
    #define MY_MALLOC_H_

    #include <unistd.h>
    #include <stdbool.h>
    #include <string.h>

    #define _invalid_ (void *) -1

typedef struct malloc_s malloc_t;
struct malloc_s {
    malloc_t *_next;
    size_t _size;
    bool _tofree;
};

static malloc_t *head = NULL;
static malloc_t *_disp = NULL;

void *malloc(size_t size);
void free(void *ptr);
void *calloc(size_t nmemb, size_t size);
void *realloc(void *ptr, size_t size);
void *reallocarray(void *ptr, size_t nmemb, size_t size);

#endif /* !MY_MALLOC_H_ */