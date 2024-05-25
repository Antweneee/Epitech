/*
** EPITECH PROJECT, 2020
** my_strncpy
** File description:
** function that copiesncharacters from a string into another
*/

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;

    while (src[i] != src[n]) {
        dest[i] = src[i];
        i++;
    }
    return (dest);
}
