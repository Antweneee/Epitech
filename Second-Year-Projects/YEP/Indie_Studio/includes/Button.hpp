/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-antoine.gavira-bottari
** File description:
** Button
*/

#ifndef BUTTON_HPP_
    #define BUTTON_HPP_
    #include "Shapes.hpp"
    #include "Text.hpp"
    #include <raylib.h>
    #include <string>
    #include <vector>

class Button {
    public:
        Button(const std::string& name, float x, float y, float width, float height);
        Button() {};
        ~Button();
        void init();
        Rectangle getRectangle() const {return _textBox;}
        bool getMouseOnButton() const {return _mouseOnButton;}
        void setMouseOnButton(bool value) {this->_mouseOnButton = value;}
        bool getbtnAction() const {return _btnAction;}
        void setbtnAction(bool value) {this->_btnAction = value;}
        bool getbtnState() const {return _btnState;}
        void setbtnState(int state) {this->_btnState = state;}
        const std::string getTextButton() const {return _textButton;}
        void drawTextButton(const std::string& name, float x, float y, int fontSize, Color textColor);
        void drawButtons(std::vector<Button> button, Color color);
        void drawButton(Color const &color, Color const textColor, int const textsize, int const paddingx = 0, int const paddingy = 0);
        void drawButtonOnHover(std::vector<Button> button, Color color, int textsize, Color onHover);
        void drawSingleButtonOnHover(Color const &textcolor, int const textsize, Color const &color, Color const &onHover, int const paddingx = 0, int const paddingy = 0);
    protected:
    private:
        Shapes _rect;
        float _width;
        float _height;
        Text _text;
        Rectangle _textBox;
        bool _mouseOnButton;
        bool _btnAction;
        int _btnState;
        std::string _textButton;

};

#endif /* !BUTTON_HPP_ */
