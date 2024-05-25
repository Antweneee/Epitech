/*
** EPITECH PROJECT, 2022
** 305construction
** File description:
** main
*/

#include "Error.hpp"
#include "Construction.hpp"

int main(int argc, char const *argv[])
{
    Construction construction;

    if (argc == 2 && std::string(argv[1]).compare("-h") == 0) {
        construction.print_usage();
        return EXIT_SUCCESS;
    }
    if (argc != 2) {
        std::cerr << "No file given" << std::endl;
        return EXIT_ERROR;
    }
    try {
        if (construction.handle_file(argv[1]) == STATUS_FAIL) {
            return EXIT_ERROR;
        }
    }
    catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
        return EXIT_ERROR;
    }
    return EXIT_SUCCESS;
}