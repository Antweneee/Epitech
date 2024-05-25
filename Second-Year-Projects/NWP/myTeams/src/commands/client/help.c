/*
** EPITECH PROJECT, 2022
** B-NWP-400-PAR-4-1-myteams-antoine.gavira-bottari
** File description:
** help
*/

#include <stdio.h>
#include "client_commands.h"
#include "client.h"

void help(send_data_t data, client_t *clients)
{
    (void) clients;
    printf("%s", data.response);
    printf("\n");
}