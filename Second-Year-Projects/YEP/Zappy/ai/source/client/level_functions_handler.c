/*
** EPITECH PROJECT, 2022
** B-YEP-410-PAR-4-1-zappy-thomas.willson
** File description:
** level_functions_handler
*/

#include "ai_info.h"
#include "level_command.h"

/**
 * @brief iterates through all the commands in the command list
 * 
 * @param ai 
 * @param level 
 * @return the poisition of the good function find in the list
 * @return on error -1 is returned
 */
int check_command(int level)
{
    int i = 0;
    int size = sizeof(LEVEL_COMMAND) / sizeof(LEVEL_COMMAND[0]);

    if (level < 1 || level > 8)
        return -1;
    for (i = 0; i < size; i++) {
        if (level == LEVEL_COMMAND[i].actual_level) {
            if (LEVEL_COMMAND[i].functions != NULL)
                return i;
        }
    }
    return -1;
}

/**
 * @brief execute the command specified by check_command
 * 
 * @param ai 
 * @return true 
 * @return false if nothing matches the command
 */
bool command_exec(struct ai_info* ai)
{
    int index = check_command(ai->level);

    if (index != -1) {
        if (LEVEL_COMMAND[index].functions != NULL)
            return (LEVEL_COMMAND[index].functions)(ai);
    }
    return (false);
}