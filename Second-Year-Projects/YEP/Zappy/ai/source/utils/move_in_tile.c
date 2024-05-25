/*
** EPITECH PROJECT, 2022
** B-YEP-410-PAR-4-1-zappy-thomas.willson
** File description:
** move_in_tile
*/

#include "ai_info.h"
#include "define.h"
#include "prototypes.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief this function is called when there is no incantation
 * and when there is shit rock in the actual tile, the function take it
 * into inventory.
 *
 * @param ai
 * @param coord coord to go to the tile that contains the rock
 */
void move_in_tile(struct ai_info* ai, int *coord)
{
    int abs_x = abs(coord[0]);
    int count = coord[1];

    if (42 == coord[0] || 42 == coord[1]) {
        ai->buf->incoming_message[ai->buf->nb_messages++] = strdup(FORWARD);
        ai->buf->incoming_message[ai->buf->nb_messages++] = strdup(LOOK);
        return;
    }
    while (count > 0) {
        ai->buf->incoming_message[ai->buf->nb_messages] = strdup(FORWARD);
        ai->buf->nb_messages += 1;
        count -= 1;
    }
    if (coord[0] < 0) {
        ai->buf->incoming_message[ai->buf->nb_messages] = strdup(LEFT);
        ai->buf->nb_messages += 1;
    } else if (coord[0] == 0 && coord[1] == 0 && !can_do_elevation_on_tile(ai->level, ai->look_result)) {
        if (is_too_many_player(ai->look_result[0], ai->level)) {
            ai->buf->incoming_message[ai->buf->nb_messages++] = strdup(EJECT);
            update_look_and_inventory(ai);
        } else {
            char** rock_to_take = rock_too_much_on_tail(ai->level, ai->look_result[0]);
            for (int i = 0; rock_to_take[i]; i++) {
                if (ai->buf->nb_messages < 7) {
                    ai->buf->incoming_message[ai->buf->nb_messages++] = my_strcat(TAKE, rock_to_take[i]);
                    update_look_and_inventory(ai);
                }
            }
        }
        return;
    } else if (coord[0] > 0) {
        ai->buf->incoming_message[ai->buf->nb_messages++] = strdup(RIGHT);
    }
    while (abs_x > 0) {
        ai->buf->incoming_message[ai->buf->nb_messages++] = strdup(FORWARD);
        abs_x -= 1;
    }
    update_look_and_inventory(ai);
}

void just_move_in_tile(struct ai_info* ai, int *coord)
{
    int abs_x = abs(coord[0]);
    int count = coord[1];

    if (42 == coord[0] || 42 == coord[1]) {
        ai->buf->incoming_message[ai->buf->nb_messages++] = strdup(FORWARD);
        ai->buf->incoming_message[ai->buf->nb_messages++] = strdup(LOOK);
        return;
    }
    while (count > 0) {
        ai->buf->incoming_message[ai->buf->nb_messages] = strdup(FORWARD);
        ai->buf->nb_messages += 1;
        count -= 1;
    }
    if (coord[0] < 0) {
        ai->buf->incoming_message[ai->buf->nb_messages] = strdup(LEFT);
        ai->buf->nb_messages += 1;
    }
    else if (coord[0] > 0) {
        ai->buf->incoming_message[ai->buf->nb_messages++] = strdup(RIGHT);
    }
    while (abs_x > 0) {
        ai->buf->incoming_message[ai->buf->nb_messages++] = strdup(FORWARD);
        abs_x -= 1;
    }
}
/*
int main()
{
    char *str = "[ player food food food food food food linemate deraumere sibur, food food, food food food, food food food food food food food food deraumere mendiane, food, food, food, food, food sibur ]";
    int **look = parse_look(str, 2);
    char *str2 = "[ food 9, linemate 0, deraumere 0, sibur 0, mendiane 0, phiras 0, thystame 0 ]\n";
    int *test = inventory(str2);
    take_the_rocks_needed_in_inventory(2, test, look[0]);
}
*/

void take_the_rocks_needed_in_inventory(struct ai_info* ai, int level, int *inventory, int *rocks_on_tile)
{
    int *rocks_is_missing = rock_missing(level, inventory);

    //if (inventory[0] < 10 && rocks_on_tile[FOOD_L] > 0)
    //    ai->buf->incoming_message[ai->buf->nb_messages++] = my_strcat(TAKE, EAT_FOOD);
    rocks_on_tile += 1;

    printf("SIZE = %d\n", (int)ai->buf->nb_messages);
    for (int i = 0; i != (int)ai->buf->nb_messages; i++ )
        printf("ai->buf->incoming_message[%d] = %s\n", i, ai->buf->incoming_message[i]);

    for (int i = 1; i != NBR_OF_ELEMENT; i++) {
        while (rocks_is_missing[i] > 0 && rocks_on_tile[i] > 0) {
            if (i == 1) {
                ai->buf->incoming_message[ai->buf->nb_messages++] = my_strcat(TAKE, "linemate\n");
                rocks_is_missing[i] -= 1;
                printf("take linemate\n");
            }
            if (i == 2) {
                ai->buf->incoming_message[ai->buf->nb_messages++] = my_strcat(TAKE, "deraumere\n");
                rocks_is_missing[i] -= 1;
                printf("take deraumere\n");
            }
            if (i == 3) {
                ai->buf->incoming_message[ai->buf->nb_messages++] = my_strcat(TAKE, "sibur\n");
                rocks_is_missing[i] -= 1;
                printf("take sibur\n");
            }
            if (i == 4) {
                ai->buf->incoming_message[ai->buf->nb_messages++] = my_strcat(TAKE, "mendiane\n");
                rocks_is_missing[i] -= 1;
                printf("take mendiane\n");
            }
            if (i == 5) {
                ai->buf->incoming_message[ai->buf->nb_messages++] = my_strcat(TAKE, "phiras\n");
                rocks_is_missing[i] -= 1;
                printf("take phiras\n");
            }
            if (i == 6) {
                ai->buf->incoming_message[ai->buf->nb_messages++] = my_strcat(TAKE, "thystame\n");
                rocks_is_missing[i] -= 1;
                printf("take thystame\n");
            }

        }
    }
}

int get_broadcast_level(char *str)
{
    char *new_str = strdup(str);
    strsep(&new_str, " ");

    return atoi(new_str);
}

int get_broadcast_direction(char *str)
{
    char *new_str = strdup(str);
    char *direction = strsep(&new_str, ",");

    return atoi(direction);
}

int *find_player_needed(int **look, int level)
{
    int *next_coord = NULL;

    for (int i = 1 ; i != calculate_slot_with_level(level); i++) {
        if (look[i][PLAYER_L] > 0)
            next_coord = find_the_pos(i);
    }
    return next_coord;
}