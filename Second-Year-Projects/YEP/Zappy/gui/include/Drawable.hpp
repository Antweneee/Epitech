/*
** EPITECH PROJECT, 2022
** B-YEP-410-PAR-4-1-zappy-thomas.willson
** File description:
** Drawable
*/

#ifndef DRAWABLE_HPP_
#define DRAWABLE_HPP_

#include <string>
#include "SFML_includes.hpp"

class Drawable
{
    public:
        Drawable(int width, int height);
        ~Drawable();

        void init_sprite(std::string const &sprite_path, int pos_x, int pos_y);
        sf::IntRect get_rect() const { return _rect; }
        void set_rect(sf::IntRect const &rect)  { _rect = rect; _sprite.setTextureRect(_rect);}
        void set_rect(int const width, int const height, int const top = 0, int const left = 0) { _rect.width = width; _rect.height = height; _rect.left = left; _rect.top = top; _sprite.setTextureRect(_rect); }
        void change_sprite(std::string const &texture_path) {_texture.loadFromFile(texture_path); _sprite.setTexture(_texture);}

    protected:
        void set_sprite_pos(int const , int const );
        void set_sprite_pos(sf::Vector2f &);
        virtual bool is_clicked(sf::Vector2f position) = 0;

        sf::Vector2f get_pos() const { return _sprite_pos; }

        void draw(sf::RenderWindow &window);

        sf::Sprite _sprite;

    private:
        sf::Texture _texture;
        sf::IntRect _rect;
        int _width;
        int _height;
        int _top;
        int _left;
        sf::Vector2f _sprite_pos;
};

#endif /* !DRAWABLE_HPP_ */
