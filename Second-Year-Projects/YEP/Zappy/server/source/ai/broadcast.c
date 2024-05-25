/*
** EPITECH PROJECT, 2022
** B-YEP-410-PAR-4-1-zappy-thomas.willson
** File description:
** broadcast
*/

#include <string.h>
#include "server.h"
#include "functions.h"
#include "broadcast.h"

/**
 * @brief Function that take the player tile from the position
 * of the player who send the Broadcast message.
 * Print the message to every client in the Zappy server.
 * 
 * @param positions Positions of all players in the game except
 * Player who send the message.
 * @param server Zappy server structure control.
 * @param player Player who send the message.
 * @param text Text of the player who send the Broadcast `text`.
 * @return true If success.
 * @return false If failure.
 */
static bool send_message_to_clients(positions_t **positions, server_t *server,
player_t *player, const char *text)
{
    char *message = NULL;
    char player_tail;

    for (positions_t *pos = *positions; pos != NULL; pos = pos->next) {
        player_tail = pos->k;
        if (player_tail == '?')
            player_tail = get_player_tile_sound(player, pos->x, pos->y,
            pos->client->player->oriented);
        if (set_writable(pos->client, server) == EXIT_FAILURE)
            return false;
        message = get_full_message(text, player_tail);
        if (message == NULL)
            return false;
        if (message_chrono(pos->client, message,
        7 / server->info_server.freq) == EXIT_FAILURE)
            return false;
        free(message);
    }
    return true;
}

/**
 * @brief Get the player and positions object
 * 
 * @param positions 
 * @param team 
 * @param player_client 
 * @return int 
 */
static int get_player_and_positions(positions_t **positions, team_t *team,
client_t *player_client)
{
    client_t *client = NULL;
    char k = '?';

    for (linked_client_t *li_client = team->clients; li_client;
    li_client = li_client->next) {
        client = li_client->client;
        if (client->file == player_client->file)
            continue;
        if (player_client->player->x == client->player->x
        && player_client->player->y == client->player->y)
            k = '0';
        if (add_player_position(positions, client, k) == false)
            return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

/**
 * @brief Function that manage everything like add player positions
 * and transmit messages to all players in the game
 * 
 * @param player_client Player who send the broadcast.
 * @param server Zappy server structure control.
 * @param text Text of the player who send the Broadcast `text`.
 * @return int SUCCESS or FAILURE.
 */
static int manage_send_message_to_clients(client_t *player_client,
server_t *server, const char *text)
{
    positions_t *positions = NULL;

    for (team_t *team = server->teams; team; team = team->next) {
        if (get_player_and_positions(&positions, team,
        player_client) == EXIT_FAILURE)
            return EXIT_FAILURE;
    }
    if (send_message_to_clients(&positions, server,
    player_client->player, text) == false)
        return EXIT_FAILURE;
    free_player_position(&positions);
    return EXIT_SUCCESS;
}

/**
 * @brief Broadcast command that send to every Player in the game
 * a message (except for the Player who send the Broadcast command).
 * 
 * @param client Client who send the Broadcast.
 * @param server Zappy server structure control.
 * @param map Zappy server map.
 * @return int SUCCESS or FAILURE.
 */
int broadcast(client_t *client, server_t *server,
__ATTRIBUTE_UNUSED__ map_t **map)
{
    if (client == NULL || client->player == NULL)
        return EXIT_SUCCESS;
    if (set_writable(client, server) == EXIT_FAILURE)
        return EXIT_FAILURE;
    if (client->command[1] == NULL)
        return message_chrono(client, "ko\n", 0);
    if (message_chrono(client, "ok\n",
    7.0 / server->info_server.freq) == EXIT_FAILURE)
        return EXIT_FAILURE;
    if (manage_send_message_to_clients(client, server,
    client->command[1]) == EXIT_FAILURE)
        return EXIT_FAILURE;
    strcpy(server->send_gui.code, "MPLA");
    translate_mod_player(&server->send_gui, client->player, BROADCAST);
    return gui_write(server);
}
