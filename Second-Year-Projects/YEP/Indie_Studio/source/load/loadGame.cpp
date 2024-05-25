/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-antoine.gavira-bottari
** File description:
** loadGame
*/

#include "LoadGame.hpp"

LoadGame::LoadGame(const std::string &dir_name)
    : _dirname(dir_name)
{
}

LoadGame::~LoadGame()
{
}

void LoadGame::activate(std::string &map, playerData &p1, playerData &p2, playerData &p3, playerData &p4)
{
    std::string dir_path = "../.db/" + this->_dirname + "/";
    std::string map_prefix = dir_path + "map";
    std::string player_prefix = dir_path + "player";
    std::string map_suffix = ".txt";
    std::string player_suffix = ".txt";

    this->output(map_prefix, map_suffix, map);
    this->output(player_prefix, FST_PLAYER, player_suffix, p1);
    this->output(player_prefix, SND_PLAYER, player_suffix, p2);
    this->output(player_prefix, TRD_PLAYER, player_suffix, p3);
    this->output(player_prefix, FTH_PLAYER, player_suffix, p4);
}

void LoadGame::output(const std::string &prefix, const std::string &suffix, std::string &map)
{
    std::string filename = prefix + suffix;
    std::ifstream in;

    in.open(filename, std::ios::in);
    while (in.good()) {
        std::string line;
        std::getline(in, line);
        map += (line + "\n");
    }
    in.close();
}

template<typename T>
void LoadGame::output(const std::string &prefix, const uint8_t player_id, const std::string &suffix, T &data)
{
    std::string filename = prefix + std::to_string(player_id) + suffix;
    std::ifstream in;

    in.open(filename, std::ios::in);
    in.seekg(0);
    in.read((char *)&data, sizeof(data));
    in.close();
}
