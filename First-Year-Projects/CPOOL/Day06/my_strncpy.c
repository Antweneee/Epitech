/*
** EPITECH PROJECT, 2020
** my strncpy
** File description:
** function that copiesncharacters from a string into another
*/

char *my_strncpy(char *dest , char  const *src , int n)
{
    int c;
    
    for (c = 0; src[c] != src[n]; c++) {
        dest[c] = src[c];
    }
    return (dest);
}
