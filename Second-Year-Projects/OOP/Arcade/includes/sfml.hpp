/*
** EPITECH PROJECT, 2022
** B-OOP-400-PAR-4-1-arcade-valentin.fouillet
** File description:
** sfml
*/

#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Config.hpp>
#include <SFML/Window.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include "IDisplay.hpp"

class SFML : public IDisplay
{
    public:
        SFML();
        ~SFML();
        Arcade::KEYS get_key();
        void draw(IInfo::GameData &);
        void init();
        void window_handler();
        void clearr();
        void refreshh();
        Arcade::PROTO get_lib_name() { return Arcade::PROTO::SFML; };
        std::tuple<Arcade::PROTO, Arcade::PROTO> my_menu();
        std::string get_name();

    private:
        IInfo::GameData _data;
        std::string _name;
        Arcade::KEYS _key;
        sf::RenderWindow _window;
        sf::Event _event;
        std::vector<sf::RectangleShape> _shapes;
};

extern "C" SFML *get_class() { return new SFML; };