/*
** EPITECH PROJECT, 2022
** B-NWP-400-PAR-4-1-myteams-antoine.gavira-bottari
** File description:
** commands
*/

#ifndef COMMANDS_H_
    #define COMMANDS_H_

    #include "server.h"

void help(send_data_t, connected_client_t *client);
void login(send_data_t, connected_client_t *client);
void logout(send_data_t, connected_client_t *client);
void users(send_data_t, connected_client_t *client);
void user(send_data_t, connected_client_t *client);
void my_send(send_data_t, connected_client_t *client);
void messages(send_data_t, connected_client_t *client);
void subscribe(send_data_t, connected_client_t *client);
void subscribed(send_data_t, connected_client_t *client);
void unsubscribe(send_data_t, connected_client_t *client);
void use(send_data_t, connected_client_t *client);
void create(send_data_t, connected_client_t *client);
void list(send_data_t, connected_client_t *client);
void info(send_data_t, connected_client_t *client);

#endif /* !COMMANDS_H_ */