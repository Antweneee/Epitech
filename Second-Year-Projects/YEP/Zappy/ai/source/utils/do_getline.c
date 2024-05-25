/*
** EPITECH PROJECT, 2022
** B-YEP-410-PAR-4-1-zappy-thomas.willson
** File description:
** do_getline
*/

#include "ai_info.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * @brief functions that delete the "\n" of a string and return the actual string
 * 
 * @param str 
 * @return char* 
 */
static char *delete_new_line(char *str)
{
    int count = 0;

    while (str[count] != '\n')
        count += 1;
    str[count] = '\0';
    return (str);
}

/**
 * @brief encapsulation of getline that free the buffer if a EOF is send to getline
 * 
 * @param fds 
 * @return char* correspond to the actual buffer allocated by getline
 */
static char* do_getline(FILE* fds)
{
    char* buffer = NULL;
    size_t len = 0;

    if (getline(&buffer, &len, fds) == -1) {
        free(buffer);
        return NULL;
    }
    return buffer;
}

/**
 * @brief 
 * 
 * @param command char** that correspond to the buffer that getline return we just set a pointer to it
 * @param fds FILE* that correspond to the server fd
 * @param ai 
 * @return 0 on success and -1 on failure 
 */
int read_client(char** command, FILE* fds, struct ai_info* ai)
{
    *command = do_getline(fds);
    if (*command == NULL)
        return -1;
    delete_new_line(*command);
    ai->verify->is_reading = !ai->verify->is_reading;
    return 0;
}