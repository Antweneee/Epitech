/*
** EPITECH PROJECT, 2020
** my strdup
** File description:
** function that allocates memory and copies the string given as argument in it
*/

#include <stdlib.h>

char *my_strdup(char  const *src)
{
    int nb = my_strlen(src);
    char *dup;
    
    dup = malloc(sizeof(char) * (nb + 1));
    for (int i = 0; i < nb; i++) {
        dup[i] = src[i];
    }
    return (dup);
}
