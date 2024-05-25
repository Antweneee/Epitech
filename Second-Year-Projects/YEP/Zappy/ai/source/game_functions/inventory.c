/*
** EPITECH PROJECT, 2022
** inventory
** File description:
** inventory
*/

#include "define.h"
#include "prototypes.h"

/**
 * @brief parse le char *inventory en int * avec l'enum resource_e comme pos
 * 1* sépare virgule par virgule l'inventaire
 * 2* suprime l'espace après la virgule
 * 3* enleve le nom de la pierre, garde que le nombre
 * @param str type = "[food 345, linemate 3, deraumere 5,
 * sibur 7, mendiane 0, phiras 2, thystame 1]\n"
 * @return type = [345, 3, 5, 7, 0, 2, 1]
 */
int *inventory(char *str)
{
    int *inventory = malloc(sizeof(int ) * NBR_OF_ELEMENT);
    char *new_str = strdup(str) + 2;
    char *tmp;

    if (inventory == NULL)
        return NULL;

    for (int i = 0; ; i++) {
        tmp = strsep(&new_str, ",");
        tmp += 1;
        strsep(&tmp, " ");
        inventory[i] = atoi(tmp);
        if (new_str == NULL || tmp == NULL)
            break;
    }
    return inventory;
}

bool drop_all_rocks_in_inventory(struct ai_info* ai)
{
    bool done = false;
    int *my_inventory = inventory(ai->buf->curr_inventory);

    for (int i = 1; i != NBR_OF_ELEMENT; i++) {
        if (my_inventory[i] > 0) {
            done = true;
            if (i == 1) {
                ai->buf->incoming_message[ai->buf->nb_messages++] = my_strcat(SET, "linemate\n");
                printf("SET linemate\n");
            }
            if (i == 2) {
                ai->buf->incoming_message[ai->buf->nb_messages++] = my_strcat(SET, "deraumere\n");
                printf("SET deraumere\n");
            }
            if (i == 3) {
                ai->buf->incoming_message[ai->buf->nb_messages++] = my_strcat(SET, "sibur\n");
                printf("SET sibur\n");
            }
            if (i == 4) {
                ai->buf->incoming_message[ai->buf->nb_messages++] = my_strcat(SET, "mendiane\n");
                printf("SET mendiane\n");
            }
            if (i == 5) {
                ai->buf->incoming_message[ai->buf->nb_messages++] = my_strcat(SET, "phiras\n");
                printf("SET phiras\n");
            }
            if (i == 6) {
                ai->buf->incoming_message[ai->buf->nb_messages++] = my_strcat(SET, "thystame\n");
                printf("SET thystame\n");
            }
        }
    }
    return done;
}