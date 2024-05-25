/*
** EPITECH PROJECT, 2022
** B-YEP-410-PAR-4-1-zappy-thomas.willson
** File description:
** broadcast_position
*/

#include "server.h"
#include "broadcast.h"

/**
 * @brief Create a node position object
 * 
 * @param client 
 * @param k 
 * @return positions_t* 
 */
static positions_t *create_node_position(client_t *client, char k)
{
    positions_t *node = (positions_t *)malloc(sizeof(positions_t));

    if (node == NULL)
        return NULL;
    node->x = client->player->x;
    node->y = client->player->y;
    node->k = k;
    node->client = client;
    node->next = NULL;
    return node;
}

/**
 * @brief Add player positions to the linked list.
 * 
 * @param positions The linked list.
 * @param client Client informations.
 * @param k Tail if the player is in the same tail that
 * the player who send the Broadcast command.
 * @return true In case of success.
 * @return false In case of failure.
 */
bool add_player_position(positions_t **positions,
client_t *client, char k)
{
    positions_t *tmp = NULL;
    positions_t *add = NULL;

    if (*positions == NULL) {
        tmp = create_node_position(client, k);
        if (!tmp)
            return false;
        *positions = tmp;
    } else {
        for (tmp = *positions; tmp->next; tmp = tmp->next);
        add = create_node_position(client, k);
        if (!add)
            return false;
        tmp->next = add;
    }
    return true;
}

/**
 * @brief Free all players positions.
 * 
 * @param positions 
 */
void free_player_position(positions_t **positions)
{
    positions_t *del = NULL;

    while (*positions != NULL) {
        del = *positions;
        *positions = (*positions)->next;
        free(del);
    }
}
