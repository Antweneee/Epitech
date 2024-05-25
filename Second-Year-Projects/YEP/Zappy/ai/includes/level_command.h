/*
** EPITECH PROJECT, 2022
** B-YEP-410-PAR-4-1-zappy-thomas.willson
** File description:
** level_command
*/

#ifndef LEVEL_COMMAND_H_
    #define LEVEL_COMMAND_H_
    #include "ai_info.h"
    #include <stdbool.h>

bool first_level(struct ai_info *ai);
bool second_level(struct ai_info *ai);
bool third_level(struct ai_info *ai);
bool fourth_level(struct ai_info *ai);
bool fifth_level(struct ai_info *ai);
bool sixt_level(struct ai_info *ai);
bool seventh_level(struct ai_info *ai);
bool heigth_level(struct ai_info *ai);

typedef struct level_command_s {
    int actual_level;
    bool (*functions)(struct ai_info*);
} level_command_t;

static const level_command_t LEVEL_COMMAND[] = {
    {.actual_level = 1, .functions = first_level},
    {.actual_level = 2, .functions = second_level},
    {.actual_level = 3, .functions = third_level},
    {.actual_level = 4, .functions = fourth_level},
    {.actual_level = 5, .functions = fifth_level},
    {.actual_level = 6, .functions = sixt_level},
    {.actual_level = 7, .functions = seventh_level},
    {.actual_level = 8, .functions = heigth_level},
};

#endif /* !LEVEL_COMMAND_H_ */
