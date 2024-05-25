/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-antoine.gavira-bottari
** File description:
** SecondMenu
*/

#ifndef SECONDMENU_HPP_
    #define SECONDMENU_HPP_
    #include "Menu.hpp"
    #include "Button.hpp"
    #include "Text.hpp"
    #include "Core.hpp"
    #include "Textures.hpp"
    #include "Audio.hpp"

class SecondMenu : public Menu {
    public:
        SecondMenu();
        ~SecondMenu();
        INDIE::KEYS get_key();
        void draw();
        void init();
        IInfo::GameScenes window_handler();
        void clear();
        void refresh();
        void unload();
        void drawButton(std::vector<Button> button, Color color);
        void drawButtonOnHover(std::vector<Button> button, Color color, Color onHover);
    protected:
        void isButtonPressed(std::vector<Button> button);
        void pushButton(Button& button) {this->_btnVector.emplace_back(button);};
    private:
        std::vector<Button> _btnVector;
        Button _loadPartyButton;
        Button _createPartyButton;
        Shapes _rect;
        Text _text;
        Core _core;
        Textures _textures;
        Audio _audio;
        Sound _clickButton;
        Texture2D _texturemen;
};

#endif /* !SECONDMENU_HPP_ */
