/*
** EPITECH PROJECT, 2022
** B-YEP-410-PAR-4-1-zappy-thomas.willson
** File description:
** server
*/

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"
#include "constant.h"
#include "server.h"

static void init_server_info(int ac, char const *av[],
    info_server_t *info_server)
{
    int i = 0;

    info_server->port = atoi(av[PORT]);
    info_server->width = atoi(av[WIDTH]);
    info_server->height = atoi(av[HEIGHT]);
    for (i = 5; i < ac && strcmp(av[i], "-c"); i += 1);
    info_server->clients_nb = atoi(av[CLIENTSNB(i)]);
    info_server->freq = atoi(av[FREQ(i)]);
}

static int get_flag_position(int ac, char const *av[], const char *flag)
{
    int i = 0;

    for (i = 0; i < ac && strcmp(av[i], flag); i += 1);
    return i;
}

static bool init_server_teams(int ac, char const *av[], teams_t **teams)
{
    int n = get_flag_position(ac, av, "-n");
    int c = get_flag_position(ac, av, "-c");

    for (int i = n + 1; i < c; i += 1) {
        if (add_existing_teams(teams, av[i]) == false)
            return false;
    }
    return true;
}

static int init_server_fd(server_t *server, info_server_t *info_server)
{
    server->fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server->fd == FUNCTION_ERROR)
        handle_error("socket()");
    if (setsockopt(server->fd, SOL_SOCKET, SO_REUSEADDR, &(int){1},
    sizeof(int)) == FUNCTION_ERROR)
        handle_error("setsockopt()");
    server->addr.sin_family = AF_INET;
    server->addr.sin_addr.s_addr = INADDR_ANY;
    server->addr.sin_port = htons(info_server->port);
    if (bind(server->fd, (struct sockaddr *)&server->addr,
    sizeof(server->addr)) == FUNCTION_ERROR)
        handle_error("bind()");
    if (listen(server->fd, LISTEN_BACKLOG) == FUNCTION_ERROR)
        handle_error("listen()");
    return EXIT_SUCCESS;
}

int activate_zappy_server(int ac, char const *av[])
{
    server_t server = {0};

    memset(&server.send_gui, 0, sizeof(data_server_to_gui_t));
    init_server_info(ac, av, &server.info_server);
    if (init_server_teams(ac, av, &server.teams) == false)
        return EXIT_FAILURE;
    if (init_server_fd(&server, &server.info_server) == EXIT_FAILURE)
        return EXIT_FAILURE;
    if (manage_server(&server) == EXIT_FAILURE)
        return EXIT_FAILURE;
    free_teams_list(&server.teams);
    return EXIT_SUCCESS;
}
