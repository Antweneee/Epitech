/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-antoine.gavira-bottari
** File description:
** VictoryScreen
*/

#ifndef VICTORYSCREEN_HPP_
    #define VICTORYSCREEN_HPP_
    #include "Menu.hpp"
    #include "Shapes.hpp"
    #include "Textures.hpp"
    #include "Text.hpp"
    #include "Core.hpp"
    #include "Audio.hpp"

class VictoryScreen  : public Menu {
    public:
        VictoryScreen();
        ~VictoryScreen();
        INDIE::KEYS get_key();
        void draw(bool is_win);
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
        std::string _message;
        std::string _lose;
        std::vector<Button> _btnVector;
        Button _quitGame;
        Shapes _rect;
        Text _text;
        Textures _textures;
        Core _core;
        Audio _audio;
        int _counter = 0;

    protected:
    private:
};

#endif /* !VICTORYSCREEN_HPP_ */
