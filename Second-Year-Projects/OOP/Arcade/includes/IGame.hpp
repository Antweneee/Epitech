/*
** EPITECH PROJECT, 2022
** B-OOP-400-PAR-4-1-arcade-valentin.fouillet
** File description:
** IGame
*/

#ifndef IGAME_HPP_
#define IGAME_HPP_

#include "enum.hpp"
#include "includes.hpp"
#include "IInfo.hpp"

class IGame { //GAME
    public:
        virtual ~IGame() = default;
        virtual void init() = 0; //init the map, collision point ...
        virtual void getkey(Arcade::KEYS key) = 0; // get input key for the game
        virtual void game_over() = 0; //winning condition
        virtual void character_handler() = 0;
        virtual void end_handler() = 0; //for pacman ghosts, and for nibbler yourself and walls || either way check collision
        virtual void points_handler() = 0;
        virtual void engine(Arcade::KEYS) = 0;
        virtual IInfo::GameData get_game_data() = 0;
        virtual Arcade::PROTO get_lib_name() = 0;

        //virtual void refresh() = 0;
    protected:
    private:
};


#endif /* IGAME_HPP_ */
