/*
** EPITECH PROJECT, 2021
** set
** File description:
** set
*/

#include "my.h"

void obstacle_related(struct movement *move, sfRenderWindow *Window, struct texture text)
{
    int appear = 0;

    if (move->indi == 0) {
        sfRenderWindow_drawSprite(Window, text.GM, NULL);
        sfRenderWindow_display(Window);
    }
    if (appear == 0) {
        sfSprite_move(text.bad_guy, move->pos);
        sfSprite_setPosition(text.bad_guy, move->pos);
        move->pos.y = 900;
    }
    if (move->pos.x == 0)
        appear = 1;
    sfClock_restart(move->ob_clock);
    if (appear == 1)
        move->indi = move->indi - 1;
}

void set_position(struct texture text, struct movement move, sfIntRect recta, sfRenderWindow *Window)
{
    sfSprite_setTextureRect(text.player, recta);
    sfSprite_setPosition(text.player, move.player_pos);
    obstacle_related(&move, Window, text);
}

void set(struct texture text)
{
    sfIntRect rectangle = {0,0,400,100};
    sfVector2f butpos = {600, 800};
    sfIntRect start_rectangle = {0,0,400,100};
    sfVector2f start_butpos = {1200, 800};

    sfSprite_setTexture(text.mountain, text.mountain_t, sfTrue);
    sfSprite_setTexture(text.road, text.road_t, sfTrue);
    sfSprite_setTexture(text.town, text.town_t, sfTrue);
    sfSprite_setTexture(text.GM, text.GM_t, sfTrue);
    sfSprite_setTexture(text.gamesp, text.gametext, sfTrue);
    sfSprite_setTexture(text.bad_guy, text.bad_guy_t, sfTrue);
    sfSprite_setTexture(text.image1, text.image, sfTrue);
    sfSprite_setTexture(text.button_sprite, text.button_texture, sfTrue);
    sfSprite_setTexture(text.start_sprite, text.button_start, sfTrue);
    sfSprite_setTextureRect(text.button_sprite, rectangle);
    sfSprite_setTextureRect(text.start_sprite, start_rectangle);
    sfSprite_setPosition(text.button_sprite, butpos);
    sfSprite_setPosition(text.start_sprite, start_butpos);
}

void second_set(struct texture text, struct movement move)
{
    sfVector2f road_pos = {0, 800};
    sfVector2f town_pos = {0, -100};
    sfVector2f bad_guypos = {1800, 700};

    sfSprite_setTexture(text.player, text.player_t, sfTrue);
    sfSprite_setTexture(text.jump, text.jump_t, sfTrue);
    sfSprite_setPosition(text.road, road_pos);
    sfSprite_setPosition(text.town, town_pos);
    sfSprite_setPosition(text.bad_guy, bad_guypos);
    sfSprite_setPosition(text.player, move.player_pos);
}
