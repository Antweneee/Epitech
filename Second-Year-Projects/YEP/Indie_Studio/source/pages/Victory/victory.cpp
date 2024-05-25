/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-antoine.gavira-bottari
** File description:
** victory
*/

#include "VictoryScreen.hpp"
#include "Button.hpp"
#include "Parser.hpp"
#include <raylib.h>
#include <string>
#include <iostream>


VictoryScreen::VictoryScreen()
{
    Parser_Json parser("../config/victory.json");
    std::map<std::string, std::string> infos;

    infos = parser.get_info_from_file("quit_game");
    _quitGame = {infos["title"], std::stof(infos["pos_x"]), std::stof(infos["pos_y"]), std::stof(infos["width"]),std::stof(infos["height"])};
    this->pushButton(_quitGame);
}

VictoryScreen::~VictoryScreen()
{
    //this->_audio.unloadSound(_clickButton);
    //this->_audio.closeAudioDevice();
}

INDIE::KEYS VictoryScreen::get_key()
{
    return INDIE::KEYS::B;
}

void VictoryScreen::draw(bool is_win)
{
    Parser_Json parser("../config/scores.json");
    std::map<std::string, std::string> infos;

    _counter++;
    this->isButtonPressed(_btnVector);
    _core.beginDrawing();
        this->clear();
        _textures.drawTextureV(_texturecs, {0, 0}, WHITE);
        infos = parser.get_info_from_file("first");
        _text.drawText(infos["lifespan"], {450, 100}, 30, RED);
        infos = parser.get_info_from_file("second");
        _text.drawText(infos["lifespan"], {450, 200}, 30, RED);
        infos = parser.get_info_from_file("third");
        _text.drawText(infos["lifespan"], {450, 300}, 30, RED);
        infos = parser.get_info_from_file("fourth");
        _text.drawText(infos["lifespan"], {450, 40}, 30, RED);
        _text.drawFPS({30, 30});
        if (is_win)
            _text.drawText(_text.textSubtext(_message.c_str(), 0, _counter / 3), {410, 600}, 70, GREEN);
        else
            _text.drawText(_text.textSubtext(_lose.c_str(), 0, _counter / 3), {410, 600}, 70, RED);
        this->_quitGame.drawButtons(_btnVector, DARKGRAY);
        this->_quitGame.drawButtonOnHover(_btnVector, BLACK, 40, GOLD);
    _core.endDrawing();
}

void VictoryScreen::init()
{
    this->_message = "V I C T O R Y";
    this->_lose = "D E F E A T";
    this->_texturecs = _textures.loadTexture("../assets/images/win_screen.png");
    _core.setTargetFPS(15);
}

void VictoryScreen::unload()
{
    _textures.unloadTexture(_texturecs);
}

IInfo::GameScenes VictoryScreen::window_handler()
{
    return IInfo::GameScenes::MENU;
}

void VictoryScreen::clear()
{
    this->_core.clearBackground(RAYWHITE);
}

void VictoryScreen::refresh()
{

}

void VictoryScreen::drawButton(std::vector<Button> button, Color color)
{
    for (auto& it : button)
        this->_rect.drawRectangleRec(it.getRectangle(), color);
}

void VictoryScreen::drawButtonOnHover(std::vector<Button> button, Color color, Color onHover)
{
    for (auto& it : button) {
        if (it.getMouseOnButton()) {
            this->_rect.drawRectangleRec(it.getRectangle(), onHover);
        }
        it.drawTextButton(it.getTextButton(), it.getRectangle().x, (int)it.getRectangle().y, 40, color);
    }
}

void VictoryScreen::isButtonPressed(std::vector<Button> button)
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
            //this->_audio.playSound(_clickButton);
            if (!_btnVector[i].getTextButton().compare("Quit")) {
                std::exit(0);
            }
        }
    }
}