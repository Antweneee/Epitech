/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-antoine.gavira-bottari
** File description:
** PlayerSettings
*/

#ifndef PLAYERSETTINGS_HPP_
#define PLAYERSETTINGS_HPP_

    #include "Menu.hpp"
    #include "Score.hpp"
    #include "Shapes.hpp"
    #include "Text.hpp"
    #include "Audio.hpp"
    #include "Core.hpp"

    #include <iostream>
    #include <map>
    #include "raylib.h"

class PlayerSettings {
    public:
        PlayerSettings();
        PlayerSettings(std::string const &type, std::string const &controller, std::string const &name);
        PlayerSettings(const PlayerSettings &) = default;
        ~PlayerSettings();
        void set_type(std::string const &type);
        void set_controller(std::string const &controller);
        void set_isAi(bool const isAi);
        void set_name(std::string const &name);
        void set_Bindings(std::map<std::string, std::string> &bindings);
        void set_position(Vector3 const &pos);
        void debug();
        void check_isAi();
        std::string const &get_type() const;
        std::string const &get_controller() const;
        bool const &get_isAi() const;
        std::string const &get_name() const;
        std::map<std::string, std::string> get_bindings() const;
        Vector3 const &get_pos() const;
        char const &get_map_char();

        PlayerSettings &operator=(PlayerSettings &player)
        {
            _name = player.get_name();
            _type = player.get_type();
            _controller = player.get_controller();
            _isAi = player.get_isAi();
            _bindings = player.get_bindings();
            _pos = player.get_pos();
            _map_char = player.get_map_char();
            return *this;
        }

    private:
        std::string _name;
        std::string _type;
        std::string _controller;
        bool _isAi;
        char _map_char;
        Vector3 _pos;
        std::map<std::string, std::string> _bindings;
};

#endif /* !PLAYERSETTINGS_HPP_ */
