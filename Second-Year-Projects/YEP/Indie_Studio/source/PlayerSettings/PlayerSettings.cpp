/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-antoine.gavira-bottari
** File description:
** PlayerSettings
*/

#include "PlayerSettings.hpp"

PlayerSettings::PlayerSettings() : _name(""), _type("Local"), _controller("Keyboard")
{
}

PlayerSettings::PlayerSettings(std::string const &type, std::string const &controller, std::string const &name) : _name(name), _type(type), _controller(controller)
{
}

PlayerSettings::~PlayerSettings()
{
}

void PlayerSettings::set_type(std::string const &type)
{
    _type = type;
}

void PlayerSettings::set_controller(std::string const &controller)
{
    _controller = controller;
}

void PlayerSettings::set_isAi(bool const isAi)
{
    _isAi = isAi;
}

void PlayerSettings::set_name(std::string const &name)
{
    _name = name;
}

void PlayerSettings::set_Bindings(std::map<std::string, std::string> &bindings)
{
    std::map<std::string,std::string>::iterator it;
    std::string tmp;
    Vector3 pos = {};

    it = bindings.find("char");
    tmp = bindings.at("char");
    _map_char = tmp[0];

    pos.x = std::stof(bindings.at("pos_x"));
    bindings.erase(bindings.find("pos_x"));
    pos.y = std::stof(bindings.at("pos_y"));
    bindings.erase(bindings.find("pos_y"));
    pos.z = std::stof(bindings.at("pos_z"));
    bindings.erase(bindings.find("pos_z"));
    bindings.erase(it);
    _pos = pos;
    if (_type.compare("Ai") != 0)
        _bindings = bindings;
}

void PlayerSettings::set_position(Vector3 const &pos)
{
    _pos = pos;
}

void PlayerSettings::debug()
{
    std::cout << _name << std::endl;
    std::cout << _type << std::endl;
    std::cout << _isAi << std::endl;
    std::cout << _controller << std::endl;
    std::map<std::string, std::string> tmp = get_bindings();
    for (auto i = tmp.cbegin(); i != tmp.cend(); ++i) {
        std::cout << i->first << " " << i->second << std::endl;
    }
    std::cout << _map_char << std::endl;
    std::cout << _pos.x << " " << _pos.y << " " << _pos.z << std::endl;
    std::cout << std::endl;
}

void PlayerSettings::check_isAi()
{
    if (_type.compare("Ai") == 0)
        set_isAi(true);
    else
        set_isAi(false);
}

std::string const &PlayerSettings::get_controller() const
{
    return _controller;
}

std::string const &PlayerSettings::get_type() const
{
    return _type;
}

bool const &PlayerSettings::get_isAi() const
{
    return _isAi;
}

std::string const &PlayerSettings::get_name() const
{
    return _name;
}

std::map<std::string, std::string> PlayerSettings::get_bindings() const
{
    return _bindings;
}

Vector3 const &PlayerSettings::get_pos() const
{
    return _pos;
}

char const &PlayerSettings::get_map_char()
{
    return _map_char;
}