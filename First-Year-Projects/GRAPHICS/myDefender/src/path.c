/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-mydefender-antoine.gavira-bottari
** File description:
** path
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include "my.h"

void normal_path(element_t *enemies, enti_t *enti, sfRenderWindow *window)
{
    if (enemies->pos.x <= 645 && enemies->pos.y == 825)
        right_moves(enemies);
    if (enemies->pos.y >= 325 && enemies->pos.x == 645)
        up_moves(enemies);
    if (enemies->pos.x <= 990 && enemies->pos.y == 325)
        right_moves(enemies);
    if (enemies->pos.y <= 910 && enemies->pos.x == 990)
        down_moves(enemies);
    if (enemies->pos.x <= 1830 && enemies->pos.y == 910)
        right_moves(enemies);
    (enemies->pos.x == 1830 && enemies->pos.y == 910 ? enti->lives -= 1 : 0);
    if (enti->lives == 0)
        check_lives(enti, window);
}

void summer_path(element_t *enemies, enti_t *enti, sfRenderWindow *window)
{
    if (enemies->pos.x <= 390 && enemies->pos.y == 480)
        right_moves(enemies);
    if (enemies->pos.y <= 720 && enemies->pos.x == 390)
        down_moves(enemies);
    if (enemies->pos.x <= 620 && enemies->pos.y == 720)
        right_moves(enemies);
    if (enemies->pos.y >= 340 && enemies->pos.x == 620)
        up_moves(enemies);
    if (enemies->pos.x <= 1140 && enemies->pos.y == 340)
        right_moves(enemies);
    if (enemies->pos.y >= 280 && enemies->pos.y <= 340
    && enemies->pos.x == 1140)
        up_moves(enemies);
    if (enemies->pos.x <= 1800 && enemies->pos.y == 280)
        right_moves(enemies);
    (enemies->pos.x == 1800 && enemies->pos.y == 280 ? enti->lives -= 1 : 0);
    if (enti->lives == 0)
        check_lives(enti, window);
}

void snow_path(element_t *enemies, enti_t *enti, sfRenderWindow *window)
{
    if (enemies->pos.x <= 1450 && enemies->pos.y == 790)
        right_moves(enemies);
    if (enemies->pos.y <= 790 && enemies->pos.y >= 590 &&
    enemies->pos.x == 1450)
        up_moves(enemies);
    if (enemies->pos.x >= 370 && enemies->pos.y == 590)
        left_moves(enemies);
    if (enemies->pos.y <= 590 && enemies->pos.y >= 355 && enemies->pos.x == 370)
        up_moves(enemies);
    if (enemies->pos.x <= 1025 && enemies->pos.y == 355)
        right_moves(enemies);
    if (enemies->pos.y <= 355 && enemies->pos.y >= 250 &&
    enemies->pos.x == 1025)
        up_moves(enemies);
    if (enemies->pos.x <= 1530 && enemies->pos.y == 250)
        right_moves(enemies);
    (enemies->pos.x == 1530 && enemies->pos.y == 250 ? enti->lives -= 1 : 0);
    if (enti->lives == 0)
        check_lives(enti, window);
}