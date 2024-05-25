/*
** EPITECH PROJECT, 2022
** B-NWP-400-PAR-4-1-myteams-antoine.gavira-bottari
** File description:
** help3
*/

#include <stdio.h>
#include "help_commands.h"
#include "client.h"

send_data_t help_use(send_data_t data)
{
    char *str = "help use : /use ?[“team_uuid”] ?[“channel_uuid”] \
    ?[“thread_uuid”] : use specify a context team/channel/thread";

    strcpy(data.response, str);
    return data;
}

send_data_t help_create(send_data_t data)
{
    char *str = "help create : /create : \
    based on what is being used create the sub resource";

    strcpy(data.response, str);
    return data;
}

send_data_t help_list(send_data_t data)
{
    char *str = "help list : /list : based on what \
    is being used list all the sub resources";

    strcpy(data.response, str);
    return data;
}

send_data_t help_info(send_data_t data)
{
    char *str = "help info : /info : based on what is \
    being used list the current logged user infos";

    strcpy(data.response, str);
    return data;
}