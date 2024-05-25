/*
** EPITECH PROJECT, 2022
** B-OOP-400-PAR-4-1-arcade-valentin.fouillet
** File description:
** ncurse
*/

#pragma once

#include <ncurses.h>
#include <curses.h>
#include "includes.hpp"
#include "IDisplay.hpp"

class NCURSE : public IDisplay
{
    public:
        NCURSE();
        ~NCURSE();
        Arcade::KEYS get_key();
        void draw(IInfo::GameData &);
        void init();
        void window_handler();
        void refreshh();
        void clearr();
        Arcade::PROTO get_lib_name();
        std::tuple<Arcade::PROTO, Arcade::PROTO> my_menu();
        std::string get_name() { return this->_name; };


    private:
        Arcade::PROTO _game;
        Arcade::PROTO _graphic;
        std::string _name;
        Arcade::KEYS _key;
};

extern "C" NCURSE *get_class() { return new NCURSE; };
