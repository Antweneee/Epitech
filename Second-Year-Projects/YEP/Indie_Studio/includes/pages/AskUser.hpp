/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-antoine.gavira-bottari
** File description:
** AskUser
*/

#ifndef ASKUSER_HPP_
    #define ASKUSER_HPP_
    #include "Menu.hpp"
    #include "Shapes.hpp"
    #include "Core.hpp"
    #include "Text.hpp"

class AskUser : Menu {
    public:
        AskUser();
        ~AskUser();
        INDIE::KEYS get_key();
        void draw();
        void init();
        void unload();
        IInfo::GameScenes window_handler();
        void clear();
        void refresh();

    protected:
        void isButtonPressed(std::vector<Button> button);
        std::string getUserName() const {return this->_userName;};
        void setUserName(const std::string& userName) {this->_userName = userName;};
        bool getMouseOnText() const {return this->_mouseOnText;};
        void setMouseOnText(bool mouseOnText) {this->_mouseOnText = mouseOnText;};
        void pushButton(Button& button) {this->_btnplayVector.emplace_back(button);}
    private:
        void drawButton(std::vector<Button> button, Color color);
        void drawButtonOnHover(std::vector<Button> button, Color color, Color onHover);
        std::string _userName;
        std::size_t letterCount;
        int _framesCounter;
        bool _mouseOnText;
        Rectangle _textBox;
        Shapes _shapes;
        Core _core;
        Text _text;
        Shapes _rectan;
        std::vector<Button> _btnplayVector;
        Button _playButton;
        Texture2D _textureask;
};

#endif /* !ASKUSER_HPP_ */
