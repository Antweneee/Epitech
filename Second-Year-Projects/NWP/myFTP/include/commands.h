/*
** EPITECH PROJECT, 2022
** B-NWP-400-PAR-4-1-myftp-antoine.gavira-bottari
** File description:
** commands
*/

#ifndef COMMANDS_H_
#define COMMANDS_H_

#include "myftp.h"

char *user_handler(char *, client_t *, socket_t *);
char *password_handler(char *, client_t *, socket_t *);
char *cwd_handler(char *, client_t *, socket_t *);
char *cdup_handler(char *, client_t *, socket_t *);
char *quit_handler(char *, client_t *, socket_t *);
char *dele_handler(char *, client_t *, socket_t *);
char *pwd_handler(char *, client_t *, socket_t *);
char *pasv_handler(char *, client_t *, socket_t *);
char *port_handler(char *, client_t *, socket_t *);
char *help_handler(char *, client_t *, socket_t *);
char *noop_handler(char *, client_t *, socket_t *);
char *retr_handler(char *, client_t *, socket_t *);
char *stor_handler(char *, client_t *, socket_t *);
char *list_handler(char *, client_t *, socket_t *);

typedef struct command_s
{
    char *str;
    char *(*handler)(char *, client_t *, socket_t *);
} command_t;

static command_t _commands[] = {
    {"USER", &user_handler},
    {"PASS", &password_handler},
    {"CWD", &cwd_handler},
    {"CDUP", &cdup_handler},
    {"QUIT", &quit_handler},
    {"DELE", &dele_handler},
    {"PWD", &pwd_handler},
    {"PASV", &pasv_handler},
    {"PORT", &port_handler},
    {"HELP", &help_handler},
    {"NOOP", &noop_handler},
    {"RETR", &retr_handler},
    {"STOR", &stor_handler},
    {"LIST", &list_handler},
};

#endif /* !COMMANDS_H_ */
