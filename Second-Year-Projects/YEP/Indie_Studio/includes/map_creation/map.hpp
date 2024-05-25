/*
** EPITECH PROJECT, 2022
** map
** File description:
** map
*/

#ifndef MAP_HPP_
#define MAP_HPP_

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>
#include "Player.hpp"

class Player;
class MapGeneration
{
    private:
        typedef enum
        {
            BONUS,
            PLAYER,
            BONUS_MODEL
        } info_e;
    public:
        MapGeneration();
        ~MapGeneration();
        void firstGene();
        void writeToFile(std::vector<std::string>& map);
        std::vector<std::string> readMap();
        std::vector<std::string> readExplosionImpact();
        char movePlayer(char player, int LR, int UD, char lastChar); //LR = left right, UD = up down
        char moveLR(std::vector<std::string>& map, int LR, char player, char lastChar);
        char moveUD(std::vector<std::string>& map, int LR, char player, char lastChar);
        void deleteUp(std::vector<std::string> &map, int x, int y, std::string &deleted_player, Player &player);
        void deleteDown(std::vector<std::string> &map, int x, int y, std::string &deleted_player, Player &player);
        void deleteLeft(std::vector<std::string> &map, int x, int y, std::string &deleted_player, Player &player);
        void deleteRight(std::vector<std::string> &map, int x, int y, std::string &deleted_player, Player &player);
        void deleteWoodInMap(std::vector<std::string> &map, int x, int y, std::string &deleted_player, Player &player);
        bool getInfoMap(char c, info_e info);
        char brokedBonus(char c);
        int getPlayerXpos(char player);
        int getPlayerZpos(char player);
        std::vector<std::string> poseTblocks(std::vector<std::string>& map, int x, int y);
        info_e getEnumBonus() const { return this->BONUS; }
        info_e getEnumPlayer() const { return this->PLAYER; }
        info_e getEnumBonusModel() const { return this->BONUS_MODEL; }

    private:
        using delete_method = void (MapGeneration::*)(std::vector<std::string> &map, int x, int y, std::string &deleted_player, Player &player);
        static const inline delete_method method_ptr[] = {
            &MapGeneration::deleteUp,
            &MapGeneration::deleteDown,
            &MapGeneration::deleteLeft,
            &MapGeneration::deleteRight,
        };
    private:
        std::vector<std::vector<char>> createSpecialBonus();
        std::vector<std::vector<char>> createWalkZone(std::vector<std::vector<char>>);
        std::vector<std::vector<char>> const createMap();
        std::vector<char> _v1_2;
        std::vector<char> _v3_4;
        std::vector<char> _v5_6_7;
        std::vector<char> _v8_9;
        std::vector<char> _vstrat_end;
};

#endif /* !MAP_HPP_ */
