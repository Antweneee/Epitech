/*
** EPITECH PROJECT, 2022
** B-NWP-400-PAR-4-1-myteams-antoine.gavira-bottari
** File description:
** client_array
*/

#ifndef CLIENT_ARRAY_H_
    #define CLIENT_ARRAY_H_

    #include "client_commands.h"

typedef struct functions_s
{
    char *str;
    void (*handler)(send_data_t, client_t *);
} functions_t;

static functions_t _commands[] = {
    {"help", &help},
    {"login", &login},
    {"logout", &logout},
    {"users", &users},
    {"user", &user},
    {"send", &my_send},
    {"messages", &messages},
    {"subscribe", &subscribe},
    {"subscribed", &subscribed},
    {"unsubscribe", &unsubscribe},
    {"use", &use},
    {"create", &create},
    {"list", &list},
    {"info", &info},
};

#endif /* !CLIENT_ARRAY_H_ */