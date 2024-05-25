/*
** EPITECH PROJECT, 2021
** gestion.c
** File description:
** gestion
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include "my.h"

void gestion(void)
{
    sfRenderWindow *Window;
    sfVideoMode video_mode = {1920, 1080, 32};
    entities_t entities;
    int life = 3;
    entities.player = fill_struct("assets/lion.png", 60, 120);
    entities.scope = fill_struct("assets/Scope.png", 60, 60);
    entities.BG = fill_struct("assets/wallpaper.jpg", 1920, 1080);

    set_text(&entities);
    Window = sfRenderWindow_create(video_mode, "my_h", sfDefaultStyle, NULL);
    sfRenderWindow_setMouseCursorVisible(Window, sfFalse);
    while (sfRenderWindow_isOpen(Window)) {
        animation(&entities);
        scope_pos(&entities, Window);
        life = move_player(&entities, Window, life);
        kill_player(&entities, Window);
        draw(&entities, Window);
        if (sfKeyboard_isKeyPressed(sfKeyEscape) || life == 0)
            break;
    }
    destroy_all(&entities, Window);
}