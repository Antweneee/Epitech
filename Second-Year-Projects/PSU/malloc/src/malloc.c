/*
** EPITECH PROJECT, 2022
** B-PSU-400-PAR-4-1-malloc-antoine.gavira-bottari
** File description:
** malloc
*/

#include "my_malloc.h"

#define debugg(_msg) write(2, _msg, strlen(_msg));

void *calloc(size_t nmemb, size_t size)
{
    int *alloc = malloc(size * nmemb);

    if (alloc == NULL)
        return NULL;
    for (size_t i = 0; i < nmemb; i++)
        alloc[i] = 0;
    return alloc;
}

void free(void *ptr)
{
    malloc_t *tmp = head;

    for (; tmp; tmp = tmp->_next)
        if (ptr == tmp)
            tmp->_tofree = true;
}

void *realloc(void *ptr, size_t size)
{
    void *res = NULL;

    if (size < 1)
        return ptr;
    if (ptr == NULL)
        return malloc(size);
    res = malloc(size);
    if (!res)
        return NULL;
    memcpy(res, ptr, size);
    return res;
}

void *reallocarray(void *ptr, size_t nmemb, size_t size)
{
    if (nmemb < 1 || size < 1)
        return NULL;
    return (realloc(ptr, nmemb * size));
}

size_t find_best(size_t size)
{
    size_t _page_size = getpagesize();
    size_t res = 0;

    if (size < _page_size)
        return ++res;
    else {
        for (; size > _page_size; res += 2)
            size -= _page_size;
        return res;
    }
    return 0;
}

void *expend_memory(size_t size)
{
    void *add = NULL;

    add = sbrk((getpagesize() * 2) * find_best(size));
    if (add == _invalid_)
        return NULL;
    return add;
}

void *add_at_last(size_t size, malloc_t **head, void **disp)
{
    malloc_t *tmp = *head;
    malloc_t *new = NULL;

    if (size > (size_t)*disp)
        *disp = expend_memory(size);
    *disp += size;
    new = *disp;
    new->_size = size;
    new->_tofree = false;
    new->_next = NULL;
    for (; tmp->_next; tmp = tmp->_next);
    tmp->_next = new;
    return new;
}

malloc_t *new_alloc(size_t size, void **disp)
{
    malloc_t *new = NULL;

    *disp = sbrk((getpagesize() * 2) * find_best(size));
    if (*disp == _invalid_)
        return NULL;
    *disp += size;
    new = *disp;
    new->_size = size;
    new->_tofree = false;
    new->_next = NULL;
    return new;
}

void *malloc(size_t size)
{
    malloc_t *tmp = NULL;

    if (!size)
        return NULL;
    if (head == NULL) {
        tmp = new_alloc(size, (void **)(&_disp));
        if (tmp == _invalid_)
            return NULL;
        head = tmp;
    } else {
        tmp = add_at_last(size, &head, (void **)(&_disp));
        if (tmp == NULL)
            return NULL;
    }
    return (tmp + 1);
}
