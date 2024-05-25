/*
** EPITECH PROJECT, 2022
** B-YEP-410-PAR-4-1-zappy-thomas.willson
** File description:
** MenuScene
*/

#ifndef MENUSCENE_HPP_
    #define MENUSCENE_HPP_

    #include <vector>
    #include "Button.hpp"
    #include "AScene.hpp"

enum BUTTONMENU {
    STARTBUTTON,
    SETTINGSBUTTON,
    EXITBUTTON
};

class MenuScene : public AScene {
    public:
        MenuScene(std::shared_ptr<Settings> settings);
        ~MenuScene();

        sf::Sprite getSkySprite() const;
        sf::Sprite getSunnySprite() const;
        std::vector<std::shared_ptr<Button>> getButtonList() const;

    protected:
    private:
        void exitScene();
        void startScene();
        void settingsScene();

        sf::Texture _textureSky;
        sf::Sprite _spriteSky;
        sf::Texture _textureSunny;
        sf::Sprite _spriteSunny;
        sf::Texture _textureButton;
        std::vector<std::shared_ptr<Button>> _buttons;
};

#endif /* !MENUSCENE_HPP_ */