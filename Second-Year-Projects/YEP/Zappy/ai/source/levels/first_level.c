/*
** EPITECH PROJECT, 2022
** B-YEP-410-PAR-4-1-zappy-thomas.willson
** File description:
** first_level
*/

#include "ai_info.h"
#include "define.h"
#include "level_command.h"
#include "prototypes.h"
#include <stdbool.h>


/**
 * @brief functions take the struct ai_info and manage event to pass
 *       pass level 1. First after the spawn of the ai, the look and
 *      inventory has to set with LOOK and INVENTORY cmd.
 *      after that we just check if the queue is empty and if ai is incantated
 *      Next we check if we can incatate in the tile, if not we send the functin move_in_tile
 * @param ai
 * @return always true actually but have to be changed
 */
bool first_level(struct ai_info *ai)
{
    if (false == ai->verify->first_look) {
        update_look_and_inventory(ai);
        ai->verify->first_look = true;
        return (true);
    } else if (true == ai->verify->first_look && !is_queue_empty(ai) && !ai->verify->is_incatated) {
        fprintf(stderr, "curr inventory = %s", ai->buf->curr_inventory);
        int* backpack = inventory(ai->buf->curr_inventory);
        int* coord = calculate_next_coo(ai->look_result, ai->level, backpack);
        if (can_do_elevation_on_tile(ai->level, ai->look_result)) {
            fprintf(stderr, "Invetory food = %d", backpack[0]);
            if (backpack[0] < 12 && ai->look_result[0][FOOD_L] > 0) {
                ai->buf->incoming_message[ai->buf->nb_messages++] = my_strcat(TAKE, EAT_FOOD);
                update_look_and_inventory(ai);
                return (true);
            }
            ai->buf->incoming_message[ai->buf->nb_messages++] = strdup(INCANTATION);
            ai->verify->is_incatated = true;
            return (true);
        }
        move_in_tile(ai, coord);
    }
    return (true);
}