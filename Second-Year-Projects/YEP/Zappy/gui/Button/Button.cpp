/*
** EPITECH PROJECT, 2022
** B-YEP-410-PAR-4-1-zappy-thomas.willson
** File description:
** Button
*/

#include "Button.hpp"

Button::Button(int id, std::shared_ptr<sf::Texture> texture, std::pair<int, int> position, std::vector<std::function<void(void)>> callbacks)
{
    _id = id;
    _position = position;
    _status = DEFAULT;
    _callback = callbacks.at(0);

    _texture = texture;
    _sprite.setTexture(*_texture);
    _sprite.setPosition(position.first, position.second);
    _sprite.setScale(1, 1);


    // _text.setPosition(0, 0/*position.first + _texture->getSize().x / 2 - name.size() / 2, position.second + _texture->getSize().y / 2*/);
    // std::cout << "B" << std::endl;
    // _text.setString(name);
    // _text.setFillColor(sf::Color::Black);
    // _text.setFont(font);
    // _text.setCharacterSize(20);
}

Button::~Button()
{
}

int Button::getId() const
{
    return _id;
}

void Button::setPosition(std::pair<int, int> position)
{
    _position = position;
}

std::pair<int, int> Button::getPosition() const
{
    return _position;
}

void Button::setStatus(Button::STATUS status)
{
    _status = status;
}

Button::STATUS Button::getStatus() const
{
    return _status;
}

void Button::draw()
{
    // _window->draw(_sprite);
    // _window->draw(_text);
}

bool Button::isMouseOverButton(std::pair<int, int> mousePosition) {
    unsigned int mousePositionX = mousePosition.first;
    unsigned int mousePositionY = mousePosition.second;
    unsigned int posX = _position.first;
    unsigned int posY = _position.second + 20;

    if (mousePositionX >= posX && mousePositionX <= _position.first + _texture->getSize().x && mousePositionY >= posY && mousePositionY <= _position.second + _texture->getSize().y + 20) {
        if (_status != SELECTED) {
            _status = MOUSEOVER;
        }
        return true;
    }
    _status = DEFAULT;
    return false;
}

void Button::onclick(std::pair<int, int> mousePosition)
{
    if (isMouseOverButton(mousePosition)) {
        _status = SELECTED;
        _callback();
    }
}

sf::Sprite Button::getSprite() const
{
    return _sprite;
}


// void Graphic::printText(int id, const Text &text)
// {
//     _textMap.at(id).setPosition(text.getPosition().x, text.getPosition().y);
//     sf::Font font;

//     if (!text.getFontFile().empty()) {
//         if (!font.loadFromFile(text.getFontFile()))
//             std::cout << "Couldn't find font" << std::endl;

//         _textMap.at(id).setFont(font);
//     }

//     _textMap.at(id).setString(text.getText());
//     _textMap.at(id).setFont(font);
//     _textMap.at(id).setCharacterSize(text.getFontSize());

//     _window.draw(_textMap.at(id));
// }

// void Graphic::setTextsMap(const std::map<int, Text> &textsMap)
// {
//     for (auto iterator = textsMap.begin(); iterator != textsMap.end(); iterator++) {
//         sf::Text text;

//         _textMap.insert({iterator->first, text});
//     }
// }