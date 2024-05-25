/*
** EPITECH PROJECT, 2021
** my.h
** File description:
** my.h
*/
#ifndef MY_H_
#define MY_H_

typedef struct image
{
    sfTexture *text;
    sfSprite *sprite;
    sfVector2f vect;
    sfClock *clock;
    sfText *cobra;
    sfTime time;
    float seconds;
    sfIntRect Rect;
} image_t;

typedef struct enti
{
    int lives;
    int win;
    sfVector2i mouse;
    sfVector2f start_pos;
    image_t game_bg;
    image_t how_bg;
    image_t castle;
    image_t menu_bg;
    image_t menu_start;
    image_t menu_quit;
    image_t pause_bg;
    image_t pause_resume;
    image_t pause_menu;
    image_t pause_quit;
    image_t cobra_text;
    image_t button_sun;
    image_t butt_snow;
    image_t butt_tuto;
    image_t game_over;
} enti_t;

struct sound {
    sfMusic *game_mus;
};

typedef struct element element_t;
struct element
{
    sfTexture *text;
    sfSprite *sprite;
    sfClock *clock;
    sfTime time;
    float seconds;
    sfIntRect Rect;
    sfVector2f pos;
    element_t *next;
};

element_t *fill_list(char *path, int width, float height, int i);
element_t *add_new(element_t *enemies, int i);

struct enti initialize(enti_t enti);
struct image fill_struct(char *path, int height, int width);
struct image fill_structt();
struct sound create(void);

void loop(enti_t *enti, sfRenderWindow *window);
void game(enti_t *enti, sfRenderWindow *window);
void event(enti_t *enti, sfRenderWindow *window);
void loose(enti_t *enti, sfRenderWindow *window);
void check_lives(enti_t *enti, sfRenderWindow *window);
void check_win(enti_t *enti, element_t *enemies, sfRenderWindow *window);

void menu_win(enti_t *enti, sfRenderWindow *window);
void pause_window(enti_t *enti, sfRenderWindow *window);
void winter_scene(enti_t *enti);
void summer_scene(enti_t *enti);
void page_how(enti_t *enti, sfRenderWindow *window);

void draw_menu(enti_t *enti, sfRenderWindow *window);
void draw_pause(enti_t *enti, sfRenderWindow *window);
void draw_text(enti_t *enti, sfText *cobra, sfRenderWindow *window);
void draw_game(enti_t *enti, sfRenderWindow *window);
void draw_snow(enti_t *enti, sfRenderWindow *window);
void draw_sun(enti_t *enti, sfRenderWindow *window);
void draw_how(enti_t *enti, sfRenderWindow *window);
void draw_enemies(element_t *enemies, sfRenderWindow *window);

void up_moves(element_t *enemies);
void down_moves(element_t *enemies);
void right_moves(element_t *enemies);
void left_moves(element_t *enemies);
void right_animation(element_t *enemies);
void left_animation(element_t *enemies);
void up_animation(element_t *enemies);
void down_animation(element_t *enemies);
void normal_path(element_t *enemies, enti_t *enti, sfRenderWindow *window);
void summer_path(element_t *enemies, enti_t *enti, sfRenderWindow *window);
void snow_path(element_t *enemies, enti_t *enti, sfRenderWindow *window);

void set_rightpos(element_t *enemies, sfVector2f playerpos, int i);

void destroy_all(enti_t *enti, sfRenderWindow *window);

int check_button(enti_t *enti, int width, int height, sfSprite *button);

#endif /* MY_H_ */
