/*
** EPITECH PROJECT, 2021
** $
** File description:
** movement
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include "my.h"

void right_moves(element_t *enemies)
{
    enemies->pos.x += 1;
    sfSprite_setPosition(enemies->sprite, enemies->pos);
    right_animation(enemies);
}

void down_moves(element_t *enemies)
{
    enemies->pos.y += 1;
    sfSprite_setPosition(enemies->sprite, enemies->pos);
    down_animation(enemies);
}

void left_moves(element_t *enemies)
{
    enemies->pos.x -= 1;
    sfSprite_setPosition(enemies->sprite, enemies->pos);
    left_animation(enemies);
}

void up_moves(element_t *enemies)
{
    enemies->pos.y -= 1;
    sfSprite_setPosition(enemies->sprite, enemies->pos);
    up_animation(enemies);
}

void check_win(enti_t *enti, element_t *enemies, sfRenderWindow *window)
{
    for (; enemies; enemies = enemies->next) {
        if (enti->win == 0)
            normal_path(enemies, enti, window);
        if (enti->win == 1)
            summer_path(enemies, enti, window);
        if (enti->win == 2) {
            snow_path(enemies, enti, window);
        }
    }
}
