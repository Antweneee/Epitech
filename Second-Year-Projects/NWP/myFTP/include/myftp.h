/*
** EPITECH PROJECT, 2022
** B-NWP-400-PAR-4-1-myftp-antoine.gavira-bottari
** File description:
** myftp
*/

#ifndef MYFTP_H_
#define MYFTP_H_

#include "socket.h"

char **turn_to_array(char const *str, char c);

int server_engine(char const *port, char const *path);
char *command_handler(char *str, socket_t *s_socket, client_t *client);
int write_case(socket_t *s_socket, int client_fd);
char *read_case(client_t *client, socket_t *s_socket);
void new_client(client_t **clients, int client_fd, char *str);
void checkreadable_client(client_t **head, socket_t *s_socket, int i);
int check_writable(socket_t *s_socket, fd_set *w_set, int i);
int check_readable(socket_t *s_socket, fd_set *r_set, int i);
void free_tab(char **arr);

#endif /* !MYFTP_H_ */
