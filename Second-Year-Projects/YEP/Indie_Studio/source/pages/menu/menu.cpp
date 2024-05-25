/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-antoine.gavira-bottari
** File description:
** menu
*/

#include "MainMenu.hpp"
#include "Button.hpp"
#include "Parser.hpp"
#include <raylib.h>
#include <string>
#include <iostream>


MainMenu::MainMenu()
{
    Parser_Json parser("../config/menu.json");
    std::map<std::string, std::string> infos;

    infos = parser.get_info_from_file("play_button");
    _playButton = {infos["title"], std::stof(infos["pos_x"]), std::stof(infos["pos_y"]), std::stof(infos["width"]),std::stof(infos["height"])};
    infos = parser.get_info_from_file("score_button");
    _scoreButton = {infos["title"], std::stof(infos["pos_x"]), std::stof(infos["pos_y"]), std::stof(infos["width"]),std::stof(infos["height"])};
    infos = parser.get_info_from_file("setting_button");
    _settingButton = {infos["title"], std::stof(infos["pos_x"]), std::stof(infos["pos_y"]), std::stof(infos["width"]),std::stof(infos["height"])};
    infos = parser.get_info_from_file("exit_button");
    _exitButton = {infos["title"], std::stof(infos["pos_x"]), std::stof(infos["pos_y"]), std::stof(infos["width"]),std::stof(infos["height"])};
    this->pushButton(_playButton);
    this->pushButton(_scoreButton);
    this->pushButton(_settingButton);
    this->pushButton(_exitButton);
}

MainMenu::~MainMenu()
{
    //this->_audio.unloadSound(_clickButton);
    //this->_audio.closeAudioDevice();
}

INDIE::KEYS MainMenu::get_key()
{
    return INDIE::KEYS::B;
}

void MainMenu::draw()
{
    this->isButtonPressed(_btnVector);
    this->_core.setMouseCursor(MOUSE_CURSOR_DEFAULT);
    _core.beginDrawing();
        this->clear();
        _textures.drawTextureV(_texturecs, {0, 0}, WHITE);
        _text.drawFPS({30, 30});
        this->_playButton.drawButtons(_btnVector, DARKGRAY);
        this->_playButton.drawButtonOnHover(_btnVector, BLACK, 40, GOLD);
    _core.endDrawing();
}

void MainMenu::init()
{
    this->_texturecs = _textures.loadTexture("../assets/images/cs.png");
    _core.setTargetFPS(FPS);

}

void MainMenu::unload()
{
    _textures.unloadTexture(_texturecs);
}

IInfo::GameScenes MainMenu::window_handler()
{
    return IInfo::GameScenes::MENU;
}

void MainMenu::clear()
{
    this->_core.clearBackground(RAYWHITE);
}

void MainMenu::refresh()
{

}

void MainMenu::drawButton(std::vector<Button> button, Color color)
{
    for (auto& it : button)
        this->_rect.drawRectangleRec(it.getRectangle(), color);
}

void MainMenu::drawButtonOnHover(std::vector<Button> button, Color color, Color onHover)
{
    for (auto& it : button) {
        if (it.getMouseOnButton()) {
            this->_rect.drawRectangleRec(it.getRectangle(), onHover);
        }
        it.drawTextButton(it.getTextButton(), it.getRectangle().x, (int)it.getRectangle().y, 40, color);
    }
}

void MainMenu::isButtonPressed(std::vector<Button> button)
{
    for (int i = 0; i < (int)button.size(); i++) {
        if (this->_rect.checkCollisionPointRec({GetMousePosition().x, GetMousePosition().y}, _btnVector[i].getRectangle())) {
            _btnVector[i].setMouseOnButton(true);
            if (this->_core.isMouseButtonDown(MOUSE_BUTTON_LEFT))
                _btnVector[i].setbtnState(2);
            else
                _btnVector[i].setbtnState(1);
            if (this->_core.isMouseButtonReleased(MOUSE_BUTTON_LEFT))
                _btnVector[i].setbtnAction(true);
            else
                _btnVector[i].setbtnAction(false);
        } else {
            _btnVector[i].setMouseOnButton(false);
            _btnVector[i].setbtnState(0);
        }
        if (_btnVector[i].getbtnAction()) {
            if (!_btnVector[i].getTextButton().compare("Play")) {
                SCENES = IInfo::GameScenes::PLAY;
                _btnVector[i].setbtnAction(0);
            }
            if (!_btnVector[i].getTextButton().compare("Scores")) {
                SCENES = IInfo::GameScenes::SCORES;
                _btnVector[i].setbtnAction(0);
            }
            if (!_btnVector[i].getTextButton().compare("Settings")) {
                SCENES = IInfo::GameScenes::SETTING;
                _btnVector[i].setbtnAction(0);
            }
            if (!_btnVector[i].getTextButton().compare("Exit")) {
                SCENES = IInfo::GameScenes::EXIT;
                _btnVector[i].setbtnAction(0);
            }
        }
    }
}