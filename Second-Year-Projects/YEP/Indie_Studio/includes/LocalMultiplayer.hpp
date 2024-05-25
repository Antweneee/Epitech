/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-antoine.gavira-bottari
** File description:
** LocalMultiplayer
*/

#pragma once

    //#include "Player.hpp"
    #include <iostream>
    #include "Core.hpp"
    #include "Textures.hpp"
    #include "Button.hpp"
    #include "IDisplay.hpp"
    #include "PlayerSettings.hpp"

class LocalMultiplayer
{
    public:
        LocalMultiplayer();
        ~LocalMultiplayer();
        std::vector<PlayerSettings> draw();
        void init();
        void clear();

    private:
        void drawButton(Color const &color);
        void drawRect(Color const &color);
        void drawMyTexts();
        void drawMySpecialButtons(std::vector<Button> &vect, int pos);
        void actions();
        bool initiate_playersettings();
        bool myWarnings(int const nb, int const nbr, int const nb2);
        void getWindowPart();
        void prev_next_btn(int const i);
        void controller_type_action(int const i);
        int check_btn_states(int const x, std::string const &cmp1, std::string const &cmp2, std::string const &set1, std::string const &set2);

        std::vector<bool> _type;
        std::vector<bool> _controller;
        std::vector<Button>  _buttons;

        std::vector<PlayerSettings> _playersettings;
        //Texture2D _texture;
        Shapes _rect;
        //Textures _d_textures;
        Text _text;
        Core _core;
        int _window_part;
        std::string const controller;
        std::string const keyboard;
        int const p1;
        int const p2;
        int const p3;
        int const p4;
};
