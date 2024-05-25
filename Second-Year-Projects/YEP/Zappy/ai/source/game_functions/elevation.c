/*
** EPITECH PROJECT, 2022
** zappy
** File description:
** elevation
*/

#include "define.h"
#include "prototypes.h"

/**
 * @brief check si une élévation de niveau est possible
 * compare l'inventaire avec le tableau de requirement par niveau au dessus
 * @param actual_level le level actuel du joueur
 * @param inventory l'inventory du joueur
 * @return true si l'élévation est possible
 * @return false si l'élévation n'est pas possible
 */
bool can_do_elevation_on_inventory(int actual_level, int *inventory)
{
    const int *requirement = requirement_inventory[actual_level - 1];

    for (int i = 1; i != NBR_OF_ELEMENT; i++) {
        if (requirement[i] != inventory[i])
            return false;
    }

    return true;
}

/**
 * @brief calculate the missings rocks for the next level in inventory
 * @param actual_level level of the player
 * @param inventory invetory of the player
 * @return an int * of all the missing rock
 */
int *rock_missing(int actual_level, int *inventory)
{
    int *missing = malloc(sizeof(int) * NBR_OF_ELEMENT);
    const int *requirement = requirement_inventory[actual_level - 1];

    for (int i = 0; i != NBR_OF_ELEMENT; i++)
        missing[i] = 0;

    for (int i = 1; i != NBR_OF_ELEMENT; i++) {
        if ((requirement[i] - inventory[i]) > 0)
            missing[i] = (requirement[i] - inventory[i]);
    }
    return missing;
}

/**
 * @brief calculate the missings rocks for the next level in tyle
 * @param actual_level level of the player
 * @param inventory invetory of the player
 * @return an int * of all the missing rock
 */
bool can_do_elevation_on_tile(int actual_level, int **look)
{
    const int *requirement = requirement_tile[actual_level - 1];
    int *tile = look[0];

    for (int i = 0; i != NBR_OF_LOOK_ELEMENT; i++) {
        if (i == FOOD_L)
            continue;
        if (requirement[i] != tile[i])
            return false;
    }
    return true;
}

bool can_do_elevation_on_tile_without_players(int actual_level, int **look)
{
    const int *requirement = requirement_tile[actual_level - 1];
    int *tile = look[0];

    for (int i = 0; i != NBR_OF_LOOK_ELEMENT; i++) {
        if (i == FOOD_L)
            continue;
        if (i == PLAYER_L)
            continue;
        if (requirement[i] != tile[i])
            return false;
    }
    return true;
}

/**
 * @brief return a char** with all rocks that are too manty on tile
 * @param actual_level level of the player
 * @param tile tha actual tile (parse_look[0]) = [1, 0, 0, 1, 0, 0, 1, 0]
 * @return char** ["deraumere", "phiras"]..
 */
char **rock_too_much_on_tail(int actual_level, int *tile)
{
    const int *requirement = requirement_tile[actual_level - 1];
    int rank = 0;
    char **to_much = malloc(sizeof(char *) * 999);

    for (int i = 2; i != NBR_OF_LOOK_ELEMENT; i++) {
        for (int nbr_rock_to_much = (tile[i] - requirement[i]); nbr_rock_to_much > 0; nbr_rock_to_much--) {
            if (i == 2) {
                to_much[rank] = malloc(sizeof(char) * strlen("linemate\n"));
                to_much[rank++] = "linemate\n";
            }
            if (i == 3) {
                to_much[rank] = malloc(sizeof(char) * strlen("deraumere\n"));
                to_much[rank++] = "deraumere\n";
            }
            if (i == 4) {
                to_much[rank] = malloc(sizeof(char) * strlen("sibur\n"));
                to_much[rank++] = "sibur\n";
            }
            if (i == 5) {
                to_much[rank] = malloc(sizeof(char) * strlen("mendiane\n"));
                to_much[rank++] = "mendiane\n";
            }
            if (i == 6) {
                to_much[rank] = malloc(sizeof(char) * strlen("phiras\n"));
                to_much[rank++] = "phiras\n";
            }
            if (i == 7) {
                to_much[rank] = malloc(sizeof(char) * strlen("thystame\n"));
                to_much[rank++] = "thystame\n";
            }
        }
    }
    to_much[rank] = NULL;
    return to_much;
}

/**
 * @brief return a char** with all rocks that are missing on tile
 * @param actual_level level of the player
 * @param tile tha actual tile (parse_look[0]) = [0, 0, 0, 0, 0, 0, 0, 0]
 * @return char** ["linemate"]
 */
char **rock_missing_on_tail(int actual_level, int *tile)
{
    const int *requirement = requirement_tile[actual_level - 1];
    int rank = 0;
    char **to_much = malloc(sizeof(char *) * 999);

    for (int i = 2; i != NBR_OF_LOOK_ELEMENT; i++) {
        for (int nbr_rock_missing = (requirement[i] - tile[i]); nbr_rock_missing > 0; nbr_rock_missing--) {
            if (i == 2) {
                to_much[rank] = malloc(sizeof(char) * strlen("linemate\n"));
                to_much[rank++] = "linemate\n";
            }
            if (i == 3) {
                to_much[rank] = malloc(sizeof(char) * strlen("deraumere\n"));
                to_much[rank++] = "deraumere\n";
            }
            if (i == 4) {
                to_much[rank] = malloc(sizeof(char) * strlen("sibur\n"));
                to_much[rank++] = "sibur\n";
            }
            if (i == 5) {
                to_much[rank] = malloc(sizeof(char) * strlen("mendiane\n"));
                to_much[rank++] = "mendiane\n";
            }
            if (i == 6) {
                to_much[rank] = malloc(sizeof(char) * strlen("phiras\n"));
                to_much[rank++] = "phiras\n";
            }
            if (i == 7) {
                to_much[rank] = malloc(sizeof(char) * strlen("thystame\n"));
                to_much[rank++] = "thystame\n";
            }
        }
    }
    to_much[rank] = NULL;
    return to_much;
}

bool is_missing_player(int *tile, int level)
{
    int required_players = requirement_tile[level - 1][PLAYER_L];
    int tile_players = tile[PLAYER_L];

    if (required_players > tile_players)
        return true;
    return false;
}

bool is_too_many_player(int *tile, int level)
{
    int required_players = requirement_tile[level - 1][PLAYER_L];
    int tile_players = tile[PLAYER_L];

    printf("tile_players = %d\n", tile_players);
    printf("required_players = %d\n", required_players);
    if (required_players < tile_players)
        return true;
    return false;
}

/*
int main()
{
    char *str = "[ player food food food food food food mendiane, food food, food food food, food food food food food food food food deraumere mendiane, food, food, food, food, food sibur ]";
    int **look = parse_look(str, 2);
    char **missing = rock_missing_on_tail(2, look[0]);
    if (missing != NULL) {
        printf("not null\n");
        for (int i = 0; missing[i] != NULL; i++)
            printf("missing[%d] = %s\n", i, missing[i]);
    }
    else
        printf("is null\n");
    //char *str2 = "[ food 9, linemate 1, deraumere 1, sibur 0, mendiane 0, phiras 0, thystame 0 ]\n";
    //int *test = inventory(str2);
    //int *pos = calculate_next_coo(look, 2, test);
    //int missing = find_missing_rock(2, test);
    //printf("x = %d y = %d\n", pos[0], pos[1]);
}*/