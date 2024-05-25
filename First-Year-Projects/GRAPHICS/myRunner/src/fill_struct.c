/*
** EPITECH PROJECT, 2021
** fill struct
** File description:
** fill my struct
*/

#include "my.h"

struct texture fill_text(void)
{
    struct texture text;

    text.player_t = sfTexture_createFromFile("assets/player_running.png", NULL);
    text.jump_t = sfTexture_createFromFile("assets/player_jumping.png", NULL);
    text.mountain_t = sfTexture_createFromFile("assets/mountain.png", NULL);
    text.road_t = sfTexture_createFromFile("assets/road.png", NULL);
    text.town_t = sfTexture_createFromFile("assets/town_sheet.png", NULL);
    text.bad_guy_t = sfTexture_createFromFile("assets/badguy.png", NULL);
    text.GM_t = sfTexture_createFromFile("assets/gameover.jpg", NULL);
    text.gametext = sfTexture_createFromFile("assets/sky.png", NULL);
    text.image = sfTexture_createFromFile("assets/oui.jpg", NULL);
    text.button_texture = sfTexture_createFromFile("assets/button.png", NULL);
    text.button_start = sfTexture_createFromFile("assets/start_button.png", NULL);
    text.jump = sfSprite_create();
    text.player = sfSprite_create();
    text.mountain = sfSprite_create();
    text.road = sfSprite_create();
    text.town = sfSprite_create();
    text.bad_guy = sfSprite_create();
    return (text);
}

struct texture fill_pre(void)
{
    struct texture text;

    text.GM = sfSprite_create();
    text.gamesp = sfSprite_create();
    text.image1 = sfSprite_create();
    text.button_sprite = sfSprite_create();
    text.start_sprite = sfSprite_create();
    text.video_mode.width = 1920;
    text.video_mode.height = 1080;
    text.video_mode.bitsPerPixel = 32;
    text.clock_m = sfClock_create();
    text.clock_t = sfClock_create();
    text.clock_r = sfClock_create();
    text.clock_s = sfClock_create();
    text.para_m.top = 0;
    text.para_m.left = 0;
    text.para_m.height = 1080;
    text.para_m.width = 1920;
    text.para_s.top = 0;
    return (text);
}

struct texture structure(void)
{
    struct texture text;
    
    text.para_s.left = 0;
    text.para_s.height = 1080;
    text.para_s.width = 1920;
    text.para_t.top = 0;
    text.para_t.left = 0;
    text.para_t.height = 1080;
    text.para_t.width = 1920;
    text.para_r.top = 0;
    text.para_r.left = 0;
    text.para_r.height = 1080;
    text.para_r.width = 1920;
    return (text);
}

struct movement setvar(void)
{
    struct movement move;
    move.player_pos.x = 850;
    move.player_pos.y = 800;
    move.clock = sfClock_create();
    move.pos.x = 1800;
    move.pos.y = 900;
    move.ob_clock = sfClock_create();
    move.time = sfClock_getElapsedTime(move.ob_clock);
    return (move);
}
