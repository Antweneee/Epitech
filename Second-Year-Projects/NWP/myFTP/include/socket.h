/*
** EPITECH PROJECT, 2022
** B-NWP-400-PAR-4-1-myftp-antoine.gavira-bottari
** File description:
** socket
*/

#ifndef SOCKET_H_
    #define SOCKET_H_

    #include <sys/types.h>
    #include <sys/socket.h>
    #include <sys/select.h>
    #include <netinet/in.h>
    #include <arpa/inet.h>
    #include <netdb.h>
    #include <unistd.h>
    #include <stdbool.h>

typedef struct data_socket_s
{
    socklen_t _csize;
    int _socket_fd;
    struct sockaddr_in addrserver;
    char *_path;
} data_socket_t;


typedef struct client_s
{
    char *_path;
    char *_username;
    char *_pass;
    int _client_fd;
    bool _is_log;
    data_socket_t *_data_socket;
    struct client_s *_next;
} client_t;

typedef struct socket_s
{
    char const *_local_host;
    char *_port;
    int _socket_fd;
    char *_server_path;
    socklen_t _csize;
    fd_set _reset;
    fd_set _w_set;
    fd_set _r_set;
    struct sockaddr_in addrserver;
    bool _is_log;
    client_t *_clients;
} socket_t;

int s_init_struct(socket_t *s_socket, char const *port, char const *path);
void s_free_struct(socket_t *socket);

void c_free_struct(client_t *c_socket);
void debug(client_t **client);
void delete_client(client_t **complete, int del_fd);

int data_init_struct(data_socket_t *data_socket, char const *path);
void data_free_struct(data_socket_t *data_socket);

#endif /* !SOCKET_H_ */

