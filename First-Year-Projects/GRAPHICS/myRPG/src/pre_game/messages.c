/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-antoine.gavira-bottari
** File description:
** message
*/

#include <stdlib.h>
#include "use.h"
#include "my.h"

char **finished_txt(void)
{
    char **text = malloc(sizeof(char *) * 4);
    for (int i = 0; i != 3; i++)
        text[i] = malloc(sizeof(char) * 50);
    text[0] = "you found all the objects\nnow go to the ...!";
    text[1] = "someone is approching\nyou be carefull !!";
    text[2] = "press  Z  to skip";
    text[3] = NULL;

    return (text);
}

char **enemyarrive_txt(void)
{
    char **text = malloc(sizeof(char *) * 4);
    for (int i = 0; i != 3; i++)
        text[i] = malloc(sizeof(char) * 40);
    text[0] = "I see you became a\nreal ninja";
    text[1] = "now bring it on !!!";
    text[2] = "press  S  to skip";
    text[3] = NULL;

    return (text);
}