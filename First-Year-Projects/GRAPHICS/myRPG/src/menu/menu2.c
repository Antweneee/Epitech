/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** menu2
*/

#include "my.h"

void check_settings(enti_t *enti)
{
    if (check_button(enti, 300, 100, enti->settings_volume100.sprite) == 1) {
        enti->song.volume = 0;
        sfMusic_setVolume(enti->song.music, enti->song.volume);
    }
    if (check_button(enti, 200, 200, enti->settings_mute.sprite) == 1) {
        enti->song.mute = enti->song.mute + 1;
        play_music(enti);
    }
}

void settings_page(enti_t *enti, sfRenderWindow *window)
{
    sfEvent evt;

    while (sfRenderWindow_isOpen(window)) {
        draw_settings(enti, window);
        while (sfRenderWindow_pollEvent(window, &evt)) {
            event(enti, window, &evt);
        }
        if (check_button(enti, 200, 200, enti->settings_exit.sprite) == 1)
            game_loop(enti, window);
        if (check_button(enti, 300, 100, enti->settings_volume10.sprite) == 1) {
            enti->song.volume = 10;
            sfMusic_setVolume(enti->song.music, enti->song.volume);
        }
        if (check_button(enti, 300, 100, enti->settings_volume50.sprite) == 1) {
            enti->song.volume = 30;
            sfMusic_setVolume(enti->song.music, enti->song.volume);
        }
        if (check_button(enti, 200, 200, enti->menu_map.sprite) == 1)
            map_page(enti, window);
        check_settings(enti);
    }
}

void man_page(enti_t *enti, sfRenderWindow *window)
{
    sfEvent evt;
    while (sfRenderWindow_isOpen(window)) {
        draw_info(enti, window);
        while (sfRenderWindow_pollEvent(window, &evt)) {
            event(enti, window, &evt);
        }
        if (check_button(enti, 200, 200, enti->menu_info.sprite) == 1)
            draw_info(enti, window);
        if (check_button(enti, 200, 200, enti->man_exit.sprite) == 1)
            game_loop(enti, window);
    }
}

void pause_window(enti_t *enti, sfRenderWindow *window)
{
    sfEvent evt;

    while (sfRenderWindow_isOpen(window)) {
        draw_pause(enti, window);
        while (sfRenderWindow_pollEvent(window, &evt)) {
            event(enti, window, &evt);
        }
        if (check_button(enti, 600, 200, enti->pause_resume.sprite) == 1)
            return;
        if (check_button(enti, 600, 200, enti->pause_menu.sprite) == 1) {
            enti->menu_map.i = 2;
            game_loop(enti, window);
        }
        if (check_button(enti, 200, 200, enti->pause_quit.sprite) == 1) {
            sfRenderWindow_close(window);
        }
        if (check_button(enti, 200, 200, enti->menu_map.sprite) == 1)
            map_page(enti, window);
    }
}

void map_page(enti_t *enti, sfRenderWindow *window)
{
    sfEvent evt;
    while (sfRenderWindow_isOpen(window)) {
        draw_map_menu(enti, window);
        while (sfRenderWindow_pollEvent(window, &evt)) {
            event(enti, window, &evt);
        }
        if (check_button(enti, 200, 200, enti->menu_map_exit.sprite) == 1) {
            if (enti->menu_map.i == 1)
                pause_window(enti, window);
            else
                settings_page(enti, window);
        }
    }
}