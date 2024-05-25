/*
** EPITECH PROJECT, 2021
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

#include <stdio.h>

typedef struct object_s /* liste chainée nbr obj dans inventaire */
{
    int number;
    char *object;
    sfSprite *sprite;
    sfVector2f pos;
    sfTexture *texture;
    struct object_s *next;
} object_t;

typedef struct inventory_s /* Structure pour inventaire */
{
    int condition;
    sfSprite *sprite;
    sfVector2f pos;
    sfTexture *texture;
    object_t *object;
} inventory_t;

typedef struct cutscene_s /* struct cut_scene */
{
    sfTexture *texture;
    sfSprite *sprite;
    sfText *text1;
    sfText *text2;
    sfText *text3;
    sfTexture *map_texture;
    sfSprite *map_sprite;

} scene_t;

typedef struct rect_s /* Structure du rect pour un perso */
{
    sfTexture *t_perso;
    sfIntRect rect;
    sfClock *clock;
    int direction;
} rect_t;

typedef struct select_s
{
    sfTexture *texture;
    sfSprite *sprite;
    int selection;
} select_t;

typedef struct stat_s /* struct pour la vie */
{
    int life;
    int level;
    sfSprite *stat_sprite;
    sfTexture *life100;
    sfTexture *life90;
    sfTexture *life75;
    sfTexture *life60;
    sfTexture *life45;
    sfTexture *life30;
    sfTexture *life15;
    sfTexture *life5;

} stat_t;

typedef struct perso_s /* Structure pour un perso */
{
    sfSprite *s_perso;
    rect_t *image;
    stat_t *stat;
    sfVector2f pos;
    sfClock *clock;

} perso_t;

typedef struct objectives_s /* structure pour objet */
{
    sfTexture *texture;
    sfSprite *sprite;
    sfIntRect rect;
    int status;
} quest_t;

typedef struct game_object_s /* struct pour les quetes */
{
    quest_t task_one;
    quest_t task_two;
    quest_t task_three;
} gameobj_t;

typedef struct image /* struct boutons dan */
{
    sfTexture *text;
    sfSprite *sprite;
    sfVector2f vect;
    sfClock *clock;
    sfIntRect Rect;
    int i;
} image_t;

typedef struct sound_s
{
    sfMusic *music;
    float volume;
    int mute;
} sound_t;

typedef struct enti /* struct general */
{
    sfVector2i mouse;

    image_t game_bg;

    image_t menu_bg;
    image_t menu_start;
    image_t menu_quit;
    image_t menu_info;
    image_t menu_settings;
    image_t man_bg;
    image_t man_exit;
    image_t menu_map;

    image_t pause_bg;
    image_t pause_resume;
    image_t pause_menu;
    image_t pause_quit;

    image_t settings_bg;
    image_t settings_volume10;
    image_t settings_volume50;
    image_t settings_volume100;
    image_t settings_mute;
    image_t settings_exit;

    image_t menu_map_img;
    image_t menu_map_exit;

    sound_t song;

    select_t select;

    gameobj_t game; /* quetes */

    inventory_t inventory; /* inventaire */

    scene_t finished; /* quest finished */
    scene_t start_battle;

    perso_t *perso; /* personnage */

    image_t pause_scrolling;
} enti_t;


/* menu.c */
void game_loop(enti_t *enti, sfRenderWindow *window);
void event(enti_t *enti, sfRenderWindow *window, sfEvent *evt);
void selection(enti_t *enti, sfRenderWindow *window);
void check_menu_choice(enti_t *enti, sfRenderWindow *window);

/* menu2.c */
void check_settings(enti_t *enti);
void settings_page(enti_t *enti, sfRenderWindow *window);
void man_page(enti_t *enti, sfRenderWindow *window);
void pause_window(enti_t *enti, sfRenderWindow *window);
void map_page(enti_t *enti, sfRenderWindow *window);

/* check.c */
int check_button(enti_t *enti, int width, int height, sfSprite *button);

/* set.c */
struct image fill_struct(char *path, int x, int y);
void set_txt(enti_t *enti);
struct enti initialize(enti_t enti);
void music(enti_t *enti);

/* set_game.c */
gameobj_t setup_game(void);
scene_t set_cutscene(char *path, int x, sfTime a, char **msg);

/* draw.c */
void draw_menu(enti_t *enti, sfRenderWindow *window);
void draw_game(enti_t *enti, sfRenderWindow *window);
void draw_pause(enti_t *enti, sfRenderWindow *window);
void draw_info(enti_t *enti, sfRenderWindow *window);
void play_music(enti_t *enti);

/* draw2.c */
void draw_inventory(inventory_t inventory, sfRenderWindow *window);
void draw_settings(enti_t *enti, sfRenderWindow *window);
void draw_cutscene(sfRenderWindow *window, sfSprite *sprite, scene_t cutscene);
void draw_map_menu(enti_t *enti, sfRenderWindow *window);
void draw_selection(enti_t *enti, sfRenderWindow *window);

/* messages.c */
char **finished_txt(void);
char **enemyarrive_txt(void);

/* music.c */
void play_music(enti_t *enti);

/* destroy.c */
void destroy_menu(enti_t *enti);
void destroy_game(enti_t *enti);
void destroy_pause(enti_t *enti);
void destroy_music(enti_t *enti);

/* move.c */
void update_fake_paralax(enti_t *enti);

/* inventory.c */
inventory_t struct_creation_inventory(void);
object_t *create_struct_object(void);
object_t *add_object(object_t *object, const char *str, int nbr,
sfVector2f pos);
object_t *create_object(const char *str, int nbr, sfVector2f pos);

/* move_pos.c */
void move_right(perso_t *perso);
void move_left(perso_t *perso);
void move_up(perso_t *perso);
void move_down(perso_t *perso);

/* move_rec.c */
void stay_cool(perso_t *perso);
void move_rect_right(perso_t *perso);
void move_rect_left(perso_t *perso);
void move_rect_up(perso_t *perso);
void move_rect_down(perso_t *perso);

/* movement.c */
void free_all(perso_t *perso);
void move_boy(perso_t *perso);
void move_girl(perso_t *perso);
rect_t *fill_image_boy(void);
rect_t *fill_image_girl(void);
perso_t *fill_perso(enti_t *enti);

/* special_move.c */
void sprint(perso_t *perso);

/* game.c */
void start_game(enti_t *enti, sfRenderWindow *window);
void check_analyse(sfRenderWindow *window, sfEvent event, perso_t *perso);
int analyse_events(sfRenderWindow *window, sfEvent event);
void check_questitems(enti_t *enti);


/* cut_scene.c */
void quest_completed(sfRenderWindow *window, enti_t *enti);
void inventory_management(sfRenderWindow *window, enti_t *enti);

/* boss_battle.c */
void boss_battle(sfRenderWindow *window, enti_t *enti);

#endif /* MY_H_ */
