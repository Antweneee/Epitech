/*
** EPITECH PROJECT, 2022
** B-YEP-410-PAR-4-1-zappy-thomas.willson
** File description:
** SettingsScene
*/

#ifndef SETTINGSSCENE_HPP_
    #define SETTINGSSCENE_HPP_

    #include "AScene.hpp"
    #include "Button.hpp"
    #include "keys.hpp"

enum SETTINGSMENU {
    PLUSBUTTON,
    MINUSBUTTON,
    RETURNBUTTON
};

class SettingsScene : public AScene {
    public:
        SettingsScene(std::shared_ptr<Settings> settings);
        ~SettingsScene();

        sf::RectangleShape getRectangleShape() const;
        std::vector<std::shared_ptr<Button>> getButtonList() const;

        void upgradeVolume();
        void downgradeVolume();
        void exitSettings();

        std::string updateSrting(std::string string, sf::Keyboard::Key &key);
    protected:
    private:
        sf::RectangleShape _rectangle;
        sf::Texture _textureButton;
        sf::Texture _texturePlus;
        sf::Texture _textureMinus;
        std::vector<std::shared_ptr<Button>> _buttons;
};

#endif /* !SETTINGSSCENE_HPP_ */