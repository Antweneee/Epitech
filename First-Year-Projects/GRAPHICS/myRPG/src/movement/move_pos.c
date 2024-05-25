/*
** EPITECH PROJECT, 2021
** movement
** File description:
** .
*/

#include <my.h>

void move_right(perso_t *perso)
{
    sfTime time = sfClock_getElapsedTime(perso->clock);
    float seconds = time.microseconds / 1000000.0;

    perso->pos.x += 8;
    sfSprite_setPosition(perso->s_perso, perso->pos);
    if (seconds > 0.000001)
        move_rect_right(perso);
}

void move_left(perso_t *perso)
{
    sfTime time = sfClock_getElapsedTime(perso->clock);
    float seconds = time.microseconds / 1000000.0;

    perso->pos.x -= 8;
    sfSprite_setPosition(perso->s_perso, perso->pos);
    if (seconds > 0.000001)
        move_rect_left(perso);
}

void move_up(perso_t *perso)
{
    sfTime time = sfClock_getElapsedTime(perso->clock);
    float seconds = time.microseconds / 1000000.0;

    perso->pos.y -= 8;
    sfSprite_setPosition(perso->s_perso, perso->pos);
    if (seconds > 0.000001)
        move_rect_up(perso);
}

void move_down(perso_t *perso)
{
    sfTime time = sfClock_getElapsedTime(perso->clock);
    float seconds = time.microseconds / 1000000.0;

    perso->pos.y += 8;
    sfSprite_setPosition(perso->s_perso, perso->pos);
    if (seconds > 0.000001)
        move_rect_down(perso);
}