/*
** EPITECH PROJECT, 2022
** B-YEP-410-PAR-4-1-zappy-thomas.willson
** File description:
** server
*/

#ifndef SERVER_H_
    #define SERVER_H_

    #include <sys/select.h>
    #include <sys/time.h>
    #include <sys/types.h>
    #include <sys/socket.h>
    #include <netinet/in.h>
    #include <arpa/inet.h>
    #include <unistd.h>
    #include <signal.h>
    #include <uuid/uuid.h>
    #include <stdbool.h>
    #include "data_server.h"
    #include "constant.h"
    #include "enum.h"
    #include "game.h"

static volatile sig_atomic_t keep_running = true;

typedef struct info_server_s {
    uint32_t port;
    uint32_t width;
    uint32_t height;
    uint32_t clients_nb;
    uint32_t freq;
} info_server_t;

typedef struct events_s {
    int epoll_fd;
    struct epoll_event events[MAX_EVENTS];
} events_t;

typedef struct chrno_buffer_s
{
    time_t time;
    char *buffer;
    float stop;
    message_e type;
    struct chrno_buffer_s *next;
} chrono_buffer_t;

typedef struct client_s {
    FILE *file;
    type_e type;
    bool read;
    bool connected;
    char *team_name;
    char **command;
    chrono_buffer_t *chrono;
    player_t *player;
    bool welcome : 1;
} client_t;

typedef struct linked_client_s {
    client_t *client;
    struct linked_client_s *next;
} linked_client_t;

typedef struct forks_s {
    char *uuid;
    int x;
    int y;
    time_t time;
    bool hatched;
    struct forks_s *next;
} forks_t;

typedef struct team_s {
    char *name;
    uint32_t clients_nb;
    uint32_t forks_nb;
    forks_t *forks;
    linked_client_t *clients;
    struct team_s *next;
} team_t, teams_t;

typedef struct base_inventory_s {
    inventory_t base;
    inventory_t inventory;
} base_inventory_t;

typedef struct server_s {
    int fd;
    size_t number_connected;
    linked_client_t *data_gui;
    data_server_to_gui_t send_gui;
    base_inventory_t base_inventory;
    struct sockaddr_in addr;
    struct timeval timeout;
    info_server_t info_server;
    teams_t *teams;
    events_t events;
    int id;
} server_t;

#endif /* !SERVER_H_ */
