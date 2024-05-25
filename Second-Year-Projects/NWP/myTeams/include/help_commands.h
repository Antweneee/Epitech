/*
** EPITECH PROJECT, 2022
** B-NWP-400-PAR-4-1-myteams-antoine.gavira-bottari
** File description:
** help_commands
*/

#ifndef HELP_COMMANDS_H_
    #define HELP_COMMANDS_H_

    #include "server.h"

send_data_t help_login(send_data_t);
send_data_t help_logout(send_data_t);
send_data_t help_users(send_data_t);
send_data_t help_user(send_data_t);
send_data_t help_send(send_data_t);
send_data_t help_messages(send_data_t);
send_data_t help_subscribe(send_data_t);
send_data_t help_subscribed(send_data_t);
send_data_t help_unsubscribe(send_data_t);
send_data_t help_use(send_data_t);
send_data_t help_create(send_data_t);
send_data_t help_list(send_data_t);
send_data_t help_info(send_data_t);

#endif /* !HELP_COMMANDS_H_ */