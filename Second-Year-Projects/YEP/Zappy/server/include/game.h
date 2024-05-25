/*
** EPITECH PROJECT, 2022
** server
** File description:
** game
*/

#ifndef GAME_H_
#define GAME_H_

    #include <sys/types.h>
    #include <netinet/in.h>

typedef struct inventory_s
{
    uint8_t food;
    uint8_t linemate;
    uint8_t deraumere;
    uint8_t sibur;
    uint8_t mendiane;
    uint8_t phiras;
    uint8_t thystame;
} inventory_t;

typedef struct player_s
{
    int id;
    int team_id;
    int x;
    int y;
    int oriented;
    uint8_t level;
    inventory_t inventory;
} player_t;

typedef struct linked_player_s
{
    player_t *player;
    struct linked_player_s *next;
} linked_player_t;

typedef struct map_s
{
    uint8_t food;
    uint8_t linemate;
    uint8_t deraumere;
    uint8_t sibur;
    uint8_t mendiane;
    uint8_t phiras;
    uint8_t thystame;
    linked_player_t *players;
} map_t;

#endif /* !GAME_H_ */
