/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-antoine.gavira-bottari
** File description:
** askUser
*/

#include "AskUser.hpp"

AskUser::AskUser()
{
    this->_userName = "";
    this->letterCount = 0;
    this->_textBox = _shapes.initRectangle({.x = 1280 / 2.0f - 100, .y = 180}, {.x = 225, .y = 50});
    _playButton = {"Select your player", 420, 480, 440, 50};
    this->pushButton(_playButton);
}


AskUser::~AskUser()
{

}

INDIE::KEYS AskUser::get_key()
{
    return INDIE::KEYS::NIL;
}

void AskUser::draw()
{
    this->window_handler();
    BeginDrawing();
        this->clear();
        DrawTextureV(_textureask, {0, 0}, WHITE);
        this->_text.drawText("ENTER A USER NAME", {.x = 60, .y = 60}, 23, WHITE);
        this->_shapes.drawRectangleRec(this->_textBox, DARKGRAY);
        this->_text.drawText(TextFormat("PRESS [B] TO GO BACK"), {.x = 1020, .y = 640}, 20, GOLD);
        if (_mouseOnText)
            _shapes.drawRectangleLines({.x = _textBox.x, .y = _textBox.y}, {.x = _textBox.height, .y = _textBox.width}, GOLD);
        else
            _shapes.drawRectangleLines({.x = _textBox.x, .y = _textBox.y}, {.x = _textBox.height, .y = _textBox.width}, DARKGRAY);
        _text.drawText(this->_userName.c_str(), {.x = _textBox.x + 5, .y = _textBox.y + 8}, 40, GOLD);
        _text.drawText(TextFormat("Nombre de lettre maximum: %i/%i", letterCount, 9), {.x = _textBox.x, .y = 250}, 20,GRAY);
        if (_mouseOnText && letterCount < 9) {
            if ((_framesCounter / 2) % 2 == 0)
                _text.drawText("_", {.x = _textBox.x + 8 + _text.measureText(_userName.c_str(), 40), .y = _textBox.y + 12}, 40, BLACK);
            _text.drawText("Press SUPPR pour supprimer des charactères...", {.x = 230, .y = 300}, 20, GRAY);
        }
        this->isButtonPressed(_btnplayVector);
        this->_core.setMouseCursor(MOUSE_CURSOR_DEFAULT);
        this->clear();
        this->_playButton.drawButtons(_btnplayVector, DARKGRAY);
        this->_playButton.drawButtonOnHover(_btnplayVector, BLACK, 40, GOLD);
    EndDrawing();
    if (_core.isKeyPressed(KEY_B)) {
        SCENES = IInfo::GameScenes::PLAY;
        return;
    }
}

void AskUser::init()
{
    this->_core.setTargetFPS(10);
    this->_framesCounter = 0;
    this->_textureask = LoadTexture("../assets/images/secmenu.png");
}

void AskUser::unload()
{
    UnloadTexture(_textureask);
}

IInfo::GameScenes AskUser::window_handler()
{
    if (_shapes.checkCollisionPointRec(_core.getMousePosition(), _textBox)) {
            this->_mouseOnText = true;
    } else
        this->_mouseOnText = false;
    if (this->_mouseOnText) {
        _core.setMouseCursor(MOUSE_CURSOR_IBEAM);
        int key = _core.getCharPressed();
        while (key > 0) {
            if ((key >= 32) && (key <= 125) && (letterCount < 9)) {
                this->_userName[letterCount] += (char)key;
                this->_userName[letterCount + 1] = '\0';
                letterCount++;
            }
            key = _core.getCharPressed();
        }
        if (_core.isKeyPressed(KEY_BACKSPACE)) {
            if (letterCount > 0)
                letterCount--;
            else
                letterCount = 0;
            this->_userName[letterCount] = '\0';
        }
        if (_core.isKeyPressed(KEY_ENTER)) {
            SCENES = IInfo::GameScenes::SELECT_PLAYERS;
            _core.clearBackground(RAYWHITE);
            return IInfo::GameScenes::SELECT_PLAYERS;
        }
    } else
        _core.setMouseCursor(MOUSE_CURSOR_DEFAULT);
    if (_mouseOnText)
        _framesCounter++;
    _framesCounter = 0;
    return IInfo::GameScenes::CREATE_PARTY;
}

void AskUser::clear()
{
    _core.clearBackground(RAYWHITE);
}

void AskUser::refresh()
{

}

void AskUser::drawButton(std::vector<Button> button, Color color)
{
    for (int i = 0; i < (int)button.size(); i++)
        this->_rectan.drawRectangleRec(button[i].getRectangle(), color);
}

void AskUser::drawButtonOnHover(std::vector<Button> button, Color color,  Color onHover)
{
    for (int i = 0; i < (int)button.size(); i++) {
        if (button[i].getMouseOnButton())
            this->_rectan.drawRectangleRec(button[i].getRectangle(), onHover);
        else
            button[i].drawTextButton(button[i].getTextButton(), button[i].getRectangle().x, button[i].getRectangle().y, 35, color);
    }
}

void AskUser::isButtonPressed(std::vector<Button> button)
{
    for (int i = 0; i < (int)button.size(); i++) {
        if (this->_rectan.checkCollisionPointRec({.x = GetMousePosition().x, .y = GetMousePosition().y}, _btnplayVector[i].getRectangle())) {
            _btnplayVector[i].setMouseOnButton(true);
            if (this->_core.isMouseButtonDown(MOUSE_BUTTON_LEFT))
                _btnplayVector[i].setbtnState(2);
            else
                _btnplayVector[i].setbtnState(1);
            if (this->_core.isMouseButtonReleased(MOUSE_BUTTON_LEFT))
                _btnplayVector[i].setbtnAction(true);
            else
                _btnplayVector[i].setbtnAction(false);
        } else {
            _btnplayVector[i].setMouseOnButton(false);
            _btnplayVector[i].setbtnState(0);
        }
        if (_btnplayVector[i].getbtnAction()) {
            if (!_btnplayVector[i].getTextButton().compare("Select your player")) {
                SCENES = IInfo::GameScenes::SELECT_PLAYERS;
                _btnplayVector[i].setbtnAction(0);
            }
        }
    }
}
