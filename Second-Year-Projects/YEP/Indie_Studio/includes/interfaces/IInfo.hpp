/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-antoine.gavira-bottari
** File description:
** IInfo
*/

#ifndef IINFO_HPP_
    #define IINFO_HPP_
    #include <iostream>

namespace IInfo
{
    enum GameScenes {
        ANIMSCREEN,
        LOAD_SCREEN,
        MENU,
        SETTING,
        SCORES,
        PLAY,
        PAUSE,
        EXIT,
        LOAD_PARTY,
        CREATE_PARTY,
        SELECT_PLAYERS,
        GAMEENGINE,
    };

    enum PaueScenes {
        IS_PAUSED,
        RESUME,
        SAVE,
        EXIT_PAUSE,
        NONE,
    };
}

extern IInfo::GameScenes SCENES;
static size_t FPS;

#endif /* !IINFO_HPP_ */
