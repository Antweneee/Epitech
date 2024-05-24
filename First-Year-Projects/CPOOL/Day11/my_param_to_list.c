/*
** EPITECH PROJECT, 2020
** my param to list
** File description:
** my param to list
*/

#include <stdlib.h>
#include "my.h"

int error(int ac)
{
    if (ac != 4) {
        return (84);
    }
    return (0);
}

linked_list_t *put_in_list(void *data, linked_list_t *list)
{
    linked_list_t *n_list;

    n_list = malloc(sizeof(*n_list));
    n_list->data = data;
    n_list->next = list;
    list = n_list;
    return (n_list);
}

linked_list_t *my_params_to_list(int ac, char * const *av)
{
    linked_list_t *list;
    
    list = NULL;
    for (int i = 0; i != ac; i++) {
        list = put_in_list(av[i], list);
        printf("%s\n", av[i]);
         }
    return (list);
}
