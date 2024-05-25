/*
** EPITECH PROJECT, 2022
** B-YEP-410-PAR-4-1-zappy-thomas.willson
** File description:
** ai_info
*/

#ifndef AI_INFO_H_
    #define AI_INFO_H_

    #include "define.h"
    #include <stdio.h>
    #include <stdbool.h>

typedef struct ai_buffer {
    char* buffer;
    char* prev_cmd;
    char* curr_inventory;
    char* curr_look;
    char* incoming_message[10];
    size_t nb_messages;
    char* boradcasted;
} ai_buffer_t;

typedef struct ai_verify {
    bool is_welcome;
    bool first_look;
    bool is_reading;
    bool is_incatated;
    int command_left;
} ai_verify_t;

struct ai_info {
    short level;
    short client_num;
    char team_name[MAX_TEAM_NAME_LENGTH];
    int pos_x;
    int pos_y;
    int** look_result;
    ai_buffer_t* buf;
    ai_verify_t* verify;
};

#endif /* !AI_INFO_H_ */
