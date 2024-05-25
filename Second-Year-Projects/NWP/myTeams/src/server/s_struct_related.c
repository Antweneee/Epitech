/*
** EPITECH PROJECT, 2022
** B-NWP-400-PAR-4-1-myteams-antoine.gavira-bottari
** File description:
** s_struct_related
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "server.h"

void del_at_front(connected_client_t **node)
{
    connected_client_t *to_free = *node;

    if ((*node)->_next)
        (*node) = (*node)->_next;
    else
        (*node) = NULL;
    if (*node)
        (*node)->_prev = NULL;
    free_node(to_free);
}

void del_at_back(connected_client_t **node)
{
    connected_client_t *tmp = *node;

    for (; tmp->_next; tmp = tmp->_next);
    tmp->_prev->_next = NULL;
    free_node(tmp);
}

void list_del_elem_at_position(connected_client_t **front_ptr, int fd)
{
    connected_client_t *current = *front_ptr;
    connected_client_t *tmp = NULL;

    if (current->_client_fd == fd) {
        del_at_front(front_ptr);
        return;
    }
    for (; current->_next; current = current->_next) {
        if (current->_next->_client_fd == fd)
            break;
    }
    tmp = current->_next;
    if (!current->_next->_next) {
        del_at_back(front_ptr);
        return;
    } else {
        current->_next = current->_next->_next;
        current->_next->_prev = current;
        free_node(tmp);
    }
}

static connected_client_t *add_node(int client_fd)
{
    connected_client_t *to_add = malloc(sizeof(connected_client_t));

    to_add->_client_fd = client_fd;
    to_add->user_uuid = NULL;
    to_add->user_name = NULL;
    to_add->_next = NULL;
    to_add->_prev = NULL;
    to_add->use = NULL;
    return to_add;
}

void new_client(connected_client_t **clients, int const client_fd)
{
    connected_client_t *tmp = NULL;

    if (*clients == NULL) {
        *clients = add_node(client_fd);
        return;
    }
    if ((*clients)->_next == NULL) {
        (*clients)->_next = add_node(client_fd);
        (*clients)->_next->_prev = *clients;
        return;
    }
    tmp = *clients;
    for (; tmp->_next; tmp = tmp->_next);
    tmp->_next = add_node(client_fd);
    tmp->_next->_prev = tmp;
}