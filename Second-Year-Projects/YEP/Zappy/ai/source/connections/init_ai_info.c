/*
** EPITECH PROJECT, 2022
** B-YEP-410-PAR-4-1-zappy-thomas.willson
** File description:
** init_ai_info
*/

#include "ai_info.h"
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


static ai_buffer_t* init_ai_buffer(void)
{
    ai_buffer_t* buf = malloc(sizeof(ai_buffer_t));

    if (!buf)
        return NULL;
    buf->buffer = NULL;
    buf->prev_cmd = NULL;
    buf->curr_inventory = NULL,
    buf->curr_look = NULL;
    memset(buf->incoming_message, 0, sizeof(buf->incoming_message));
    buf->nb_messages = 0;
    buf->boradcasted = NULL;
    return (buf);
}

static ai_verify_t* init_ai_verify(void)
{
    ai_verify_t* check = malloc(sizeof(ai_verify_t));

    if (!check)
        return NULL;
    check->is_welcome = true;
    check->first_look = false;
    check->is_reading = true;
    check->is_incatated = false;
    check->command_left = 0;
    return (check);
}

/**
 * @brief this function init all resource that ai_info need
 * this is called only 1 time at the beginning of program
 * 
 * @param team_name 
 * @return struct ai_info 
 */
struct ai_info init_ai_info(const char* team_name)
{
    struct ai_info ai = { 0 };

    ai.level = 1;
    ai.client_num = 0;
    strcpy(ai.team_name, team_name);
    strcat(ai.team_name, "\n");
    if (team_name == NULL)
        return (ai);
    ai.pos_x = 0;
    ai.pos_y = 0;
    ai.buf = init_ai_buffer();
    ai.verify = init_ai_verify();
    return (ai);
}