/*
** EPITECH PROJECT, 2022
** B-YEP-410-PAR-4-1-zappy-thomas.willson
** File description:
** Drawable
*/

#include <iostream>
#include "Drawable.hpp"

Drawable::Drawable(int width, int height) : _width(width), _height(height), _top(200), _left(84)
{
    if (width != 84) {
        _top = std::rand();
        _left = std::rand();
        ((_top % 2) == 0 ? _top = 0 : _top = 246);
        ((_left % 2) == 0 ? _left = 0 : _left = 246);
        set_rect(_width, _height, _top, _left);
    } else
        set_rect(_width, _height, _top, _left);
}

Drawable::~Drawable()
{
}

void Drawable::draw(sf::RenderWindow &window)
{
    window.draw(_sprite);
}

void Drawable::init_sprite(std::string const &sprite_path, int pos_x, int pos_y)
{
    set_sprite_pos(pos_x, pos_y);
    _texture.loadFromFile(sprite_path);
    _sprite.setTexture(_texture);
    _sprite.setPosition(_sprite_pos);
    _sprite.setTextureRect(_rect);
}

void Drawable::set_sprite_pos(int const pos_x, int const pos_y)
{
    _sprite_pos = sf::Vector2f(pos_x, pos_y);
    _sprite.setPosition(_sprite_pos);
}

void Drawable::set_sprite_pos(sf::Vector2f &pos)
{
    _sprite_pos = pos;
    _sprite.setPosition(_sprite_pos);
}
