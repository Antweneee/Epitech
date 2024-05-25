/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-mydefender-antoine.gavira-bottari
** File description:
** menu
*/

#include <stdlib.h>
#include "my.h"

void game_loop(enti_t *enti, sfRenderWindow *window)
{
    sfEvent evt;
    sfRenderWindow_setFramerateLimit(window, 60);
    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &evt)) {
            event(enti, window, &evt);
        }
        check_menu_choice(enti, window);
        draw_menu(enti, window);
    }
}

void event(enti_t *enti, sfRenderWindow *window, sfEvent *evt)
{
    if (evt->type == sfEvtClosed) {
        sfRenderWindow_close(window);
        exit(0);
    }
    if (evt->type == sfEvtMouseButtonPressed)
        enti->mouse = sfMouse_getPositionRenderWindow(window);
}

void selection(enti_t *enti, sfRenderWindow *window)
{
    sfEvent evt;

    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &evt)) {
            event(enti, window, &evt);
        }
        draw_selection(enti, window);
        if (enti->mouse.x > 180 && enti->mouse.x < 300
        && enti->mouse.y > 410 && enti->mouse.y < 530) {
            enti->menu_map.i = 1;
            enti->select.selection = 1;
            start_game(enti, window);
        } if (enti->mouse.x > 480 && enti->mouse.x < 600
        && enti->mouse.y > 650 && enti->mouse.y < 770) {
            enti->menu_map.i = 1;
            enti->select.selection = 2;
            start_game(enti, window);
        }
    }
}

void check_menu_choice(enti_t *enti, sfRenderWindow *window)
{
    if (check_button(enti, 600, 200, enti->menu_start.sprite) == 1) {
        if (!enti->select.selection)
            selection(enti, window);
        else
            start_game(enti, window);
    }
    if (check_button(enti, 600, 200, enti->menu_quit.sprite) == 1)
        sfRenderWindow_close(window);
    if (check_button(enti, 200, 200, enti->menu_info.sprite) == 1)
        man_page(enti, window);
    if (check_button(enti, 200, 200, enti->menu_settings.sprite) == 1)
        settings_page(enti, window);
}