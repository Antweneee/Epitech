/*
** EPITECH PROJECT, 2021
** set.c
** File description:
** set everything
*/

#include "my.h"

void set_txt(enti_t *enti)
{
    enti->pause_scrolling.vect = (sfVector2f){-1920, - 1080};
    enti->pause_scrolling.sprite = sfSprite_create();
    enti->pause_scrolling.text = sfTexture_createFromFile("assets/rpgg.png",
    NULL);
    sfTexture_setRepeated(enti->pause_scrolling.text, sfTrue);
    sfSprite_setTexture(enti->pause_scrolling.sprite,
    enti->pause_scrolling.text, sfTrue);
    sfSprite_setTextureRect(enti->pause_scrolling.sprite,
    (sfIntRect){0, 0, 10000, 10000});
}

select_t fill_selection(void)
{
    select_t select;

    select.sprite = sfSprite_create();
    select.texture = sfTexture_createFromFile("assets/menu_assets/select.jpg",
    NULL);
    sfSprite_setTexture(select.sprite, select.texture, sfFalse);
    select.selection = 0;

    return select;
}