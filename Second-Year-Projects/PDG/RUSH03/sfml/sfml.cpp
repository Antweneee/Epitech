/*
** EPITECH PROJECT, 2022
** B-PDG-300-PAR-3-1-PDGRUSH3-illyas.chihi
** File description:
** sfml
*/

#include "includes/sfml.hpp"

manip::manip(int x, int y)
{
    rect.setSize(sf::Vector2f(x, y));
}

manip::~manip()
{
}

void manip::bar(sf::RenderWindow *win, int use, int posx, int posy, int mul) //ex pourcentage du CPU utiliser
{
    sf::RectangleShape recta;

    recta.setSize(sf::Vector2f(use * mul, 30));
    recta.setOutlineColor(sf::Color::Black);
    rect.setOutlineColor(sf::Color::Black);
    rect.setFillColor(sf::Color::Transparent);
    if (use <= 25 || (use >= 100 && use <= 250))
        recta.setFillColor(sf::Color::Green);
    if ((use >= 25 && use <= 75) || (use >= 250 && use <= 750))
        recta.setFillColor(sf::Color::Yellow);
    if ((use >= 75 && use <= 100) || (use >= 750 && use <= 1000))
        recta.setFillColor(sf::Color::Red);
    recta.setOutlineThickness(2);
    rect.setOutlineThickness(2);
    recta.setPosition(posx, posy);
    rect.setPosition(posx, posy);
    win->draw(recta);
}
