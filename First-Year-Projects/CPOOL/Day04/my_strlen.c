/*
** EPITECH PROJECT, 2020
** My strlen
** File description:
** counts and returns the number of characters found in the string
*/

int my_strlen(char const *str)
{
    int n;

    while(str[n] !='\0'){
        n = n + 1;
    }
    return(n);

}

