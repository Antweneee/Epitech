/*
** EPITECH PROJECT, 2020
** my_strncat
** File description:
** function
*/

int my_strlen(char const *str);

char *my_strncat(char *dest, char const *src, int nb)
{
    int s_str = my_strlen(dest);
    int t = s_str + my_strlen(src);
    int r = s_str;
    int p = 0;

    while (nb > 0) {
        dest[r] = src[p];
        r++;
        p++;
        nb--;
    }
    dest[r] = '\0';
    return (dest);
}
