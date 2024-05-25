/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-antoine.gavira-bottari
** File description:
** setting
*/

#include "Setting.hpp"
#include "Button.hpp"
#include <raylib.h>
#include <string>
#include <filesystem>
#include <iostream>

Setting::Setting()
{
    this->_soundButton = {"ON", 320, 175, 120, 50};
    this->_soundoffButton = {"OFF", 520, 175, 120, 50};
    this->_fpsminButton = {"30", 320, 375, 120, 50};
    this->_fpsmaxButton = {"60", 520, 375, 120, 50};
    this->pushButton(_fpsmaxButton);
    this->pushButton(_soundButton);
    this->pushButton(_fpsminButton);
    this->pushButton(_soundoffButton);
}

Setting::~Setting()
{
}

void Setting::init()
{
    this->_texture = _textures.loadTexture("../assets/images/activeSouns.png");
    this->_textureset = _textures.loadTexture("../assets/images/set.png");
    this->_muteMusic = { 0, 0, (float)_texture.width, (float)_texture.height};
    this->_btnBounds = { _core.getScreenWidth() / 2.0f - _texture.width / 2.0f, _core.getScreenHeight() / 2.0f - _texture.height / 2.0f, (float)_texture.width, (float)_texture.height};
    this->_btnState = 0;
    this->_btnAction = false;
}

INDIE::KEYS Setting::get_key()
{
    return INDIE::KEYS::B;
}

void Setting::draw()
{
    this->isButtonPressed(_btnVector);
    this->_core.setMouseCursor(MOUSE_CURSOR_DEFAULT);
    _core.beginDrawing();
        this->clear();
        _textures.drawTextureV(_textureset, {0, 0}, WHITE);
        _text.drawFPS({30, 30});
        this->_text.drawText(TextFormat("PRESS [B] TO GO BACK TO MENU"), {920, 640}, 20, GOLD);
        this->_text.drawText(TextFormat("GAME SETTINGS"), {60, 60}, 20, WHITE);
        this->_text.drawText(TextFormat("AUDIO"), {160, 190}, 25, WHITE);
        this->_text.drawText(TextFormat("FPS"), {160, 390}, 25, WHITE);
        this->_soundButton.drawButtons(_btnVector, DARKGRAY);
        this->_soundButton.drawButtonOnHover(_btnVector, BLACK, 40, GOLD);
        this->_soundoffButton.drawButtons(_btnVector, DARKGRAY);
        this->_soundoffButton.drawButtonOnHover(_btnVector, BLACK, 40, GOLD);
        this->_fpsminButton.drawButtons(_btnVector, DARKGRAY);
        this->_fpsminButton.drawButtonOnHover(_btnVector, BLACK, 40, GOLD);
        this->_fpsmaxButton.drawButtons(_btnVector, DARKGRAY);
        this->_fpsmaxButton.drawButtonOnHover(_btnVector, BLACK, 40, GOLD);
    _core.endDrawing();
    if (_core.isKeyPressed(KEY_B)) {
        SCENES = IInfo::GameScenes::MENU;
        return;
    }
}

void Setting::unload()
{
    _textures.unloadTexture(_textureset);
}

IInfo::GameScenes Setting::window_handler()
{
    return IInfo::GameScenes::EXIT;
}

void Setting::clear()
{
    this->_core.clearBackground(RAYWHITE);
}

void Setting::refresh()
{
}

void Setting::drawButton(std::vector<Button> button, Color color)
{
    for (int i = 0; i < (int)button.size(); i++)
        this->_rectan.drawRectangleRec(button[i].getRectangle(), color);
}

void Setting::isButtonPressed(std::vector<Button> button)
{
    for (int i = 0; i < (int)button.size(); i++) {
        if (_shapes.checkCollisionPointRec(GetMousePosition(), _btnBounds)) {
        if (_core.isMouseButtonDown(MOUSE_BUTTON_LEFT))
            _btnState = 2;
        else
            _btnState = 1;

        if (_core.isMouseButtonReleased(MOUSE_BUTTON_LEFT))
            _btnAction = true;
    } else
        _btnState = 0;
    if (this->_rectan.checkCollisionPointRec({.x = GetMousePosition().x, .y = GetMousePosition().y}, _btnVector[i].getRectangle())) {
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
            if (!_btnVector[i].getTextButton().compare("ON")) {
                //ici activer le son
                _btnVector[i].setbtnAction(0);
            }
        if (_btnVector[i].getbtnAction()) {
            if (!_btnVector[i].getTextButton().compare("OFF")) {
                //ici activer le son
                _btnVector[i].setbtnAction(0);
            }
        }
        if (_btnVector[i].getbtnAction()) {
            if (!_btnVector[i].getTextButton().compare("30")) {
                FPS = 30;
                _core.setTargetFPS(FPS);
                _btnVector[i].setbtnAction(0);
            }
        if (_btnVector[i].getbtnAction()) {
            if (!_btnVector[i].getTextButton().compare("60")) {
                FPS = 60;
                _core.setTargetFPS(FPS);
                _btnVector[i].setbtnAction(0);
            }
        }
        }
    }
}
}