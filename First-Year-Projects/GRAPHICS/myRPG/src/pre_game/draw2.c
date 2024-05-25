/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** draw2
*/

#include "my.h"

void draw_inventory(inventory_t inventory, sfRenderWindow *window)
{
    if (sfKeyboard_isKeyPressed(sfKeyI)) {
        sfRenderWindow_drawSprite(window, inventory.sprite, NULL);
        for (; inventory.object; inventory.object = inventory.object->next)
            sfRenderWindow_drawSprite(window, inventory.object->sprite, NULL);
    }
}

void draw_settings(enti_t *enti, sfRenderWindow *window)
{
    sfRenderWindow_display(window);
    sfRenderWindow_clear(window, sfBlack);
    sfRenderWindow_drawSprite(window, enti->settings_bg.sprite, NULL);
    sfRenderWindow_drawSprite(window, enti->settings_volume10.sprite, NULL);
    sfRenderWindow_drawSprite(window, enti->settings_volume50.sprite, NULL);
    sfRenderWindow_drawSprite(window, enti->settings_volume100.sprite, NULL);
    sfRenderWindow_drawSprite(window, enti->settings_mute.sprite, NULL);
    sfRenderWindow_drawSprite(window, enti->settings_exit.sprite, NULL);
    sfRenderWindow_drawSprite(window, enti->menu_map.sprite, NULL);
}

void draw_map_menu(enti_t *enti, sfRenderWindow *window)
{
    sfRenderWindow_display(window);
    sfRenderWindow_clear(window, sfBlack);
    sfRenderWindow_drawSprite(window, enti->menu_map_img.sprite, NULL);
    sfRenderWindow_drawSprite(window, enti->menu_map_exit.sprite, NULL);
}

void draw_selection(enti_t *enti, sfRenderWindow *window)
{
    sfRenderWindow_display(window);
    sfRenderWindow_clear(window, sfBlack);
    sfRenderWindow_drawSprite(window, enti->select.sprite, NULL);
}

void draw_cutscene(sfRenderWindow *window, sfSprite *sprite, scene_t cutscene)
{
    sfRenderWindow_display(window);
    sfRenderWindow_clear(window, sfBlack);
    sfRenderWindow_drawSprite(window, sprite, NULL);
    sfRenderWindow_drawText(window, cutscene.text1, NULL);
    sfRenderWindow_drawText(window, cutscene.text2, NULL);
    sfRenderWindow_drawText(window, cutscene.text3, NULL);
}