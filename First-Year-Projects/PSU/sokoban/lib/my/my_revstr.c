/*
** EPITECH PROJECT, 2020
** my_revstr
** File description:
** function that reverses a string
*/

int my_strlen(char const *str);

char *my_revstr(char *str)
{
    int i = my_strlen(str) - 1;
    int e = 0;
    char end;

    while (e < i) {
        end = str[e];
        str[e] = str[i];
        str[i] = end;
        e++;
        i--;
    }
    return (str);
}
