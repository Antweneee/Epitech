/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-mydefender-antoine.gavira-bottari
** File description:
** check
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include "my.h"

int check_button(enti_t *enti, int width, int height, sfSprite *button)
{
    if (enti->mouse.x > sfSprite_getPosition(button).x
    && enti->mouse.x < sfSprite_getPosition(button).x + width
    && enti->mouse.y > sfSprite_getPosition(button).y &&
    enti->mouse.y < sfSprite_getPosition(button).y + height)
        return 1;
    return 0;
}

void check_lives(enti_t *enti, sfRenderWindow *window)
{
    if (enti->lives == 0)
        loose(enti, window);
}