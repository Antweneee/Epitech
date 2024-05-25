/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-mydefender-antoine.gavira-bottari
** File description:
** destroy
*/

#include "my.h"

void destroy_menu(enti_t *enti)
{
    sfSprite_destroy(enti->menu_bg.sprite);
    sfSprite_destroy(enti->menu_start.sprite);
    sfSprite_destroy(enti->menu_quit.sprite);
}

void destroy_game(enti_t *enti)
{
    sfSprite_destroy(enti->game_bg.sprite);
}

void destroy_pause(enti_t *enti)
{
    sfSprite_destroy(enti->pause_scrolling.sprite);
    sfSprite_destroy(enti->pause_bg.sprite);
    sfSprite_destroy(enti->pause_resume.sprite);
    sfSprite_destroy(enti->pause_menu.sprite);
    sfSprite_destroy(enti->pause_quit.sprite);
}

void destroy_music(enti_t *enti)
{
    sfMusic_destroy(enti->song.music);
}