/*
** EPITECH PROJECT, 2021
** set.c
** File description:
** set everything
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/Window.h>
#include <SFML/System.h>
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

struct image fill_structt(void)
{
    image_t fill;
    sfFont *font = sfFont_createFromFile("assets/s.ttf");

    fill.cobra = sfText_create();
    sfText_setFont(fill.cobra, font);
    sfText_setString(fill.cobra, "life = ");
    sfText_setString(fill.cobra, "               A8Q");
    sfText_setCharacterSize(fill.cobra, 65);

    fill.clock = sfClock_create();
    return (fill);
}

void set_pos(enti_t *enti)
{
    sfVector2f castle_pos = {1454, 670};
    sfVector2f start_pos = {1300, 800};
    sfVector2f quit_pos = {600, 800};
    sfVector2f pause_res = {765, 200};
    sfVector2f pause_menu = {765, 500};
    sfVector2f pause_quit = {765, 800};
    sfVector2f button_sun_pos = {120, 600};
    sfVector2f button_snow_pos = {100, 800};
    sfVector2f button_tuto_pos = {1430, 850};

    sfSprite_setPosition(enti->castle.sprite, castle_pos);
    sfSprite_setPosition(enti->butt_tuto.sprite, button_tuto_pos);
    sfSprite_setPosition(enti->button_sun.sprite, button_sun_pos);
    sfSprite_setPosition(enti->butt_snow.sprite, button_snow_pos);
    sfSprite_setPosition(enti->menu_start.sprite, start_pos);
    sfSprite_setPosition(enti->menu_quit.sprite, quit_pos);
    sfSprite_setPosition(enti->pause_resume.sprite, pause_res);
    sfSprite_setPosition(enti->pause_menu.sprite, pause_menu);
    sfSprite_setPosition(enti->pause_quit.sprite, pause_quit);
}

void set_txt(enti_t *enti)
{
    sfSprite_setTexture(enti->game_bg.sprite, enti->game_bg.text, sfTrue);
    sfSprite_setTexture(enti->button_sun.sprite, enti->button_sun.text, sfTrue);
    sfSprite_setTexture(enti->butt_snow.sprite, enti->butt_snow.text, sfTrue);
    sfSprite_setTexture(enti->butt_tuto.sprite, enti->butt_tuto.text, sfTrue);
    sfSprite_setTexture(enti->castle.sprite, enti->castle.text, sfTrue);
    sfSprite_setTexture(enti->how_bg.sprite, enti->how_bg.text, sfTrue);
    sfSprite_setTexture(enti->menu_bg.sprite, enti->menu_bg.text, sfTrue);
    sfSprite_setTexture(enti->menu_start.sprite, enti->menu_start.text, sfTrue);
    sfSprite_setTexture(enti->menu_quit.sprite, enti->menu_quit.text, sfTrue);
    sfSprite_setTexture(enti->pause_bg.sprite, enti->pause_bg.text, sfTrue);
    sfSprite_setTexture(enti->pause_resume.sprite, enti->pause_resume.text,
    sfTrue);
    sfSprite_setTexture(enti->pause_menu.sprite, enti->pause_menu.text, sfTrue);
    sfSprite_setTexture(enti->pause_quit.sprite, enti->pause_quit.text, sfTrue);
    set_pos(enti);
}

struct enti initialize(enti_t enti)
{
    enti.cobra_text = fill_structt();
    enti.game_bg = fill_struct("assets/newbackground.jpg", 1080, 1920);
    enti.castle = fill_struct("assets/castle.png", 516, 500);
    enti.how_bg = fill_struct("assets/howtoplay.png", 1080, 1920);
    enti.button_sun = fill_struct("assets/sun_button.png", 100, 217);
    enti.butt_snow = fill_struct("assets/snow_button.png", 100, 217);
    enti.butt_tuto = fill_struct("assets/tutoriall.png", 512, 146);
    enti.menu_bg = fill_struct("assets/menu.jpg", 1080, 1920);
    enti.menu_start = fill_struct("assets/start_button.png", 100, 217);
    enti.menu_quit = fill_struct("assets/button.png", 100, 170);
    enti.pause_bg = fill_struct("assets/pause.jpg", 1080, 1920);
    enti.pause_resume = fill_struct("assets/resume.png", 130, 390);
    enti.pause_menu = fill_struct("assets/go_to_menu_button.png", 130, 390);
    enti.pause_quit = fill_struct("assets/quit_pause.png", 130, 390);
    enti.game_over = fill_struct("assets/gameover.png", 1080, 1920);
    enti.mouse.x = 0;
    enti.mouse.y = 0;
    enti.win = 0;

    set_txt(&enti);
    return (enti);
}
