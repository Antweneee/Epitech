/*
** EPITECH PROJECT, 2020
** sokoban.h
** File description:
** .h for sokoban
*/

#ifndef sokoban_H_
#define sokoban_H_

typedef struct pos
{
    int **pos_p;
    int nb;
} pos_t;
void set_window(char **map, char *get);
int *player_pos(char **map, char *str);
int end(char **map, pos_t *posi, char *str);
int get_space(char *get);
void free_all(char **arr, char *str, int **pos);
char **move_p(int key, char **map, char *get, pos_t *posi);
void fix_o(char **map, pos_t *posi);

#endif /* sokoban_H_ */
