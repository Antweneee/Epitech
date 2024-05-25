/*
** EPITECH PROJECT, 2022
** server
** File description:
** elevation
*/

#ifndef ELEVATION_H_
#define ELEVATION_H_

#include "command.h"
#include "server.h"

static const elevation_t elevation[] = {
    [1] = {
        .nb_players = 1,
        .linemate = 1,
        .deraumere = 0,
        .sibur = 0,
        .mendiane = 0,
        .phiras = 0,
        .thystame = 0
    },
    [2] = {
        .nb_players = 2,
        .linemate = 1,
        .deraumere = 1,
        .sibur = 1,
        .mendiane = 0,
        .phiras = 0,
        .thystame = 0
    },
    [3] = {
        .nb_players = 2,
        .linemate = 2,
        .deraumere = 0,
        .sibur = 1,
        .mendiane = 0,
        .phiras = 2,
        .thystame = 0
    },
    [4] = {
        .nb_players = 4,
        .linemate = 1,
        .deraumere = 1,
        .sibur = 2,
        .mendiane = 0,
        .phiras = 1,
        .thystame = 0
    },
    [5] = {
        .nb_players = 4,
        .linemate = 1,
        .deraumere = 2,
        .sibur = 1,
        .mendiane = 3,
        .phiras = 0,
        .thystame = 0
    },
    [6] = {
        .nb_players = 6,
        .linemate = 1,
        .deraumere = 2,
        .sibur = 3,
        .mendiane = 0,
        .phiras = 1,
        .thystame = 0
    },
    [7] = {
        .nb_players = 6,
        .linemate = 2,
        .deraumere = 2,
        .sibur = 2,
        .mendiane = 2,
        .phiras = 2,
        .thystame = 1
    },
};

#endif /* !ELEVATION_H_ */
