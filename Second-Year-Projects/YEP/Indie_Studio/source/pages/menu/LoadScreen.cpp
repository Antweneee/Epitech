/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-antoine.gavira-bottari
** File description:
** LoadScreen
*/

#include "LoadScreen.hpp"

LoadScreen::LoadScreen()
{
}

LoadScreen::~LoadScreen()
{
}


void LoadScreen::draw()
{
    _counter++;
    _core.beginDrawing();
        this->clear();
        _textures.drawTextureV(_textureload, {0, 0}, WHITE);
        _text.drawFPS({30, 30});

        _text.drawText(TextSubtext(_names.c_str(), 0, _counter/1), {140, 150}, 50, WHITE);
        if ((_counter/10)%2)
        this->_text.drawText(TextFormat("PRESS [B] TO GO TO THE MENU"), {500, 600}, 20, LIGHTGRAY);
       _core.endDrawing();
    if (_core.isKeyPressed(KEY_B)) {
        SCENES = IInfo::GameScenes::MENU;
        return;
    }
}

void LoadScreen::clear()
{
    this->_core.clearBackground(RAYWHITE);
}

void LoadScreen::init()
{
    this->_textureload = _textures.loadTexture("../assets/images/loading.png");
    this->_names = "Antoine GAVIRA ?????\nIllyas CHIHI Ravitailleur de Crasy Tiger\nInes-Lidya HADJADJ Dev full remote\nThomas WILSON Stagiaire (fait tout beuger)\nSilya NAÏT-ZERRAD LeadDev\nValoup FOUILLET Dev de Silya\n";
}

void LoadScreen::unload()
{
    _textures.unloadTexture(_textureload);
}

void LoadScreen::refresh()
{

}