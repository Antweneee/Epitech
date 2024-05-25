/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** check
*/

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