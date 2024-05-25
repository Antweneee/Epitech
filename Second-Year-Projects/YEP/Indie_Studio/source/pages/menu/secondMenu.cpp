/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-antoine.gavira-bottari
** File description:
** secondMenu
*/

#include "SecondMenu.hpp"
#include "LoadGame.hpp"

SecondMenu::SecondMenu()
{
    this->_createPartyButton = {"Create new party", 175, 315, 435, 70};
    this->_loadPartyButton = {"Load save party", 655, 315, 435, 70};
    this->pushButton(_loadPartyButton);
    this->pushButton(_createPartyButton);
}

SecondMenu::~SecondMenu()
{
    //this->_audio.unloadSound(_clickButton);
    //this->_audio.closeAudioDevice();
}

INDIE::KEYS SecondMenu::get_key()
{
    if (_core.isKeyPressed(KEY_B)) {
        SCENES = IInfo::GameScenes::MENU;
        return INDIE::KEYS::B;
    }
    return INDIE::KEYS::B;
}

void SecondMenu::draw()
{
    this->isButtonPressed(_btnVector);
    this->_core.setMouseCursor(MOUSE_CURSOR_DEFAULT);
    _core.beginDrawing();
        this->clear();
        _textures.drawTextureV(_texturemen, {0, 0}, WHITE);
        _text.drawFPS({30, 30});
        this->_text.drawText(TextFormat("PRESS [B] TO GO BACK TO MENU"), {920, 640}, 20, GOLD);
        this->_text.drawText(TextFormat("SELECT AN OPTION"), {60, 60}, 23, WHITE);
        this->_createPartyButton.drawButtons(_btnVector, DARKGRAY);
        this->_createPartyButton.drawButtonOnHover(_btnVector, BLACK, 40, GOLD);
    _core.endDrawing();
    if (this->get_key() == INDIE::KEYS::B) {
        return;
    }
}

void SecondMenu::init()
{
   this->_texturemen = _textures.loadTexture("../assets/images/secmenue.png");
}

void SecondMenu::unload()
{
    _textures.unloadTexture(_texturemen);
}

IInfo::GameScenes SecondMenu::window_handler()
{
    return IInfo::GameScenes::EXIT;
}

void SecondMenu::clear()
{
    _core.clearBackground(RAYWHITE);
}

void SecondMenu::refresh()
{

}

void SecondMenu::drawButton(std::vector<Button> button, Color color)
{
    for (int i = 0; i < (int)button.size(); i++)
        this->_rect.drawRectangleRec(button[i].getRectangle(), color);
}

void SecondMenu::drawButtonOnHover(std::vector<Button> button, Color color,  Color onHover)
{
    for (int i = 0; i < (int)button.size(); i++) {
        if (button[i].getMouseOnButton()) {
            this->_rect.drawRectangleRec(button[i].getRectangle(), onHover);
        }
        else
            button[i].drawTextButton(button[i].getTextButton(), button[i].getRectangle().x, button[i].getRectangle().y, 35, color);
    }
}

void SecondMenu::isButtonPressed(std::vector<Button> button)
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
            if (!_btnVector[i].getTextButton().compare("Create new party")) {
                SCENES = IInfo::GameScenes::SELECT_PLAYERS;
                _btnVector[i].setbtnAction(0);
            }
            if (!_btnVector[i].getTextButton().compare("Load save party")) {
                SCENES = IInfo::GameScenes::LOAD_PARTY;
                _btnVector[i].setbtnAction(0);
            }
        }
    }
}