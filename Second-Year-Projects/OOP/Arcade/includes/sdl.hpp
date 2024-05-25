/*
** EPITECH PROJECT, 2022
** B-OOP-400-PAR-4-1-arcade-valentin.fouillet
** File description:
** sdl
*/

#pragma once

#include <SDL2/SDL_video.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_events.h>
#include "includes.hpp"
#include "IDisplay.hpp"

class Sdl : public IDisplay
{
public:
    Sdl();
    ~Sdl();
    Arcade::KEYS get_key();
    void draw(IInfo::GameData&);
    void init();
    void window_handler();
    void refreshh();
    void clearr();
    Arcade::PROTO get_lib_name();
    std::tuple<Arcade::PROTO, Arcade::PROTO> my_menu() { return std::make_tuple(Arcade::PROTO::NIBBLER, Arcade::PROTO::NCRUSES); };
    std::string get_name() { return this->_name; };

private:
    std::string _name;
    Arcade::KEYS _key;
    IInfo::GameData _data;
    SDL_Window *_window;
    SDL_Renderer *_renderer;
    SDL_bool _is_launched;
    SDL_Event _event;
    std::vector<SDL_Rect> _rect;
    std::vector<SDL_Surface*> _surface;
    SDL_Rect shape;
    SDL_Surface* surf;
};

extern "C" Sdl *get_class() { return new Sdl; };