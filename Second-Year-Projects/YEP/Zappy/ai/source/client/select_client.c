/*
** EPITECH PROJECT, 2022
** B-YEP-410-PAR-4-1-zappy-thomas.willson
** File description:
** select_client
*/

#include "prototypes.h"
#include "socket_info.h"
#include "ai_info.h"
#include <stdlib.h>
#include <unistd.h>
#include <sys/select.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>

/**
 * @brief check if the queue is empty
 *
 * @param ai
 * @return true if the queue is not empty
 * @return false if the queue is empty
 */
bool is_queue_empty(struct ai_info* ai)
{
    if (ai->buf->incoming_message[0] != NULL)
        return (true);
    return (false);
}

/**
 * @brief this function is called only when a client connect to the server
 * they exchange data like team_name and coord of the map
 *
 * @param socket
 * @param ai
 * @return true
 * @return false if a bad team_name is send
 */
static bool welcom_server(struct ai_info* ai)
{
    if (ai->verify->is_welcome == true) {
        ai->buf->incoming_message[ai->buf->nb_messages++] = strdup(ai->team_name);
        ai->verify->is_welcome = false;
        return (true);
    }
    if (!strcmp(ai->buf->buffer, "ko"))
        return (false);
    if (ai->client_num == 0 && !ai->verify->is_welcome)
        ai->client_num = atoi(ai->buf->buffer);
    return (true);
}

/**
 * @brief check if this is the welcome part, if a command exec functions is called
 * and check if a player is dead or not
 *
 * @param socket
 * @param ai
 * @return true
 * @return false
 */
static bool check_command(struct ai_info* ai)
{
    if (ai->client_num == 0) {
        if (!welcom_server(ai))
            return (false);
    }
    if (ai->client_num != 0)
        if (!command_exec(ai))
            return (false);
    if (!strcmp(ai->buf->buffer, "dead"))
        return (false);
    return (true);
}

/**
 * @brief write handler handle message to be send by the queue
 * after a write to the server a shift is processed by the shift_element function
 * 
 * @param socket 
 * @param ai 
 * @return true 
 * @return false 
 */
static bool client_write_handler(struct socket_info *socket,
struct ai_info* ai)
{
    if (write(socket->client_fd, ai->buf->incoming_message[0],
                    strlen(ai->buf->incoming_message[0])) == -1) {
        perror("write: ");
        return (false);
    }

    fprintf(stderr, "\nwrite to server: %s", ai->buf->incoming_message[0]);
    ai->buf->prev_cmd = strdup(ai->buf->incoming_message[0]);
    shift_element(ai);
    ai->buf->nb_messages -= 1;
    if (ai->verify->command_left > 0)
        ai->verify->command_left--;
    FD_ZERO(&socket->set_write);
    return (true);
}

/**
 * @brief read handler for incoming message receive by the server and
 * update the look variable and the inventory variable
 * 
 * @param socket 
 * @param ai 
 * @return true 
 * @return false 
 */
static bool client_read_handler(struct socket_info *socket, struct ai_info* ai)
{
    FILE* file = fdopen(socket->client_fd, "r");

    if (file == NULL)
        return (false);
    if ((read_client(&ai->buf->buffer, file, ai)) == -1) {
        return (false);
    }
    fprintf(stderr, "\nFrom server: %s\n", ai->buf->buffer);
    fprintf(stderr, "is reading %d\n", ai->verify->is_reading);
    fprintf(stderr, "%s\n", ai->buf->incoming_message[0]);
    if (ai->verify->first_look == true) {
        if (!strcmp(ai->buf->prev_cmd, LOOK) && !strncmp(ai->buf->buffer, "[ ", 2)) {
            ai->buf->curr_look = strdup(ai->buf->buffer);
            ai->look_result = parse_look(ai->buf->curr_look, ai->level);
            print_look_parsed(ai->look_result, ai->level);
        }
        if (!strcmp(ai->buf->prev_cmd, INVENTORY))
            ai->buf->curr_inventory = strdup(ai->buf->buffer);
        if (!strncmp(ai->buf->buffer, "Current level: ", 15)) {
            ai->level += 1;
            ai->verify->first_look = false;
            ai->verify->is_incatated = false;
            ai->verify->is_reading = !ai->verify->is_reading;
        }
        if (!strncmp(ai->buf->buffer, "message", 7)) {
            ai->buf->boradcasted = strdup(ai->buf->buffer + 8);
            ai->verify->is_reading = !ai->verify->is_reading;
        }
    }
    if (check_command(ai) == false) {
        fprintf(stderr, "Client disconnected: %s\n", ai->buf->buffer);
        return (false);
    }
    return (true);
}

/**
 * @brief main loop function that contains everything, select handler here
 * this function is the core of the client ai, be careful when modifying
 * 
 * @param socket 
 * @param ai 
 * @return int 
 */
int client_loop(struct socket_info* socket, struct ai_info* ai)
{
    FD_ZERO(&socket->set_write);
    while (1) {
        FD_ZERO(&socket->set_read);
        FD_SET(socket->client_fd, &socket->set_read);
        socket->set_exeption = socket->set_read;
        if (ai->verify->is_reading == false && is_queue_empty(ai)) {
            FD_SET(socket->client_fd, &socket->set_write);
            ai->verify->is_reading = true;
        }
        fprintf(stderr, "Waiting select\n");
        if (select(socket->client_fd + 1, &socket->set_read,
            &socket->set_write, &socket->set_exeption, NULL) == -1) {
            perror("select failed: ");
            return (-1);
        }
        if (FD_ISSET(socket->client_fd, &socket->set_read))
            if (!client_read_handler(socket, ai))
                return (EXIT_FAILURE);
        if (FD_ISSET(socket->client_fd, &socket->set_write)) {
            if (!client_write_handler(socket, ai))
                return (EXIT_FAILURE);
        }
        if (FD_ISSET(socket->client_fd, &socket->set_exeption))
            return (EXIT_FAILURE);

    }
    return (EXIT_SUCCESS);
}