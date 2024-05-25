/*
** EPITECH PROJECT, 2022
** B-NWP-400-PAR-4-1-myteams-antoine.gavira-bottari
** File description:
** help2
*/

#include <stdio.h>
#include "help_commands.h"
#include "client.h"

send_data_t help_send(send_data_t data)
{
    char *str = "help send : /send [“user_uuid”] [“message_body”] : \
    send a message to a user";

    strcpy(data.response, str);
    return data;
}

send_data_t help_messages(send_data_t data)
{
    char *str = "help messages : /messages [“user_uuid”] : \
    list all messages exchange with an user";

    strcpy(data.response, str);
    return data;
}

send_data_t help_subscribe(send_data_t data)
{
    char *str = "help subscribe : /subscribe [“team_uuid”] : \
    subscribe to the event of a team and its sub directories \
    (enable reception of all events from a team)";

    strcpy(data.response, str);
    return data;
}

send_data_t help_subscribed(send_data_t data)
{
    char *str = "help subscribed : /subscribed ?[“team_uuid”] : \
    list all subscribed teams or list all users subscribed to a team";

    strcpy(data.response, str);
    return data;
}

send_data_t help_unsubscribe(send_data_t data)
{
    char *str = "help unsubscribe : /unsubscribe [“team_uuid”] : \
    unsubscribe from a team";

    strcpy(data.response, str);
    return data;
}