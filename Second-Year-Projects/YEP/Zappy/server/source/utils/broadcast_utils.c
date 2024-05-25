/*
** EPITECH PROJECT, 2022
** B-YEP-410-PAR-4-1-zappy-thomas.willson
** File description:
** broadcast_utils
*/

#include <string.h>
#include <math.h>
#include "server.h"
#include "broadcast.h"

/**
 * @brief Compute angle between two Vectors positions
 * [A1, B1] and [A2, B2] with ARCTANG Math library function.
 * 
 * @param x1 Player who send Broadcast pos x.
 * @param y1 Player who send Broadcast pos x.
 * @param x Other players pos x.
 * @param y Other players pos y.
 * @return float Angle between the two Vectors (2D).
 */
static float compute_angle_between_two_positions(
    uint x1,
    uint y1,
    uint x,
    uint y)
{
    float angle = atan2f((float)y1 - (float)y, (float)x1 - (float)x);

    return angle;
}

/**
 * @brief Find the position of a player in the Map
 * Positions are : NORTH, WEST, EST, SOUTH,
 * NORTH_WEST, NORTH_EST, SOUTH_WEST, SOUTH_EST.
 * 
 * @param degree The degree between 0°, 90°, 180°.
 * @return const char* Position.
 */
static const char *position_of_player_in_map(float degree)
{
    for (size_t i = 0; i < sizeof_array(DEGREE_ANGLE_TABLE); i += 1) {
        if (degree >= DEGREE_ANGLE_TABLE[i].min_degree
        && degree <= DEGREE_ANGLE_TABLE[i].max_degree)
            return DEGREE_ANGLE_TABLE[i].position;
    }
    return NULL;
}

/**
 * @brief Get the tail with position in map object
 * 
 * @param position 
 * @param oriented 
 * @return char 
 */
static char get_tail_with_position_in_map(const char *position, int oriented)
{
    for (size_t i = 0; i < sizeof_array(POSITION_TABLE_TAIL); i += 1) {
        if (oriented == POSITION_TABLE_TAIL[i].oriented)
            if (strcmp(position, POSITION_TABLE_TAIL[i].position) == 0)
                return POSITION_TABLE_TAIL[i].tail;
    }
    return 'E';
}

/**
 * @brief Get the player tile sound object
 * 
 * @param player 
 * @param x 
 * @param y 
 * @param oriented 
 * @return char 
 */
char get_player_tile_sound(player_t *player, uint x, uint y, int oriented)
{
    float angle = 0.0;
    float degree = 0.0;
    const char *position = NULL;
    char player_tail;

    angle = compute_angle_between_two_positions(player->x, player->y, x, y);
    degree = angle * (SCALE_PROTRACTOR_MAX_SIZE / M_PI);
    position = position_of_player_in_map(degree);
    if (!position)
        return 'E';
    player_tail = get_tail_with_position_in_map(position, oriented);
    if (player_tail == 'E')
        return 'E';
    return player_tail;
}

/**
 * @brief Get the full message object
 * 
 * @param text 
 * @param c 
 * @return char* 
 */
char *get_full_message(const char *text, char c)
{
    size_t size = (strlen("message") + strlen(text) + 1 + 4);
    char *buffer = (char *)malloc(sizeof(char) * (size + 1));
    int i = 0;

    if (buffer == NULL)
        return NULL;
    memset(buffer, 0, size);
    strcpy(buffer, "message ");
    i = strlen(buffer);
    buffer[i++] = c;
    strcat(buffer, ", ");
    strcat(buffer, text);
    i = strlen(buffer);
    buffer[i++] = '\n';
    buffer[i] = '\0';
    return buffer;
}
