/*
** EPITECH PROJECT, 2022
** B-OOP-400-PAR-4-1-arcade-valentin.fouillet
** File description:
** sfml
*/

#include "sfml.hpp"

SFML::SFML()
{
    _key = Arcade::KEYS::NIL;
}

SFML::~SFML()
{
}

Arcade::KEYS SFML::get_key()
{
    Arcade::KEYS key = Arcade::KEYS::NIL;

    while (_window.pollEvent(_event)) {
        if (_event.key.code == sf::Keyboard::Up)
            key = Arcade::KEYS::UP;
        if (_event.key.code == sf::Keyboard::Down)
            key = Arcade::KEYS::DOWN;
        if (_event.key.code == sf::Keyboard::Left)
            key = Arcade::KEYS::LEFT;
        if (_event.key.code == sf::Keyboard::Right)
            key = Arcade::KEYS::RIGHT;
        if (_event.key.code == sf::Keyboard::Escape)
            key = Arcade::KEYS::ESC;
        if (_event.key.code == sf::Keyboard::F1)
            key = Arcade::KEYS::F1;
        if (_event.key.code == sf::Keyboard::F2)
            key = Arcade::KEYS::F2;
        if (_event.key.code == sf::Keyboard::F3)
            key = Arcade::KEYS::F3;
        if (_event.key.code == sf::Keyboard::F4)
            key = Arcade::KEYS::F4;
        if (_event.key.code == sf::Keyboard::R)
            key = Arcade::KEYS::R;
        if (_event.key.code == sf::Keyboard::M)
            key = Arcade::KEYS::M;
        if (_event.key.code == sf::Keyboard::F)
            key = Arcade::KEYS::F;
    }
    if (key == Arcade::KEYS::NIL)
        key = _key;
    if (key == Arcade::KEYS::ESC) {
        _window.close();
        _key = key;
    }
    _key = key;
    return _key;
}

void SFML::draw(IInfo::GameData &data)
{
    if (_window.isOpen() == false)
        init();
    _data = data;
    clearr();
    window_handler();
    for (size_t i = 0; i < _shapes.size(); i++)
        _window.draw(_shapes[i]);
    window_handler();
    refreshh();
    _shapes.clear();
}

sf::RectangleShape set_shape(sf::Vector2f size, sf::Color color, int x = 0, int y = 0)
{
    sf::RectangleShape rect;

    rect.setFillColor(color);
    rect.setSize(size);
    rect.setPosition(x ,y);
    return rect;
}

void SFML::init()
{
    if (_window.isOpen() == false) {
        _window.create(sf::VideoMode(715, 504), "Arcade");
        _shapes.push_back(set_shape(sf::Vector2f(715, 504), sf::Color::Black));
    }
}


void SFML::window_handler()
{
    int number = 0;
    sf::Color clr(84, 84, 84);

    for (size_t i = 0, si = 0; i < _data._map.size(); i++, si += 24) {
        for (size_t j = 0, sj = 0; j < _data._map[i].Content.size(); j++, sj += 11) {
            if (_data._map[i].Content[j] == 'W') {
                clr.r = 84; clr.g = 84; clr.b = 84;
                _shapes.push_back(set_shape(sf::Vector2f(11, 24), clr, sj, si));
            } else if (_data._map[i].Content[j] == 'G') {
                _shapes.push_back(set_shape(sf::Vector2f(11, 24), sf::Color::Red, sj, si));
            } else if (_data._map[i].Content[j] == 'C')
                _shapes.push_back(set_shape(sf::Vector2f(6, 12), sf::Color::Green, sj + 3, si + 4));
            else if (_data._map[i].Content[j] == '.')
                _shapes.push_back(set_shape(sf::Vector2f(2, 3), sf::Color::Green, sj + 3, si + 4));
            else if (_data._map[i].Content[j] == 'T') {
                clr.r = 54; clr.g = 54; clr.b = 54;
                _shapes.push_back(set_shape(sf::Vector2f(11, 24), clr, sj, si));
            } else if (_data._map[i].Content[j] == 'P') {
                _shapes.push_back(set_shape(sf::Vector2f(11, 24), sf::Color::Yellow, sj,  si));
            } else if (_data._map[i].Content[j] == 'a') {
                _shapes.push_back(set_shape(sf::Vector2f(11, 24), sf::Color::Red, sj,  si));
            } else if (_data._map[i].Content[j] == '0') {
                clr.r = 81;clr.g = 227; clr.b = 32;
                _shapes.push_back(set_shape(sf::Vector2f(11, 24), clr, sj,  si));
            } else if (_data._map[i].Content[j] == 'x') {
                clr.r = 100;clr.g = 232; clr.b = 56;
                _shapes.push_back(set_shape(sf::Vector2f(11, 24), clr, sj,  si));
            } else if (_data._map[i].Content[j] == 'o') {
                clr.r = 119;clr.g = 232; clr.b = 81;
                _shapes.push_back(set_shape(sf::Vector2f(11, 24), clr, sj,  si));
            }
        }
    }
}

void SFML::clearr()
{
    SFML::_window.clear();
}

void SFML::refreshh()
{
    SFML::_window.display();
}

Arcade::PROTO choose_game_page(std::string name)
{
    return Arcade::PROTO::PACMAN;
}

Arcade::PROTO choose_lib_page(std::string name)
{
    return Arcade::PROTO::SFML;
}

std::tuple<Arcade::PROTO, Arcade::PROTO> SFML::my_menu()
{
    bool running_menu = true;
    Arcade::PROTO game;
    Arcade::PROTO graph;
    _name = "player 1";
    sf::Texture text[5];
    sf::Sprite sprt[5];
    text[0].loadFromFile("assets/sfml/pacaman.jpg");
    sprt[0].setTexture(text[0]);
    sprt[0].setPosition(sf::Vector2f(100, 304));
    text[1].loadFromFile("assets/sfml/snake.png");
    sprt[1].setTexture(text[1]);
    sprt[1].setPosition(sf::Vector2f(600, 304));

    while (running_menu) {
        while (_window.pollEvent(_event)) {
            if (_event.key.code == sf::Keyboard::Enter) {
                running_menu = false;
            }
        }
        _window.clear();
        _window.draw(sprt[0]);
        _window.draw(sprt[1]);
        _window.display();
    }
    _window.close();
    game = choose_game_page(_name);
    graph = choose_game_page(_name);
    return std::make_tuple(game, graph);
}

std::string SFML::get_name()
{
    return _name;
}