/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-antoine.gavira-bottari
** File description:
** core
*/

#ifndef GAME_HPP_
    #define GAME_HPP_
    #include <map>
    #include <functional>
    #include <iostream>
    #include "enum.hpp"
    #include "MainMenu.hpp"
    #include "Setting.hpp"
    #include "Core.hpp"
    #include "SecondMenu.hpp"
    #include "AskUser.hpp"
    #include "LocalMultiplayer.hpp"
    #include "PlayerSettings.hpp"
    #include "GameEngine.hpp"
    #include "AnimScreen.hpp"
    #include "LoadScreen.hpp"
    #include "VictoryScreen.hpp"

class Game
{
    public:
        Game();
        Game(const MainMenu& menu, const Score& score, const Setting& setting) : _mainMenu(menu), _scores(score), _setting(setting) {}
        ~Game();
        void init();
        void engine();
        void unload();
    private:
        std::size_t getScreenWidth() const {return this->_screenWidth;}
        std::size_t getScreenHeight() const {return this->_screenWidth;}
        void setGameScenes(IInfo::GameScenes newScenes) {_coreScenes = newScenes;}
        IInfo::GameScenes getGameScenes() const {return _coreScenes;}
        std::size_t _screenWidth;
        std::size_t _screenHeight;
        IInfo::GameScenes _coreScenes;
        std::size_t FPS;
        MainMenu _mainMenu;
        Score _scores;
        Setting _setting;
        SecondMenu _secondMenu;
        LocalMultiplayer _choosePlayers;
        AskUser _createParty;
        Core _core;
        GameEngine _gameEngine;
        AnimScreen _animScreen;
        LoadScreen _loadScreen;
        VictoryScreen _victoryScreen;
        Sound _csmus;
};

#endif /* !CORE_HPP_ */
