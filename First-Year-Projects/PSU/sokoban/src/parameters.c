/*
** EPITECH PROJECT, 2021
** B-PSU-200-PAR-2-1-mysokoban-antoine.gavira-bottari
** File description:
** parameters
*/

#include <ncurses.h>
#include "my.h"
#include "sokoban.h"

int *player_pos(char **map, char *str)
{
    int *get = malloc(sizeof(int) * 3);

    if (get == NULL)
        return NULL;
    for (int i = 0; i != tab_size(str, '\n'); i++) {
        for (int o = 0; map[i][o] != '\0'; o++) {
            if (map[i][o] == 'P') {
                get[0] = i;
                get[1] = o;
                get[2] = '\0';
                break;
            }
        }
    }
    return (get);
}

void print_map(char **map, char *get)
{
    int nb = tab_size(get, '\n');

    for (int i = 0; i != nb; i++) {
        mvprintw(((LINES / 2) + i) - (nb / 2), (COLS / 2) - (nb / 2),
        "%s", map[i]);
        refresh();
    }
}

int get_space(char *get)
{
    int nb = 0;

    for (int i = 0; get[i] != '\0'; i++) {
        if (get[i] == 'O') {
            nb++;
        }
    }
    return (nb);
}

pos_t *get_pos(char **map, char *get)
{
    pos_t *fill = malloc(sizeof(pos_t));
    int x = 0;
    int y = 0;

    fill->nb = 0;
    fill->pos_p = malloc(sizeof(int *) * (get_space(get) + 1));
    for (int p = 0; p != get_space(get); p++)
        fill->pos_p[p] = malloc(sizeof(int) * 3);
    for (int i = 0; i != tab_size(get, '\n'); i++) {
        for (int o = 0; map[i][o] != '\0'; o++) {
            if (map[i][o] == 'O') {
                fill->pos_p[x][y] = i;
                fill->pos_p[x][y + 1] = o;
                fill->pos_p[x][y + 2] = '\0';
                fill->nb += 1;
                x++;
            }
        }
    }
    fill->pos_p[x] = NULL;
    return (fill);
}

void set_window(char **map, char *get)
{
    int keyb = 0;
    pos_t *posi = get_pos(map, get);

    initscr();
    noecho();
    keypad(stdscr, TRUE);
    while (45) {
        print_map(map, get);
        keyb = getch();
        map = move_p(keyb, map, get, posi);
        if (end(map, posi, get) == 1 || keyb == 'v')
            break;
        if (keyb == ' ') {
            free_tab(map);
            map = turn_to_array(get, '\n');
        }
    }
    endwin();
    free_all(map, get, posi->pos_p);
}