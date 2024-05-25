/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-mydefender-antoine.gavira-bottari
** File description:
** destroy
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include "my.h"

void destroy_all(enti_t *enti, sfRenderWindow *window)
{
    sfSprite_destroy(enti->menu_bg.sprite);
    sfSprite_destroy(enti->menu_start.sprite);
    sfSprite_destroy(enti->menu_quit.sprite);
    sfSprite_destroy(enti->game_bg.sprite);
    sfSprite_destroy(enti->castle.sprite);
    sfText_destroy(enti->castle.cobra);
    sfSprite_destroy(enti->pause_bg.sprite);
    sfSprite_destroy(enti->pause_resume.sprite);
    sfSprite_destroy(enti->pause_menu.sprite);
    sfSprite_destroy(enti->pause_quit.sprite);
    sfSprite_destroy(enti->how_bg.sprite);
    sfRenderWindow_destroy(window);
}