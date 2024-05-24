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
    int s_str = my_strlen(dest);
    int t = s_str + my_strlen(src);
    int r = s_str;
    int p = 0;

    while (r != t) {
        dest[r] = src[p];
        r++;
        p++;
    }
    return (dest);
}
