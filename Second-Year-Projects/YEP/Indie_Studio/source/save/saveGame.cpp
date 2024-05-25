/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-antoine.gavira-bottari
** File description:
** saveGame
*/

#include "SaveGame.hpp"

SaveGame::SaveGame(const std::string &old_name, const std::string &new_name, const std::string &map,
    const Player &p1, const Player &p2, const Player &p3, const Player &p4)
    : _oldname(old_name), _newname(new_name), _map(map), _p1(p1), _p2(p2), _p3(p3), _p4(p4)
{
}

SaveGame::~SaveGame()
{
}

void SaveGame::assignData(playerData &data, const Player &player)
{
    data._animsCount = player.getAnimsCount();
    data._rotation = player.getRotation();
    data._frameCounter = player.getFrame();
    data._is_ai = player.getIsAi();
    data._is_alive = player.getIsAlive();
    data._playerChar = player.getPlayerchar();
    data._bomb_key = player.getKeyboardKey();
    data._position = player.getPosition();
    data._model = player.getModel();
    data._texture = player.getTexture();
    data._models = player.getModels();
    data._textures = player.getTextures();
    // data._animations = player.getAnimations();
    data.bombe = player.getBombe();
    data._bombe_position = player.getBombeposition();
    data._isBombe = player.getIsBombe();
    data._isSpeed = player.getIsSpeed();
    data._isBombeUp = player.getIsBombeUp();
    data._isShield = player.getIsShield();
    data._speed = player.getSpeed();
    data._bombeUp = player.getBombeUp();
    data._speedChrono = player.getSpeedChrono();
    data._bombeUpChrono = player.getBombeUpChrono();
    data._shieldChrono = player.getShieldChrono();
}

void SaveGame::activate()
{
    std::string new_dir = "../.db/" + this->_newname + "/";
    std::string old_dir = "../.db/" + this->_oldname + "/";
    std::string map_prefix = new_dir + "map";
    std::string player_prefix = new_dir + "player";
    std::string map_suffix = ".txt";
    std::string player_suffix = ".txt";
    playerData p1data;
    playerData p2data;
    playerData p3data;
    playerData p4data;

    this->createDir("../.db");
    // for (const auto &path : std::filesystem::directory_iterator("../.db/")) {
    //     if (path.path() == ("../.db/" + this->_oldname)) {
    //         this->removeDir(path.path());
    //         break;
    //     }
    // }
    this->createDir(new_dir);
    this->input(map_prefix, map_suffix, this->_map);
    this->assignData(p1data, this->_p1);
    this->assignData(p2data, this->_p2);
    this->assignData(p3data, this->_p3);
    this->assignData(p4data, this->_p4);
    this->input(player_prefix, FST_PLAYER, player_suffix, p1data);
    this->input(player_prefix, SND_PLAYER, player_suffix, p2data);
    this->input(player_prefix, TRD_PLAYER, player_suffix, p3data);
    this->input(player_prefix, FTH_PLAYER, player_suffix, p4data);
}

bool SaveGame::createDir(const std::string &dir_name)
{
    return std::filesystem::create_directory(dir_name);
}

bool SaveGame::removeDir(const std::string &dir_name)
{
    return std::filesystem::remove(dir_name);
}

template<typename T>
void SaveGame::input(const std::string &prefix, const uint8_t player_id ,const std::string &suffix, T &data)
{
    std::string filename = prefix + std::to_string(player_id) + suffix;
    std::ofstream out;

    out.open(filename, std::ios::app);
    out.write((char *)&data, sizeof(data));
    out.close();
}

void SaveGame::input(const std::string &prefix, const std::string &suffix, const std::string &map)
{
    std::string filename = prefix + suffix;
    std::ofstream out;

    out.open(filename, std::ios::app);
    out << map;
    out.close();
}
