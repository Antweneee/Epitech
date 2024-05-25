/*
** EPITECH PROJECT, 2022
** B-YEP-410-PAR-4-1-zappy-thomas.willson
** File description:
** command_gui
*/


#include <stdio.h>
#include <string.h>
#include "command.h"
#include "functions.h"

static const client_command_t gui_command[] = {
    {
        .command = "/help",
        .function = help_gui
    },
    {
        .command = "amap",
        .function = amap
    },
    {
        .command = "apla",
        .function = apla
    }
};

static void display_struct(data_server_to_gui_t *gui)
{
    printf("{\n \
    code[%s]\n \
    number_case: %d\n \
    cases: ", gui->code, gui->number_cases);
    for (int i = 0; i < gui->number_cases; ++i) {
        printf("[x: %d y: %d] ", gui->cases[i].pos_x,
        gui->cases[i].pos_y);
    }
    printf("\nnumber_player: %d\n \
    players: ",
           gui->number_players);
    for (int i = 0; i < gui->number_players; ++i) {
        printf("[id:%d teams:%d x: %d y: %d] ", gui->players[i].player_id,
        gui->players[i].team_id,
        gui->players[i].pos_x, gui->players[i].pos_y);
    }
    printf("\n}\n");
}

static int write_gui(client_t *client, server_t *server)
{
    display_struct(&server->send_gui);
    if (write(fileno(client->file), &server->send_gui
    , sizeof(data_server_to_gui_t)) == -1)
        return EXIT_FAILURE;
    server->send_gui.number_players = 0;
    server->send_gui.number_cases = 0;
    memset(&server->send_gui, 0, sizeof(data_server_to_gui_t));
    return reset_ev(client, server);
}

int command_gui(client_t *client, server_t *server,
__ATTRIBUTE_UNUSED__ map_t **map)
{
    if (client->read == false)
        return write_gui(client, server);
    for (size_t i = 0; client->command != NULL && client->command[0] != NULL
    && i < sizeof_arr(gui_command); ++i)
        if (strcmp(client->command[0], gui_command[i].command) == 0)
            return gui_command[i].function(client, server, map);
    return EXIT_SUCCESS;
}