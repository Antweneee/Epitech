/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-antoine.gavira-bottari
** File description:
** MainMenu
*/

#ifndef MAINMENU_HPP_
    #define MAINMENU_HPP_
    #include "Menu.hpp"
    #include "Score.hpp"
    #include "Shapes.hpp"
    #include "Text.hpp"
    #include "Audio.hpp"
    #include "Core.hpp"

class MainMenu : public Menu {
    public:
        MainMenu();
        ~MainMenu();
        INDIE::KEYS get_key();
        void draw();
        void init();
        IInfo::GameScenes window_handler();
        void clear();
        void refresh();
        void unload();
        void isButtonPressed(std::vector<Button> button);
        void drawButton(std::vector<Button> button, Color color);
        void drawButtonOnHover(std::vector<Button> button, Color color, Color onHover);
    protected:
        void pushButton(Button& button) {this->_btnVector.emplace_back(button);};
    private:
        std::vector<Button> _btnVector;
        Button _playButton;
        Button _exitButton;
        Button _settingButton;
        Button _scoreButton;
        Shapes _rect;
        Text _text;
        Textures _textures;
        Core _core;
        Audio _audio;
        //Sound _clickButton;
};

#endif /* !MAINMENU_HPP_ */
