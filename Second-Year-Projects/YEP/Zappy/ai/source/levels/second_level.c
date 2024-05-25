/*
** EPITECH PROJECT, 2022
** B-YEP-410-PAR-4-1-zappy-thomas.willson
** File description:
** first_level
*/

#include "ai_info.h"
#include "prototypes.h"
#include "level_command.h"
#include <stdbool.h>


bool second_level(struct ai_info *ai)
{
    bool check_inventory = false;
    bool check_tile = false;

    if (ai->verify->command_left > 0)
        return true;

    if (ai->buf->nb_messages > 0 && ai->buf->boradcasted == NULL)
        return true;

    if (ai->buf->boradcasted && get_broadcast_level(ai->buf->boradcasted) == ai->level) {
        printf("BROADCASTED = %s\n", ai->buf->boradcasted);

        for (; ai->buf->nb_messages != 0; ai->buf->nb_messages-- )
            ai->buf->incoming_message[ai->buf->nb_messages] = NULL;

        int direction = get_broadcast_direction(ai->buf->boradcasted);

        if (direction == 0) {
            printf("FOUUUUUUUUUUUUUUUUUUUUUUUUUND\n");
            ai->buf->incoming_message[ai->buf->nb_messages++] = strdup(LOOK);
            for (int i = 0; i != (int)ai->buf->nb_messages; i++ )
                printf("ai->buf->nb_messages[%d] = %s\n",i, ai->buf->incoming_message[i]);
        }
        else {
            if (direction == 3) {
                ai->buf->incoming_message[ai->buf->nb_messages++] = strdup(LEFT);
                ai->buf->incoming_message[ai->buf->nb_messages++] = strdup(FORWARD);
                ai->verify->command_left = 2;
                printf("LEFT\n");
                printf("FORWARD\n");
            }
            else if (direction == 7) {
                ai->buf->incoming_message[ai->buf->nb_messages++] = strdup(RIGHT);
                ai->buf->incoming_message[ai->buf->nb_messages++] = strdup(FORWARD);
                ai->verify->command_left = 2;
                printf("RIGHT\n");
                printf("FORWARD\n");
            }
            else if (direction == 4) {
                ai->buf->incoming_message[ai->buf->nb_messages++] = strdup(LEFT);
                ai->buf->incoming_message[ai->buf->nb_messages++] = strdup(LEFT);
                ai->buf->incoming_message[ai->buf->nb_messages++] = strdup(FORWARD);
                ai->buf->incoming_message[ai->buf->nb_messages++] = strdup(RIGHT);
                ai->buf->incoming_message[ai->buf->nb_messages++] = strdup(FORWARD);
                ai->verify->command_left = 5;
                printf("LEFT\n");
                printf("FORWARD\n");
            }
            else if (direction == 6) {
                ai->buf->incoming_message[ai->buf->nb_messages++] = strdup(RIGHT);
                ai->buf->incoming_message[ai->buf->nb_messages++] = strdup(RIGHT);
                ai->buf->incoming_message[ai->buf->nb_messages++] = strdup(FORWARD);
                ai->buf->incoming_message[ai->buf->nb_messages++] = strdup(LEFT);
                ai->buf->incoming_message[ai->buf->nb_messages++] = strdup(FORWARD);
                ai->verify->command_left = 5;
                printf("RIGHT\n");
                printf("FORWARD\n");
            }
            else if (direction == 5) {
                ai->buf->incoming_message[ai->buf->nb_messages++] = strdup(RIGHT);
                ai->buf->incoming_message[ai->buf->nb_messages++] = strdup(RIGHT);
                ai->buf->incoming_message[ai->buf->nb_messages++] = strdup(FORWARD);
                ai->verify->command_left = 3;
            }
            else if (direction == 2) {
                ai->buf->incoming_message[ai->buf->nb_messages++] = strdup(FORWARD);
                ai->buf->incoming_message[ai->buf->nb_messages++] = strdup(LEFT);
                ai->buf->incoming_message[ai->buf->nb_messages++] = strdup(FORWARD);
                ai->verify->command_left = 3;
            }
            else if (direction == 8) {
                ai->buf->incoming_message[ai->buf->nb_messages++] = strdup(FORWARD);
                ai->buf->incoming_message[ai->buf->nb_messages++] = strdup(RIGHT);
                ai->buf->incoming_message[ai->buf->nb_messages++] = strdup(FORWARD);
                ai->verify->command_left = 3;
            }
            else {
                ai->buf->incoming_message[ai->buf->nb_messages++] = strdup(FORWARD);
                printf("FORWARD\n");
                ai->verify->command_left = 1;
            }
            ai->buf->incoming_message[ai->buf->nb_messages++] = strdup(LOOK);
            return true;
        }
        printf("00 MON POTES\n");
        //ai->buf->incoming_message[ai->buf->nb_messages++] = strdup(LOOK);
    }
    else
        printf("RENTRE PAS DANS LE BROADCAST\n");

    if (false == ai->verify->first_look) {
        fprintf(stderr, "Je pass ici\n");
        update_look_and_inventory(ai);
        fprintf(stderr, "%s\n", ai->buf->incoming_message[0]);
        ai->verify->first_look = true;
        if (true == drop_all_rocks_in_inventory(ai)) //drop toute les pierres de mon inventaire
            ai->buf->incoming_message[ai->buf->nb_messages++] = strdup(LOOK);
    } else {
        for (int i = 0; i != NBR_OF_LOOK_ELEMENT; i++)
            printf("look_result[%d] = %d\n", i, ai->look_result[0][i]);
        for (int i = 0; i != NBR_OF_ELEMENT; i++)
            printf("inventory[%d] = %d\n", i, inventory(ai->buf->curr_inventory)[i]);
        check_inventory = can_do_elevation_on_inventory(ai->level, inventory(ai->buf->curr_inventory));
        check_tile = can_do_elevation_on_tile(ai->level, ai->look_result);


        if (check_tile == true) {
            printf("INCANTATION SEND\n");
            ai->buf->incoming_message[ai->buf->nb_messages++] = strdup(INVENTORY);
            int* backpack = inventory(ai->buf->curr_inventory);
            while (backpack[0] < 12 && ai->look_result[0][FOOD_L] > 0 && ai->buf->nb_messages < 8)
                ai->buf->incoming_message[ai->buf->nb_messages++] = my_strcat(TAKE, EAT_FOOD);
            ai->buf->incoming_message[ai->buf->nb_messages++] = strdup(INVENTORY);
            ai->buf->incoming_message[ai->buf->nb_messages++] = strdup(INCANTATION);
        }
        else if (can_do_elevation_on_tile_without_players(ai->level, ai->look_result)) {
            if (is_missing_player(ai->look_result[0], ai->level) == true && ai->buf->boradcasted == NULL) {
                printf("BROADCAST SEND\n");
                char nbr[2];
                sprintf(nbr, "%d", ai->level);
                ai->buf->incoming_message[ai->buf->nb_messages++] = my_strcat(my_strcat(BROADCAST, nbr), "\n");
                ai->buf->incoming_message[ai->buf->nb_messages++] = strdup(LOOK);
                return true;
            }
            else if (is_too_many_player(ai->look_result[0], ai->level)) {
                printf("EJECT SEND\n");
                ai->buf->incoming_message[ai->buf->nb_messages++] = strdup(EJECT);
            }
            update_look_and_inventory(ai);
        }
        else if (check_inventory == true) {
            if (rock_too_much_on_tail(ai->level, ai->look_result[0])[0] != NULL) { // si y a trop de pierre, derniere raison de blocké, prend tt les pierres
                printf("TROP DE PIERRE\n");
                char** rock_to_take = rock_too_much_on_tail(ai->level, ai->look_result[0]);
                for (int i = 0; rock_to_take[i]; i++)
                    ai->buf->incoming_message[ai->buf->nb_messages++] = my_strcat(TAKE, rock_to_take[i]);
                char** rock_to_set = rock_missing_on_tail(ai->level, ai->look_result[0]);
                for (int i = 0; rock_to_set[i]; i++)
                    ai->buf->incoming_message[ai->buf->nb_messages++] = my_strcat(SET, rock_to_set[i]);
            }
            else if (rock_missing_on_tail(ai->level, ai->look_result[0])[0] != NULL) {// drop all rocks qui manquent, comme rock_too_much_on_tail mais un rock_missing_on_tail
                printf("PAS ASSEZ DE PIERRE\n");
                char** rock_to_set = rock_missing_on_tail(ai->level, ai->look_result[0]);
                for (int i = 0; rock_to_set[i]; i++)
                    ai->buf->incoming_message[ai->buf->nb_messages++] = my_strcat(SET, rock_to_set[i]);
            }
            update_look_and_inventory(ai);
        }
        else {
            int* coord = calculate_next_coo(ai->look_result, ai->level, inventory(ai->buf->curr_inventory));
            fprintf(stderr, "coord x = %d coord y = %d\n", coord[0], coord[1]);
            just_move_in_tile(ai, coord);
            int *my_inventory = inventory(ai->buf->curr_inventory);
            take_the_rocks_needed_in_inventory(ai, ai->level, my_inventory, ai->look_result[0]);
            update_look_and_inventory(ai);
        }
    }
    return (true);
}