/*
** EPITECH PROJECT, 2022
** B-OOP-400-PAR-4-1-arcade-valentin.fouillet
** File description:
** sdl
*/

#include "sdl.hpp"
#include <SDL2/SDL.h>

Sdl::Sdl()
{
    _key = Arcade::KEYS::NIL;
}

Sdl::~Sdl()
{
    SDL_DestroyRenderer(_renderer);
    SDL_DestroyWindow(_window);
    SDL_Quit();
}

Arcade::KEYS Sdl::get_key()
{
    Arcade::KEYS key = Arcade::KEYS::NIL;

    while (SDL_PollEvent(&_event))
    {
        if (_event.type == SDL_QUIT) {
            SDL_DestroyRenderer(_renderer);
            SDL_DestroyWindow(_window);
            SDL_Quit();
        }
        if (_event.key.keysym.sym == SDLK_UP)
            key = Arcade::KEYS::UP;
        if (_event.key.keysym.sym == SDLK_DOWN)
            key = Arcade::KEYS::DOWN;
        if (_event.key.keysym.sym == SDLK_RIGHT)
            key = Arcade::KEYS::RIGHT;
        if (_event.key.keysym.sym == SDLK_LEFT)
            key = Arcade::KEYS::LEFT;
        if (_event.key.keysym.sym == SDLK_ESCAPE)
            key = Arcade::KEYS::ESC;
        if (_event.key.keysym.sym == SDLK_F1)
            key = Arcade::KEYS::F1;
        if (_event.key.keysym.sym == SDLK_F2)
            key = Arcade::KEYS::F2;
        if (_event.key.keysym.sym == SDLK_F3)
            key = Arcade::KEYS::F3;
        if (_event.key.keysym.sym == SDLK_F4)
            key = Arcade::KEYS::F4;
        if (_event.key.keysym.sym == SDLK_r)
            key = Arcade::KEYS::R;
        if (_event.key.keysym.sym == SDLK_m)
            key = Arcade::KEYS::M;
        if (_event.key.keysym.sym == SDLK_f)
            key = Arcade::KEYS::F;
    }

    if (key == Arcade::KEYS::NIL)
        key = _key;
    if (key == Arcade::KEYS::ESC)
    {
        SDL_DestroyRenderer(_renderer);
        SDL_DestroyWindow(_window);
        SDL_Quit();
        _key = key;
    }
    _key = key;
    return key;
}

void Sdl::draw(IInfo::GameData &data)
{
    if (_window == NULL)
        init();
    _data = data;
    window_handler();
    for (size_t i = 0; i < _rect.size(); i++)
    {
        //this->refreshh();
        if (_rect[i].h == 24) {
            SDL_SetRenderDrawColor(_renderer, 0, 0, 255, 255);
            SDL_RenderFillRect(_renderer, &_rect[i]);
        } else if (_rect[i].h == 12) {
            SDL_SetRenderDrawColor(_renderer, 0, 255, 255, 255);
            SDL_RenderFillRect(_renderer, &_rect[i]);
        } else if (_rect[i].h == 3 && _rect[i].w == 2) {
            SDL_SetRenderDrawColor(_renderer, 255, 255, 255, 0);
            SDL_RenderFillRect(_renderer, &_rect[i]);
        } else if (_rect[i].h == 20 && _rect[i].w == 11) {
            SDL_SetRenderDrawColor(_renderer, 255, 0, 0, 0);
            SDL_RenderFillRect(_renderer, &_rect[i]);
        } else if (_rect[i].h == 19 && _rect[i].w == 9) {
            SDL_SetRenderDrawColor(_renderer, 255, 0, 0, 0);
            SDL_RenderFillRect(_renderer, &_rect[i]);
        } else if (_rect[i].h == 22 && _rect[i].w == 10) {
            SDL_SetRenderDrawColor(_renderer, 0, 255, 0, 0);
            SDL_RenderFillRect(_renderer, &_rect[i]);
        } else if (_rect[i].h == 21 && _rect[i].w == 10) {
            SDL_SetRenderDrawColor(_renderer, 255, 140, 0, 0);
            SDL_RenderFillRect(_renderer, &_rect[i]);
        } else if (_rect[i].h == 19 && _rect[i].w == 10) {
            SDL_SetRenderDrawColor(_renderer, 255, 255, 0, 0);
            SDL_RenderFillRect(_renderer, &_rect[i]);
        }

    }
    this->refreshh();
    _rect.clear();
}

SDL_Rect setRect(int x, int y, int h, int w)
{
    SDL_Rect rect;

    rect.x = x;
    rect.y = y;
    rect.h = h;
    rect.w = w;

    return rect;
}

void Sdl::init()
{
    SDL_Init(SDL_INIT_EVERYTHING);
    _window = SDL_CreateWindow("Arcade", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 715, 504, 0);
    _renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_SOFTWARE);
    _is_launched = SDL_TRUE;
}

void Sdl::window_handler()
{
    int number = 0;

    _rect.push_back(setRect(0, 0, 504, 715));
    SDL_SetRenderDrawColor(_renderer, 0, 0, 0, 0);
    SDL_RenderFillRect(_renderer, &_rect[0]);
    for (size_t i = 0, si = 0; i < _data._map.size(); i++, si += 24)
    {
        for (size_t j = 0, sj = 0; j < _data._map[i].Content.size(); j++, sj += 11)
        {
            if (_data._map[i].Content[j] == 'W')
            {
                _rect.push_back(setRect(sj, si, 24, 11));
            }
            else if (_data._map[i].Content[j] == 'G') {
                _rect.push_back(setRect(sj, si, 24, 11));
            }
            else if (_data._map[i].Content[j] == 'C')
                _rect.push_back(setRect(sj + 3, si + 4, 12, 6));
            else if (_data._map[i].Content[j] == '.')
                _rect.push_back(setRect(sj + 3, si + 4, 3, 2));
            else if (_data._map[i].Content[j] == 'T')
            {
                _rect.push_back(setRect(sj, si, 24, 11));
            }
            else if (_data._map[i].Content[j] == 'P')
            {
                _rect.push_back(setRect(sj, si, 20, 11));
            } else if (_data._map[i].Content[j] == 'a')
            {
                _rect.push_back(setRect(sj, si, 19, 9));
            }
            else if (_data._map[i].Content[j] == '0')
            {
                _rect.push_back(setRect(sj, si, 22, 10));
            }
            else if (_data._map[i].Content[j] == 'x')
            {
                _rect.push_back(setRect(sj, si, 21, 10));
            }
            else if (_data._map[i].Content[j] == 'o')
            {
                _rect.push_back(setRect(sj, si, 19, 10));
            }
        }
    }
}
void Sdl::refreshh()
{
    SDL_RenderPresent(_renderer);
}

void SDL_LimitFPS(unsigned int limit)
{
    unsigned int ticks = SDL_GetTicks();

    if (limit < ticks)
        return;
    else if (limit > ticks + 33)
        SDL_Delay(30);
    else
        SDL_Delay(limit - ticks);
}

void Sdl::clearr()
{
    SDL_RenderClear(_renderer);
}

Arcade::PROTO Sdl::get_lib_name()
{
    return Arcade::PROTO::SDL;
}