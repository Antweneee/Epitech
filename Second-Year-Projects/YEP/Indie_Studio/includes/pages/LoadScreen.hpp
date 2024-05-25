/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-antoine.gavira-bottari
** File description:
** LoadScreen
*/

#ifndef LOADSCREEN_HPP_
    #define LOADSCREEN_HPP_
    #include "IDisplay.hpp"
    #include "Button.hpp"
    #include "IInfo.hpp"
    #include <vector>
    #include <memory>
    #include "IDisplay.hpp"
    #include "Button.hpp"
    #include "Core.hpp"
    #include "Textures.hpp"
    #include "Audio.hpp"
    #include "Text.hpp"
    #include "Shapes.hpp"

class LoadScreen {
    public:
        LoadScreen();
        ~LoadScreen();
        void draw();
        void init();
        void unload();
        void clear();
        void refresh();
    protected:
    private:
        Core _core;
        Textures _textures;
        Texture2D _textureload;
        Text _text;
        int _counter = 0;
        int _data = 0;
        Audio _audio;
        Sound _clickButton;
        std::string _names;
};

#endif /* !LOADSCREEN_HPP_ */
