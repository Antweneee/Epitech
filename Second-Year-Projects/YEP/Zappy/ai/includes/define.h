/*
** EPITECH PROJECT, 2022
** B-YEP-410-PAR-4-1-zappy-thomas.willson
** File description:
** define
*/

#ifndef DEFINE_H_
    #define DEFINE_H_

    #define HELP "USAGE: ./zappy_ai -p port -n name -h machine\n\t \
port\t  is the port number\n\t name\t  is the name of the team\n\t \
machine  is the name of the machine; localhost by default\n"
    #define NBR_OF_ELEMENT 7
    #define NBR_OF_LOOK_ELEMENT 8
    #define MAX_TEAM_NAME_LENGTH 16
    #define FORWARD "Forward\n"
    #define RIGHT "Right\n"
    #define LEFT "Left\n"
    #define LOOK "Look\n"
    #define INVENTORY "Inventory\n"
    #define BROADCAST "Broadcast "
    #define CONNECT_NBR "Connect_nbr\n"
    #define FORK "Fork\n"
    #define EJECT "Eject\n"
    #define TAKE "Take "
    #define SET "Set "
    #define INCANTATION "Incantation\n"
    #define EAT_FOOD "food\n"


/**
 * @brief tableau de requirement de pierre pour passer de level
 */
static const int requirement_inventory[7][7] = {
    {0, 1, 0, 0, 0, 0, 0},   //1->2
    {0, 1, 1, 1, 0, 0, 0},   //2->3
    {0, 2, 0, 1, 0, 2, 0},   //3->4
    {0, 1, 1, 2, 0, 1, 0},   //4->5
    {0, 1, 2, 1, 3, 0, 0},   //5->6
    {0, 1, 2, 3, 0, 1, 0},   //6->7
    {0, 2, 2, 2, 2, 2, 1},   //7->8
};

static const int requirement_tile[7][8] = {
    {1, 0, 1, 0, 0, 0, 0, 0},   //1->2
    {2, 0, 1, 1, 1, 0, 0, 0},   //2->3
    {2, 0, 2, 0, 1, 0, 2, 0},   //3->4
    {4, 0, 1, 1, 2, 0, 1, 0},   //4->5
    {4, 0, 1, 2, 1, 3, 0, 0},   //5->6
    {6, 0, 1, 2, 3, 0, 1, 0},   //6->7
    {6, 0, 2, 2, 2, 2, 2, 1},   //7->8
};

typedef enum {
    FOOD,
    LINEMATE,
    DERAUMERE,
    SIBUR,
    MENDIANE,
    PHIRAS,
    THYSTAME
} resource_e;
// inventory


typedef enum {
    PLAYER_L,
    FOOD_L,
    LINEMATE_L,
    DERAUMERE_L,
    SIBUR_L,
    MENDIANE_L,
    PHIRAS_L,
    THYSTAME_L
} look_e;
// requirement

#endif /* !DEFINE_H_ */
