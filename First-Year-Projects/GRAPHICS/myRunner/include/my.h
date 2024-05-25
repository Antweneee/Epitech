
/*
** EPITECH PROJECT, 2020
** my.h
** File description:
** my.h
*/

#ifndef MY_H_
#define MY_H_

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <stdlib.h>

struct texture {
    sfTexture *player_t;
    sfSprite *player;
    sfTexture *jump_t;
    sfSprite *jump;
    sfTexture *mountain_t;
    sfSprite *mountain;
    sfTexture *road_t;
    sfSprite *road;
    sfTexture *town_t;
    sfSprite *town;    
    sfTexture *gametext;
    sfSprite *gamesp;
    sfTexture *button_texture;
    sfSprite *button_sprite;
    sfTexture *button_start;
    sfSprite *start_sprite;
    sfVideoMode video_mode;
    sfTexture *image;
    sfSprite *image1;
    sfSprite *bad_guy;
    sfTexture *bad_guy_t;
    sfTexture *GM_t;
    sfSprite *GM;
    sfIntRect para_s;
    sfIntRect para_t;
    sfIntRect para_r;
    sfIntRect para_m;
    sfClock *clock_s;
    sfClock *clock_t;
    sfClock *clock_r;
    sfClock *clock_m;
};
struct sound {
    sfMusic *game_mus;
};
struct jump {
    sfMusic *Jump;
};
struct movement {
    float seconds;
    sfTime time;
    sfClock *clock;
    sfVector2f player_pos;
    sfVector2f jump_pos;
    sfVector2f pos;
    sfClock *ob_clock;
    char *map;
    int indi;
};
struct movement setvar(void);
struct texture fill_text(void);
struct texture fill_pre(void);
struct texture structure(void);
struct jump setJ_sound(void);
int get_obstacle(struct movement *move);
void update(struct texture text);
void jump(sfRenderWindow *Window, struct movement move, struct texture text);
void parallax(struct texture *text);
void set_position(struct texture text, struct movement move, sfIntRect recta, sfRenderWindow *Window);
void start_mse(sfRenderWindow *Window, struct texture text, sfVector2i mousepos, sfEvent evt, struct movement move);
void boucle(sfRenderWindow *Window, sfVector2i mousepos, struct texture text, struct movement move);
void second_set(struct texture text, struct movement move);
void set(struct texture text);
void mse(sfRenderWindow *Window, struct texture text, sfVector2i mousepos, sfEvent evt);
void draw(struct texture text, sfRenderWindow *Window);
int my_strlen(char const *str);
int my_putstr(char const *str);
struct sound create(void);

#endif /* MY_H_ */
