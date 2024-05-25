/*
** EPITECH PROJECT, 2020
** ls.h
** File description:
** .h for my_ls
*/

#ifndef ls_H_
#define ls_H_

typedef struct data_s
{
    int max;
    int size;
    int line;
    int matches;
    int turn;
    char *c_line;
    char *c_matches;
    int status;
} data_t;
void setup(data_t *data);
void game_process(char **match, data_t *data);
int check_line(char **match, data_t *data);
int check_matches(char **match, data_t *data);
int get_match_number(char **match, int size);
char **update_map(char **match, int const line, int const nb);
void print_map(int const size, char **match);
char **ia_turn(char **match, data_t *data);
void ending(data_t *data);
void get_check_line(char **match, data_t *data);
int check_matche_line(char **match, int line);

#endif /* ls_H_ */