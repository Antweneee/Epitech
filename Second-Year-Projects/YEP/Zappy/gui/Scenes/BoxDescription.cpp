/*
** EPITECH PROJECT, 2022
** B-YEP-410-PAR-4-1-zappy-thomas.willson
** File description:
** BoxDescription
*/

#include "BoxDescription.hpp"

BoxDescription::BoxDescription()
{
    if (!_boxTexture.loadFromFile("gui/assets/boxDescription.png"))
        std::cerr << "Error(s): while loading texture from file gui/assets/boxDescription.png" << std::endl;
    _boxSprite.setTexture(_boxTexture);

    if (!_deraumereTexture.loadFromFile("gui/assets/ressources/deraumere.png"))
        std::cerr << "Error(s): while loading texture from file gui/assets/ressources/deraumere.png" << std::endl;
    _deraumereSprite.setTexture(_deraumereTexture);

    if (!_foodTexture.loadFromFile("gui/assets/ressources/food.png"))
        std::cerr << "Error(s): while loading texture from file gui/assets/ressources/food.png" << std::endl;
    _foodSprite.setTexture(_foodTexture);

    if (!_linemateTexture.loadFromFile("gui/assets/ressources/linemate.png"))
        std::cerr << "Error(s): while loading texture from file gui/assets/ressources/linemate.png" << std::endl;
    _linemateSprite.setTexture(_linemateTexture);

    if (!_mendianeTexture.loadFromFile("gui/assets/ressources/mendiane.png"))
        std::cerr << "Error(s): while loading texture from file gui/assets/ressources/mendiane.png" << std::endl;
    _mendianeSprite.setTexture(_mendianeTexture);

    if (!_phirasTexture.loadFromFile("gui/assets/ressources/phiras.png"))
        std::cerr << "Error(s): while loading texture from file gui/assets/ressources/phiras.png" << std::endl;
    _phirasSprite.setTexture(_phirasTexture);

    if (!_siburTexture.loadFromFile("gui/assets/ressources/sibur.png"))
        std::cerr << "Error(s): while loading texture from file gui/assets/ressources/sibur.png" << std::endl;
    _siburSprite.setTexture(_siburTexture);

    if (!_thystameTexture.loadFromFile("gui/assets/ressources/thystame.png"))
        std::cerr << "Error(s): while loading texture from file gui/assets/ressources/thystame.png" << std::endl;
    _thystameSprite.setTexture(_thystameTexture);

    // _sprites["deraumere"]->setPosition(80, 180);
    // _sprites["food"]->setPosition(180, 180);
    // _sprites["linemate"]->setPosition(280, 180);
    // _sprites["mendiane"]->setPosition(380, 180);
    // _sprites["phiras"]->setPosition(480, 180);
    // _sprites["sibur"]->setPosition(580, 180);
    // _sprites["thystame"]->setPosition(680, 180);
}

BoxDescription::~BoxDescription()
{

}

sf::Sprite BoxDescription::getBoxSprite() const
{
    return _boxSprite;
}

void BoxDescription::setPosBoxSprite(sf::Vector2f pos)
{
    _boxSprite.setPosition(pos);
}

sf::Sprite BoxDescription::getDeraumereSprite() const
{
    return _deraumereSprite;
}

sf::Sprite BoxDescription::getFoodSprite() const
{
    return _foodSprite;
}

sf::Sprite BoxDescription::getLinemateSprite() const
{
    return _linemateSprite;
}

sf::Sprite BoxDescription::getMendianeSprite() const
{
    return _mendianeSprite;
}

sf::Sprite BoxDescription::getPhirasSprite() const
{
    return _phirasSprite;
}

sf::Sprite BoxDescription::getSiburSprite() const
{
    return _siburSprite;
}

sf::Sprite BoxDescription::getThystameSprite() const
{
    return _thystameSprite;
}

void BoxDescription::setPosMapSprite(std::vector<std::pair<int, int>> positions)
{
    _deraumereSprite.setPosition(positions.at(0).first, positions.at(0).second);
    _foodSprite.setPosition(positions.at(1).first, positions.at(1).second);
    _linemateSprite.setPosition(positions.at(2).first, positions.at(2).second);
    _mendianeSprite.setPosition(positions.at(3).first, positions.at(3).second);
    _phirasSprite.setPosition(positions.at(4).first, positions.at(4).second);
    _siburSprite.setPosition(positions.at(5).first, positions.at(5).second);
    _thystameSprite.setPosition(positions.at(6).first, positions.at(6).second);
}