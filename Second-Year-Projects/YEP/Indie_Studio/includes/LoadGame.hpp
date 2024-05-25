/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-antoine.gavira-bottari
** File description:
** LoadGame
*/

#ifndef LOADGAME_HPP_
    #define LOADGAME_HPP_

    #include <iostream>
    #include <fstream>
    #include "Player.hpp"

class LoadGame {
    private:
        #define FST_PLAYER 1
        #define SND_PLAYER 2
        #define TRD_PLAYER 3
        #define FTH_PLAYER 4
    public:
        LoadGame(const std::string &dir_name);
        ~LoadGame();
        void activate(std::string &map, playerData &p1, playerData &p2, playerData &p3, playerData &p4);
        // std::string getMap() const { return this->_map; }
        // Player getPlayer1() const { return this->_p1; }
        // Player getPlayer2() const { return this->_p2; }
        // Player getPlayer3() const { return this->_p3; }
        // Player getPlayer4() const { return this->_p4; }
        template<typename T>
        void output(const std::string &prefix, const uint8_t player_id, const std::string &suffix, T &data);
        void output(const std::string &prefix, const std::string &suffix, std::string &map);
    protected:
    private:
        const std::string _dirname;
        // std::string _map;
        // Player _p1;
        // Player _p2;
        // Player _p3;
        // Player _p4;
};

#endif /* !LOADGAME_HPP_ */
