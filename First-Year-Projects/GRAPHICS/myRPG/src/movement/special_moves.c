/*
** EPITECH PROJECT, 2021
** specials mooves
** File description:
** .
*/

#include <my.h>

static void sprint_right(perso_t *perso)
{
    sfIntRect rect = {0, 0, 49.5, 55};

    perso->image->rect = rect;
    sfSprite_setTextureRect(perso->s_perso, perso->image->rect);
    sfTexture_destroy(perso->image->t_perso);
    perso->image->t_perso = sfTexture_createFromFile
    ("assets/movement_assets/sprint_right.png", NULL);
    sfSprite_setTexture(perso->s_perso, perso->image->t_perso, sfFalse);
    perso->pos.x += 20;
    perso->image->rect.left += 49.5;
    sfSprite_setTextureRect(perso->s_perso, perso->image->rect);
    sfSprite_setPosition(perso->s_perso, perso->pos);
}

static void sprint_left(perso_t *perso)
{
    sfIntRect rect = {0, 0, 49.5, 55};

    perso->image->rect = rect;
    sfSprite_setTextureRect(perso->s_perso, perso->image->rect);
    sfTexture_destroy(perso->image->t_perso);
    perso->image->t_perso = sfTexture_createFromFile
    ("assets/movement_assets/sprint_left.png", NULL);
    sfSprite_setTexture(perso->s_perso, perso->image->t_perso, sfFalse);
    perso->pos.x -= 20;
    perso->image->rect.left += 49.5;
    sfSprite_setTextureRect(perso->s_perso, perso->image->rect);
    sfSprite_setPosition(perso->s_perso, perso->pos);
}

static void sprint_up(perso_t *perso)
{
    sfIntRect rect = {0, 0, 49.5, 55};

    perso->image->rect = rect;
    sfSprite_setTextureRect(perso->s_perso, perso->image->rect);
    sfTexture_destroy(perso->image->t_perso);
    perso->image->t_perso = sfTexture_createFromFile
    ("assets/movement_assets/sprint_up.png", NULL);
    sfSprite_setTexture(perso->s_perso, perso->image->t_perso, sfFalse);
    perso->pos.y -= 20;
    perso->image->rect.left += 49.5;
    sfSprite_setTextureRect(perso->s_perso, perso->image->rect);
    sfSprite_setPosition(perso->s_perso, perso->pos);
}

static void sprint_down(perso_t *perso)
{
    sfIntRect rect = {0, 0, 49.5, 55};

    perso->image->rect = rect;
    sfSprite_setTextureRect(perso->s_perso, perso->image->rect);
    sfTexture_destroy(perso->image->t_perso);
    perso->image->t_perso = sfTexture_createFromFile
    ("assets/movement_assets/sprint_down.png", NULL);
    sfSprite_setTexture(perso->s_perso, perso->image->t_perso, sfFalse);
    perso->pos.y += 20;
    perso->image->rect.left += 49.5;
    sfSprite_setTextureRect(perso->s_perso, perso->image->rect);
    sfSprite_setPosition(perso->s_perso, perso->pos);
}

void sprint(perso_t *perso)
{
    if (perso->image->direction == 1) {
        sprint_up(perso);
    }
    else if (perso->image->direction == 2) {
        sprint_down(perso);
    }
    else if (perso->image->direction == 3) {
        sprint_right(perso);
    }
    else {
        sprint_left(perso);
    }
}