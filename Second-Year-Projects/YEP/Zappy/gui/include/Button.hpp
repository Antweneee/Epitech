/*
** EPITECH PROJECT, 2022
** B-YEP-410-PAR-4-1-zappy-thomas.willson
** File description:
** Button
*/

#ifndef BUTTON_HPP_
    #define BUTTON_HPP_

    #include <utility>
    #include <string>
    #include <iostream>
    #include <memory>
    #include <functional>

    #include "Settings.hpp"

class Button {
    enum STATUS {
        DEFAULT,
        MOUSEOVER,
        SELECTED
    };
    public:
        Button(int id, std::shared_ptr<sf::Texture> texture, std::pair<int, int> position, std::vector<std::function<void(void)>> callbacks);
        ~Button();

        int getId() const;

        void setPosition(std::pair<int, int> position);
        std::pair<int, int> getPosition() const;

        void setStatus(Button::STATUS status);
        Button::STATUS getStatus() const;

        void draw();

        bool isMouseOverButton(std::pair<int, int> mousePosition);

        void onclick(std::pair<int, int> mousePosition);

        sf::Sprite getSprite() const;

    protected:
    private:
        int _id;
        Button::STATUS _status;
        std::pair<int, int> _position;
        std::shared_ptr<sf::Texture> _texture;
        sf::Sprite _sprite;
        std::function<void(void)> _callback;
};

#endif /* !BUTTON_HPP_ */