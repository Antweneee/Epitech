/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-antoine.gavira-bottari
** File description:
** boss_battle
*/

#include <stdbool.h>
#include "my.h"

void boss_battle(sfRenderWindow *window, enti_t *enti)
{
    sfEvent evt;

    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &evt)) {
            event(enti, window, &evt);
        }
        sfRenderWindow_display(window);
        sfRenderWindow_clear(window, sfBlack);
        sfRenderWindow_drawSprite(window, enti->perso->s_perso, NULL);
        sfRenderWindow_drawSprite(window, enti->start_battle.map_sprite, NULL);
        if (sfKeyboard_isKeyPressed(sfKeyEscape)) {
            pause_window(enti, window);
        }
    }
}