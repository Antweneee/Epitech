/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-mydefender-antoine.gavira-bottari
** File description:
** game
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include "my.h"

void loose(enti_t *enti, sfRenderWindow *window)
{
    sfClock_restart(enti->game_over.clock);
    enti->game_over.time = sfClock_getElapsedTime(enti->game_over.clock);
    enti->game_over.seconds = enti->game_over.time.microseconds / 1000000.0;
    sfRenderWindow_clear(window, sfBlack);
    while (enti->game_over.seconds <= 3) {
        enti->game_over.time = sfClock_getElapsedTime(enti->game_over.clock);
        enti->game_over.seconds = enti->game_over.time.microseconds / 1000000.0;
        sfRenderWindow_drawSprite(window, enti->game_over.sprite, NULL);
        sfRenderWindow_display(window);
    }
    sfRenderWindow_close(window);
}

void keyboard_esc(struct sound music, enti_t *enti, sfRenderWindow *window)
{
    sfMusic_pause(music.game_mus);
    pause_window(enti, window);
    sfMusic_play(music.game_mus);
}

void game(enti_t *enti, sfRenderWindow *window)
{
    int nb = 3;
    element_t *enemies = NULL;
    struct sound music = create();

    enti->lives = 3;
    for (int i = 0; i != nb ; i++) {
        enemies = add_new(enemies, i);
        set_rightpos(enemies, enti->start_pos, i);
    }
    while (sfRenderWindow_isOpen(window)) {
        draw_game(enti, window);
        draw_enemies(enemies, window);
        check_win(enti, enemies, window);
        sfRenderWindow_display(window);
        event(enti, window);
        if (sfKeyboard_isKeyPressed(sfKeyEscape)) {
            keyboard_esc(music, enti, window);
        }
    }
    sfMusic_destroy(music.game_mus);
}