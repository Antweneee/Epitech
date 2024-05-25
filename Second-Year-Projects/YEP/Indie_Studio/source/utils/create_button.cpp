/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-antoine.gavira-bottari
** File description:
** create_button
*/

#include "Button.hpp"
#include <iostream>

Button::Button(const std::string& name, float x, float y, float width, float height) : _width(width), _height(height)
{
    this->_textBox = this->_rect.initRectangle({.x = x, .y = y}, {.x = width, .y = height});
    this->_mouseOnButton = false;
    this->_btnAction = false;
    this->_btnState = 0;
    this->_textButton = name;
}

Button::~Button()
{

}

void Button::init()
{

}

void Button::drawSingleButtonOnHover(Color const &textcolor, int const textsize, Color const &color, Color const &onHover, int const paddingx, int const paddingy)
{
    if (getMouseOnButton()) {
        _rect.drawRectangleRec(getRectangle(), onHover);
    } else {
        _rect.drawRectangleRec(getRectangle(), color);
    }
    drawTextButton(getTextButton(), getRectangle().x + paddingx, (int)getRectangle().y + paddingy, textsize, textcolor);
}

void Button::drawTextButton(const std::string& name, float x, float y, int fontSize, Color textColor)
{
    this->_text.drawText(name.c_str(), {.x = x + (_width / 2) - (int)(name.length() * 10), .y = y + (_height / 5)}, fontSize, textColor);
}

void Button::drawButton(Color const &color, Color const textColor, int const textsize, int const paddingx, int const paddingy)
{
    _rect.drawRectangleRec(getRectangle(), color);
    drawTextButton(getTextButton(), getRectangle().x + paddingx, (int)getRectangle().y + paddingy, textsize, textColor);
}

void Button::drawButtons(std::vector<Button> button, Color color)
{
    for (auto& it : button)
        _rect.drawRectangleRec(it.getRectangle(), color);
}

void Button::drawButtonOnHover(std::vector<Button> button, Color color, int textsize, Color onHover)
{
    for (auto& it : button) {
        if (it.getMouseOnButton()) {
            this->_rect.drawRectangleRec(it.getRectangle(), onHover);
        }
        it.drawTextButton(it.getTextButton(), it.getRectangle().x, (int)it.getRectangle().y, textsize, color);
    }
}