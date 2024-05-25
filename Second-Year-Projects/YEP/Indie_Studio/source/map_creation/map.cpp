/*
** EPITECH PROJECT, 2022
** map
** File description:
** map
*/

#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <map>
#include "map.hpp"

#define MAP_LEN 13

MapGeneration::MapGeneration()
{
    _v1_2   = {'#', 'X', 'X', 'X', '#', 'X', 'X', 'X', 'X', 'X', 'X', 'X', '#', 'X', '#'};
    _v3_4   = {'#', 'X', 'X', 'X', 'X', 'X', '#', 'X', 'X', 'X', 'X', 'X', 'X', 'X', '#'};
    _v5_6_7 = {'#', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', '#', 'X', 'X', 'X', '#'};
    _v8_9   = {'#', 'X', 'X', 'X', 'X', 'X', 'X', 'X', '#', 'X', 'X', 'X', 'X', 'X', '#'};
    _vstrat_end = {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'};
}

MapGeneration::~MapGeneration()
{
}

std::vector<std::vector<char>> const MapGeneration::createMap()
{
    int num;
    std::vector<std::vector<char>> map;

    srand(time(0));
    map.push_back(_vstrat_end);
    for (int i = 0; i != MAP_LEN; i++) {
        num = rand() % 10 + 1;
        if (num <= 2)
            map.push_back(_v1_2);
        else if (num > 2 && num <= 4)
            map.push_back(_v3_4);
        else if (num > 4 && num <= 7)
            map.push_back(_v5_6_7);
        else
            map.push_back(_v8_9);
    }
    map.push_back(_vstrat_end);
    return map;
}

void MapGeneration::firstGene()
{
    std::vector<std::vector<char>> vectors = this->createSpecialBonus();
    std::ofstream mapFile;

    mapFile.open("../assets/map/map.txt");

    for (int i = 0; i != (int)vectors.size(); i++) {
        std::string s(vectors[i].begin(), vectors[i].end());
        mapFile << s;
        if (!vectors[i].empty())
            mapFile << "\n";
    }

    mapFile.close();
}

void MapGeneration::writeToFile(std::vector<std::string>& map)
{
    std::ofstream mapFile;

    mapFile.open("../assets/map/map.txt");

    for (int i = 0; i != (int)map.size(); i++) {
        mapFile << map[i];
        mapFile << "\n";
    }
    mapFile.close();
}

std::vector<std::vector<char>> MapGeneration::createSpecialBonus()
{
    std::vector<std::vector<char>> vectors = this->createMap();
    int line = 0;
    int position = 0;

    for (int i = 0; i != 6; i++) {
        line = rand() % (MAP_LEN - 2 + 1) + 2;
        position = rand() % (MAP_LEN - 2 + 1) + 2;
        if (i == 0 || i == 1)
            vectors[line].insert(vectors[line].begin() + position, '4');
        if (i == 2 || i == 3)
            vectors[line].insert(vectors[line].begin() + position, '5');
        if (i == 4 || i == 5)
            vectors[line].insert(vectors[line].begin() + position, '6');
        vectors[line].erase(vectors[line].begin() + position + 1);
    }

    return this->createWalkZone(vectors);
}

std::vector<std::vector<char>> MapGeneration::createWalkZone(std::vector<std::vector<char>> vectors)
{
    vectors[1][1] = 'A';
    vectors[1][2] = ' ';
    vectors[2][1] = ' ';
    vectors[1][(vectors[1].size() - 2)] = 'B';
    vectors[1][(vectors[1].size() - 3)] = ' ';
    vectors[2][(vectors[1].size() - 2)] = ' ';

    vectors[vectors.size() - 2][(vectors[1].size() - 2)] = 'C';
    vectors[vectors.size() - 2][(vectors[1].size() - 3)] = ' ';
    vectors[vectors.size() - 3][(vectors[1].size() - 2)] = ' ';
    vectors[vectors.size() - 2][1] = 'D';
    vectors[vectors.size() - 2][2] = ' ';
    vectors[vectors.size() - 3][1] = ' ';
    return vectors;
}

char MapGeneration::moveLR(std::vector<std::string>& map, int LR, char player, char lastChar)
{
    std::string str1;
    char tmp;

    str1.push_back(player);
    for (size_t i = 0; i != map.size(); i++) {
        size_t found = map[i].find(str1);
        if (found != std::string::npos) {
            map[i][found] = lastChar;
            tmp = map[i][found + LR];
            map[i][found + LR] = player;
        }
    }
    writeToFile(map);
    return tmp;
}

char MapGeneration::moveUD(std::vector<std::string>& map, int UD, char player, char lastChar)
{
    std::string str1;
    char tmp;

    str1.push_back(player);
    for (size_t i = 0; i != map.size(); i++) {
        size_t found = map[i].find(str1);
        if (found != std::string::npos) {
             map[i][found] = lastChar;
            tmp = map[i + UD][found];
            map[i + UD][found] = player;
            break;
        }
    }
    writeToFile(map);
    return tmp;
}

char MapGeneration::movePlayer(char player, int LR, int UD, char lastChar)
{
    std::vector<std::string> map = readMap();
    std::string str1;
    str1.push_back(player);

    for (size_t i = 0; i != map.size(); i++) {
        size_t found = map[i].find(str1);
        if (found != std::string::npos) {
            if (LR != 0)
                return moveLR(map, LR, player, lastChar);
            else if (UD != 0)
                return moveUD(map, UD, player, lastChar);
        }
    }
    return 'N';
}

std::vector<std::string> MapGeneration::readMap()
{
    std::vector<std::string> map;
    std::string line;

    std::ifstream is("../assets/map/map.txt");

    while (getline(is, line))
        map.push_back(line);

    return map;
}

bool MapGeneration::getInfoMap(char c, info_e info)
{
    if (info == BONUS)
        return c == '1' || c == '2' || c == '3';
    else if (info == BONUS_MODEL)
        return c == '4' || c == '5' || c == '6';
    else
        return c == 'A' || c == 'B' || c == 'C' || c == 'D';
}

char MapGeneration::brokedBonus(char c)
{
    const std::map<char, char> bonusMap = {
        {'4', '1'},
        {'5', '2'},
        {'6', '3'},
    };

    for (const auto &[_old, _new] : bonusMap) {
        if (c == _old)
            return _new;
    }
    return c;
}

void MapGeneration::deleteUp(std::vector<std::string> &map, int x, int y, std::string &deleted_player, Player &player)
{
    for (int i = x, j = 0; j < player.getBombeUp() && map[i][y] != '#'; i -= 1, j += 1) {
        if (this->getInfoMap(map[i][y], BONUS) == false) {
            if (this->getInfoMap(map[i][y], PLAYER) == true && player.getIsShield() == false)
                deleted_player.push_back(map[i][y]);
            if (this->getInfoMap(map[i][y], BONUS_MODEL) == true)
                map[i][y] = this->brokedBonus(map[i][y]);
            else {
                if (player.getIsShield() == false)
                    map[i][y] = ' ';
            }
        }
    }
}

void MapGeneration::deleteDown(std::vector<std::string> &map, int x, int y, std::string &deleted_player, Player &player)
{
    for (int i = x, j = 0; j < player.getBombeUp() && map[i][y] != '#'; i += 1, j += 1) {
        if (this->getInfoMap(map[i][y], BONUS) == false) {
            if (this->getInfoMap(map[i][y], PLAYER) == true && player.getIsShield() == false)
                deleted_player.push_back(map[i][y]);
            if (this->getInfoMap(map[i][y], BONUS_MODEL) == true)
                map[i][y] = this->brokedBonus(map[i][y]);
            else {
                if (player.getIsShield() == false)
                    map[i][y] = ' ';
            }
        }
    }
}

void MapGeneration::deleteLeft(std::vector<std::string> &map, int x, int y, std::string &deleted_player, Player &player)
{
    for (int i = y, j = 0; j < player.getBombeUp() && map[x][i] != '#'; i -= 1, j += 1) {
        if (this->getInfoMap(map[x][i], BONUS) == false) {
            if (this->getInfoMap(map[x][i], PLAYER) == true && player.getIsShield() == false)
                deleted_player.push_back(map[x][i]);
            if (this->getInfoMap(map[x][i], BONUS_MODEL) == true)
                map[x][i] = this->brokedBonus(map[x][i]);
            else {
                if (player.getIsShield() == false)
                    map[x][i] = ' ';
            }
        }
    }
}

void MapGeneration::deleteRight(std::vector<std::string> &map, int x, int y, std::string &deleted_player, Player &player)
{
    for (int i = y, j = 0; j < player.getBombeUp() && map[x][i] != '#'; i += 1, j += 1) {
        if (this->getInfoMap(map[x][i], BONUS) == false) {
            if (this->getInfoMap(map[x][i], PLAYER) == true && player.getIsShield() == false)
                deleted_player.push_back(map[x][i]);
            if (this->getInfoMap(map[x][i], BONUS_MODEL) == true)
                map[x][i] = this->brokedBonus(map[x][i]);
            else {
                if (player.getIsShield() == false)
                    map[x][i] = ' ';
            }
        }
    }
}

void MapGeneration::deleteWoodInMap(std::vector<std::string> &map, int x, int y, std::string &deleted_player, Player &player)
{
    for (const auto &func : method_ptr)
        (this->*func)(map, x, y, deleted_player, player);
}

int MapGeneration::getPlayerZpos(char player)
{
    std::vector<std::string> map = readMap();
    std::string str1;
    str1.push_back(player);

    for (size_t i = 0; i != map.size(); i++) {
        size_t found = map[i].find(str1);
        if (found != std::string::npos) {
            return i;
        }
    }
    return 2;
}

int MapGeneration::getPlayerXpos(char player)
{
    std::vector<std::string> map = readMap();
    std::string str1;
    str1.push_back(player);

    for (size_t i = 0; i != map.size(); i++) {
        size_t found = map[i].find(str1);
        if (found != std::string::npos) {
            return found;
        }
    }
    return 2;
}

int countBombe(std::vector<std::string> map)
{
    int bombes = 0;

    for (size_t i = 0; i != map.size(); i++) {
        bombes += std::count(map[i].begin(), map[i].end(), 'b');
    }
    return bombes;
}

std::vector<std::string> MapGeneration::poseTblocks(std::vector<std::string>& map, int x, int y)
{
    bool good_x = false;
    bool good_y = false;

    if (x <= 12 && x >= 2)
        good_x = true;
    if (y <= 12 && y >= 2)
        good_y = true;
    if (map.empty())
        return readMap();
    if (!map[x + 1].empty() && map[x + 1][y] && (map[x + 1][y] == ' ' || (map[x + 1][y] >= 'A' && map[x + 1][y] <= 'D')))
        map[x + 1][y] = 'T';
    if (good_x == true) {
        if (!map[x + 1].empty() && !map[x + 2].empty() && map[x + 1][y] && map[x + 2][y] && (map[x + 2][y] == ' ' || (map[x + 2][y] >= 'A' && map[x + 2][y] <= 'D')))
            map[x + 2][y] = 'T';
    }
    if (!map[x - 1].empty() && map[x - 1][y] && (map[x - 1][y] == ' ' || (map[x - 1][y] >= 'A' && map[x - 1][y] <= 'D')))
        map[x - 1][y] = 'T';
    if (good_x == true) {
        if (good_x == true && !map[x - 1].empty() && !map[x - 2].empty() && map[x - 1][y] && map[x - 2][y] && (map[x - 2][y] == ' ' || (map[x - 2][y] >= 'A' && map[x - 2][y] <= 'D')))
            map[x - 2][y] = 'T';
    }
    if (!map[x].empty() && map[x][y + 1] && (map[x][y + 1] == ' ' || (map[x][y + 1] >= 'A' && map[x][y + 1] <= 'D')))
        map[x][y + 1] = 'T';
    if (good_y == true) {
        if (!map[x].empty() && map[x][y + 1] && map[x][y + 2] && (map[x][y + 2] == ' ' || (map[x][y + 2] >= 'A' && map[x][y + 2] <= 'D')))
            map[x][y + 2] = 'T';
    }
    if (!map[x].empty() && map[x][y - 1] && (map[x][y - 1] == ' ' || (map[x][y - 1] >= 'A' && map[x][y - 1] <= 'D')))
        map[x][y - 1] = 'T';
    if (good_y == true) {
        if (!map[x].empty() && map[x][y - 1] && map[x][y - 2] && (map[x][y - 2] == ' ' || (map[x][y - 2] >= 'A' && map[x][y - 2] <= 'D')))
            map[x][y - 2] = 'T';
    }
    return map;
}

std::vector<std::string> MapGeneration::readExplosionImpact()
{
    std::vector<std::string> map = readMap();
    int bombes = countBombe(map);

    if (bombes <= 0)
        return map;

    for (int i = 0; i != bombes; i++) {
        for (size_t lines = 0; lines != map.size(); lines++) {
            size_t found = map[lines].find("b");
            if (found != std::string::npos) {
                map[lines][found] = 'T';
                map = poseTblocks(map, lines, found);
            }
        }
    }
    return map;
}