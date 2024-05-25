/*
** EPITECH PROJECT, 2022
** zappy_server
** File description:
** functions
*/

#ifndef FUNCTIONS_H_
    #define FUNCTIONS_H_
    #include <stdbool.h>
    #include "server.h"
    #include "game.h"

bool error_handling(int ac, char const *av[]);

int activate_zappy_server(int ac, char const *av[]);
int manage_server(server_t *server);
int accept_client(server_t *server);

bool add_existing_teams(teams_t **teams, const char *name);
void free_teams_list(teams_t **teams);
//init
map_t **create_map(info_server_t *info, inventory_t *inventory);
void put_in_map(map_t *map, resource_e resource);

//service
int manage_operation_on_client(client_t *client, server_t *server,
map_t **map, bool read);

//utils
char **split_str(const char *str, const char *delim);
void free_2d_array(char **array);
void fix_space(char *line);
void change_quote(char *line);
int gui_write(server_t *server);
int add_gui(client_t *client, server_t *server);
int delete_gui(client_t *client, server_t *server);
int reset_ev(client_t *client, server_t *server);
void free_client(client_t *client);
int message_buffer(server_t *server, const char *message);
int message_gui(server_t *server, const char *message);
int message_ai(client_t *client, server_t *server, const char *message);
int message_client_gui(client_t *client, server_t *server,
const char *message);
int check_if_player_can_connect(team_t *team, server_t *server);
int connection_for_team_from_client(client_t *client, server_t *server,
char *lineptr);
bool add_egg_to_fork_list(forks_t **forks, int x, int y, time_t time);
void free_forks_in_team(forks_t **forks);
int handle_disconnection(teams_t **teams, int fd);
int message_chrono(client_t *client, const char *message, float delay);
int message_chrono_style(client_t *client, const char *message, float delay
, message_e style);
int write_chrono(client_t *client);
int set_writable(client_t *client, server_t *server);

int writing_default(client_t *client, chrono_buffer_t *message);
int writing_inventory(client_t *client, chrono_buffer_t *message);

int delete_chrono(client_t *client, chrono_buffer_t *del);
chrono_buffer_t *add_chrono(client_t *client, const char *message);
chrono_buffer_t *init_new(const char *message);

void eject_player(map_t *map, player_t *player);
void assign_player(map_t *map, player_t *player);

void set_id_teams(server_t *server);

//utils/game
player_t *add_player(map_t **map, uint32_t width, uint32_t height);

//utils/gui
void translate_map(data_server_to_gui_t *gui, map_t **map
, info_server_t *info);
void translate_player(data_server_to_gui_t *gui, map_t **map
, info_server_t *info);
void translate_mod_player(data_server_to_gui_t *gui, player_t *player, player_actions action_id);
void translate_mod_map(data_server_to_gui_t *gui, map_t **a_map, int y, int x);

//utils/ai
void display_case(map_t *map, char *buffer, bool last);
void up_line(map_t **map, client_t *client, info_server_t *info, char *buffer);
void left_line(map_t **map, client_t *client, info_server_t *info, char *buffer);
void right_line(map_t **map, client_t *client, info_server_t *info, char *buffer);
void down_line(map_t **map, client_t *client, info_server_t *info, char *buffer);

//command
int command_gui(client_t *client, server_t *server, map_t **map);
int command_ai(client_t *client, server_t *server, map_t **map);
int command_server(client_t *client, server_t *server, map_t **map);
int command_type(client_t *client, server_t *server, map_t **map);

//gui
int help_gui(client_t *client, server_t *server, map_t **map);
int amap(client_t *client, server_t *server, map_t **map);
int apla(client_t *client, server_t *server, map_t **map);
int print(client_t *client, server_t *server, map_t **map);

//ai
int help_ai(client_t *client, server_t *server, __ATTRIBUTE_UNUSED__ map_t **map);
int right(client_t *client, server_t *server, map_t **map);
int left(client_t *client, server_t *server, map_t **map);
int forward(client_t *client, server_t *server, map_t **map);
int inventory(client_t *client, server_t *server, map_t **map);
int take_object(client_t *client, server_t *server, map_t **map);
int set_object(client_t *client, server_t *server, map_t **map);
int broadcast(client_t *client, server_t *server, map_t **map);
int connect_nbr(client_t *client, server_t *server, map_t **map);
int look(client_t *client, server_t *server, map_t **map);
int incantation(client_t *client, server_t *server, map_t **map);
int xfork(client_t *client, server_t *server, map_t **map);
int eject(client_t *client, server_t *server, map_t **map);

#endif /* !FUNCTIONS_H_ */
