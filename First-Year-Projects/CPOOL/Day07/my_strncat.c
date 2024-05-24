/*
** EPITECH PROJECT, 2020
** my strncat
** File description:
** copy a string in an other string but whith a given number
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

char *my_strncat(char *dest , char  const *src , int nb)
{
    int first_str = caracters_in_dest(dest);
    int total = first_str + my_strlen_src(src);
    int count = first_str;
    int p = 0;
    int calcul = 0;

    while (nb != 0) {
        dest[count] = src[p];
        count++;
        p++;
        nb--;
    }
    return (dest);
}
