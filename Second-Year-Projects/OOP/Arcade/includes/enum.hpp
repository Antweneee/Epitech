/*
** EPITECH PROJECT, 2022
** B-OOP-400-PAR-4-1-arcade-valentin.fouillet
** File description:
** enum
*/

#ifndef ENUM_HPP_
#define ENUM_HPP_

namespace Arcade
{
    enum PROTO {
        NCRUSES,
        SFML,
        SDL,
        PACMAN,
        NIBBLER,
    };
    enum KEYS
    {
        UP, // • upper key
        DOWN, // • down key
        LEFT, // • left key
        RIGHT, // • right key
        SPACE, // • space key
        ESC, // • exit key
        F1, // • previous graphics library.
        F2, // • next graphics library.
        F3, // • previous game.
        F4, // • next game.
        R, // • restart the game.
        M, // • go back to the menu.
        F, // • Bonus key
        NIL, // • error key
    };
    const struct
    {
        Arcade::KEYS _key;
        int x;
        int y;
    } __position__[] = {
        {Arcade::KEYS::UP, -1, 0},
        {Arcade::KEYS::DOWN, 1, 0},
        {Arcade::KEYS::LEFT, 0, -1},
        {Arcade::KEYS::RIGHT, 0, 1},
    };
}

#endif /* !ENUM_HPP_ */
