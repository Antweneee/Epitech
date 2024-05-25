/*
** EPITECH PROJECT, 2021
** movement
** File description:
** .
*/

#include <my.h>

void stay_cool(perso_t *perso)
{
    sfTexture_destroy(perso->image->t_perso);
    if (perso->image->direction == 4)
        perso->image->t_perso = sfTexture_createFromFile
        ("assets/movement_assets/stay_left.png", NULL);
    if (perso->image->direction == 3)
        perso->image->t_perso = sfTexture_createFromFile
        ("assets/movement_assets/stay_right.png", NULL);
    if (perso->image->direction == 2)
        perso->image->t_perso = sfTexture_createFromFile
        ("assets/movement_assets/stay_down.png", NULL);
    if (perso->image->direction == 1)
        perso->image->t_perso = sfTexture_createFromFile
        ("assets/movement_assets/stay_up.png", NULL);
    sfSprite_setTexture(perso->s_perso, perso->image->t_perso, sfFalse);
    sfSprite_setTextureRect(perso->s_perso, perso->image->rect);
}

void move_rect_right(perso_t *perso)
{
    if (perso->image->direction != 3) {
        sfTexture_destroy(perso->image->t_perso);
        perso->image->t_perso = sfTexture_createFromFile
        ("assets/movement_assets/naruto_right.png", NULL);
        sfSprite_setTexture(perso->s_perso, perso->image->t_perso, sfFalse);
        perso->image->direction = 3;
    }
    if (perso->image->rect.left >= 160) {
        perso->image->rect.left = 0;
    }
    else
        perso->image->rect.left += 32.5;
    sfSprite_setTextureRect(perso->s_perso, perso->image->rect);
}

void move_rect_left(perso_t *perso)
{
    if (perso->image->direction != 4) {
        sfTexture_destroy(perso->image->t_perso);
        perso->image->t_perso = sfTexture_createFromFile
        ("assets/movement_assets/naruto_left.png", NULL);
        sfSprite_setTexture(perso->s_perso, perso->image->t_perso, sfFalse);
        perso->image->direction = 4;
    }
    if (perso->image->rect.left >= 160) {
        perso->image->rect.left = 0;
    }
    else
        perso->image->rect.left += 32.5;
    sfSprite_setTextureRect(perso->s_perso, perso->image->rect);
}

void move_rect_up(perso_t *perso)
{
    if (perso->image->direction != 1) {
        sfTexture_destroy(perso->image->t_perso);
        perso->image->t_perso = sfTexture_createFromFile
        ("assets/movement_assets/naruto_up.png", NULL);
        sfSprite_setTexture(perso->s_perso, perso->image->t_perso, sfFalse);
        perso->image->direction = 1;
    }
    if (perso->image->rect.left >= 160) {
        perso->image->rect.left = 0;
    }
    else
        perso->image->rect.left += 32.5;
    sfSprite_setTextureRect(perso->s_perso, perso->image->rect);
}

void move_rect_down(perso_t *perso)
{
    if (perso->image->direction != 2) {
        sfTexture_destroy(perso->image->t_perso);
        perso->image->t_perso = sfTexture_createFromFile
        ("assets/movement_assets/naruto_down.png", NULL);
        sfSprite_setTexture(perso->s_perso, perso->image->t_perso, sfFalse);
        perso->image->direction = 2;
    }
    if (perso->image->rect.left >= 160) {
        perso->image->rect.left = 0;
    }
    else
        perso->image->rect.left += 32.5;
    sfSprite_setTextureRect(perso->s_perso, perso->image->rect);
}