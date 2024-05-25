/*
** EPITECH PROJECT, 2022
** B-NWP-400-PAR-4-1-myteams-antoine.gavira-bottari
** File description:
** help_array
*/

#ifndef HELP_ARRAY_H_
    #define HELP_ARRAY_H_

    #include "help_commands.h"

typedef struct function_s
{
    char *str;
    send_data_t (*function)(send_data_t);
} function_t;

static function_t _command[] = {
    {"login", &help_login},
    {"logout", &help_logout},
    {"users", &help_users},
    {"user", &help_user},
    {"send", &help_send},
    {"messages", &help_messages},
    {"subscribe", &help_subscribe},
    {"subscribed", &help_subscribed},
    {"unsubscribe", &help_unsubscribe},
    {"use", &help_use},
    {"create", &help_create},
    {"list", &help_list},
    {"info", &help_info}
};

#endif /* !HELP_ARRAY_H_ */