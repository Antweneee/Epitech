/*
** EPITECH PROJECT, 2022
** B-MAT-500-PAR-5-1-303make-antoine.gavira-bottari
** File description:
** Main
*/

#include <stdio.h>
#include <string.h>
#include <fstream>
#include "Make.hpp"
#include "Error.hpp"

int helper(Exit_states state)
{
    for (const auto &elem : _usage) {
        std::cout << elem;
    }
    return state == SUCCESS ? EXIT_SUCCESS : EXIT_FAILURE_EPI;
}

int main(int ac, char const *av[])
{
    try {
        if (ac == 2 && strcmp(av[1], "-h") == 0)
            return helper(SUCCESS);
        if (ac < 2 || ac > 3)
            return helper(FAILURE);
        Make Make(ac, av);
        Make.manageFile();
    } catch (const Error &e) {
        std::cerr << e.what() << std::endl;
        return EXIT_FAILURE_EPI;
    }
    return EXIT_SUCCESS;
}
