/*
** EPITECH PROJECT, 2020
** my evil str
** File description:
** swap the first sting letter with the last one
*/

int *my_evil_str(char *str)
{
    char n;

    while (str[n] !='\0') {
        n = n + 1;
    }
    n = n + 1;
    while (str[n] != str[0]) {
        n = n - 1;
    }
    return (str);
}
