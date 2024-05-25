/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-mydefender-antoine.gavira-bottari
** File description:
** animation
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <stdlib.h>
#include "my.h"

void right_animation(element_t *enemies)
{
    enemies->time = sfClock_getElapsedTime(enemies->clock);
    enemies->seconds = enemies->time.microseconds / 1000000.0;
    enemies->Rect.top += 32.5;
    if (enemies->seconds > 0.2) {
        if (enemies->Rect.left == 144)
            enemies->Rect.left -= 144;
        else
            enemies->Rect.left += 24;
        sfSprite_setTextureRect(enemies->sprite, enemies->Rect);
        sfClock_restart(enemies->clock);
    }
    enemies->Rect.top -= 32.5;
}

void left_animation(element_t *enemies)
{
    enemies->time = sfClock_getElapsedTime(enemies->clock);
    enemies->seconds = enemies->time.microseconds / 1000000.0;
    enemies->Rect.top += 97.5;
    if (enemies->seconds > 0.2) {
        if (enemies->Rect.left == 144)
            enemies->Rect.left -= 144;
        else
            enemies->Rect.left += 24;
        sfSprite_setTextureRect(enemies->sprite, enemies->Rect);
        sfClock_restart(enemies->clock);
    }
    enemies->Rect.top -= 97.5;
}

void up_animation(element_t *enemies)
{
    enemies->time = sfClock_getElapsedTime(enemies->clock);
    enemies->seconds = enemies->time.microseconds / 1000000.0;
    if (enemies->seconds > 0.2) {
        if (enemies->Rect.left == 144)
            enemies->Rect.left -= 144;
        else
            enemies->Rect.left += 24;
        sfSprite_setTextureRect(enemies->sprite, enemies->Rect);
        sfClock_restart(enemies->clock);
    }
}

void down_animation(element_t *enemies)
{
    enemies->time = sfClock_getElapsedTime(enemies->clock);
    enemies->seconds = enemies->time.microseconds / 1000000.0;
    enemies->Rect.top += 65;
    if (enemies->seconds > 0.2) {
        if (enemies->Rect.left == 144)
            enemies->Rect.left -= 144;
        else
            enemies->Rect.left += 24;
        sfSprite_setTextureRect(enemies->sprite, enemies->Rect);
        sfClock_restart(enemies->clock);
    }
    enemies->Rect.top -= 65;
}