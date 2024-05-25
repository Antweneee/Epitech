/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-mydefender-antoine.gavira-bottari
** File description:
** scene
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include "my.h"

void page_how(enti_t *enti, sfRenderWindow *window)
{
    while (sfRenderWindow_isOpen(window)) {
        draw_how(enti, window);
        sfRenderWindow_display(window);
        if (sfKeyboard_isKeyPressed(sfKeyEscape)) {
            pause_window(enti, window);
        }
    }
}

void set_rightpos(element_t *enemies, sfVector2f playerpos, int i)
{
    enemies->pos.x = playerpos.x + (i * 50);
    enemies->pos.y = playerpos.y;
    sfSprite_setPosition(enemies->sprite, playerpos);
}

void winter_scene(enti_t *enti)
{
    sfVector2f castle_pos = {1150, 40};

    enti->start_pos.x = 0;
    enti->start_pos.y = 790;
    enti->win = 2;
    enti->game_bg.text = sfTexture_createFromFile("assets/mountain.png", NULL);
    sfSprite_setTexture(enti->game_bg.sprite, enti->game_bg.text, sfTrue);
    sfSprite_setPosition(enti->castle.sprite, castle_pos);
}

void summer_scene(enti_t *enti)
{
    sfVector2f castle_pos = {1454, 54};

    enti->start_pos.x = 0;
    enti->start_pos.y = 480;
    enti->win = 1;
    enti->game_bg.text = sfTexture_createFromFile("assets/game_BG.png", NULL);
    sfSprite_setTexture(enti->game_bg.sprite, enti->game_bg.text, sfTrue);
    sfSprite_setPosition(enti->castle.sprite, castle_pos);
}