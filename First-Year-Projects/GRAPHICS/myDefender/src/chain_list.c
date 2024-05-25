/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-mydefender-antoine.gavira-bottari
** File description:
** chain_list
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <stdlib.h>
#include "my.h"

element_t *fill_list(char *path, int width, float height, int i)
{
    element_t *new = malloc(sizeof(element_t));

    if (new == NULL)
        return (NULL);
    new->text = sfTexture_createFromFile(path, NULL);
    new->sprite = sfSprite_create();
    new->Rect.top = 0;
    new->Rect.left = 0;
    new->Rect.height = height;
    new->Rect.width = width;
    new->clock = sfClock_create();
    new->pos.x = (i * 50);
    new->pos.y = 825;
    sfSprite_setTexture(new->sprite, new->text, sfTrue);
    sfSprite_setPosition(new->sprite, new->pos);
    sfSprite_setTextureRect(new->sprite, new->Rect);
    new->next = NULL;
    return (new);
}

element_t *add_new(element_t *enemies, int i)
{
    element_t *new;

    new = fill_list("assets/link02.png", 24, 32.5, i);
    new->next = enemies;
    return (new);
}
