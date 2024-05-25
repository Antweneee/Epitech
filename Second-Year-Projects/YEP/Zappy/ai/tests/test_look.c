/*
** EPITECH PROJECT, 2022
** zappy
** File description:
** test_look
*/


#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <criterion/assert.h>
#include <criterion/output.h>
#include "prototypes.h"
#include "define.h"

void redirect_all_std(void);

Test(test_slots_look_with_level_0, calculate_slot_with_level, .init=redirect_all_std)
{
    int slots = calculate_slot_with_level(1);

    cr_assert_eq(slots, 4);
}

Test(test_slots_look_with_level_1, calculate_slot_with_level, .init=redirect_all_std)
{
    int slots = calculate_slot_with_level(2);

    cr_assert_eq(slots, 9);
}

Test(test_slots_look_with_level_2, calculate_slot_with_level, .init=redirect_all_std)
{
    int slots = calculate_slot_with_level(3);

    cr_assert_eq(slots, 16);
}

Test(test_slots_look_with_level_3, calculate_slot_with_level, .init=redirect_all_std)
{
    int slots = calculate_slot_with_level(4);

    cr_assert_eq(slots, 25);
}

Test(test_slots_look_with_level_4, calculate_slot_with_level, .init=redirect_all_std)
{
    int slots = calculate_slot_with_level(5);

    cr_assert_eq(slots, 36);
}

Test(test_slots_look_with_level_5, calculate_slot_with_level, .init=redirect_all_std)
{
    int slots = calculate_slot_with_level(6);

    cr_assert_eq(slots, 49);
}

Test(test_create_one_slot_0, create_one_slot, .init=redirect_all_std)
{
    char *str = "player phiras";
    int *slot = create_one_slot(str);

    cr_assert_eq(slot[PLAYER_L], 1);
    cr_assert_eq(slot[FOOD_L], 0);
    cr_assert_eq(slot[LINEMATE_L], 0);
    cr_assert_eq(slot[DERAUMERE_L], 0);
    cr_assert_eq(slot[SIBUR_L], 0);
    cr_assert_eq(slot[MENDIANE_L], 0);
    cr_assert_eq(slot[PHIRAS_L], 1);
    cr_assert_eq(slot[THYSTAME_L], 0);
}

Test(test_create_one_slot_1, create_one_slot, .init=redirect_all_std)
{
    char *str = "player phiras phiras";
    int *slot = create_one_slot(str);

    cr_assert_eq(slot[PLAYER_L], 1);
    cr_assert_eq(slot[FOOD_L], 0);
    cr_assert_eq(slot[LINEMATE_L], 0);
    cr_assert_eq(slot[DERAUMERE_L], 0);
    cr_assert_eq(slot[SIBUR_L], 0);
    cr_assert_eq(slot[MENDIANE_L], 0);
    cr_assert_eq(slot[PHIRAS_L], 2);
    cr_assert_eq(slot[THYSTAME_L], 0);
}

Test(test_create_one_slot_2, create_one_slot, .init=redirect_all_std)
{
    char *str = "player";
    int *slot = create_one_slot(str);

    cr_assert_eq(slot[PLAYER_L], 1);
    cr_assert_eq(slot[FOOD_L], 0);
    cr_assert_eq(slot[LINEMATE_L], 0);
    cr_assert_eq(slot[DERAUMERE_L], 0);
    cr_assert_eq(slot[SIBUR_L], 0);
    cr_assert_eq(slot[MENDIANE_L], 0);
    cr_assert_eq(slot[PHIRAS_L], 0);
    cr_assert_eq(slot[THYSTAME_L], 0);
}

Test(test_create_one_slot_3, create_one_slot, .init=redirect_all_std)
{
    char *str = "player phiras deraumere deraumere deraumere";
    int *slot = create_one_slot(str);

    cr_assert_eq(slot[PLAYER_L], 1);
    cr_assert_eq(slot[FOOD_L], 0);
    cr_assert_eq(slot[LINEMATE_L], 0);
    cr_assert_eq(slot[DERAUMERE_L], 3);
    cr_assert_eq(slot[SIBUR_L], 0);
    cr_assert_eq(slot[MENDIANE_L], 0);
    cr_assert_eq(slot[PHIRAS_L], 1);
    cr_assert_eq(slot[THYSTAME_L], 0);
}

Test(test_create_one_slot_4, create_one_slot, .init=redirect_all_std)
{
    char *str = "player player player";
    int *slot = create_one_slot(str);

    cr_assert_eq(slot[PLAYER_L], 3);
    cr_assert_eq(slot[FOOD_L], 0);
    cr_assert_eq(slot[LINEMATE_L], 0);
    cr_assert_eq(slot[DERAUMERE_L], 0);
    cr_assert_eq(slot[SIBUR_L], 0);
    cr_assert_eq(slot[MENDIANE_L], 0);
    cr_assert_eq(slot[PHIRAS_L], 0);
    cr_assert_eq(slot[THYSTAME_L], 0);
}

Test(test_create_one_slot_5, create_one_slot, .init=redirect_all_std)
{
    char *str = "player food linemate deraumere sibur mendiane phiras thystame";
    int *slot = create_one_slot(str);

    cr_assert_eq(slot[PLAYER_L], 1);
    cr_assert_eq(slot[FOOD_L], 1);
    cr_assert_eq(slot[LINEMATE_L], 1);
    cr_assert_eq(slot[DERAUMERE_L], 1);
    cr_assert_eq(slot[SIBUR_L], 1);
    cr_assert_eq(slot[MENDIANE_L], 1);
    cr_assert_eq(slot[PHIRAS_L], 1);
    cr_assert_eq(slot[THYSTAME_L], 1);
}

Test(test_create_one_slot_6, create_one_slot, .init=redirect_all_std)
{
    char *str = "player player food food linemate linemate deraumere deraumere sibur sibur mendiane mendiane phiras phiras thystame thystame";
    int *slot = create_one_slot(str);

    cr_assert_eq(slot[PLAYER_L], 2);
    cr_assert_eq(slot[FOOD_L], 2);
    cr_assert_eq(slot[LINEMATE_L], 2);
    cr_assert_eq(slot[DERAUMERE_L], 2);
    cr_assert_eq(slot[SIBUR_L], 2);
    cr_assert_eq(slot[MENDIANE_L], 2);
    cr_assert_eq(slot[PHIRAS_L], 2);
    cr_assert_eq(slot[THYSTAME_L], 2);
}

Test(test_look_parsed_0, parse_look, .init=redirect_all_std)
{
    char *str = "[ player phiras, deraumere mendiane, food linemate, food deraumere ]";
    int **slot = parse_look(str, 1);

    cr_assert_eq(slot[0][PLAYER_L], 1);
    cr_assert_eq(slot[0][FOOD_L], 0);
    cr_assert_eq(slot[0][LINEMATE_L], 0);
    cr_assert_eq(slot[0][DERAUMERE_L], 0);
    cr_assert_eq(slot[0][SIBUR_L], 0);
    cr_assert_eq(slot[0][MENDIANE_L], 0);
    cr_assert_eq(slot[0][PHIRAS_L], 1);
    cr_assert_eq(slot[0][THYSTAME_L], 0);

    cr_assert_eq(slot[1][PLAYER_L], 0);
    cr_assert_eq(slot[1][FOOD_L], 0);
    cr_assert_eq(slot[1][LINEMATE_L], 0);
    cr_assert_eq(slot[1][DERAUMERE_L], 1);
    cr_assert_eq(slot[1][SIBUR_L], 0);
    cr_assert_eq(slot[1][MENDIANE_L], 1);
    cr_assert_eq(slot[1][PHIRAS_L], 0);
    cr_assert_eq(slot[1][THYSTAME_L], 0);

    cr_assert_eq(slot[2][PLAYER_L], 0);
    cr_assert_eq(slot[2][FOOD_L], 1);
    cr_assert_eq(slot[2][LINEMATE_L], 1);
    cr_assert_eq(slot[2][DERAUMERE_L], 0);
    cr_assert_eq(slot[2][SIBUR_L], 0);
    cr_assert_eq(slot[2][MENDIANE_L], 0);
    cr_assert_eq(slot[2][PHIRAS_L], 0);
    cr_assert_eq(slot[2][THYSTAME_L], 0);

    cr_assert_eq(slot[3][PLAYER_L], 0);
    cr_assert_eq(slot[3][FOOD_L], 1);
    cr_assert_eq(slot[3][LINEMATE_L], 0);
    cr_assert_eq(slot[3][DERAUMERE_L], 1);
    cr_assert_eq(slot[3][SIBUR_L], 0);
    cr_assert_eq(slot[3][MENDIANE_L], 0);
    cr_assert_eq(slot[3][PHIRAS_L], 0);
    cr_assert_eq(slot[3][THYSTAME_L], 0);
}

Test(test_look_parsed_1, parse_look, .init=redirect_all_std)
{
    char *str = "[ player player phiras deraumere, , food food food food food linemate, player food linemate deraumere sibur mendiane phiras thystame ]";
    int **slot = parse_look(str, 1);

    cr_assert_eq(slot[0][PLAYER_L], 2);
    cr_assert_eq(slot[0][FOOD_L], 0);
    cr_assert_eq(slot[0][LINEMATE_L], 0);
    cr_assert_eq(slot[0][DERAUMERE_L], 1);
    cr_assert_eq(slot[0][SIBUR_L], 0);
    cr_assert_eq(slot[0][MENDIANE_L], 0);
    cr_assert_eq(slot[0][PHIRAS_L], 1);
    cr_assert_eq(slot[0][THYSTAME_L], 0);

    cr_assert_eq(slot[1][PLAYER_L], 0);
    cr_assert_eq(slot[1][FOOD_L], 0);
    cr_assert_eq(slot[1][LINEMATE_L], 0);
    cr_assert_eq(slot[1][DERAUMERE_L], 0);
    cr_assert_eq(slot[1][SIBUR_L], 0);
    cr_assert_eq(slot[1][MENDIANE_L], 0);
    cr_assert_eq(slot[1][PHIRAS_L], 0);
    cr_assert_eq(slot[1][THYSTAME_L], 0);

    cr_assert_eq(slot[2][PLAYER_L], 0);
    cr_assert_eq(slot[2][FOOD_L], 5);
    cr_assert_eq(slot[2][LINEMATE_L], 1);
    cr_assert_eq(slot[2][DERAUMERE_L], 0);
    cr_assert_eq(slot[2][SIBUR_L], 0);
    cr_assert_eq(slot[2][MENDIANE_L], 0);
    cr_assert_eq(slot[2][PHIRAS_L], 0);
    cr_assert_eq(slot[2][THYSTAME_L], 0);

    cr_assert_eq(slot[3][PLAYER_L], 1);
    cr_assert_eq(slot[3][FOOD_L], 1);
    cr_assert_eq(slot[3][LINEMATE_L], 1);
    cr_assert_eq(slot[3][DERAUMERE_L], 1);
    cr_assert_eq(slot[3][SIBUR_L], 1);
    cr_assert_eq(slot[3][MENDIANE_L], 1);
    cr_assert_eq(slot[3][PHIRAS_L], 1);
    cr_assert_eq(slot[3][THYSTAME_L], 1);
}

Test(test_look_parsed_2, parse_look, .init=redirect_all_std)
{
    char *str = "[ player,,, ]";
    int **slot = parse_look(str, 1);

    cr_assert_eq(slot[0][PLAYER_L], 1);
    cr_assert_eq(slot[0][FOOD_L], 0);
    cr_assert_eq(slot[0][LINEMATE_L], 0);
    cr_assert_eq(slot[0][DERAUMERE_L], 0);
    cr_assert_eq(slot[0][SIBUR_L], 0);
    cr_assert_eq(slot[0][MENDIANE_L], 0);
    cr_assert_eq(slot[0][PHIRAS_L], 0);
    cr_assert_eq(slot[0][THYSTAME_L], 0);

    cr_assert_eq(slot[1][PLAYER_L], 0);
    cr_assert_eq(slot[1][FOOD_L], 0);
    cr_assert_eq(slot[1][LINEMATE_L], 0);
    cr_assert_eq(slot[1][DERAUMERE_L], 0);
    cr_assert_eq(slot[1][SIBUR_L], 0);
    cr_assert_eq(slot[1][MENDIANE_L], 0);
    cr_assert_eq(slot[1][PHIRAS_L], 0);
    cr_assert_eq(slot[1][THYSTAME_L], 0);

    cr_assert_eq(slot[2][PLAYER_L], 0);
    cr_assert_eq(slot[2][FOOD_L], 0);
    cr_assert_eq(slot[2][LINEMATE_L], 0);
    cr_assert_eq(slot[2][DERAUMERE_L], 0);
    cr_assert_eq(slot[2][SIBUR_L], 0);
    cr_assert_eq(slot[2][MENDIANE_L], 0);
    cr_assert_eq(slot[2][PHIRAS_L], 0);
    cr_assert_eq(slot[2][THYSTAME_L], 0);

    cr_assert_eq(slot[3][PLAYER_L], 0);
    cr_assert_eq(slot[3][FOOD_L], 0);
    cr_assert_eq(slot[3][LINEMATE_L], 0);
    cr_assert_eq(slot[3][DERAUMERE_L], 0);
    cr_assert_eq(slot[3][SIBUR_L], 0);
    cr_assert_eq(slot[3][MENDIANE_L], 0);
    cr_assert_eq(slot[3][PHIRAS_L], 0);
    cr_assert_eq(slot[3][THYSTAME_L], 0);
}

Test(test_look_parsed_3, parse_look, .init=redirect_all_std)
{
    char *str = "[ player player player, food food food food food, linemate linemate linemate linemate, phiras phiras phiras phiras ]";
    int **slot = parse_look(str, 1);

    cr_assert_eq(slot[0][PLAYER_L], 3);
    cr_assert_eq(slot[0][FOOD_L], 0);
    cr_assert_eq(slot[0][LINEMATE_L], 0);
    cr_assert_eq(slot[0][DERAUMERE_L], 0);
    cr_assert_eq(slot[0][SIBUR_L], 0);
    cr_assert_eq(slot[0][MENDIANE_L], 0);
    cr_assert_eq(slot[0][PHIRAS_L], 0);
    cr_assert_eq(slot[0][THYSTAME_L], 0);

    cr_assert_eq(slot[1][PLAYER_L], 0);
    cr_assert_eq(slot[1][FOOD_L], 5);
    cr_assert_eq(slot[1][LINEMATE_L], 0);
    cr_assert_eq(slot[1][DERAUMERE_L], 0);
    cr_assert_eq(slot[1][SIBUR_L], 0);
    cr_assert_eq(slot[1][MENDIANE_L], 0);
    cr_assert_eq(slot[1][PHIRAS_L], 0);
    cr_assert_eq(slot[1][THYSTAME_L], 0);

    cr_assert_eq(slot[2][PLAYER_L], 0);
    cr_assert_eq(slot[2][FOOD_L], 0);
    cr_assert_eq(slot[2][LINEMATE_L], 4);
    cr_assert_eq(slot[2][DERAUMERE_L], 0);
    cr_assert_eq(slot[2][SIBUR_L], 0);
    cr_assert_eq(slot[2][MENDIANE_L], 0);
    cr_assert_eq(slot[2][PHIRAS_L], 0);
    cr_assert_eq(slot[2][THYSTAME_L], 0);

    cr_assert_eq(slot[3][PLAYER_L], 0);
    cr_assert_eq(slot[3][FOOD_L], 0);
    cr_assert_eq(slot[3][LINEMATE_L], 0);
    cr_assert_eq(slot[3][DERAUMERE_L], 0);
    cr_assert_eq(slot[3][SIBUR_L], 0);
    cr_assert_eq(slot[3][MENDIANE_L], 0);
    cr_assert_eq(slot[3][PHIRAS_L], 4);
    cr_assert_eq(slot[3][THYSTAME_L], 0);
}

Test(test_look_parsed_4, parse_look, .init=redirect_all_std)
{
    char *str = "[ player food food food deraumere sibur sibur mendiane, food food linemate sibur mendiane, sibur, food food ]";
    int **slot = parse_look(str, 1);

    cr_assert_eq(slot[0][PLAYER_L], 1);
    cr_assert_eq(slot[0][FOOD_L], 3);
    cr_assert_eq(slot[0][LINEMATE_L], 0);
    cr_assert_eq(slot[0][DERAUMERE_L], 1);
    cr_assert_eq(slot[0][SIBUR_L], 2);
    cr_assert_eq(slot[0][MENDIANE_L], 1);
    cr_assert_eq(slot[0][PHIRAS_L], 0);
    cr_assert_eq(slot[0][THYSTAME_L], 0);

    cr_assert_eq(slot[1][PLAYER_L], 0);
    cr_assert_eq(slot[1][FOOD_L], 2);
    cr_assert_eq(slot[1][LINEMATE_L], 1);
    cr_assert_eq(slot[1][DERAUMERE_L], 0);
    cr_assert_eq(slot[1][SIBUR_L], 1);
    cr_assert_eq(slot[1][MENDIANE_L], 1);
    cr_assert_eq(slot[1][PHIRAS_L], 0);
    cr_assert_eq(slot[1][THYSTAME_L], 0);

    cr_assert_eq(slot[2][PLAYER_L], 0);
    cr_assert_eq(slot[2][FOOD_L], 0);
    cr_assert_eq(slot[2][LINEMATE_L], 0);
    cr_assert_eq(slot[2][DERAUMERE_L], 0);
    cr_assert_eq(slot[2][SIBUR_L], 1);
    cr_assert_eq(slot[2][MENDIANE_L], 0);
    cr_assert_eq(slot[2][PHIRAS_L], 0);
    cr_assert_eq(slot[2][THYSTAME_L], 0);

    cr_assert_eq(slot[3][PLAYER_L], 0);
    cr_assert_eq(slot[3][FOOD_L], 2);
    cr_assert_eq(slot[3][LINEMATE_L], 0);
    cr_assert_eq(slot[3][DERAUMERE_L], 0);
    cr_assert_eq(slot[3][SIBUR_L], 0);
    cr_assert_eq(slot[3][MENDIANE_L], 0);
    cr_assert_eq(slot[3][PHIRAS_L], 0);
    cr_assert_eq(slot[3][THYSTAME_L], 0);
}

Test(test_look_parsed_5, parse_look, .init=redirect_all_std)
{
    char *str = "[ player food food food food food food food food food food food, food food food food food food food food phiras, food food food food food food phiras, food food food food food food food food sibur sibur mendiane ]";
    int **slot = parse_look(str, 1);

    cr_assert_eq(slot[0][PLAYER_L], 1);
    cr_assert_eq(slot[0][FOOD_L], 11);
    cr_assert_eq(slot[0][LINEMATE_L], 0);
    cr_assert_eq(slot[0][DERAUMERE_L], 0);
    cr_assert_eq(slot[0][SIBUR_L], 0);
    cr_assert_eq(slot[0][MENDIANE_L], 0);
    cr_assert_eq(slot[0][PHIRAS_L], 0);
    cr_assert_eq(slot[0][THYSTAME_L], 0);

    cr_assert_eq(slot[1][PLAYER_L], 0);
    cr_assert_eq(slot[1][FOOD_L], 8);
    cr_assert_eq(slot[1][LINEMATE_L], 0);
    cr_assert_eq(slot[1][DERAUMERE_L], 0);
    cr_assert_eq(slot[1][SIBUR_L], 0);
    cr_assert_eq(slot[1][MENDIANE_L], 0);
    cr_assert_eq(slot[1][PHIRAS_L], 1);
    cr_assert_eq(slot[1][THYSTAME_L], 0);

    cr_assert_eq(slot[2][PLAYER_L], 0);
    cr_assert_eq(slot[2][FOOD_L], 6);
    cr_assert_eq(slot[2][LINEMATE_L], 0);
    cr_assert_eq(slot[2][DERAUMERE_L], 0);
    cr_assert_eq(slot[2][SIBUR_L], 0);
    cr_assert_eq(slot[2][MENDIANE_L], 0);
    cr_assert_eq(slot[2][PHIRAS_L], 1);
    cr_assert_eq(slot[2][THYSTAME_L], 0);

    cr_assert_eq(slot[3][PLAYER_L], 0);
    cr_assert_eq(slot[3][FOOD_L], 8);
    cr_assert_eq(slot[3][LINEMATE_L], 0);
    cr_assert_eq(slot[3][DERAUMERE_L], 0);
    cr_assert_eq(slot[3][SIBUR_L], 2);
    cr_assert_eq(slot[3][MENDIANE_L], 1);
    cr_assert_eq(slot[3][PHIRAS_L], 0);
    cr_assert_eq(slot[3][THYSTAME_L], 0);
}