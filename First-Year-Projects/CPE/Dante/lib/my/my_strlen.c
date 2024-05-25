/*
** EPITECH PROJECT, 2020
** my_strlen
** File description:
** function
*/

int my_strlen(char const *str)
{
    int f = 0;
    while (str[f] != '\0') {
        f++;
    }
    return (f);
}
