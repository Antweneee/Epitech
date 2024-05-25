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
    sfTime time;
    float seconds;
    sfIntRect Rect;
} image_t;

typedef struct entities
{
    image_t player;
    image_t  BG;
    image_t scope;
    image_t menu_bg;
    image_t menu_sbutton;
    image_t menu_qbutton;
} entities_t;
void gestion(void);
struct image fill_struct(char *path, int height, int width);
void set_text(entities_t *entities);
void draw(entities_t *entities, sfRenderWindow *Window);
void animation(entities_t *entities);
void scope_pos(entities_t *entities, sfRenderWindow *Window);
int move_player(entities_t *entities, sfRenderWindow *Window, int life);
void kill_player(entities_t *entities, sfRenderWindow *Window);
void destroy_all(entities_t *entities, sfRenderWindow *Window);

#endif /* MY_H_ */
