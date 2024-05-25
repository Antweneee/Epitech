/*
** EPITECH PROJECT, 2022
** B-MAT-500-PAR-5-1-302separation-antoine.gavira-bottari
** File description:
** Main
*/

#include <stdio.h>
#include <string.h>
#include <fstream>
#include "Separation.hpp"
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
        if (ac < 3 || ac > 4)
            return helper(FAILURE);
        Separation separation(ac, av);
        separation.manageFile();
    } catch (const Error &e) {
        std::cerr << e.what() << std::endl;
        return EXIT_FAILURE_EPI;
    }
    return EXIT_SUCCESS;
}
