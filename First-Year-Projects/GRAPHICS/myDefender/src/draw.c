/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-mydefender-antoine.gavira-bottari
** File description:
** draw
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include "my.h"

void draw_menu(enti_t *enti, sfRenderWindow *window)
{
    sfRenderWindow_drawSprite(window, enti->menu_bg.sprite, NULL);
    sfRenderWindow_drawSprite(window, enti->menu_start.sprite, NULL);
    sfRenderWindow_drawSprite(window, enti->menu_quit.sprite, NULL);
    sfRenderWindow_drawSprite(window, enti->button_sun.sprite, NULL);
    sfRenderWindow_drawSprite(window, enti->butt_snow.sprite, NULL);
    sfRenderWindow_drawSprite(window, enti->butt_tuto.sprite, NULL);
    sfRenderWindow_display(window);
}

void draw_pause(enti_t *enti, sfRenderWindow *window)
{
    sfRenderWindow_drawSprite(window, enti->pause_bg.sprite, NULL);
    sfRenderWindow_drawSprite(window, enti->pause_resume.sprite, NULL);
    sfRenderWindow_drawSprite(window, enti->pause_menu.sprite, NULL);
    sfRenderWindow_drawSprite(window, enti->pause_quit.sprite, NULL);
}

void draw_game(enti_t *enti, sfRenderWindow *window)
{
    sfRenderWindow_drawSprite(window, enti->game_bg.sprite, NULL);
    sfRenderWindow_drawSprite(window, enti->castle.sprite, NULL);
    sfRenderWindow_drawText(window, enti->cobra_text.cobra, NULL);
}

void draw_enemies(element_t *enemies, sfRenderWindow *window)
{
    for (; enemies; enemies = enemies->next) {
        sfRenderWindow_drawSprite(window, enemies->sprite, NULL);
    }
}

void draw_how(enti_t *enti, sfRenderWindow *window)
{
    sfRenderWindow_drawSprite(window, enti->how_bg.sprite, NULL);
}