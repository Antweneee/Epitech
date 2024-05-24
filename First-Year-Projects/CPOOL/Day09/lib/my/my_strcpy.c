/*
** EPITECH PROJECT, 2020
** my strcpy
** File description:
** function that copies a string into another
*/

char *my_strcpy(char *dest, char const *scr)
{
    int c;

    for (c = 0; scr[c] != '\0'; c++) {
        dest[c] = scr[c];
    }
    dest[c] = '\0';
    return (dest);
}
