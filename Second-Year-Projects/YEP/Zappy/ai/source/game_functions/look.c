/*
** EPITECH PROJECT, 2022
** zappy
** File description:
** look
*/

#include <ctype.h>
#include "prototypes.h"

int *add_player(int *slot)
{
    slot[PLAYER_L] = slot[PLAYER_L] + 1;
    return slot;
}

int *add_food(int *slot)
{
    slot[FOOD_L] = slot[FOOD_L] + 1;
    return slot;
}

int *add_linemate(int *slot)
{
    slot[LINEMATE_L] = slot[LINEMATE_L] + 1;
    return slot;
}

int *add_deraumere(int *slot)
{
    slot[DERAUMERE_L] = slot[DERAUMERE_L] + 1;
    return slot;
}

int *add_sibur(int *slot)
{
    slot[SIBUR_L] = slot[SIBUR_L] + 1;
    return slot;
}

int *add_mendiane(int *slot)
{
    slot[MENDIANE_L] = slot[MENDIANE_L] + 1;
    return slot;
}

int *add_phiras(int *slot)
{
    slot[PHIRAS_L] = slot[PHIRAS_L] + 1;
    return slot;
}

int *add_thystame(int *slot)
{
    slot[THYSTAME_L] = slot[THYSTAME_L] + 1;
    return slot;
}

/**
 * @brief tableau de pointeur sur fonction pour ajouter des pierres a des
 * int * (une tyle)
 */
typedef struct look_command_s {
    char *element;
    int *(*functions)(int *slot);
} look_command_t;

static const look_command_t LOOK_COMMAND[] = {
    {"player", .functions = add_player},
    {"food", .functions = add_food},
    {"linemate", .functions = add_linemate},
    {"deraumere", .functions = add_deraumere},
    {"sibur", .functions = add_sibur},
    {"mendiane", .functions = add_mendiane},
    {"phiras", .functions = add_phiras},
    {"thystame", .functions = add_thystame},
};

/**
 * @brief return the number of tile for the command look for the level requested
 * @param level the level of the player
 * @return int return the number of tyles that a player can look
 */
int calculate_slot_with_level(int level)
{
    int slots = 3;
    int all = 4;

    for (int i = 1; i != level; i++) {
        all = all + slots + 2;
        slots += 2;
    }
    return all;
}

/**
 * @brief Create a one slot object parse tyle by tyle the look command
 * @param tile only one tyle of the look command type = player phiras
 * @return int* return the a tyle parsed type = [1, 0, 0, 0, 0, 0, 1, 0]
 */
int *create_one_slot(char *tile)
{
    int *slot = malloc(sizeof(int) * NBR_OF_LOOK_ELEMENT);
    char *new_tile = strdup(tile);
    char *tmp;

    if (!slot)
        return NULL;
    for (int i = 0; i != NBR_OF_LOOK_ELEMENT; i++)
        slot[i] = 0;
    for (; ; ) {
        tmp = strsep(&new_tile, " ");
        if (tmp == NULL)
            break;
        if (isalpha(tmp[0]) == 0)
            continue;
        for (int i = 0; i != 8; i++) {
            if (strcmp(LOOK_COMMAND[i].element, tmp) == 0) {
                slot = LOOK_COMMAND[i].functions(slot);
                break;
            }
        }
    }
    return slot;
}

/**
 * @brief add spaces between empty comma
 * @param str the string of tyle type = "[ player,,, ]"
 * @return char* the new string with spaces "[ player , , , ]";
 */
char *add_spaces(char *str)
{
    char *new_str = malloc(sizeof(char) * strlen(str) + 10);
    int y = 0;

    for (int i = 0; str[i]; i++) {
        if (str[i] == ',' && str[i + 1] == ',') {
            new_str[y] = ',';
            y++;
            new_str[y] = ' ';
            y++;
        }
        else {
            new_str[y] = str[i];
            y++;
        }
    }
    return new_str;
}

/**
 * @brief take the look command and parse it to int **look of each cases
 * @param str the str of the look command type = [ player phiras, deraumere mendiane, food linemate, food deraumere ]
 * @param level the level of the player
 * @return int** the string parsed type = [[1, 0, 0, 0, 0, 0, 1, 0][0, 0, 0, 1, 0, 1, 0, 0][0, 1, 1, 0, 0, 0, 0, 0][0, 1, 0, 1, 0, 0, 0, 0]]
 */
int **parse_look(char *str, int level)
{
    int slots = calculate_slot_with_level(level);
    int **look = malloc(sizeof(int *) * slots);
    char *new_str =  malloc(sizeof(char) * strlen(str) + 10);
    strcpy(new_str, add_spaces(strdup(str)));
    char *tmp;

    for (int i = 0; i != slots; i++) {
        if (i == 0)
            new_str += 2;
        else if (new_str && new_str[1] != ',')
            new_str += 1;
        tmp = strsep(&new_str, ",");
        look[i] = create_one_slot(tmp);
    }
    return look;
}

/**
 * @brief print wtih tile style the tyles
 * @param look int **look of type = [[1, 0, 0, 0, 0, 0, 1, 0][0, 0, 0, 1, 0, 1, 0, 0][0, 1, 1, 0, 0, 0, 0, 0][0, 1, 0, 1, 0, 0, 0, 0]]
 * @param level level of the player
 */
void print_look_parsed(int **look, int level)
{
    int slots = calculate_slot_with_level(level);

    printf("\n");
    printf("[");
    for (int i = 0; i != slots; i++) {
        printf("[");
        for (int y = 0; y != NBR_OF_LOOK_ELEMENT; y++) {
            if (y + 1 == NBR_OF_LOOK_ELEMENT)
                printf("%d", look[i][y]);
            else
                printf("%d, ", look[i][y]);
        }
        /*
        printf("look[i][PLAYER_L] = %d\n", look[i][PLAYER_L]);
        printf("look[i][FOOD_L] = %d\n", look[i][FOOD_L]);
        printf("look[i][LINEMATE_L] = %d\n", look[i][LINEMATE_L]);
        printf("look[i][DERAUMERE_L] = %d\n", look[i][DERAUMERE_L]);
        printf("look[i][SIBUR_L] = %d\n", look[i][SIBUR_L]);
        printf("look[i][MENDIANE_L] = %d\n", look[i][MENDIANE_L]);
        printf("look[i][PHIRAS_L] = %d\n", look[i][PHIRAS_L]);
        printf("look[i][THYSTAME_L] = %d\n", look[i][THYSTAME_L]);
        */
        printf("]");
    }
    printf("]\n");
}

/*
[ player phiras, deraumere mendiane, food linemate, food deraumere ]
->
[[PLAYER, FOOD, LINEMATE, DERAUMERE, SIBUR, MENDIANE, PHIRAS, THYSTAME][][][]]
->
[[1, 0, 0, 0, 0, 0, 1, 0][0, 0, 0, 1, 0, 1, 0, 0][0, 1, 1, 0, 0, 0, 0, 0][0, 1, 0, 1, 0, 0, 0, 0]]

[ player phiras, deraumere mendiane, food linemate, food deraumere ]
[ player linemate, food sibur mendiane, food sibur mendiane, mendiane mendiane, food linemate, deraumere,,, food sibur ]

      TTTTTTTTTTTTT 49
       TTTTTTTTTTT 36
        TTTTTTTTT 25
         TTTTTTT 16
          TTTTT 9
           TTT 4
            T 1
*/

int *find_the_pos(int i)
{
    int *result = malloc(sizeof(int) * 2);

    if (i >= 1 && i<= 3)
        result[1] = 1;
    else if (i >= 4 && i<= 8)
        result[1] = 2;
    else if (i >= 9 && i<= 15)
        result[1] = 3;
    else if (i >= 16 && i<= 24)
        result[1] = 4;
    else if (i >= 25 && i<= 35)
        result[1] = 5;
    else if (i >= 36 && i<= 48)
        result[1] = 6;
    else
        result[1] = 0;

    if (i == 25)
        result[0] = -5;
    else if (i == 16 || i == 26)
        result[0] = -4;
    else if (i == 9 || i == 17 || i == 27)
        result[0] = -3;
    else if (i == 4 || i == 10 || i == 18 || i == 28)
        result[0] = -2;
    else if (i == 1 || i == 5 || i == 11 || i == 19 || i == 29)
        result[0] = -1;
    else if (i == 0 || i == 2 || i == 6 || i == 12 || i == 20 || i == 30)
        result[0] = 0;
    else if (i == 3 || i == 7 || i == 13 || i == 21 || i == 31)
        result[0] = 1;
    else if (i == 8 || i == 14 || i == 22 || i == 32)
        result[0] = 2;
    else if (i == 15 || i == 23 || i == 33)
        result[0] = 3;
    else if (i == 24 || i == 34)
        result[0] = 4;
    else if (i == 35)
        result[0] = 5;
    else
        result[0] = 0;

    return result;
}

/**
 * @brief calculate the next coordonnées for the next rock needed
 * @param look look command parsed
 * @param level level of the player
 * @param inventory inventory command parsed
 * @return int* return the position type {x, y}, return {42, 42} if no need or error
 */
int *calculate_next_coo(int **look, int level, int *inventory)
{
    const int *requirement = requirement_inventory[level - 1];
    int need_index = -1;
    int *result = malloc(sizeof(int) * 2);
    result[0] = 42;
    result[1] = 42;

    for (int i = 0; i != NBR_OF_ELEMENT; i++) {
        if (i == FOOD)
            continue;
        if (requirement[i] - inventory[i] > 0) {
            need_index = i;
            break;
        }
    }
    if (need_index == -1)
        return result;
    for (int i = 0 ; i != calculate_slot_with_level(level); i++) {
        if (look[i][need_index + 1] >= 1) {
            return find_the_pos(i);
        }
    }
    return result;
}

int find_missing_rock(int level, int *inventory)
{
    const int *requirement = requirement_inventory[level - 1];
    int need_index = 0;

    for (int i = 0; i != NBR_OF_ELEMENT; i++) {
        if (i == FOOD)
            continue;
        if (requirement[i] - inventory[i] > 0) {
            need_index = i;
            break;
        }
    }
    printf("need_index = %d\n", need_index);
    printf("LINEMATE = %d\n", LINEMATE);
    return need_index;
}
/*
int main()
{
    char *str = "[ player food food food food food food linemate deraumere mendiane, food food, food food food, food food food food food food food food deraumere mendiane, food, food, food, food, food sibur ]";
    int **look = parse_look(str, 2);
    char *str2 = "[ food 9, linemate 1, deraumere 1, sibur 0, mendiane 0, phiras 0, thystame 0 ]\n";
    int *test = inventory(str2);
    int *pos = calculate_next_coo(look, 2, test);
    int missing = find_missing_rock(2, test);
    printf("x = %d y = %d\n", pos[0], pos[1]);
}
*/