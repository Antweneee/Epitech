/*
** EPITECH PROJECT, 2022
** B-OOP-400-PAR-4-1-arcade-valentin.fouillet
** File description:
** IDisplay
*/

#ifndef IDisplay_HPP_
#define IDisplay_HPP_

#include "enum.hpp"
#include "includes.hpp"
#include "IInfo.hpp"

class IDisplay { //DISPLAY
    public:
        virtual ~IDisplay() = default;
        virtual Arcade::KEYS get_key() = 0;
        virtual void draw(IInfo::GameData &) = 0;
        virtual void init() = 0;
        virtual void window_handler() = 0;
        virtual Arcade::PROTO get_lib_name() = 0;
        virtual void clearr() = 0;
        virtual void refreshh() = 0;
        virtual std::tuple<Arcade::PROTO, Arcade::PROTO> my_menu() = 0;
        virtual std::string get_name() = 0;

    protected:
    private:
};

#endif /* IDisplay_HPP_ */