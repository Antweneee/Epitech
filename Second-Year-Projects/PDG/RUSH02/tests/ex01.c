/*
** EPITECH PROJECT, 2022
** B-PDG-300-PAR-3-1-PDGRUSH2-illyas.chihi
** File description:
** ex01
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <criterion/assert.h>
#include <criterion/output.h>
#include "../new.h"
#include "../player.h"
#include "../raise.h"
#include "../object.h"
#include "../vertex.h"
#include "../point.h"

#include <stdio.h>

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(my_new, simple_new)
{
    Object *player;
    cr_assert(new (Player), "Player()\n");
}

Test(ex02, ex002, .init = redirect_all_std)
{
    Object *point = new (Point, 42, -42);

    cr_assert(printf("point = %s\n", str(point)), "point = <Point (42, -42)>\n");
    delete (point);
}

Test(ex03, ex003, .init = redirect_all_std)
{
    Object *vertex = new (Vertex, 42, -42, 2);

    cr_assert(printf("vertex = %s\n", str(vertex)), "vertex = <Vertex (42, -42, 2)>\n");
    delete (vertex);
}

Test(ex03bis, ex003bis, .init = redirect_all_std)
{
    Object *vertex = new (Vertex, 42, -42, 2);
    Object *point = new (Point, 42, -42);

    cr_assert(printf("vertex = %s\n", str(vertex)), "vertex = <Vertex (42, -42, 2)>\n");
    cr_assert(printf("point = %s\n", str(point)), "point = <Point (42, -42)>\n");
    delete (point);
    delete (vertex);
}