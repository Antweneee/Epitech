/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-mydefender-antoine.gavira-bottari
** File description:
** move
*/

#include <stdlib.h>
#include "my.h"

void update_fake_paralax(enti_t *enti)
{
    sfIntRect rect = sfSprite_getTextureRect(enti->pause_scrolling.sprite);
    rect.width += 5;
    rect.height += 5;
    enti->pause_scrolling.vect.x -= 1;
    enti->pause_scrolling.vect.y -= 1;
    sfSprite_setTextureRect(enti->pause_scrolling.sprite, rect);
    sfSprite_setPosition(enti->pause_scrolling.sprite,
    enti->pause_scrolling.vect);
}