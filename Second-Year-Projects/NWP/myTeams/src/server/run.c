/*
** EPITECH PROJECT, 2022
** B-NWP-400-PAR-4-1-myteams-antoine.gavira-bottari
** File description:
** run
*/

#include <stdio.h>
#include <sys/select.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "mydata.h"
#include "server.h"
#include "../libs/myteams/logging_server.h"

static int read_my_stuff(connected_client_t *tmp, int i, server_t *s_server)
{
    send_data_t get;

    memset(&get, 0, sizeof(send_data_t));
    if (i == tmp->_client_fd) {
        if (read(tmp->_client_fd, &get, sizeof(send_data_t)) == 0) {
            FD_CLR(tmp->_client_fd, &(s_server->_reset));
            list_del_elem_at_position(&(s_server->_s_clients),
            tmp->_client_fd);
            return ERROR;
        }
        check_commands(get, tmp);
    }
    return SUCCESS;
}

static void checkreadable_client(server_t *s_server, int i)
{
    connected_client_t *tmp = s_server->_s_clients;
    send_data_t get;

    memset(&get, 0, sizeof(send_data_t));
    if (s_server->_s_clients == NULL)
        return;

    for (; tmp; tmp = tmp->_next) {
        if (read_my_stuff(tmp, i, s_server) == ERROR)
            break;
    }
}

static int accept_or_check(server_t *s_server, int fd, int const i)
{
    if (FD_ISSET(i, &(s_server->_r_set))) {
        if (i == s_server->_socket_fd) {
            fd = accept(i, (struct sockaddr *) &s_server->addrserver,
            &s_server->_csize);
            new_client(&(s_server->_s_clients), fd);
            FD_SET(fd, &(s_server->_reset));
            printf("new_client\n");
        } else
            checkreadable_client(s_server, i);
    }
    return fd;
}

static int get_accept_fd(server_t *s_server)
{
    int fd = 0;

    for (int i = 0; i < FD_SETSIZE; i++) {
        fd = accept_or_check(s_server, fd, i);
    }
    if (fd == -1)
        return ERROR;
    return SUCCESS;
}

int run(server_t *s_server)
{
    bool running = true;

    check_if_server_loaded();
    while (running) {
        s_server->_r_set = s_server->_reset;
        s_server->_w_set = s_server->_reset;
        if (select(FD_SETSIZE, &(s_server->_r_set), &(s_server->_w_set), \
            NULL, NULL) == -1)
            return ERROR;
        if (get_accept_fd(s_server) == ERROR)
            return ERROR;
    }
    return SUCCESS;
}