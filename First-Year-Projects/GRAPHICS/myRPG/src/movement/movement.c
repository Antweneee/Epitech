/*
** EPITECH PROJECT, 2021
** movement
** File description:
** .
*/

#include <stdlib.h>
#include <my.h>

void free_all(perso_t *perso)
{
    sfSprite_destroy(perso->s_perso);
    sfTexture_destroy(perso->image->t_perso);
    sfClock_destroy(perso->clock);
    free(perso);
}

void move_boy(perso_t *perso)
{
    sfTime time = sfClock_getElapsedTime(perso->clock);
    float seconds = time.microseconds / 1000000.0;
    if (sfKeyboard_isKeyPressed(sfKeyRight) && seconds > 0.07) {
        sfClock_restart(perso->clock);
        move_right(perso);
    }
    if (sfKeyboard_isKeyPressed(sfKeyLeft) && seconds > 0.07) {
        sfClock_restart(perso->clock);
        move_left(perso);
    }
    if (sfKeyboard_isKeyPressed(sfKeyUp) && seconds > 0.07) {
        sfClock_restart(perso->clock);
        move_up(perso);
    }
    if (sfKeyboard_isKeyPressed(sfKeyDown) && seconds > 0.07) {
        sfClock_restart(perso->clock);
        move_down(perso);
    }
    if (sfKeyboard_isKeyPressed(sfKeyA) && seconds > 0.07)
        sprint(perso);
}

void move_girl(perso_t *perso)
{
    sfTime time = sfClock_getElapsedTime(perso->clock);
    float seconds = time.microseconds / 1000000.0;

    if (sfKeyboard_isKeyPressed(sfKeyRight) && seconds > 0.07) {
        sfClock_restart(perso->clock);
        move_right(perso);
    }
    if (sfKeyboard_isKeyPressed(sfKeyLeft) && seconds > 0.07) {
        sfClock_restart(perso->clock);
        move_left(perso);
    }
    if (sfKeyboard_isKeyPressed(sfKeyUp) && seconds > 0.07) {
        sfClock_restart(perso->clock);
        move_up(perso);
    }
    if (sfKeyboard_isKeyPressed(sfKeyDown) && seconds > 0.07) {
        sfClock_restart(perso->clock);
        move_down(perso);
    }
    if (sfKeyboard_isKeyPressed(sfKeyA) && seconds > 0.07)
        sprint(perso);
}