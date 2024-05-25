/*
** EPITECH PROJECT, 2021
** object_t
** File description:
** struct_inventory
*/

#include <stdlib.h>
#include "my.h"
#include "use.h"

object_t *create_object(const char *str, int nbr, sfVector2f pos)
{
    object_t *object = malloc(sizeof(object_t));

    if (!object)
        return NULL;
    object->object = malloc(sizeof(char) * my_strlen(str) + 1);
    if (!object->object)
        return NULL;
    my_strcpy(object->object, str);
    object->number = nbr;
    object->texture = sfTexture_createFromFile(str, NULL);
    object->sprite = sfSprite_create();
    sfSprite_setTexture(object->sprite, object->texture, sfTrue);
    sfSprite_setPosition(object->sprite, pos);
    object->next = NULL;
    return object;
}

object_t *add_object(object_t *object, const char *str, int nbr, sfVector2f pos)
{
    object_t *new_object = create_object(str, nbr, pos);

    if (!object)
        return new_object;
    new_object->next = object;
    return new_object;
}

object_t *create_struct_object(void)
{
    object_t *object = NULL;

    return object;
}

inventory_t struct_creation_inventory(void)
{
    sfVector2f pos = {300, 650};
    inventory_t inventory;

    inventory.pos = pos;
    inventory.condition = 0;
    inventory.object = create_struct_object();
    inventory.sprite = sfSprite_create();
    inventory.texture = sfTexture_createFromFile(
    "assets/inventory/inventory.png", NULL);
    sfSprite_setTexture(inventory.sprite, inventory.texture, sfFalse);
    sfSprite_setPosition(inventory.sprite, inventory.pos);
    return inventory;
}