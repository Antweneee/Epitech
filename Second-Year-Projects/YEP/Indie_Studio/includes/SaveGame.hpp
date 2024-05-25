/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-antoine.gavira-bottari
** File description:
** SaveGame
*/

#ifndef SAVEGAME_HPP_
    #define SAVEGAME_HPP_

    #include <iostream>
    #include <filesystem>
    #include "Player.hpp"

class SaveGame {
    private:
        #define FST_PLAYER 1
        #define SND_PLAYER 2
        #define TRD_PLAYER 3
        #define FTH_PLAYER 4
    public:
        SaveGame(const std::string &old_name, const std::string &new_name, const std::string &map,
            const Player &p1, const Player &p2, const Player &p3, const Player &p4);
        ~SaveGame();
        void activate();
        void assignData(playerData &data, const Player &player);
        bool createDir(const std::string &dir_name);
        bool removeDir(const std::string &dir_name);
        template<typename T>
        void input(const std::string &prefix, const uint8_t player_id, const std::string &suffix, T &data);
        void input(const std::string &prefix, const std::string &suffix, const std::string &map);
    protected:
    private:
        const std::string _oldname;
        const std::string _newname;
        const std::string _map;
        const Player _p1;
        const Player _p2;
        const Player _p3;
        const Player _p4;
};

#endif /* !SAVEGAME_HPP_ */
