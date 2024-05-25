/*
** EPITECH PROJECT, 2022
** $
** File description:
** server
*/

#ifndef SERVER_H_
    #define SERVER_H_
    #define FILE_PATH_SUBSCIBE_LEN 60
    #define CLIENT_LIST_PATH "conf/client_list"

    #include <sys/types.h>
    #include <sys/socket.h>
    #include <netinet/in.h>
    #include <netinet/ip.h>
    #include <stdbool.h>
    #include "mydata.h"
    #include "defines.h"

typedef struct connected_client_s {
    int _client_fd;
    char *user_uuid;
    char *user_name;
    char *use;
    struct connected_client_s *_prev;
    struct connected_client_s *_next;
} connected_client_t;

typedef struct server_s
{
    char const *_local_host;
    char const *_port;
    int _socket_fd;
    socklen_t _csize;
    fd_set _reset;
    fd_set _w_set;
    fd_set _r_set;
    struct sockaddr_in addrserver;
    connected_client_t *_s_clients;
} server_t;

int init(char const *port);
int run(server_t *s_server);
void new_client(connected_client_t **clients, int const client_fd);
void check_commands(send_data_t data, connected_client_t *clients);
char *open_read_file(const char *path);
void write_new_client(const char *path, char *name, char *uuid);
char **parse_str(char *str, int do_space, int do_ret);
char **parse_message(char *str);
char **parse_args(char *str);
int open_fd(const char *path);
void list_del_elem_at_position(connected_client_t **front_ptr, int fd);
void free_node(connected_client_t *to_free);
void check_if_server_loaded(void);

#endif /* !SERVER_H_ */