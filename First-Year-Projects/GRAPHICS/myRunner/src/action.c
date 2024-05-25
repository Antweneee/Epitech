/*
** EPITECH PROJECT, 2020
** loop
** File description:
** mouse position & actions
*/

#include "../include/my.h"
#include <SFML/Graphics/RenderWindow.h>
#include <stdio.h>

void jump(sfRenderWindow *Window, struct movement move, struct texture text)
{
    struct jump j_sound = setJ_sound();

    move.player_pos.y = 725;
    sfSprite_setPosition(text.player, move.player_pos);
    sfRenderWindow_drawSprite(Window, text.player, NULL);
    sfRenderWindow_display(Window);
    sfMusic_destroy(j_sound.Jump);
}

void boucle(sfRenderWindow *Window, sfVector2i mousepos, struct texture text, struct movement move)
{
    sfEvent evt;
    sfVector2i mouse;
    int i = 0;

    while (sfRenderWindow_pollEvent(Window, &evt)) {
        if (evt.type == sfEvtMouseButtonPressed) {
            mouse.x = evt.mouseButton.x;
            mouse.y = evt.mouseButton.y;
            i++;
        }
        mousepos = sfMouse_getPositionRenderWindow(Window);
        if (evt.type == sfEvtClosed)
            sfRenderWindow_close(Window);
        if (evt.type == sfEvtMouseButtonPressed) {
            start_mse(Window, text, mousepos, evt, move);
        }
    }
}
