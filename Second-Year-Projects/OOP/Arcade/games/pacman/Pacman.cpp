/*
** EPITECH PROJECT, 2022
** B-OOP-400-PAR-4-1-arcade-valentin.fouillet
** File description:
** Pacman
*/

#include "Pacman.hpp"

Arcade::Pacman::Pacman(std::string map_path)
{
    _data._map = read_file(map_path);
    _data._score = 0;
    _data._win = false;
    _data.ppos_x = 0;
    _data.ppos_y = 0;
    _data._name = " ";
    _data._loose = false;
    _prevc = 'P';
    _to_win = 635;
    init();
}

Arcade::Pacman::~Pacman()
{
}

void Arcade::Pacman::init()
{
    int nb = 1;
    IInfo::DataInfo add;

    for (size_t i = 0; i < _data._map.size(); i++) {
        if (_data._map[i].Content.find("P") != std::string::npos) {
            _data.ppos_x = i;
            _data.ppos_y = _data._map[i].Content.find("P");
            break;
        }
        for (size_t j = 0; j < _data._map[i].Content.size(); j++) {
            if (_data._map[i].Content[j] == 'G') {
                add.Content = "enemy" + std::to_string(nb);
                add.x = i;
                add.y = j;
                nb++;
                _data._enemies.push_back(add);
            }
        }
    }
}

void Arcade::Pacman::getkey(Arcade::KEYS key)
{
    if (key == Arcade::KEYS::NIL)
        return;
    for (int i = 0; i < 4; i++) {
        if (key == Arcade::__position__[i]._key) {
        if (_data._map[_data.ppos_x + Arcade::__position__[i].x].Content[_data.ppos_y + Arcade::__position__[i].y] == 'W' || _data._map[_data.ppos_x + Arcade::__position__[i].x].Content[_data.ppos_y + Arcade::__position__[i].y] == 'T')
                break;
            _data._map[_data.ppos_x].Content[_data.ppos_y] = ' ';
            _prevc = _data._map[_data.ppos_x].Content[_data.ppos_y];
            _data.ppos_x += Arcade::__position__[i].x;
            _data.ppos_y += Arcade::__position__[i].y;
            break;
        }
    }
}

void Arcade::Pacman::game_over()
{
    if (_data._score > 300)
        _data._win = true;

    if (_to_win == _data._score)
        _data._win = true;
}

void Arcade::Pacman::character_handler()
{
    for (size_t i = 0; i < _data._enemies.size(); ++i) {
        _data._map[_data._enemies[i].x].Content[_data._enemies[i].y] = e_prevc;
        if (i == 0) {
            if (_data._map[_data._enemies[i].x].Content[_data._enemies[i].y - 1] != 'W')
                _data._enemies[i].y -= 1;
            if (_data._map[_data._enemies[i].x + 1].Content[_data._enemies[i].y] != 'W' || _data._map[_data._enemies[i].x + 1].Content[_data._enemies[i].y] != 'T')
                _data._enemies[i].x += 1;
            if (_data._map[_data._enemies[i].x - 1].Content[_data._enemies[i].y] != 'W' || _data._map[_data._enemies[i].x + 1].Content[_data._enemies[i].y] != 'T')
                _data._enemies[i].x -= 1;
            if (_data._map[_data._enemies[i].x].Content[_data._enemies[i].y + 1] != 'W' || _data._map[_data._enemies[i].x + 1].Content[_data._enemies[i].y] != 'T')
                _data._enemies[i].y += 1;
        }
        if (i == 1) {
            _data._map[_data._enemies[i].x].Content[_data._enemies[i].y] = e_prevc;
            if (_data._map[_data._enemies[i].x].Content[_data._enemies[i].y - 1] != 'W')
                _data._enemies[i].y -= 1;
            if (_data._map[_data._enemies[i].x - 1].Content[_data._enemies[i].y] != 'W' || _data._map[_data._enemies[i].x + 1].Content[_data._enemies[i].y] != 'T')
                _data._enemies[i].x -= 1;
            if (_data._map[_data._enemies[i].x + 1].Content[_data._enemies[i].y] != 'W' || _data._map[_data._enemies[i].x + 1].Content[_data._enemies[i].y] != 'T')
                _data._enemies[i].x += 1;
            if (_data._map[_data._enemies[i].x].Content[_data._enemies[i].y + 1] != 'W' || _data._map[_data._enemies[i].x + 1].Content[_data._enemies[i].y] != 'T')
                _data._enemies[i].y += 1;
        }
        if (i == 2) {
            _data._map[_data._enemies[i].x].Content[_data._enemies[i].y] = e_prevc;
            if (_data._map[_data._enemies[i].x].Content[_data._enemies[i].y - 1] != 'W')
                _data._enemies[i].y -= 1;
            if (_data._map[_data._enemies[i].x + 1].Content[_data._enemies[i].y] != 'W' || _data._map[_data._enemies[i].x + 1].Content[_data._enemies[i].y] != 'T')
                _data._enemies[i].x += 1;
            if (_data._map[_data._enemies[i].x].Content[_data._enemies[i].y + 1] != 'W' || _data._map[_data._enemies[i].x + 1].Content[_data._enemies[i].y] != 'T')
                _data._enemies[i].y += 1;
            if (_data._map[_data._enemies[i].x - 1].Content[_data._enemies[i].y] != 'W' || _data._map[_data._enemies[i].x + 1].Content[_data._enemies[i].y] != 'T')
                _data._enemies[i].x -= 1;
        }
        e_prevc = _data._map[_data._enemies[i].x].Content[_data._enemies[i].y];
    }
}

void Arcade::Pacman::end_handler()
{
    if (_data._map[_data.ppos_x].Content[_data.ppos_y] == 'G') {
        _data._loose = true;
    }
}

void Arcade::Pacman::points_handler()
{
    if (_data._map[_data.ppos_x].Content[_data.ppos_y] == '.')
        _data._score += 1;
    if (_data._map[_data.ppos_x].Content[_data.ppos_y] == 'C')
        _data._score += 10;
    _data._map[_data.ppos_x].Content[_data.ppos_y] = 'P';
}

void Arcade::Pacman::engine(Arcade::KEYS key)
{
    getkey(key);
    end_handler();
    points_handler();
    game_over();
}

IInfo::GameData Arcade::Pacman::get_game_data()
{
    return _data;
}

std::vector<IInfo::DataInfo> Arcade::Pacman::read_file(std::string map_path)
{
    std::ifstream file(map_path);
    std::string line;
    std::vector<IInfo::DataInfo> ret;
    IInfo::DataInfo _to_add;
    int i = 0;

    if (file.is_open())
        while (std::getline(file, line)) {
            _to_add.Content = line;
            _to_add.x = 0;
            _to_add.y = 0;
            ret.push_back(_to_add);
        }
    return ret;
}

// extern "C" Arcade::Pacman *get_game()
// {
//     return new Arcade::Pacman;
// }

extern "C" Arcade::Pacman *get_game()
{
    return new Arcade::Pacman;
}