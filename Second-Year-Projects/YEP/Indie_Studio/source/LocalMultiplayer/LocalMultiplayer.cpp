/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-antoine.gavira-bottari
** File description:
** LocalMultiplayer
*/

#include <chrono>
#include "Parser.hpp"
#include "LocalMultiplayer.hpp"

LocalMultiplayer::LocalMultiplayer() : controller("controller"), keyboard("keyboard"), p1(0), p2(1), p3(2), p4(3)
{
    init();
}

LocalMultiplayer::~LocalMultiplayer()
{
}

std::vector<PlayerSettings> LocalMultiplayer::draw()
{
    _core.beginDrawing();
    clear();
    _text.drawFPS({30, 30});
    //DrawTextureV(_texture, {0, 0}, WHITE);
    drawButton(GRAY);
    drawRect(RED);
    drawMyTexts();
    actions();
    _core.endDrawing();
    if (_playersettings[0].get_bindings().empty())
        return {};
    else
        return _playersettings;
}

void LocalMultiplayer::init()
{
    //_texture = _d_textures.loadTexture("../assets/images/bomeber.png");
    if (_buttons.empty()) {
        _buttons.emplace_back(Button("prev", 90, 610, 80, 50));
        _buttons.emplace_back(Button("next", 210, 610, 80, 50));
        _buttons.emplace_back(Button("prev", 390, 610, 80, 50));
        _buttons.emplace_back(Button("next", 510, 610, 80, 50));
        _buttons.emplace_back(Button("prev", 690, 610, 80, 50));
        _buttons.emplace_back(Button("next", 810 , 610, 80, 50));
        _buttons.emplace_back(Button("prev", 990, 610, 80, 50));
        _buttons.emplace_back(Button("next", 1110 , 610, 80, 50));
        _buttons.emplace_back(Button("Play", 1180 , 670, 100, 50));

        _buttons.emplace_back(Button("control", 125, 500, 120, 35));
        _buttons.emplace_back(Button("type", 150, 550, 75, 35));
        _buttons.emplace_back(Button("control", 425, 500, 120, 35));
        _buttons.emplace_back(Button("type", 450, 550, 75, 35));
        _buttons.emplace_back(Button("control", 725, 500, 120, 35));
        _buttons.emplace_back(Button("type", 750, 550, 75, 35));
        _buttons.emplace_back(Button("control", 1025, 500, 120, 35));
        _buttons.emplace_back(Button("type", 1050, 550, 75, 35));
    }

    bool init_bool = false;
    if (_type.empty()) {
        _type.push_back(init_bool);
        _type.push_back(init_bool);
        _type.push_back(init_bool);
        _type.push_back(init_bool);
    }
    if (_controller.empty()) {
        _controller.push_back(init_bool);
        _controller.push_back(init_bool);
        _controller.push_back(init_bool);
        _controller.push_back(init_bool);
    }
    if (_playersettings.empty()) {
        _playersettings.emplace_back(PlayerSettings("Local", "Keyboard", "Player 1"));
        _playersettings.emplace_back(PlayerSettings("Local", "Keyboard", "Player 2"));
        _playersettings.emplace_back(PlayerSettings("Ai", "Keyboard", "Player 3"));
        _playersettings.emplace_back(PlayerSettings("Ai", "Keyboard", "Player 4"));
    }
}

void LocalMultiplayer::clear()
{
    _core.clearBackground(BLACK);
}

void LocalMultiplayer::drawMySpecialButtons(std::vector<Button> &vect, int pos)
{
    int pair = 0;

    for (size_t i = pos; i < vect.size(); i++) {
        if (_buttons[i].getTextButton().compare("control") == 0 && _controller[pair] == true) {
            _buttons[i].drawButton(DARKPURPLE, BLACK, 25, 25);
        } else if (_buttons[i].getTextButton().compare("control") == 0 && _controller[pair] == false) {
            _buttons[i].drawSingleButtonOnHover(BLACK, 25, PURPLE, DARKPURPLE, 25);
        } else if (_buttons[i].getTextButton().compare("type") == 0 && _type[pair] == true) {
            _buttons[i].drawButton(PINK, BLACK, 25, 15);
            pair++;
        } else if (_buttons[i].getTextButton().compare("type") == 0 && _type[pair] == false)
        {
            _buttons[i].drawSingleButtonOnHover(BLACK, 25, MAGENTA, PINK, 15);
            pair++;
        }
    }
}

void LocalMultiplayer::drawButton(Color const &color)
{
    if (_buttons.empty())
        return;
    for (size_t i = 0; i < _buttons.size(); ++i) {
        if (_buttons[i].getTextButton().compare("control") == 0) {
            drawMySpecialButtons(_buttons, i);
            break;
        } else {
            _buttons[i].drawSingleButtonOnHover(BLACK, 25, color, LIGHTGRAY, 12);
        }
    }
}

void LocalMultiplayer::drawRect(Color const &color)
{
    _rect.drawRectangleLines(Vector2{85, 100}, Vector2{370, 205}, color);
    //_d_textures.drawTextureV(_texture, Vector2{85, 100}, WHITE);
    _rect.drawRectangleLines(Vector2{390, 100}, Vector2{370, 205}, color);
    _rect.drawRectangleLines(Vector2{690, 100}, Vector2{370, 205}, color);
    _rect.drawRectangleLines(Vector2{990, 100}, Vector2{370, 205}, color);
}

bool LocalMultiplayer::myWarnings(int const nb, int const nbr, int const nb2)
{
    if (nb > 1 || nbr == 4 || nb2 > 1) {
        auto start = std::chrono::steady_clock::now();
        std::chrono::duration<double> elapsed;
        for (auto stop = std::chrono::steady_clock::now(); elapsed.count() < 2.5; elapsed = (stop - start)) {
            BeginDrawing();
            clear();
            if (nb > 1)
                _text.drawText("Only one player should be playing with a controller", Vector2{100, 360}, 40, RED);
            if (nbr == 4)
                _text.drawText("Only three player should be playing with a Keyboard", Vector2{100, 360}, 40, RED);
            if (nb2 > 1)
                _text.drawText("Can't play with more then 1 ai", Vector2{350, 360}, 40, RED);
            stop = std::chrono::steady_clock::now();
            EndDrawing();
        }
        return false;
    }
    return true;
}

bool LocalMultiplayer::initiate_playersettings()
{
    int nb = 0;
    int nbr = 0;
    int nb2 = 0;
    bool ret = true;
    Parser_Json parser("../config/bindings.json");
    std::map<std::string, std::string> tmp;
    int x = 1;

    for (size_t i = 0; i < _playersettings.size(); i++) {
        if (_playersettings[i].get_controller().compare("Controller") == 0) {
            nb++;
            tmp = parser.get_info_from_file("Player 4");
        } else {
            tmp = parser.get_info_from_file("Player " +  std::to_string(x));
            x++;
            if (_playersettings[i].get_type().compare("Ai") != 0)
                nbr++;
            else
                nb2++;
        }
        _playersettings[i].set_Bindings(tmp);
        _playersettings[i].check_isAi();
    }
    ret = myWarnings(nb, nbr, nb2);
    return ret;
}

void LocalMultiplayer::actions()
{
    Vector2 mousepos = GetMousePosition();

    for(size_t i = 0; i < _buttons.size(); i++) {
        if (_rect.checkCollisionPointRec(mousepos, _buttons[i].getRectangle())) {
            _buttons[i].setMouseOnButton(true);
            if (_core.isMouseButtonDown(MOUSE_BUTTON_LEFT))
                _buttons[i].setbtnState(2);
            else
                _buttons[i].setbtnState(1);
            if (_core.isMouseButtonReleased(MOUSE_BUTTON_LEFT))
                _buttons[i].setbtnAction(true);
            else
                _buttons[i].setbtnAction(false);
        } else {
            _buttons[i].setMouseOnButton(false);
            _buttons[i].setbtnState(0);
        }
        if (_buttons[i].getbtnAction()) {
            if (!_buttons[i].getTextButton().compare("Play")) {
                if (initiate_playersettings()) {
                    SCENES = IInfo::GameScenes::GAMEENGINE;
                }
                _buttons[i].setbtnAction(0);
            }
            prev_next_btn(i);
            controller_type_action(i);
        }
    }
    getWindowPart();
}

int LocalMultiplayer::check_btn_states(int const x, std::string const &cmp1, std::string const &cmp2, std::string const &set1, std::string const &set2)
{
    if (_controller[x] == true) {
        if (_playersettings[x].get_controller().compare(cmp1) == 0) {
            _playersettings[x].set_controller(set1);
            return 1;
        }
    } else if (_type[x] == true) {
        if (_playersettings[x].get_type().compare(cmp2) == 0) {
            _playersettings[x].set_type(set2);
            return 1;
        }
    }
    return 0;
}

void LocalMultiplayer::prev_next_btn(int const i)
{
    for (int x = 0; x < 4; x++) {
        if (!_buttons[i].getTextButton().compare("prev") && _window_part == x) {
            if (check_btn_states(x, "Keyboard", "Local", "Controller", "Ai") == 1)
                break;
        } else if (!_buttons[i].getTextButton().compare("next") && _window_part == x) {
            if (check_btn_states(x, "Controller", "Ai", "Keyboard", "Local") == 1)
                break;
        }
    }
}

void LocalMultiplayer::controller_type_action(int const i)
{
    for (int x = 0; x < 4; x++) {
        if (_buttons[i].getTextButton().compare("control") == 0 && _window_part == x) {
            if (_controller[x] == false) {
                _controller[x] = true;
                _type[x] = false;
            }
        }
        if (_buttons[i].getTextButton().compare("type") == 0 && _window_part == x) {
            if (_type[x] == false) {
                _type[x] = true;
                _controller[x] = false;
            }
        }
    }
}

void LocalMultiplayer::getWindowPart()
{
    Vector2 vect = GetMousePosition();

    if (vect.x > 0 && vect.x < 320)
        _window_part = p1;
    else if (vect.x > 320 && vect.x < 640)
        _window_part = p2;
    else if (vect.x > 640 && vect.x < 960)
        _window_part = p3;
    else if (vect.x > 960 && vect.x < 1280)
        _window_part = p4;
}

void LocalMultiplayer::drawMyTexts()
{
    _text.drawText("Player 1", Vector2{ 150, 50}, 20, BLUE);
    _text.drawText("Player 2", Vector2{ 450, 50}, 20, GREEN);
    _text.drawText("Player 3", Vector2{ 750, 50}, 20, PURPLE);
    _text.drawText("Player 4", Vector2{ 1050, 50}, 20, LIME);

    float i = 150.0f;
    float const j = 400.0f;
    for (size_t x = 0; x < _playersettings.size(); i += 300, x++) {
        _text.drawText(_playersettings[x].get_controller(), Vector2{i, j}, 20, PURPLE);
        _text.drawText(_playersettings[x].get_type(), Vector2{i + 10, j + 25}, 20, PURPLE);
    }
}