/*
** EPITECH PROJECT, 2020
** my show word array
** File description:
** display the content of an array of words
*/

#include <stdlib.h>

int nombers(char * const *tab)
{
    int nbr = 0;
    int c = 0;
    int p = 0;

    while (tab[p] != NULL) {
        while (tab[p][c] != '\0') {
            nbr = nbr + 1;
            c = c + 1;
        }
        nbr = nbr + 1;
        p = p + 1;
        c = 0;
    }
    return (nbr);
}

int my_show_word_array(char * const *tab)
{
    int c = 0;
    int p = 0;
    int i = 0;
    char *conc;
    int nbr = nombers(tab);

    conc = malloc(sizeof(char) * (nbr + 1));
    while(i != nbr) {
        conc[i] = tab[p][c];
        if (tab[p][c] == '\0') {
            conc[i] = '\n';
            p = p + 1;
            c = -1;
        }
        c = c + 1;
        i = i + 1;
    }
    conc[i -1] = '\0';
    return (0);
}
