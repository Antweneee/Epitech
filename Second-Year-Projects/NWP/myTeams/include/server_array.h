/*
** EPITECH PROJECT, 2022
** B-NWP-400-PAR-4-1-myteams-antoine.gavira-bottari
** File description:
** array
*/

#ifndef ARRAY_H_
    #define ARRAY_H_

    #include "server_commands.h"

typedef struct functions_s
{
    char *str;
    void (*handler)(send_data_t, connected_client_t *);
} functions_t;

static functions_t _commands[] = {
    {"/help", &help},
    {"/login", &login},
    {"/logout", &logout},
    {"/users", &users},
    {"/user", &user},
    {"/send", &my_send},
    {"/messages", &messages},
    {"/subscribe", &subscribe},
    {"/subscribed", &subscribed},
    {"/unsubscribe", &unsubscribe},
    {"/use", &use},
    {"/create", &create},
    {"/list", &list},
    {"/info", &info},
};

#endif /* !ARRAY_H_ */