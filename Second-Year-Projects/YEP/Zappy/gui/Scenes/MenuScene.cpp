/*
** EPITECH PROJECT, 2022
** B-YEP-410-PAR-4-1-zappy-thomas.willson
** File description:
** MenuScene
*/

#include "MenuScene.hpp"

MenuScene::MenuScene(std::shared_ptr<Settings> settings) : AScene(settings)
{
    if (!_textureSunny.loadFromFile("gui/assets/menu/sunny.png"))
        std::cerr << "Error(s): while loading texture from file gui/assets/menu/sunny.png" << std::endl;
    _spriteSunny.setTexture(_textureSunny);

    if (!_textureSky.loadFromFile("gui/assets/menu/sky.png"))
        std::cerr << "Error(s): while loading texture from file gui/assets/menu/sky.png" << std::endl;
    _spriteSky.setTexture(_textureSky);

    if (!_textureButton.loadFromFile("gui/assets/menu/button.png"))
        std::cerr << "Error(s): while loading texture from file gui/assets/menu/button.png" << std::endl;
    _buttons.push_back(std::make_unique<Button>(0, std::make_shared<sf::Texture>(_textureButton), std::make_pair(871, 360), std::vector<std::function<void(void)>>{std::bind(&MenuScene::startScene, this)}));
    _buttons.push_back(std::make_unique<Button>(1, std::make_shared<sf::Texture>(_textureButton), std::make_pair(871, 540), std::vector<std::function<void(void)>>{std::bind(&MenuScene::settingsScene, this)}));
    _buttons.push_back(std::make_unique<Button>(2, std::make_shared<sf::Texture>(_textureButton), std::make_pair(871, 720), std::vector<std::function<void(void)>>{std::bind(&MenuScene::exitScene, this)}));
}

MenuScene::~MenuScene()
{
}

sf::Sprite MenuScene::getSkySprite() const
{
    return _spriteSky;
}

sf::Sprite MenuScene::getSunnySprite() const
{
    return _spriteSunny;
}

std::vector<std::shared_ptr<Button>> MenuScene::getButtonList() const
{
    return _buttons;
}

void MenuScene::exitScene()
{
    _settings->setScene(Scenes::QUIT);
}

void MenuScene::startScene()
{
    _settings->setScene(Scenes::GAME);
}

void MenuScene::settingsScene()
{
    std::cout << "setting scene" << std::endl;
    _settings->setScene(Scenes::SETTINGS);
}