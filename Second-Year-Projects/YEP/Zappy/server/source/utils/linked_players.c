/*
** EPITECH PROJECT, 2022
** server
** File description:
** linked_players
*/

#include "constant.h"
#include "game.h"

int assign_player(map_t *map, player_t *player)
{
    linked_player_t *linked = map->players;
    linked_player_t *new_player;

    if (player == NULL)
        return EXIT_SUCCESS;
    new_player = malloc(sizeof(linked_player_t));
    if (new_player == NULL)
        return EXIT_FAILURE;
    new_player->player = player;
    new_player->next = NULL;
    if (linked == NULL) {
        map->players = new_player;
        return EXIT_SUCCESS;
    }
    for (; linked->next != NULL; linked = linked->next);
    linked->next = new_player;
    return EXIT_SUCCESS;
}

void eject_player(map_t *map, player_t *player)
{
    linked_player_t *linked = map->players;
    linked_player_t *to_free;

    if (linked->player == NULL)
        return;
    if (linked->player == player) {
        map->players = map->players->next;
        free(linked);
        return;
    }
    for (; linked->next != NULL; linked = linked->next)
        if (linked->next->player == player) {
            to_free = linked->next;
            linked->next = linked->next->next;
            free(to_free);
            return;
        }
}