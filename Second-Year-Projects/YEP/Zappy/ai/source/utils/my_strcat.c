/*
** EPITECH PROJECT, 2022
** B-YEP-410-PAR-4-1-zappy-thomas.willson
** File description:
** my_strcat
*/

#include <stdlib.h>
#include <string.h>

/**
 * @brief strcat encapsulation that allocate a new pointer for the concat string
 * 
 * @param dest that will be concat
 * @param src to concat with the destination string
 * @return char* malloced destination string
 */
char *my_strcat(char *dest, char *src)
{
    int x = 0;
    int i = strlen(dest);
    int i2 = strlen(src);
    char *new = malloc(sizeof(char)*(i + i2 + 1));

    if (!new)
        return NULL;
    for (int j = 0; x < (i + i2); x++) {
        if (x < i)
            new[x] = dest[x];
        else {
            new[x] = src[j];
            j++;
        }
    }
    new[x] = '\0';
    return new;
}