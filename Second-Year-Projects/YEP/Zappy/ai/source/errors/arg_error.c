/*
** EPITECH PROJECT, 2022
** B-YEP-410-PAR-4-1-zappy-thomas.willson
** File description:
** arg_error
*/

#include "define.h"
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

/**
 * @brief check if a string is an alphanumeric character
 * 
 * @param str string to check
 * @return true 
 * @return false 
 */
bool is_num(const char* str)
{
    size_t i = 0;

    while (i < strlen(str)) {
        if (str[i] < '0' || str[i] > '9') {
            return (false);
        }
        i++;
    }
    return (true);
}

/**
 * @brief check if the argv is correct with the mandatory argument 
 * 
 * @param argc corrsponds to the number of arguments passed
 * @param argv corrsponds to the arguments
 * @return true 
 * @return false 
 */
bool check_args(int argc, const char *argv[])
{
    static const char* tab[] = {"-p", "-n", "-h", NULL};

    if (argc != 7) {
        fprintf(stderr, "%s", HELP);
        return (false);
    }
    if (strcmp(argv[1], tab[0]) || !is_num(argv[2])) {
        fprintf(stderr, "%s", HELP);
        return (false);
    }
    if (strcmp(argv[3], tab[1])) {
        fprintf(stderr, "%s", HELP);
        return (false);
    }
    if (strcmp(argv[5], tab[2])) {
        fprintf(stderr, "%s", HELP);
        return (false);
    }
    return (true);
}