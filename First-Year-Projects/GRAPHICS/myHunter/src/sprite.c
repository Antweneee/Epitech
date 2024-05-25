/*
** EPITECH PROJECT, 2021
** sprite.c
** File description:
** sprite function related
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <stdlib.h>
#include "my.h"

void animation(entities_t *entities)
{
    entities->player.time = sfClock_getElapsedTime(entities->player.clock);
    entities->player.seconds = entities->player.time.microseconds / 1000000.0;
    if (entities->player.seconds > 0.2) {
        if (entities->player.Rect.left == 240)
            entities->player.Rect.left -= 240;
        else
            entities->player.Rect.left += 120;
        sfSprite_setTextureRect(entities->player.sprite, entities->player.Rect);
        sfClock_restart(entities->player.clock);
    }
}

void scope_pos(entities_t *entities, sfRenderWindow *Window)
{
    entities->scope.vect.x = sfMouse_getPositionRenderWindow(Window).x;
    entities->scope.vect.x -= 30;
    entities->scope.vect.y = sfMouse_getPositionRenderWindow(Window).y;
    entities->scope.vect.y -= 30;
    sfSprite_setPosition(entities->scope.sprite, entities->scope.vect);
}

int life_check(int life)
{
    life -= 1;
    return (life);
}

int move_player(entities_t *entities, sfRenderWindow *Window, int life)
{
    entities->player.vect.x = sfSprite_getPosition(entities->player.sprite).x;
    entities->player.vect.y = sfSprite_getPosition(entities->player.sprite).y;
    entities->player.vect.x += 0.75;
    if (entities->player.vect.x > 1920) {
        entities->player.vect.x = 0;
        entities->player.vect.y = rand() % (1080 - 0) - 0;
        life = life_check(life);
    }
    sfSprite_setPosition(entities->player.sprite, entities->player.vect);
    return (life);
}

void kill_player(entities_t *entities, sfRenderWindow *Window)
{
    sfVector2f mouse_pos;
    sfVector2f lion_pos;

    mouse_pos.x = sfMouse_getPositionRenderWindow(Window).x;
    mouse_pos.y = sfMouse_getPositionRenderWindow(Window).y;
    lion_pos.x = sfSprite_getPosition(entities->player.sprite).x;
    lion_pos.y = sfSprite_getPosition(entities->player.sprite).y;
    if (mouse_pos.x >= lion_pos.x
        && mouse_pos.x <= (lion_pos.x + 120)
                && mouse_pos.y >= lion_pos.y
        && mouse_pos.y <= (lion_pos.y + 60)) {
        if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue) {
            entities->player.vect.x = -500;
            entities->player.vect.y = rand() % (1080 - 0) - 0;
        }
    }
    sfSprite_setPosition(entities->player.sprite, entities->player.vect);
}
