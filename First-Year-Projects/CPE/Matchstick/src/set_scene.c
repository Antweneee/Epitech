/*
** EPITECH PROJECT, 2021
** B-CPE-200-PAR-2-1-matchstick-antoine.gavira-bottari
** File description:
** set_scene
*/

#include "my.h"
#include "matchstick.h"
int const OUTLINE = 2;

int get_size(int const size)
{
    int nb = 1;

    for (int i = 1; i < size; i++) {
        nb += 2;
    }
    return (nb);
}

void print_map(int const size, char **match)
{
    for (int i = 0; i < (size + OUTLINE); i++) {
        my_printf("%s\n", match[i]);
    }
}

char **fill(int const size, char **match)
{
    int y = 0;

    for (int x = 0; x != (size + OUTLINE); x++) {
        for (y = 0; y != (get_size(size) + OUTLINE); y++) {
            if (x == 0 ||  y == 0 || x == ((size + OUTLINE) - 1) ||
            y == (get_size(size) + OUTLINE - 1)) {
                match[x][y] = '*';
            } else {
                match[x][y] = ' ';
            }
        }
        match[x][y] = '\0';
    }
    return (match);
}

char **fill_stick(int const size, int const max_stick, char **match)
{
    int stick = 1;
    int space = 0;
    int count = 0;

    for (int i = 1; i <= size; i++) {
        if (i > 1)
            stick += 2;
        space = (max_stick - stick) / 2;
        for (int o = 1; o <= space; o++) {
            match[i][o] = ' ';
        }
        count = stick;
        for (int j = 1 + space; count != 0; j++) {
            match[i][j] = '|';
            count -= 1;
        }
    }
    return (match);
}

void setup(data_t *data)
{
    char **match = malloc(sizeof(char *) * (data->size + OUTLINE));

    for (int i = 0; i < (data->size + OUTLINE); i++) {
        match[i] = malloc(sizeof(char) * (get_size(data->size) + OUTLINE + 1));
    }
    match = fill(data->size, match);
    match = fill_stick(data->size, get_size(data->size), match);
    print_map(data->size, match);
    game_process(match, data);
}