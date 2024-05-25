/*
** EPITECH PROJECT, 2022
** B-NWP-400-PAR-4-1-myteams-antoine.gavira-bottari
** File description:
** client_commands
*/

#ifndef CLIENT_COMMANDS_H_
    #define CLIENT_COMMANDS_H_

    #include "mydata.h"
    #include "client.h"

void help(send_data_t, client_t *);
void login(send_data_t, client_t *);
void logout(send_data_t, client_t *);
void users(send_data_t, client_t *);
void user(send_data_t, client_t *);
void my_send(send_data_t, client_t *);
void messages(send_data_t, client_t *);
void subscribe(send_data_t, client_t *);
void subscribed(send_data_t, client_t *);
void unsubscribe(send_data_t, client_t *);
void use(send_data_t, client_t *);
void create(send_data_t, client_t *);
void list(send_data_t, client_t *);
void info(send_data_t, client_t *);

#endif /* !CLIENT_COMMANDS_H_ */