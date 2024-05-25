/*
** EPITECH PROJECT, 2022
** zappy
** File description:
** test_elevation
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <criterion/assert.h>
#include <criterion/output.h>
#include "prototypes.h"
#include "define.h"

void redirect_all_std(void);

Test(test_can_elevation_on_tyle0, inventory, .init=redirect_all_std)
{
    char *str = "[food 345, linemate 1, deraumere 0, sibur 0, mendiane 0, phiras 0, thystame 0]\n";
    int *test = inventory(str);

    bool can = can_do_elevation_on_inventory(1, test);
    cr_assert_eq(can, true);
}

Test(test_can_elevation_on_tyle1, inventory, .init=redirect_all_std)
{
    char *str = "[food 345, linemate 1, deraumere 1, sibur 1, mendiane 0, phiras 0, thystame 0]\n";
    int *test = inventory(str);

    bool can = can_do_elevation_on_inventory(2, test);
    cr_assert_eq(can, true);
}

Test(test_can_elevation_on_tyle2, inventory, .init=redirect_all_std)
{
    char *str = "[food 345, linemate 2, deraumere 0, sibur 1, mendiane 0, phiras 2, thystame 0]\n";
    int *test = inventory(str);

    bool can = can_do_elevation_on_inventory(3, test);
    cr_assert_eq(can, true);
}

Test(test_can_elevation_on_tyle3, inventory, .init=redirect_all_std)
{
    char *str = "[food 345, linemate 1, deraumere 1, sibur 2, mendiane 0, phiras 1, thystame 0]\n";
    int *test = inventory(str);

    bool can = can_do_elevation_on_inventory(4, test);
    cr_assert_eq(can, true);
}

Test(test_can_elevation_on_tyle4, inventory, .init=redirect_all_std)
{
    char *str = "[food 345, linemate 1, deraumere 2, sibur 1, mendiane 3, phiras 0, thystame 0]\n";
    int *test = inventory(str);

    bool can = can_do_elevation_on_inventory(5, test);
    cr_assert_eq(can, true);
}

Test(test_can_elevation_on_tyle5, inventory, .init=redirect_all_std)
{
    char *str = "[food 345, linemate 1, deraumere 2, sibur 3, mendiane 0, phiras 1, thystame 0]\n";
    int *test = inventory(str);

    bool can = can_do_elevation_on_inventory(6, test);
    cr_assert_eq(can, true);
}

Test(test_can_elevation_on_tyle6, inventory, .init=redirect_all_std)
{
    char *str = "[food 345, linemate 2, deraumere 2, sibur 2, mendiane 2, phiras 2, thystame 1]\n";
    int *test = inventory(str);

    bool can = can_do_elevation_on_inventory(7, test);
    cr_assert_eq(can, true);
}

Test(test_can_elevation_on_tyle_false0, inventory, .init=redirect_all_std)
{
    char *str = "[food 345, linemate 1, deraumere 0, sibur 0, mendiane 0, phiras 0, thystame 0]\n";
    int *test = inventory(str);

    bool can = can_do_elevation_on_inventory(7, test);
    cr_assert_eq(can, false);
}

Test(test_can_elevation_on_tyle_false1, inventory, .init=redirect_all_std)
{
    char *str = "[food 345, linemate 1, deraumere 1, sibur 0, mendiane 0, phiras 0, thystame 0]\n";
    int *test = inventory(str);

    bool can = can_do_elevation_on_inventory(2, test);
    cr_assert_eq(can, false);
}

Test(test_can_elevation_on_tyle_false2, inventory, .init=redirect_all_std)
{
    char *str = "[food 345, linemate 2, deraumere 0, sibur 1, mendiane 0, phiras 1, thystame 0]\n";
    int *test = inventory(str);

    bool can = can_do_elevation_on_inventory(3, test);
    cr_assert_eq(can, false);
}

Test(test_can_elevation_on_tyle_false3, inventory, .init=redirect_all_std)
{
    char *str = "[food 345, linemate 1, deraumere 1, sibur 1, mendiane 0, phiras 1, thystame 0]\n";
    int *test = inventory(str);

    bool can = can_do_elevation_on_inventory(4, test);
    cr_assert_eq(can, false);
}

Test(test_can_elevation_on_tyle_false4, inventory, .init=redirect_all_std)
{
    char *str = "[food 345, linemate 1, deraumere 2, sibur 1, mendiane 2, phiras 0, thystame 0]\n";
    int *test = inventory(str);

    bool can = can_do_elevation_on_inventory(5, test);
    cr_assert_eq(can, false);
}

Test(test_can_elevation_on_tyle_false5, inventory, .init=redirect_all_std)
{
    char *str = "[food 345, linemate 1, deraumere 2, sibur 2, mendiane 0, phiras 1, thystame 0]\n";
    int *test = inventory(str);

    bool can = can_do_elevation_on_inventory(6, test);
    cr_assert_eq(can, false);
}

Test(test_can_elevation_on_tyle_false6, inventory, .init=redirect_all_std)
{
    char *str = "[food 345, linemate 2, deraumere 2, sibur 2, mendiane 2, phiras 1, thystame 1]\n";
    int *test = inventory(str);

    bool can = can_do_elevation_on_inventory(7, test);
    cr_assert_eq(can, false);
}

Test(test_rock_missing0, rock_missing, .init=redirect_all_std)
{
    char *str = "[food 345, linemate 0, deraumere 0, sibur 0, mendiane 0, phiras 0, thystame 0]\n";
    int *test = inventory(str);
    int *missing = rock_missing(1, test);

    cr_assert_eq(missing[FOOD], 0);
    cr_assert_eq(missing[LINEMATE], 1);
    cr_assert_eq(missing[DERAUMERE], 0);
    cr_assert_eq(missing[SIBUR], 0);
    cr_assert_eq(missing[MENDIANE], 0);
    cr_assert_eq(missing[PHIRAS], 0);
    cr_assert_eq(missing[THYSTAME], 0);
}

Test(test_rock_missing1, rock_missing, .init=redirect_all_std)
{
    char *str = "[food 345, linemate 0, deraumere 0, sibur 0, mendiane 0, phiras 0, thystame 0]\n";
    int *test = inventory(str);
    int *missing = rock_missing(2, test);

    cr_assert_eq(missing[FOOD], 0);
    cr_assert_eq(missing[LINEMATE], 1);
    cr_assert_eq(missing[DERAUMERE], 1);
    cr_assert_eq(missing[SIBUR], 1);
    cr_assert_eq(missing[MENDIANE], 0);
    cr_assert_eq(missing[PHIRAS], 0);
    cr_assert_eq(missing[THYSTAME], 0);
}

Test(test_rock_missing2, rock_missing, .init=redirect_all_std)
{
    char *str = "[food 345, linemate 0, deraumere 0, sibur 0, mendiane 0, phiras 0, thystame 0]\n";
    int *test = inventory(str);
    int *missing = rock_missing(3, test);

    cr_assert_eq(missing[FOOD], 0);
    cr_assert_eq(missing[LINEMATE], 2);
    cr_assert_eq(missing[DERAUMERE], 0);
    cr_assert_eq(missing[SIBUR], 1);
    cr_assert_eq(missing[MENDIANE], 0);
    cr_assert_eq(missing[PHIRAS], 2);
    cr_assert_eq(missing[THYSTAME], 0);
}

Test(test_rock_missing3, rock_missing, .init=redirect_all_std)
{
    char *str = "[food 345, linemate 0, deraumere 0, sibur 0, mendiane 0, phiras 0, thystame 0]\n";
    int *test = inventory(str);
    int *missing = rock_missing(4, test);

    cr_assert_eq(missing[FOOD], 0);
    cr_assert_eq(missing[LINEMATE], 1);
    cr_assert_eq(missing[DERAUMERE], 1);
    cr_assert_eq(missing[SIBUR], 2);
    cr_assert_eq(missing[MENDIANE], 0);
    cr_assert_eq(missing[PHIRAS], 1);
    cr_assert_eq(missing[THYSTAME], 0);
}

Test(test_rock_missing4, rock_missing, .init=redirect_all_std)
{
    char *str = "[food 345, linemate 0, deraumere 0, sibur 0, mendiane 0, phiras 0, thystame 0]\n";
    int *test = inventory(str);
    int *missing = rock_missing(5, test);

    cr_assert_eq(missing[FOOD], 0);
    cr_assert_eq(missing[LINEMATE], 1);
    cr_assert_eq(missing[DERAUMERE], 2);
    cr_assert_eq(missing[SIBUR], 1);
    cr_assert_eq(missing[MENDIANE], 3);
    cr_assert_eq(missing[PHIRAS], 0);
    cr_assert_eq(missing[THYSTAME], 0);
}

Test(test_rock_missing5, rock_missing, .init=redirect_all_std)
{
    char *str = "[food 345, linemate 0, deraumere 0, sibur 0, mendiane 0, phiras 0, thystame 0]\n";
    int *test = inventory(str);
    int *missing = rock_missing(6, test);

    cr_assert_eq(missing[FOOD], 0);
    cr_assert_eq(missing[LINEMATE], 1);
    cr_assert_eq(missing[DERAUMERE], 2);
    cr_assert_eq(missing[SIBUR], 3);
    cr_assert_eq(missing[MENDIANE], 0);
    cr_assert_eq(missing[PHIRAS], 1);
    cr_assert_eq(missing[THYSTAME], 0);
}

Test(test_rock_missing6, rock_missing, .init=redirect_all_std)
{
    char *str = "[food 345, linemate 0, deraumere 0, sibur 0, mendiane 0, phiras 0, thystame 0]\n";
    int *test = inventory(str);
    int *missing = rock_missing(7, test);

    cr_assert_eq(missing[FOOD], 0);
    cr_assert_eq(missing[LINEMATE], 2);
    cr_assert_eq(missing[DERAUMERE], 2);
    cr_assert_eq(missing[SIBUR], 2);
    cr_assert_eq(missing[MENDIANE], 2);
    cr_assert_eq(missing[PHIRAS], 2);
    cr_assert_eq(missing[THYSTAME], 1);
}

Test(can_do_elevation_on_tile_0, can_do_elevation_on_tile, .init=redirect_all_std)
{
    char *str = "[ player phiras, deraumere mendiane, food linemate, food deraumere ]";
    int **slot = parse_look(str, 1);
    bool can = can_do_elevation_on_tile(1, slot);

    cr_assert_eq(can, false);
}

Test(can_do_elevation_on_tile_1, can_do_elevation_on_tile, .init=redirect_all_std)
{
    char *str = "[ player linemate, deraumere mendiane, food linemate, food deraumere ]";
    int **slot = parse_look(str, 1);
    bool can = can_do_elevation_on_tile(1, slot);

    cr_assert_eq(can, true);
}

Test(can_do_elevation_on_tile_2, can_do_elevation_on_tile, .init=redirect_all_std)
{
    char *str = "[ player linemate, deraumere mendiane, food linemate, food deraumere, food deraumere, food deraumere, food deraumere, food deraumere, food deraumere ]";
    int **slot = parse_look(str, 2);
    bool can = can_do_elevation_on_tile(2, slot);

    cr_assert_eq(can, false);
}

Test(can_do_elevation_on_tile_3, can_do_elevation_on_tile, .init=redirect_all_std)
{
    char *str = "[ player player linemate deraumere sibur, deraumere mendiane, food linemate, food deraumere, food deraumere, food deraumere, food deraumere, food deraumere, food deraumere ]";
    int **slot = parse_look(str, 2);
    bool can = can_do_elevation_on_tile(2, slot);

    cr_assert_eq(can, true);
}

Test(can_do_elevation_on_tile_4, can_do_elevation_on_tile, .init=redirect_all_std)
{
    char *str = "[ player linemate deraumere sibur, deraumere mendiane, food linemate, food deraumere, food deraumere, food deraumere, food deraumere, food deraumere, food deraumere ]";
    int **slot = parse_look(str, 2);
    bool can = can_do_elevation_on_tile(2, slot);

    cr_assert_eq(can, false);
}