/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-antoine.gavira-bottari
** File description:
** cut_scene
*/

#include "my.h"

void inventory_management(sfRenderWindow *window, enti_t *enti)
{
    check_questitems(enti);
    draw_inventory(enti->inventory, window);
}

void enemy_arrive(sfRenderWindow *window, enti_t *enti)
{
    while (sfRenderWindow_isOpen(window)) {
        draw_cutscene(window, enti->start_battle.sprite, enti->start_battle);
        if (sfKeyboard_isKeyPressed(sfKeyEscape)) {
            pause_window(enti, window);
        }
        if (sfKeyboard_isKeyPressed(sfKeyS))
            break;
    }
    boss_battle(window, enti);
}

void quest_completed(sfRenderWindow *window, enti_t *enti)
{
    sfEvent evt;

    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &evt)) {
            event(enti, window, &evt);
        }
        draw_cutscene(window, enti->finished.sprite, enti->finished);
        if (sfKeyboard_isKeyPressed(sfKeyEscape)) {
            pause_window(enti, window);
        }
        if (sfKeyboard_isKeyPressed(sfKeyZ))
            break;
    }
    enemy_arrive(window, enti);
}