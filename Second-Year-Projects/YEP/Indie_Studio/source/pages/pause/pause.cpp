/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-antoine.gavira-bottari
** File description:
** pause
*/

#include "Parser.hpp"
#include "Pause.hpp"

Pause::Pause()
{
}

Pause::~Pause()
{
}

void Pause::init()
{
    Parser_Json parser("../config/pause.json");
    std::map<std::string, std::string> infos;

    infos = parser.get_info_from_file("resume_button");
    this->_resumeButton = {infos["title"], std::stof(infos["pos_x"]), std::stof(infos["pos_y"]), std::stof(infos["width"]),std::stof(infos["height"])};
    infos = parser.get_info_from_file("save_button");
    this->_saveButton = {infos["title"], std::stof(infos["pos_x"]), std::stof(infos["pos_y"]), std::stof(infos["width"]),std::stof(infos["height"])};
    infos = parser.get_info_from_file("exit_button");
    this->_exitButton = {infos["title"], std::stof(infos["pos_x"]), std::stof(infos["pos_y"]), std::stof(infos["width"]),std::stof(infos["height"])};
    this->pushButton(_resumeButton);
    this->pushButton(_saveButton);
    this->pushButton(_exitButton);
}

void Pause::draw(IInfo::PaueScenes &isPaused)
{
    isPaused = this->isButtonPressed(_btnVector);
    this->_core.setMouseCursor(MOUSE_CURSOR_DEFAULT);
    _core.beginDrawing();
        this->_resumeButton.drawButtons(_btnVector, DARKGRAY);
        this->_resumeButton.drawButtonOnHover(_btnVector, BLACK, 40, GOLD);
    _core.endDrawing();
}

void Pause::clear()
{
    this->_core.clearBackground(RAYWHITE);
}

void Pause::refresh()
{
}

IInfo::PaueScenes Pause::isButtonPressed(std::vector<Button> &button)
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
            if (!_btnVector[i].getTextButton().compare("Resume")) {
                return IInfo::PaueScenes::RESUME;
                _btnVector[i].setbtnAction(0);
            }
            if (!_btnVector[i].getTextButton().compare("Save")) {
                return IInfo::PaueScenes::RESUME;
                _btnVector[i].setbtnAction(0);
            }
            if (!_btnVector[i].getTextButton().compare("Exit")) {
                return IInfo::PaueScenes::EXIT_PAUSE;
                _btnVector[i].setbtnAction(0);
            }
        }
    }
    return IInfo::PaueScenes::IS_PAUSED;
}