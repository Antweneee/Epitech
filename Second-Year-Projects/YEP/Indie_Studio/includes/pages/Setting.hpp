/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-antoine.gavira-bottari
** File description:
** Setting
*/

#ifndef SETTING_HPP_
    #define SETTING_HPP_
    #include "IDisplay.hpp"
    #include "Button.hpp"
    #include "Core.hpp"
    #include "Textures.hpp"
    #include "Audio.hpp"
    #include "Text.hpp"
    #include "Shapes.hpp"

class Setting : public IDisplay {
    public:
        Setting();
        ~Setting();
        INDIE::KEYS get_key();
        void draw();
        void init();
        void unload();
        IInfo::GameScenes window_handler();
        void clear();
        void refresh();
        void isButtonPressed(std::vector<Button> button);
    protected:
        void pushButton(Button& button) {this->_btnVector.emplace_back(button);};
    private:
        void drawButton(std::vector<Button> button, Color color);
        void drawButtonOnHover(std::vector<Button> button, Color color, Color onHover);
        std::vector<Button> _btnVector;
        Rectangle _muteMusic;
        Rectangle _btnBounds;
        Texture2D _texture;
        int _btnState;
        bool _btnAction;
        Core _core;
        Textures _textures;
        Audio _audio;
        Text _text;
        Shapes _shapes;
        Texture2D _textureset;
        Button _soundButton;
        Shapes _rectan;
        Button _soundoffButton;
        Button _fpsminButton;
        Button _fpsmaxButton;
};

#endif /* !SETTING_HPP_ */
