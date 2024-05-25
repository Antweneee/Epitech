/*
** EPITECH PROJECT, 2022
** inventory
** File description:
** test_inventory
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <criterion/assert.h>
#include <criterion/output.h>
#include "prototypes.h"
#include "define.h"

void redirect_all_std(void);

Test(test_inventory_bien_rempli0, inventory, .init=redirect_all_std)
{
    char *str = "[ food 349, linemate 1, deraumere 1, sibur 1, mendiane 0,\
phiras 0, thystame 0  ]\n";
    int *test = inventory(str);

    cr_assert_eq(test[FOOD], 349);
    cr_assert_eq(test[LINEMATE], 1);
    cr_assert_eq(test[DERAUMERE], 1);
    cr_assert_eq(test[SIBUR], 1);
    cr_assert_eq(test[MENDIANE], 0);
    cr_assert_eq(test[PHIRAS], 0);
    cr_assert_eq(test[THYSTAME], 0);
}

Test(test_inventory_bien_rempli1, inventory, .init=redirect_all_std)
{
    char *str = "[ food 999, linemate 10, deraumere 10, sibur 10, mendiane 10,\
phiras 10, thystame 10  ]\n";
    int *test = inventory(str);

    cr_assert_eq(test[FOOD], 999);
    cr_assert_eq(test[LINEMATE], 10);
    cr_assert_eq(test[DERAUMERE], 10);
    cr_assert_eq(test[SIBUR], 10);
    cr_assert_eq(test[MENDIANE], 10);
    cr_assert_eq(test[PHIRAS], 10);
    cr_assert_eq(test[THYSTAME], 10);
}

Test(test_inventory_bien_rempli2, inventory, .init=redirect_all_std)
{
    char *str = "[ food 0, linemate 0, deraumere 0, sibur 0, mendiane 0,\
phiras 0, thystame 0 ]\n";
    int *test = inventory(str);

    cr_assert_eq(test[FOOD], 0);
    cr_assert_eq(test[LINEMATE], 0);
    cr_assert_eq(test[DERAUMERE], 0);
    cr_assert_eq(test[SIBUR], 0);
    cr_assert_eq(test[MENDIANE], 0);
    cr_assert_eq(test[PHIRAS], 0);
    cr_assert_eq(test[THYSTAME], 0);
}

Test(test_inventory_bien_rempli3, inventory, .init=redirect_all_std)
{
    char *str = "[ food 245, linemate 1, deraumere 2, sibur 3, mendiane 4,\
phiras 5, thystame 6 ]\n";
    int *test = inventory(str);

    cr_assert_eq(test[FOOD], 245);
    cr_assert_eq(test[LINEMATE], 1);
    cr_assert_eq(test[DERAUMERE], 2);
    cr_assert_eq(test[SIBUR], 3);
    cr_assert_eq(test[MENDIANE], 4);
    cr_assert_eq(test[PHIRAS], 5);
    cr_assert_eq(test[THYSTAME], 6);
}