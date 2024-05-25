/*
** EPITECH PROJECT, 2021
** movement2
** File description:
** .
*/

#include <stdlib.h>
#include <my.h>

stat_t *fill_stat(void)
{
    stat_t *stat = malloc(sizeof(stat_t));

    stat->level = 0;
    stat->life = 100;
    stat->stat_sprite = sfSprite_create();
    stat->life100 = sfTexture_createFromFile("assets/life/life100.png", NULL);
    stat->life90 = sfTexture_createFromFile("assets/life/life90.png", NULL);
    stat->life75 = sfTexture_createFromFile("assets/life/life75.png", NULL);
    stat->life60 = sfTexture_createFromFile("assets/life/life60.png", NULL);
    stat->life45 = sfTexture_createFromFile("assets/life/life45.png", NULL);
    stat->life30 = sfTexture_createFromFile("assets/life/life30.png", NULL);
    stat->life15 = sfTexture_createFromFile("assets/life/life15.png", NULL);
    stat->life5 = sfTexture_createFromFile("assets/life/life5.png", NULL);
    sfSprite_setTexture(stat->stat_sprite, stat->life100, sfFalse);
    sfSprite_setPosition(stat->stat_sprite, (sfVector2f){7, 15});
    return stat;
}

rect_t *fill_image_boy(void)
{
    rect_t *image = malloc(sizeof(rect_t));
    sfIntRect rect = {0, 0, 32.5, 55};

    image->t_perso = sfTexture_createFromFile
    ("assets/movement_assets/naruto_up.png", NULL);
    image->direction = 1;
    image->rect = rect;
    image->clock = sfClock_create();
    return image;
}

rect_t *fill_image_girl(void)
{
    rect_t *image = malloc(sizeof(rect_t));
    sfIntRect rect = {0, 0, 45, 48};

    image->t_perso = sfTexture_createFromFile
    ("assets/movement_assets/sakura_up.png", NULL);
    image->direction = 1;
    image->rect = rect;
    image->clock = sfClock_create();
    return image;
}

perso_t *fill_perso(enti_t *enti)
{
    perso_t *perso = malloc(sizeof(perso_t));
    sfVector2f p = {500, 500};

    if (!perso)
        return NULL;
    if (enti->select.selection == 1)
        perso->image = fill_image_boy();
    else
        perso->image = fill_image_girl();
    perso->s_perso = sfSprite_create();
    perso->pos = p;
    perso->clock = sfClock_create();
    perso->stat = fill_stat();
    sfSprite_setTexture(perso->s_perso, perso->image->t_perso, sfFalse);
    sfSprite_setPosition(perso->s_perso, perso->pos);
    sfSprite_setTextureRect(perso->s_perso, perso->image->rect);
    return perso;
}