/*
** EPITECH PROJECT, 2022
** B-NWP-400-PAR-4-1-myteams-antoine.gavira-bottari
** File description:
** client
*/

#ifndef CLIENT_H_
    #define CLIENT_H_

    #include <sys/types.h>
    #include <sys/socket.h>
    #include <netinet/in.h>
    #include <netinet/ip.h>
    #include <arpa/inet.h>
    #include <sys/select.h>
    #include <unistd.h>
    #include <stdlib.h>
    #include <stdio.h>
    #include <string.h>
    #include <stdbool.h>
    #include "mydata.h"
    #include "defines.h"

    #define CLIENT_LIST_PATH "conf/client_list"
    #define FILE_PATH_SUBSCIBE_LEN 60
    #define UUID_LEN 37
    #define NAME_LEN_MAX 32

typedef struct client_s
{
    socklen_t _csize;
    int _socket_fd;
    struct sockaddr_in addrserver;
    char *_ip;
    send_data_t to_send;
} client_t;

int c_init_struct(client_t *c_socket, char const *ip, char const *port);
void c_free_struct(client_t *c_socket);
int init_client(char const *ip, char const *port);
int read_from_server(int sockfd, client_t *client);
int send_to_server(int sockfd, client_t *client);
char **parse_str(char *str, int do_space, int do_ret);
char *check_client_file(char *name);
void print_all_teams(char *response);

#endif /* !CLIENT_H_ */