/*
** EPITECH PROJECT, 2022
** B-OOP-400-PAR-4-1-arcade-valentin.fouillet
** File description:
** main
*/

#include "includes.hpp"
#include "Preprocess.hpp"

int main(int const argc, char const * const argv[])
{
    if (argc < 2)
        return 84;

    std::tuple<Arcade::PROTO, Arcade::PROTO> libraries;
    Arcade::PROTO game;
    Arcade::PROTO graphic;
    Preprocessor::Loader process(argv[1]);

        //          MENU
    process._class_display.get()->init();
    libraries = process._class_display.get()->my_menu();
    process.set_name(process._class_display.get()->get_name());

    game = std::get<0>(libraries);
    graphic = std::get<1>(libraries);


        //          GAME
    process.StartGame(graphic, game);
    process.engine();

    return 0;
}