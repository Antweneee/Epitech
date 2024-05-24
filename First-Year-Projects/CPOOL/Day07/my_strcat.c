/*
** EPITECH PROJECT, 2020
** my strcat
** File description:
** concatenate two strings
*/

int my_strlen_src(char const *src)
{
    int c = 0;

    while (src[c] != '\0') {
        c++;
    }
    return (c);
}

int caracters_in_dest(char *dest)
{
    int i;

    while (dest[i] != '\0') {
        i++;
    }
    return (i);
}

char *my_strcat(char *dest, char const *src)
{
    int first_str = caracters_in_dest(dest);
    int total = first_str + my_strlen_src(src);
    int count = first_str;
    int p = 0;

    while (count != total) {
        dest[count] = src[p];
        count++;
        p++;
    }
    return (dest);
}
