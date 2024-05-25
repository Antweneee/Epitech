/*
** EPITECH PROJECT, 2021
** double
** File description:
** set_game
*/

#include <stdlib.h>
#include "my.h"

scene_t set_cutscene(char *path, int x, sfTime a, char **msg)
{
    int seconds = a.microseconds;
    scene_t fill;
    sfFont *font = sfFont_createFromFile("assets/fonts/naruto_font.ttf");

    fill.text1 = sfText_create();
    fill.text2 = sfText_create();
    fill.text3 = sfText_create();
    fill.texture = sfTexture_createFromFile(path, NULL);
    fill.sprite = sfSprite_create();

    fill.map_sprite = sfSprite_create();

    if (seconds % 2 == 0)
        fill.map_texture = sfTexture_createFromFile(
        "assets/cutscene/map2.jpg", NULL);
    else if (seconds % 3 == 0)
        fill.map_texture = sfTexture_createFromFile(
        "assets/cutscene/map4.png", NULL);
    else
        fill.map_texture = sfTexture_createFromFile(
        "assets/cutscene/tournament.png", NULL);
    sfSprite_setTexture(fill.map_sprite, fill.map_texture, sfTrue);

    if (x == 1) {
        sfText_setColor(fill.text1, sfBlack);
        sfText_setColor(fill.text2, sfBlack);
        sfText_setColor(fill.text3, sfBlack);
    }
    sfText_setPosition(fill.text1, (sfVector2f){40, 180});
    sfText_setFont(fill.text1, font);
    sfText_setString(fill.text1, msg[0]);
    sfText_setCharacterSize(fill.text1, 45);

    sfText_setPosition(fill.text2, (sfVector2f){1300, 400});
    sfText_setFont(fill.text2, font);
    sfText_setString(fill.text2, msg[1]);
    sfText_setCharacterSize(fill.text2, 45);

    sfText_setPosition(fill.text3, (sfVector2f){750, 900});
    sfText_setFont(fill.text3, font);
    sfText_setString(fill.text3, msg[2]);
    sfText_setCharacterSize(fill.text3, 45);

    sfSprite_setTexture(fill.sprite, fill.texture, sfTrue);
    return fill;
}

quest_t set_questobject(char *path, sfVector2f quest_pos, int x, int y)
{
    quest_t fill;
    sfIntRect rect = {0, 0, x, y};

    fill.texture = sfTexture_createFromFile(path, NULL);
    fill.sprite = sfSprite_create();
    fill.status = 0;
    fill.rect = rect;
    sfSprite_setTexture(fill.sprite, fill.texture, sfTrue);
    sfSprite_setPosition(fill.sprite, quest_pos);
    return fill;
}

gameobj_t setup_game(void)
{
    gameobj_t fill;

    fill.task_one = set_questobject("assets/game_assets/quest_01.png",
    (sfVector2f) {200, 210}, 26, 67);
    fill.task_two = set_questobject("assets/game_assets/quest_02.png",
    (sfVector2f) {620, 400}, 69, 23);
    fill.task_three = set_questobject("assets/game_assets/quest_03.png",
    (sfVector2f) {1400, 900}, 64, 26);
    return fill;
}