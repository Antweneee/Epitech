/*
** EPITECH PROJECT, 2022
** B-YEP-410-PAR-4-1-zappy-thomas.willson
** File description:
** SettingsScene
*/

#include "SettingsScene.hpp"

SettingsScene::SettingsScene(std::shared_ptr<Settings> settings) : AScene(settings), _rectangle(sf::Vector2f(1440, 810))
{
    _rectangle.setPosition(250, 150);
    _rectangle.setFillColor(sf::Color::Blue);

    if (!_textureButton.loadFromFile("gui/assets/menu/button.png"))
        std::cerr << "Error(s): while loading texture from file gui/assets/menu/button.png" << std::endl;
    if (!_texturePlus.loadFromFile("gui/assets/menu/plusButton.png"))
        std::cerr << "Error(s): while loading texture from file gui/assets/menu/plusButton.png" << std::endl;
    if (!_textureMinus.loadFromFile("gui/assets/menu/minusButton.png"))
        std::cerr << "Error(s): while loading texture from file gui/assets/menu/minusButton.png" << std::endl;
    _buttons.push_back(std::make_unique<Button>(0, std::make_shared<sf::Texture>(_texturePlus), std::make_pair(1106, 360), std::vector<std::function<void(void)>>{std::bind(&SettingsScene::upgradeVolume, this)}));
    _buttons.push_back(std::make_unique<Button>(1, std::make_shared<sf::Texture>(_textureMinus), std::make_pair(806, 360), std::vector<std::function<void(void)>>{std::bind(&SettingsScene::downgradeVolume, this)}));
    _buttons.push_back(std::make_unique<Button>(2, std::make_shared<sf::Texture>(_textureButton), std::make_pair(260, 880), std::vector<std::function<void(void)>>{std::bind(&SettingsScene::exitSettings, this)}));
    for (auto &music : _settings->getMusicList()) {
        music->setVolume(_settings->getVolume());
    }
}

SettingsScene::~SettingsScene()
{
}

sf::RectangleShape SettingsScene::getRectangleShape() const
{
    return _rectangle;
}

std::vector<std::shared_ptr<Button>> SettingsScene::getButtonList() const
{
    return _buttons;
}

void SettingsScene::upgradeVolume()
{
    float volume = _settings->getVolume() + 10;

    if (volume > 100)
        volume = 100.0;
    _settings->setVolume(volume);
    for (auto &music : _settings->getMusicList()) {
        music->setVolume(volume);
    }
}

void SettingsScene::downgradeVolume()
{
    float volume = _settings->getVolume() - 10;

    if (volume < 0.0)
        volume = 0.0;
    _settings->setVolume(volume);
    for (auto &music : _settings->getMusicList()) {
        music->setVolume(volume);
    }
}

void SettingsScene::exitSettings()
{
    _settings->setScene(Scenes::MENU);
}

std::string SettingsScene::updateSrting(std::string string, sf::Keyboard::Key &key)
{
    std::string delim = ".";

    if (key >= sf::Keyboard::Key::A && key <= sf::Keyboard::Key::Z)
        string += (key + 'a');
    if (key >= sf::Keyboard::Key::Num0 && key <= sf::Keyboard::Key::Num9)
        string += (key - 26 + '0');
    if (key == sf::Keyboard::Key::Backspace && !string.empty())
        string = string.erase(string.size() - 1);
    if (key == sf::Keyboard::Key::Space)
        string += delim;
    return string;
}