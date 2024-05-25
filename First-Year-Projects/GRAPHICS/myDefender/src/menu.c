/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-mydefender-antoine.gavira-bottari
** File description:
** menu
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include "my.h"

void event(enti_t *enti, sfRenderWindow *window)
{
    sfEvent evt;
    while (sfRenderWindow_pollEvent(window, &evt)) {
        if (evt.type == sfEvtClosed) {
            sfRenderWindow_close(window);
            break;
        }
        if (evt.type == sfEvtMouseButtonPressed)
            enti->mouse = sfMouse_getPositionRenderWindow(window);
    }
}

void pause_window(enti_t *enti, sfRenderWindow *window)
{
    while (sfRenderWindow_isOpen(window)) {
        draw_pause(enti, window);
        sfRenderWindow_display(window);
        sfRenderWindow_display(window);
        event(enti, window);
        if (check_button(enti, 390, 130, enti->pause_resume.sprite) == 1)
            return;
        if (check_button(enti, 390, 130, enti->pause_menu.sprite) == 1) {
            draw_menu(enti, window);
            loop(enti, window);
        }
        if (check_button(enti, 390, 130, enti->pause_quit.sprite) == 1)
            sfRenderWindow_close(window);
    }
}

void menu_win(enti_t *enti, sfRenderWindow *window)
{
    if (check_button(enti, 170, 100, enti->menu_start.sprite) == 1)
        game(enti, window);
    if (check_button(enti, 170, 100, enti->butt_snow.sprite) == 1)
        winter_scene(enti);
    if (check_button(enti, 170, 100, enti->button_sun.sprite) == 1)
        summer_scene(enti);
    if (check_button(enti, 512, 100, enti->butt_tuto.sprite) == 1)
        page_how(enti, window);
    if (check_button(enti, 170, 100, enti->menu_quit.sprite) == 1)
        sfRenderWindow_close(window);
}

void loop(enti_t *enti, sfRenderWindow *window)
{
    sfRenderWindow_setFramerateLimit(window, 60);
    enti->start_pos.x = 0;
    enti->start_pos.y = 825;
    while (sfRenderWindow_isOpen(window)) {
        event(enti, window);
        menu_win(enti, window);
    }
}
