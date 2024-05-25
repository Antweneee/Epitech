/*
** EPITECH PROJECT, 2022
** B-YEP-410-PAR-4-1-zappy-thomas.willson
** File description:
** constant
*/

#ifndef CONSTANT_H_
    #define CONSTANT_H_

    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <sys/epoll.h>
    #include <fcntl.h>

    #define UNKNOW "ko\n"
    #define MAX_EVENTS 10
    #define EXIT_FAILURE_EPI 84
    #define NUMBER_MAX_ARGS 13
    #define FUNCTION_ERROR -1
    #define LISTEN_BACKLOG 50
    #define MAX_CASE_LOOK \
    strlen("[ player food linemate deraumere sibur mendiane phiras thystame]")
    #define LEVEL_CASE_LOOK_MAX(level) (level * 2 + 2) * MAX_CASE_LOOK

    #define INVENTORY_FORMAT  \
    "[ food %d, linemate %d, deraumere %d, sibur %d, mendiane %d, phiras %d, thystame %d ]\n"

    #define NETWORK_CLIENT(i, j) (i == '\n' || j == '\r')

    #define UP_Y(player, level, index) (int)(player->y - level + index)
    #define RIGHT_Y(player, level, index) (int)(player->y - level + index)
    #define LEFT_Y(player, level, index) (int)(player->y + level - index)
    #define DOWN_Y(player, level, index) (int)(player->y + level - index)

    #define RIGHT_X(player, level, index) (int)(player->x + level - index)

    #define Y_NEG(info, level, index) (int)(info->height - level + index)
    #define Y_POS(level, index) (int)(0 + index - 2)

    #define O_Y_POS(level, index) (int)(level - index - 1)

    #define O_X_POS(index) (int)(index)
    #define O_X_NEG(info, index) (int)( info->width - 1 - index)

    #define X_NEG(info, level, index) (int)(info->width - level + index)
    #define X_POS(level, index) (int)(index)

    #define UP_X(player, level, index) (int)(player->x - level + index)
    #define RIGHT_X(player, level, index) (int)(player->x + level - index)
    #define LEFT_X(player, level, index) (int)(player->x - level + index)
    #define DOWN_X(player, level, index) (int)(player->x + level - index)

    #define RIGHT_Y_ABS(info, player, level, index) \
    RIGHT_Y(player, level, index) < 0 ? Y_NEG(info, level, index) :   \
    RIGHT_Y(player, level, index) > (int)(info->height - 1) ? Y_POS(level, index)    \
    : RIGHT_Y(player, level, index)

    #define RIGHT_X_ABS(info, player, level, index) \
    RIGHT_X(player, level, index) < 0 ? X_NEG(info, level, index) :   \
    RIGHT_X(player, level, index) > (int)(info->width - 1) ? X_POS(level, index)    \
    : RIGHT_X(player, level, index)

    #define LEFT_Y_ABS(info, player, level, index) \
    LEFT_Y(player, level, index) < 0 ? Y_NEG(info, level, index) :   \
    LEFT_Y(player, level, index) > (int)(info->height - 1) ? O_X_POS(index)    \
    : LEFT_Y(player, level, index)

    #define LEFT_X_ABS(info, player, level, index) \
    LEFT_X(player, level, index) < 0 ? X_NEG(info, level, index) :   \
    LEFT_X(player, level, index) > (int)(info->width - 1) ? X_POS(level, index)    \
    : LEFT_X(player, level, index)

    #define UP_Y_ABS(info, player, level, index) \
    UP_Y(player, level, index) < 0 ? Y_NEG(info, level, index) :   \
    UP_Y(player, level, index) > (int)(info->height - 1) ? X_POS(level, index)    \
    : UP_Y(player, level, index)

    #define UP_X_ABS(info, player, level, index) \
    UP_X(player, level, index) < 0 ? X_NEG(info, level, index) :   \
    UP_X(player, level, index) > (int)(info->width - 1) ? Y_POS(level, index)    \
    : UP_X(player, level, index)

    #define DOWN_Y_ABS(info, player, level, index) \
    DOWN_Y(player, level, index) < 0 ? Y_NEG(info, level, index) :   \
    DOWN_Y(player, level, index) > (int)(info->height - 1) ? O_Y_POS(level, index)    \
    : DOWN_Y(player, level, index)

    #define DOWN_X_ABS(info, player, level, index) \
    DOWN_X(player, level, index) < 0 ? O_X_NEG(info, index) :   \
    DOWN_X(player, level, index) > (int)(info->width - 1) ? O_X_POS(index)    \
    : DOWN_X(player, level, index)

    #define sizeof_arr(array) sizeof(array) / sizeof(array[0])
    #define __ATTRIBUTE_UNUSED__ __attribute__((unused))

    #define CHOOSE_CHRONO(ok, client, server) (set_writable(client, server) == EXIT_FAILURE) \
    || (ok == true && message_chrono(client, "ok\n", 7 / server->info_server.freq) \
    == EXIT_FAILURE ) || (ok == false \
    && message_chrono(client, "ko\n", 0) \
    == EXIT_FAILURE )

    #define P 0
    #define PORT 1
    #define PORT_FLAG "-p"
    #define X 2
    #define WIDTH 3
    #define WIDTH_FLAG "-x"
    #define Y 4
    #define HEIGHT 5
    #define HEIGHT_FLAG "-y"
    #define N 6
    #define NAME_FLAG "-n"
    #define C(i) (i + 0)
    #define CLIENTSNB(i) (i + 1)
    #define CLIENTSNB_FLAG "-c"
    #define F(i) (i + 2)
    #define FREQ(i) (i + 3)
    #define FREQ_FLAG "-f"

    #define MIN_WIDTH 10
    #define MAX_WIDTH 30
    #define MIN_HEIGHT 10
    #define MAX_HEIGHT 30
    #define MIN_CLIENTS_NB 0
    #define MIN_FREQ 2
    #define MAX_FREQ 10000
    #define ELEVATION_MESSAGE "Current level: "

    #define handle_error(msg)   \
        do { perror(msg); return (EXIT_FAILURE); } while(0);

    #define debug(msg)                      \
        do {                                \
            fprintf(stderr, "[%s]\n", msg); \
        } while(0);

#endif /* !CONSTANT_H_ */
