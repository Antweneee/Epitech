/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-antoine.gavira-bottari
** File description:
** init_game
*/

#include "game.hpp"
#include "Menu.hpp"
#include "Score.hpp"
#include "Parser.hpp"

IInfo::GameScenes SCENES;

Game::Game()
{
    Parser_Json parser("../config/menu.json");
    std::map<std::string, std::string> info;

    info = parser.get_info_from_file("window");
    this->_screenWidth = std::stoi(info["width"]);
    this->_screenHeight = std::stoi(info["height"]);;
    this->FPS = std::stoi(info["fps"]);;
    SCENES = IInfo::GameScenes::ANIMSCREEN;
    this->_core.initWindow(_screenWidth, _screenHeight, "Bomberman");
}

Game::~Game()
{
    _core.closeWindow();
}

void Game::init()
{
    FPS = 15;
    this->_core.setTargetFPS(FPS);
    this->_mainMenu.init();
    this->_scores.init();
    this->_setting.init();
    this->_secondMenu.init();
    this->_createParty.init();
    this->_animScreen.init();
    this->_loadScreen.init();
    this->_victoryScreen.init();
}

void Game::unload()
{
    this->_scores.unload();
    this->_mainMenu.unload();
    this->_setting.unload();
    this->_secondMenu.unload();
    this->_createParty.unload();
    this->_animScreen.unload();
    this->_loadScreen.unload();
    this->_victoryScreen.unload();
}

void Game::engine()
{
    std::vector<PlayerSettings> settings;
    while (!_core.windowShouldClose()) {
        _core.clearBackground(RAYWHITE);
        if (SCENES == IInfo::GameScenes::ANIMSCREEN)
            this->_animScreen.draw();
        else if (SCENES == IInfo::GameScenes::LOAD_SCREEN)
            this->_loadScreen.draw();
        else if (SCENES == IInfo::GameScenes::MENU)
            this->_mainMenu.draw();
        else if (SCENES == IInfo::GameScenes::PLAY)
            this->_secondMenu.draw();
        else if (SCENES == IInfo::GameScenes::GAMEENGINE)
            this->_gameEngine.engine(settings);
        else if (SCENES == IInfo::GameScenes::SCORES)
            this->_scores.draw();
        else if (SCENES == IInfo::GameScenes::SETTING)
            this->_setting.draw();
        else if (SCENES == IInfo::GameScenes::SELECT_PLAYERS)
            settings = this->_choosePlayers.draw();
        else if (SCENES == IInfo::GameScenes::LOAD_PARTY)
            break;
        else if (SCENES == IInfo::GameScenes::EXIT) {
            break;
        }
    }
    this->unload();
}