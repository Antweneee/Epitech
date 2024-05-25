/*
** EPITECH PROJECT, 2021
** gestion
** File description:
** gestion
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <stdlib.h>
#include "my.h"

struct image fill_struct(char *path, int height, int width)
{
    image_t fill;

    fill.text = sfTexture_createFromFile(path, NULL);
    fill.sprite = sfSprite_create();
    fill.Rect.top = 0;
    fill.Rect.left = 0;
    fill.Rect.height = height;
    fill.Rect.width = width;
    fill.clock = sfClock_create();
    return (fill);
}

void set_text(entities_t *entities)
{
    sfSprite_setTexture(entities->player.sprite, entities->player.text, sfTrue);
    sfSprite_setTexture(entities->BG.sprite, entities->BG.text, sfTrue);
    sfSprite_setTexture(entities->scope.sprite, entities->scope.text, sfTrue);
    sfSprite_setTextureRect(entities->player.sprite, entities->player.Rect);
}

void draw(entities_t *entities, sfRenderWindow *Window)
{
    sfRenderWindow_drawSprite(Window, entities->BG.sprite, NULL);
    sfRenderWindow_drawSprite(Window, entities->player.sprite, NULL);
    sfRenderWindow_drawSprite(Window, entities->scope.sprite, NULL);
    sfRenderWindow_display(Window);
}

void destroy_all(entities_t *entities, sfRenderWindow *Window)
{
    sfSprite_destroy(entities->player.sprite);
    sfSprite_destroy(entities->scope.sprite);
    sfSprite_destroy(entities->BG.sprite);
    sfRenderWindow_destroy(Window);
}