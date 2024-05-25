/*
** EPITECH PROJECT, 2022
** B-YEP-410-PAR-4-1-zappy-thomas.willson
** File description:
** data_server
*/

#ifndef DATA_SERVER_H_
    #define DATA_SERVER_H_

    #define CODE_MAX_LENGH 5
    #define RECEIVE_CODE_LENGH 10
    // ! do not use the define bellow it is a temporary define
    #define MAX_PLAYERS 41
    //TODO define for MAX_PLAYERS that take clientsNb * nb_team

    // ! do not use the define bellow it is a temporary define
    #define MAX_CASES 401
    //TODO define for MAX_CASES that take width * heigh

enum player_actions
{
    DEFAULT,
    MOVE_FORWARD,
    RIGHT,
    LEFT,
    BROADCAST,
    FORK,
    EJECT,
    INCANTATION,
};

typedef struct receive_gui_s {
    char code[RECEIVE_CODE_LENGH];
} receive_gui_t;

typedef struct player_data_s
{
    int pos_x;
    int pos_y;

    int player_id;
    int team_id;
    player_actions action_id;
    int level;
} player_data_t;

typedef struct cases_data_s {
    int pos_x;
    int pos_y;
    int nb_food;
    int nb_linemate;
    int nb_deraumere;
    int nb_sibur;
    int nb_mendiane;
    int nb_phiras;
    int nb_thystame;
} cases_data_t;

typedef struct data_server_to_gui_s {
    char code[CODE_MAX_LENGH];
    int number_cases;
    cases_data_t cases[MAX_CASES];
    int number_players;
    player_data_t players[MAX_PLAYERS];
} data_server_to_gui_t;

#endif /* !DATA_SERVER_H_ */
