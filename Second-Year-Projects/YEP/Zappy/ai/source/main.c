/*
** EPITECH PROJECT, 2022
** B-YEP-410-PAR-4-1-zappy-thomas.willson
** File description:
** main
*/

#include "prototypes.h"
#include "socket_info.h"
#include "ai_info.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char *argv[])
{
    struct socket_info info = { 0 };
    struct ai_info ai = { 0 };

    if (!check_args(argc, argv))
        return (84);
    info = init_socket_info(atoi(argv[2]), argv[6]);
    if (info.ip == NULL)
        return (84);
    if (connect_to_server(info.client_fd, info.servaddr) == EXIT_FAILURE)
        return (84);
    printf("Connect succesful to %s:%d\n", info.ip, info.port);
    ai = init_ai_info(argv[4]);
    if (client_loop(&info, &ai) == -1)
        return (84);
    return (EXIT_SUCCESS);
}
