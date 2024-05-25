/*
** EPITECH PROJECT, 2022
** sfml
** File description:
** sfml
*/

#ifndef SFML_HPP_
#define SFML_HPP_

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Config.hpp>
#include <SFML/Window.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include "../../backend/CPU/cpu_info.hpp"
#include "../../backend/Network/Network.hpp"

class manip
{
    public:
        manip(int, int);
        ~manip();

        void bar(sf::RenderWindow *win, int use, int posx, int posy, int mul);
        void setRect(int, int);
        sf::RectangleShape rect;
    private:
};

typedef struct info_s
{
    sf::RenderWindow Window;
    sf::Event evt;
    sf::Mouse mouse;
    sf::Sprite bg;
    sf::Texture text;
    sf::Clock clock;
    sf::Time time;
    float sec;
    bool check1;
    bool check2;
    bool check3;
    bool check4;
} info_t;

class Button
{
    public :
    sf::Texture text;
    sf::Texture second;
    sf::Sprite sprite;
    sf::Vector2f but_pos;
    sf::IntRect rect;

    Button(std::string path, std::string path2, sf::Vector2f pos, int width, int height)
    {
        text.loadFromFile(path);
        second.loadFromFile(path2);
        sprite = sf::Sprite(text);
        but_pos = pos;
        sprite.setPosition(but_pos);
        rect.width = width;
        rect.height = height;
        sprite.setTextureRect(rect);
    }

    ~Button()
    {
    }

    bool check(sf::Vector2i mousepos, sf::Mouse action)
    {
        if (mousepos.x >= but_pos.x && mousepos.x <= but_pos.x + rect.width && mousepos.y >= but_pos.y && mousepos.y <= but_pos.y + rect.height && action.isButtonPressed(sf::Mouse::Left))
            return true;
        return false;
    }
    void pass_by(sf::Vector2i mousepos)
    {
        if (mousepos.x >= but_pos.x && mousepos.x <= but_pos.x + rect.width && mousepos.y >= but_pos.y && mousepos.y <= but_pos.y + rect.height)
            sprite.setTexture(second);
        else
            sprite.setTexture(text);
    }
};
int main_sfml(void);

#endif /* !SFML_HPP_ */