/*
** EPITECH PROJECT, 2020
** concat param
** File description:
** function that turns the command-line given arguments into a single string
*/

#include <stdlib.h>

int nomber(int argc, char **argv)
{
    int nbr = 0;
    int c = 0;
    int p = 0;

    while (p != argc) {
        while (argv[p][c] != '\0') {
            nbr++;
            c++;
        }
        nbr++;
        p++;
        c = 0;
    }
    return (nbr);
}

char *concat_params(int argc, char **argv)
{
    int c = 0;
    int p = 0;
    int i = 0;
    char *conc;
    int nbr = nomber(argc, argv);

    conc = malloc(sizeof(char) * (nbr + 1));
    while(i != nbr) {
        conc[i] = argv[p][c];
        if (argv[p][c] == '\0') {
            conc[i] = '\n';
            p = p + 1;
            c = -1;
        }
        c = c + 1;
        i = i + 1;
    }
    conc[i -1] = '\0';
    return (conc);
}
