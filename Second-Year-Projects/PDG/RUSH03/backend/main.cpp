/*
** EPITECH PROJECT, 2022
** main
** File description:
** a
*/

#include "../ncurse/includes/ncurses.hpp"
#include "../sfml/includes/sfml.hpp"

int main(int argc, char **argv)
{
    if (argc != 1 && argv[1][0] == '-' && argv[1][1] == 'h' && argv[1][2] == '\0')
    {
        std::cout << "usage:\n./a.out for ncurses\n./a.out -g for sfml" << std::endl;
        return 0;
    }
    else if (argc != 1 && argv[1][0] == '-' && argv[1][1] == 'g' && argv[1][2] == '\0') {
        main_sfml();
    }
    else {
        main_ncurses();
    }
    return 0;
}