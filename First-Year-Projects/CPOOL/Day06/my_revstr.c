/*
** EPITECH PROJECT, 2020
** my revstr
** File description:
** function that reverses a strin
*/

int my_strlen(char const *str)
{
    int i;

    for (i = 0; str[i] != '\0'; i++);
    return (i);
}

char *my_revstr(char *str)
{
    int i = my_strlen(str) - 1;
    int a = 0;
    char tmp;

    while (a < i) {
        tmp = str[a];
        str[a] = str[i];
        str[i] = tmp;
        a++;
        i--;
    }
    return (str);
}
