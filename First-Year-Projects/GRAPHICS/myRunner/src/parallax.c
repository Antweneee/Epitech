/*
** EPITECH PROJECT, 2021
** parallax function
** File description:
** parallax effect function
*/

#include "my.h"

void mountain_p(struct texture *text)
{
    sfTime time;
    float seconds;

    time = sfClock_getElapsedTime(text->clock_m);
    seconds = time.microseconds / 1000000.0;
    if (seconds > 0.035) {
        if (text->para_m.left >= 3840) {
            text->para_m.left = 0;
        } else {
            text->para_m.left += 2;
        }
        sfSprite_setTextureRect(text->mountain, text->para_m);
        sfClock_restart(text->clock_m);
    }
}

void town_p(struct texture *text)
{
    sfTime time;
    float seconds;

    time = sfClock_getElapsedTime(text->clock_t);
    seconds = time.microseconds / 1000000.0;
    if (seconds > 0.025) {
        if (text->para_t.left >= 3840) {
            text->para_t.left = 0;
        } else {
            text->para_t.left += 2;
        }
        sfSprite_setTextureRect(text->town, text->para_t);
        sfClock_restart(text->clock_t);
    }
}

void road_p(struct texture *text)
{
    sfTime time;
    float seconds;

    time = sfClock_getElapsedTime(text->clock_r);
    seconds = time.microseconds / 1000000.0;
    if (seconds > 0.0125) {
        if (text->para_r.left >= 3840) {
            text->para_r.left = 0;
        } else {
            text->para_r.left += 2;
        }
        sfSprite_setTextureRect(text->road, text->para_r);
        sfClock_restart(text->clock_r);
    }
}

void sky_p(struct texture *text)
{
    sfTime time;
    float seconds;

    time = sfClock_getElapsedTime(text->clock_s);
    seconds = time.microseconds / 1000000.0;
    if (seconds > 0.05) {
        if (text->para_s.left >= 3840) {
            text->para_s.left = 0;
        } else {
            text->para_s.left += 1;
        }
        sfSprite_setTextureRect(text->gamesp, text->para_s);
        sfClock_restart(text->clock_s);
    }
}

void parallax(struct texture *text)
{
    mountain_p(text);
    sky_p(text);
    road_p(text);
    town_p(text);
}
