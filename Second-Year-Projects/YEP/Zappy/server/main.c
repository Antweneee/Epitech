/*
** EPITECH PROJECT, 2022
** B-YEP-410-PAR-4-1-zappy-thomas.willson
** File description:
** main
*/

#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include "functions.h"
#include "constant.h"
#include "server.h"

enum return_code_e {
    SUCCESS,
    FAILURE,
};

int helper(enum return_code_e return_code)
{
    const char *helper_tab[] = {
        "USAGE: ./zappy_server -p port -x width -y height -n name1 name2 ... \
-c clientsNb -f freq",
        "\tport\t\tis the port number",
        "\twidth\t\tis the width of the world",
        "\theight\t\tis the height of the world",
        "\tnameX\t\tis the name of the team X",
        "\tclientsNb\tis the number of authorized clients per team",
        "\tfreq\t\tis the reciprocal of time unit for execution of actions",
        NULL
    };

    for (int i = 0; helper_tab[i] != NULL; i += 1)
        dprintf(1, "%s\n", helper_tab[i]);
    return return_code == SUCCESS ? EXIT_SUCCESS : EXIT_FAILURE_EPI;
}

int main(int ac, char const *av[])
{
    if (ac == 2 && strcmp(av[1], "-help") == 0)
        return helper(SUCCESS);
    if (error_handling(ac, &av[1]) == true)
        return helper(FAILURE);
    return activate_zappy_server(ac, &av[1]);
}
