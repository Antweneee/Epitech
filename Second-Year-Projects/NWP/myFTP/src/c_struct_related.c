/*
** EPITECH PROJECT, 2022
** B-NWP-400-PAR-4-1-myftp-antoine.gavira-bottari
** File description:
** c_struct_related
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "myftp.h"

void list_del_elem_at_front(client_t **front_ptr)
{
    client_t *tmp = NULL;

    if (*front_ptr == NULL)
        return;
    tmp = *front_ptr;
    if (tmp->_pass)
        free(tmp->_pass);
    if (tmp->_username)
        free(tmp->_username);
    if (tmp->_path)
        free(tmp->_path);
    close(tmp->_client_fd);
    *front_ptr = (*front_ptr)->_next;
    free(tmp);
}

void delete_client(client_t **complete, int del_fd)
{
    client_t *current = *complete;
    client_t *tmp = NULL;

    if (*complete == NULL)
        return;
    if (!current->_next) {
        list_del_elem_at_front(complete);
        return;
    }
    for (; current; current = current->_next)
        if (current->_client_fd == del_fd)
            break;
    tmp = current;
    if (tmp != NULL && tmp->_pass)
        free(tmp->_pass);
    if (tmp != NULL && tmp->_username)
        free(tmp->_username);
    if (tmp != NULL && tmp->_path)
        free(tmp->_path);
    current = current->_next;
    free(tmp);
}

void debug(client_t **client)
{
    client_t *tmp = *client;

    if (!tmp) {
        printf("no client\n");
        return;
    }
    for (int i = 0; tmp; tmp = tmp->_next, i++) {
        printf("client %d:\n", i);
        printf("client_fd : %d\n", tmp->_client_fd);
        printf("usr : %s\n", tmp->_username);
        printf("pass : %s\n", tmp->_pass);
        if (tmp->_is_log)
            printf("logged\n");
        else
            printf("not logged\n");
        printf("path : %s\n", tmp->_path);
        printf("\n");
    }
    printf("\n\n");
}

static client_t *add_node(int client_fd, char *str)
{
    client_t *to_add = malloc(sizeof(client_t));

    to_add->_path = strdup(str);
    to_add->_username = NULL;
    to_add->_pass = NULL;
    to_add->_client_fd = client_fd;
    to_add->_data_socket = NULL;
    to_add->_next = NULL;
    to_add->_is_log = false;
    return to_add;
}

void new_client(client_t **clients, int client_fd, char *str)
{
    client_t *tmp;
    client_t *to_add;

    if (*clients == NULL) {
        tmp = add_node(client_fd, str);
        *clients = tmp;
    } else {
        tmp = *clients;
        for (; tmp->_next; tmp = tmp->_next);
        to_add = add_node(client_fd, str);
        tmp->_next = to_add;
    }
}

void c_free_struct(client_t *clients)
{
    for(; clients; clients = clients->_next) {
        if (clients->_path)
            free(clients->_path);
        if (clients->_username)
            free(clients->_username);
        if (clients->_pass)
            free(clients->_pass);
        close(clients->_client_fd);
    }
}