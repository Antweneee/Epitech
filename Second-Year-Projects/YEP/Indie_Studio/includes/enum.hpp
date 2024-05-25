/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-antoine.gavira-bottari
** File description:
** enum
*/

#ifndef ENUM_HPP_
    #define ENUM_HPP_

namespace INDIE
{
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
        NIL, // • Null
        Z, // • upper key
        Q, // • down key
        S, // • left key
        D, // • right key
        B, // • B key
    };
    const struct {
        INDIE::KEYS _key;
        int x;
        int y;
    } __position__[] = {
        {INDIE::KEYS::UP, -1, 0},
        {INDIE::KEYS::DOWN, 1, 0},
        {INDIE::KEYS::LEFT, 0, -1},
        {INDIE::KEYS::RIGHT, 0, 1},
        {INDIE::KEYS::Z, -1, 0},
        {INDIE::KEYS::S, 1, 0},
        {INDIE::KEYS::Q, 0, -1},
        {INDIE::KEYS::D, 0, 1},
    };
}

#endif /* !ENUM_HPP_ */
