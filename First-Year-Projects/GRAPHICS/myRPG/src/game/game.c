/*
** EPITECH PROJECT, 2021
** double
** File description:
** game
*/

#include <stdlib.h>
#include <stdbool.h>
#include "my.h"

bool in_range(sfIntRect size, enti_t *enti, sfSprite *check)
{
    if (enti->perso->pos.x + 50 > sfSprite_getPosition(check).x &&
        enti->perso->pos.x + 50 < sfSprite_getPosition(check).x + size.width
        + 30 && enti->perso->pos.y + 70 > sfSprite_getPosition(check).y &&
        enti->perso->pos.y + 70 < sfSprite_getPosition(check).y + size.height
        + 30)
        return true;
    return false;
}

void check_questitems(enti_t *enti)
{
    if (in_range(enti->game.task_one.rect, enti, enti->game.task_one.sprite)
    && sfKeyboard_isKeyPressed(sfKeyF) && enti->game.task_one.status == 0) {
        enti->game.task_one.status = 1;
        enti->inventory.object = add_object(enti->inventory.object,
        "assets/game_assets/quest_01.png", 10, (sfVector2f){380, 710});
    }
    if (in_range(enti->game.task_two.rect, enti, enti->game.task_two.sprite)
    && sfKeyboard_isKeyPressed(sfKeyF) && enti->game.task_two.status == 0) {
        enti->game.task_two.status = 1;
        enti->inventory.object = add_object(enti->inventory.object,
        "assets/game_assets/quest_02.png", 2, (sfVector2f){441, 733});
    }
    if (in_range(enti->game.task_three.rect, enti, enti->game.task_three.sprite)
    && sfKeyboard_isKeyPressed(sfKeyF) && enti->game.task_three.status == 0) {
        enti->game.task_three.status = 1;
        enti->inventory.object = add_object(enti->inventory.object,
        "assets/game_assets/quest_03.png", 10, (sfVector2f){530, 733});
    }
}

int analyse_events(sfRenderWindow *window, sfEvent event)
{
    if (event.type == sfEvtClosed)
        sfRenderWindow_close(window);
    if (event.type == sfEvtClosed)
        return 1;
    return 0;
}

void check_analyse(sfRenderWindow *window, sfEvent event, perso_t *perso)
{
    if (analyse_events(window, event) == 1) {
        sfRenderWindow_close(window);
        sfRenderWindow_destroy(window);
        free_all(perso);
        exit(0);
    }
}

void start_game(enti_t *enti, sfRenderWindow *window)
{
    sfEvent evt;
    enti->perso = fill_perso(enti);

    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &evt)) {
            event(enti, window, &evt);
            if (enti->select.selection == 1)
                move_boy(enti->perso);
            else
                move_girl(enti->perso);
            check_analyse(window, evt, enti->perso);
        }
        inventory_management(window, enti);
        draw_game(enti, window);
        if (enti->game.task_one.status == 1 && enti->game.task_two.status == 1
            && enti->game.task_three.status == 1)
            quest_completed(window, enti);
        if (sfKeyboard_isKeyPressed(sfKeyEscape))
            pause_window(enti, window);
    }
}