/*
** EPITECH PROJECT, 2022
** B-YEP-410-PAR-4-1-zappy-thomas.willson
** File description:
** prototypes
*/

#ifndef PROTOTYPES_H_
    #define PROTOTYPES_H_
    #include <stdbool.h>
    #include <stdio.h>
    #include <stdint.h>
    #include <stdlib.h>
    #include <string.h>
    #include <sys/types.h>
    #include <sys/socket.h>
    #include <arpa/inet.h>
    #include "ai_info.h"

bool is_num(const char* str);
bool check_args(int argc, const char *argv[]);
struct socket_info init_socket_info(int port, const char* ip);
int connect_to_server(int socket, struct sockaddr_in servaddr);
int client_loop(struct socket_info* socket, struct ai_info* ai);
int *inventory(char *inventory);
bool can_do_elevation_on_inventory(int actual_level, int *inventory);
int read_client(char** command, FILE* fds, struct ai_info* ai);
int *rock_missing(int actual_level, int *inventory);
struct ai_info init_ai_info(const char* team_name);

bool can_do_elevation_on_tile(int actual_level, int **look);

/* look.c */
int calculate_slot_with_level(int level);
int *create_one_slot(char *tile);
int **parse_look(char *str, int level);
void print_look_parsed(int **look, int level);
int *calculate_next_coo(int **look, int level, int *inventory);
char **rock_too_much_on_tail(int actual_level, int *tile);
char **rock_missing_on_tail(int actual_level, int *tile);
void just_move_in_tile(struct ai_info* ai, int *coord);
void take_the_rocks_needed_in_inventory(struct ai_info* ai, int level, int *inventory, int *rocks_on_tile);
int *find_player_needed(int **look, int level);
int *find_the_pos(int i);
bool drop_all_rocks_in_inventory(struct ai_info* ai);
int get_broadcast_level(char *str);
int get_broadcast_direction(char *str);
bool can_do_elevation_on_tile_without_players(int actual_level, int **look);

bool shift_element(struct ai_info *ai);
bool command_exec(struct ai_info* ai);

void move_in_tile(struct ai_info* ai, int *coord);
bool is_queue_empty(struct ai_info* ai);

char *my_strcat(char *dest, char *src);
void update_look_and_inventory(struct ai_info * ai);
int find_missing_rock(int level, int *inventory);
bool is_too_many_player(int *tile, int level);
bool is_missing_player(int *tile, int level);
#endif /* !PROTOTYPES_H_ */
