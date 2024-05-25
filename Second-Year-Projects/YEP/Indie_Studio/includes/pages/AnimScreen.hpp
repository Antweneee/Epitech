/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-antoine.gavira-bottari
** File description:
** AnimScreen
*/

#ifndef ANIMSCREEN_HPP_
    #define ANIMSCREEN_HPP_
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

class AnimScreen {
    public:
        AnimScreen();
        ~AnimScreen();
        void draw();
        void init();
        void unload();
        void clear();
        void refresh();

    protected:
    private:
        Core _core;
        Textures _textures;
        Texture2D _textureAnim;
        Text _text;
        std::string _message;
        int _counter = 0;
        Sound _csmus;
        Sound _btnsound;
        Audio _audio;
};

#endif /* !ANIMSCREEN_HPP_ */
