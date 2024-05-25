/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-antoine.gavira-bottari
** File description:
** AnimScreen
*/

#include "AnimScreen.hpp"
#include "Button.hpp"
#include <raylib.h>
#include "Parser.hpp"
#include <string>
#include <filesystem>
#include <iostream>

AnimScreen::AnimScreen()
{
}

AnimScreen::~AnimScreen()
{
}

void AnimScreen::draw()
{
   _counter++;
    _core.beginDrawing();
    this->clear();
    _textures.drawTextureV(_textureAnim, {0, 0}, WHITE);
    _text.drawText(_text.textSubtext(_message.c_str(), 0, _counter/3), {450, 320}, 70, BLACK);
    if ((_counter/10)%2)
        this->_text.drawText(TextFormat("PRESS [B] TO CONTINUE"), {500, 600}, 20, LIGHTGRAY);
    _core.endDrawing();
    if (_core.isKeyPressed(KEY_B)) {
        PlaySound(_btnsound);
        SCENES = IInfo::GameScenes::LOAD_SCREEN;
        return;
    }
}

void AnimScreen::clear()
{
    this->_core.clearBackground(RAYWHITE);
}

void AnimScreen::init()
{
    InitAudioDevice();
    this->_csmus = _audio.loadSound("../assets/sounds/csmus.ogg");
    this->_btnsound = _audio.loadSound("../assets/sounds/button_effect.wav");
    _audio.playSound(_csmus);
    this->_message = "V A L V E";
    this->_textureAnim = _textures.loadTexture("../assets/images/start.png");
}

void AnimScreen::unload()
{
    _textures.unloadTexture(_textureAnim);
    _audio.unloadSound(_csmus);
    _audio.unloadSound(_btnsound);
}

void AnimScreen::refresh()
{

}
