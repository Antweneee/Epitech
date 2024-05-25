/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-antoine.gavira-bottari
** File description:
** score
*/

#include "Score.hpp"
#include <string>
#include <vector>

Score::Score()
{
    this->_highScore = 43230;
    this->_secondScore = 31890;
    this->_thirdScore = 1899;
    this->_firstPlayer = "Silya";
    this->_secondPlayer = "Inès";
    this->_thirdPlayer = "Catalina";
}

Score::~Score()
{

}

INDIE::KEYS Score::get_key()
{
    return INDIE::KEYS::NIL;
}

void Score::draw()
{
    BeginDrawing();
        this->clear();
        _shapes.drawTriangle({200, 20}, {20, 200}, {20, 20}, BLUE);
        _textures.drawTextureV(_texturescore, {0, 0}, WHITE);
        _text.drawFPS({30, 30});
        this->_text.drawText(TextFormat("GAME SCORES"), {.x = 60, .y = 60}, 20, WHITE);
        this->_text.drawText(TextFormat("PRESS [B] TO GO BACK TO MENU"), {.x = 920, .y = 640}, 20, GOLD);
        this->_text.drawText(TextFormat("SECOND PLAYER: %s => %d", _secondPlayer.c_str(), _secondScore),{.x = 320, .y = 270}, 50, MAROON);
        this->_text.drawText(TextFormat("BEST PLAYER: %s => %d", _firstPlayer.c_str(), _highScore), {.x = 410, .y = 350}, 50, RED);
        this->_text.drawText(TextFormat("THIRD PLAYER: %s => %d", _thirdPlayer.c_str(), _thirdScore), {.x = 320, .y = 430}, 50, MAROON);
    _core.endDrawing();
    if (_core.isKeyPressed(KEY_B)) {
        SCENES = IInfo::GameScenes::MENU;
        return;
    }
}

void Score::init()
{
    this->_texturescore= LoadTexture("../assets/images/set.png");
}

void Score::unload()
{
    _textures.unloadTexture(_texturescore);
}

IInfo::GameScenes Score::window_handler()
{
    return IInfo::GameScenes::EXIT;
}

void Score::clear()
{
    this->_core.clearBackground(RAYWHITE);
}

void Score::refresh()
{

}
