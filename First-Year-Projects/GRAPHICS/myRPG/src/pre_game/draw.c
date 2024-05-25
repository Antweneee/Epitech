/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-mydefender-antoine.gavira-bottari
** File description:
** draw
*/

#include "my.h"

void draw_menu(enti_t *enti, sfRenderWindow *window)
{
    sfRenderWindow_display(window);
    sfRenderWindow_clear(window, sfBlack);
    sfRenderWindow_drawSprite(window, enti->menu_bg.sprite, NULL);
    sfRenderWindow_drawSprite(window, enti->menu_start.sprite, NULL);
    sfRenderWindow_drawSprite(window, enti->menu_quit.sprite, NULL);
    sfRenderWindow_drawSprite(window, enti->menu_info.sprite, NULL);
    sfRenderWindow_drawSprite(window, enti->menu_settings.sprite, NULL);
}

void draw_stat(enti_t *enti, sfRenderWindow *window)
{
    int life = enti->perso->stat->life;
    sfSprite *sprite = enti->perso->stat->stat_sprite;

    if (life >= 0 && life <= 5)
        sfSprite_setTexture(sprite, enti->perso->stat->life5, sfFalse);
    if (life > 5 && life < 15)
        sfSprite_setTexture(sprite, enti->perso->stat->life15, sfFalse);
    if (life >= 15 && life <= 30)
        sfSprite_setTexture(sprite, enti->perso->stat->life30, sfFalse);
    if (life > 30 && life < 45)
        sfSprite_setTexture(sprite, enti->perso->stat->life45, sfFalse);
    if (life >= 45 && life <= 60)
        sfSprite_setTexture(sprite, enti->perso->stat->life60, sfFalse);
    if (life > 60 && life < 75)
        sfSprite_setTexture(sprite, enti->perso->stat->life75, sfFalse);
    if (life >= 75 && life <= 90)
        sfSprite_setTexture(sprite, enti->perso->stat->life90, sfFalse);
    if (life > 90 && life < 100)
        sfSprite_setTexture(sprite, enti->perso->stat->life100, sfFalse);
    sfRenderWindow_drawSprite(window, sprite, NULL);
}

void draw_game(enti_t *enti, sfRenderWindow *window)
{
    sfRenderWindow_display(window);
    sfRenderWindow_clear(window, sfBlack);
    sfRenderWindow_drawSprite(window, enti->game_bg.sprite, NULL);
    if (enti->game.task_one.status == 0)
        sfRenderWindow_drawSprite(window, enti->game.task_one.sprite, NULL);
    if (enti->game.task_two.status == 0)
        sfRenderWindow_drawSprite(window, enti->game.task_two.sprite, NULL);
    if (enti->game.task_three.status == 0)
        sfRenderWindow_drawSprite(window, enti->game.task_three.sprite, NULL);
    sfRenderWindow_drawSprite(window, enti->perso->s_perso, NULL);
    draw_stat(enti, window);
}

void draw_info(enti_t *enti, sfRenderWindow *window)
{
    sfRenderWindow_display(window);
    sfRenderWindow_clear(window, sfBlack);
    sfRenderWindow_drawSprite(window, enti->man_bg.sprite, NULL);
    sfRenderWindow_drawSprite(window, enti->man_exit.sprite, NULL);
}

void draw_pause(enti_t *enti, sfRenderWindow *window)
{
    sfRenderWindow_display(window);
    sfRenderWindow_clear(window, sfBlack);
    update_fake_paralax(enti);
    sfRenderWindow_drawSprite(window, enti->pause_scrolling.sprite, NULL);
    sfRenderWindow_drawSprite(window, enti->pause_resume.sprite, NULL);
    sfRenderWindow_drawSprite(window, enti->pause_menu.sprite, NULL);
    sfRenderWindow_drawSprite(window, enti->pause_quit.sprite, NULL);
    sfRenderWindow_drawSprite(window, enti->menu_map.sprite, NULL);
}