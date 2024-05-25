/*
** EPITECH PROJECT, 2020
** my_strcat
** File description:
** function that concatenates two strings
*/

int my_strlen(char const *str)
{
    int f = 0;
    while (str[f] != '\0') {
        f++;
    }
    return (f);
}

char *my_strcat(char *dest, char const *src)
{
    char *str = malloc(sizeof(char) * (my_strlen(dest) + my_strlen(src) + 1));
    int i = 0;

    for (int x = 0; dest[x] != '\0'; x++) {
        str[i++] = dest[x];
    }
    for (int x = 0; src[x] != '\0'; x++) {
        str[i++] = src[x];
    }
    str[i] = '\0';
    return (str);
}
