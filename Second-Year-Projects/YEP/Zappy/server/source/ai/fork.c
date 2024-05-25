/*
** EPITECH PROJECT, 2022
** B-YEP-410-PAR-4-1-zappy-thomas.willson
** File description:
** fork
*/

#include <string.h>
#include <time.h>
#include "functions.h"
#include "server.h"

team_t *get_specific_team(teams_t **teams, const char *client_team_name)
{
    team_t *team = NULL;

    for (team_t *tmp = *teams; tmp; tmp = tmp->next) {
        if (tmp->name && strcmp(tmp->name, client_team_name) == 0)
            team = tmp;
    }
    return team;
}

static int manage_forking_on_player(client_t *client, server_t *server)
{
    team_t *team = NULL;
    uint x = client->player->x;
    uint y = client->player->y;

    team = get_specific_team(&server->teams, client->team_name);
    if (team == NULL)
        return EXIT_FAILURE;
    if (add_egg_to_fork_list(&team->forks, x, y, time(NULL)) == false)
        return EXIT_FAILURE;
    team->forks_nb++;
    return EXIT_SUCCESS;
}

int xfork(client_t *client, server_t *server,
__ATTRIBUTE_UNUSED__ map_t **map)
{
    if (client == NULL || client->player == NULL)
        return EXIT_SUCCESS;
    if (set_writable(client, server) == EXIT_FAILURE)
        return EXIT_FAILURE;
    if (manage_forking_on_player(client, server) == EXIT_FAILURE)
        return EXIT_FAILURE;
    if (message_chrono(client, "ok\n",
    42.0 / server->info_server.freq) == EXIT_FAILURE)
        return EXIT_FAILURE;
    strcpy(server->send_gui.code, "MPLA");
    translate_mod_player(&server->send_gui, client->player, FORK);
    return gui_write(server);
}
