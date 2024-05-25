/*
** EPITECH PROJECT, 2020
** gestion
** File description:
** gestion
*/

#include "my.h"

struct texture text;

void draw(struct texture text, sfRenderWindow *Window)
{
    sfRenderWindow_drawSprite(Window, text.gamesp, NULL);
    sfRenderWindow_drawSprite(Window, text.mountain, NULL);
    sfRenderWindow_drawSprite(Window, text.road, NULL);
    sfRenderWindow_drawSprite(Window, text.town, NULL);
    sfRenderWindow_drawSprite(Window, text.player, NULL);
    sfRenderWindow_drawSprite(Window, text.bad_guy, NULL);
    sfRenderWindow_display(Window);
}

int animation(struct movement move, sfIntRect recta)
{
    sfTime time;
    float seconds;

    time = sfClock_getElapsedTime(move.clock);
    seconds = time.microseconds / 1000000.0;
    if (seconds > 0.2) {
        if (recta.left == 300)
            recta.left -= 300;
        else
            recta.left += 150;
        sfClock_restart(move.clock);
    }
    return (recta.left);
}

void game(sfRenderWindow *Window, struct texture text, struct movement move)
{
    sfIntRect recta;
    struct sound music = create();

    recta.top = 0;
    recta.left = 0;
    recta.width = 150;
    recta.height = 180;
    while (8) {
        sfRenderWindow_setFramerateLimit(Window, 60);
        sfRenderWindow_clear(Window, sfBlack);
        recta.left = animation(move, recta);
        parallax(&text);
        draw(text, Window);
        set_position(text, move, recta, Window);
        if (sfKeyboard_isKeyPressed(sfKeySpace))
            jump(Window, move, text);
        if (sfKeyboard_isKeyPressed(sfKeyEscape))
            break;
    }
    sfMusic_destroy(music.game_mus);
}

void start_mse(sfRenderWindow *Window, struct texture text, sfVector2i mousepos, sfEvent evt, struct movement move)
{
    if (mousepos.x > sfSprite_getPosition(text.button_sprite).x && mousepos.x <
        sfSprite_getPosition(text.button_sprite).x + 400 && mousepos.y >
        sfSprite_getPosition(text.button_sprite).y && mousepos.y <
        sfSprite_getPosition(text.button_sprite).y + 100)
        sfRenderWindow_close(Window);
    if (mousepos.x > sfSprite_getPosition(text.start_sprite).x && mousepos.x <
        sfSprite_getPosition(text.start_sprite).x + 400 && mousepos.y >
        sfSprite_getPosition(text.start_sprite).y && mousepos.y <
        sfSprite_getPosition(text.start_sprite).y + 100) {
        game(Window, text, move);
    }
}
