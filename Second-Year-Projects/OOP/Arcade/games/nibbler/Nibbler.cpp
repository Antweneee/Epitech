/*
** EPITECH PROJECT, 2022
** B-OOP-400-PAR-4-1-arcade-valentin.fouillet
** File description:
** Nibbler
*/

#include "Nibbler.hpp"

Arcade::Nibbler::Nibbler(std::string map_path)
{
    _data._map = read_file(map_path);
    _snake_head = '0';
    _snake_body = 'x';
    _snake_tail = 'o';
    _data._win = false;
    _data.ppos_x = 0;
    _data.ppos_y = 0;
    _data._name = "";
    init();
}

Arcade::Nibbler::~Nibbler()
{
}

void Arcade::Nibbler::init()
{
    std::pair<int, int> push;

    for (size_t i = 0; i < _data._map.size(); ++i) {
        if (_data._map[i].Content.find('0') != std::string::npos) {
            push.first = i;
            push.second = _data._map[i].Content.find('0');
            _body_pos.push_back(push);
        } else if (_data._map[i].Content.find('o') != std::string::npos) {
            push.first = i;
            push.second = _data._map[i].Content.find('o');
            _body_pos.push_back(push);
        }
    }
}

void Arcade::Nibbler::getkey(Arcade::KEYS key)
{
    int x = 0;
    std::pair<int, int> keep;
    std::pair<int, int> keep2;

    keep = _body_pos[0];
    _data._map[_prev_headpos.first].Content[_prev_headpos.second] = ' ';
    for (int i = 0; i < 4; i++) {
        if (key == Arcade::__position__[i]._key) {
            _prev_headpos = std::pair<int, int>(_body_pos[0].first, _body_pos[0].second);
            _body_pos[0].first += Arcade::__position__[i].x;
            _body_pos[0].second += Arcade::__position__[i].y;
        }
    }
    for (size_t j = 0; j < _body_pos.size(); ++j) {
        if (j == 0)
            continue;
        keep2 = _body_pos[j];
        _body_pos[j] = keep;
        keep = keep2;
    }
    points_handler();
    end_handler();
    if (_data._loose == true)
        return;
    for (size_t i = 0 ; i < _body_pos.size(); ++i) {
            if (i == 0)
                _data._map[_body_pos[i].first].Content[_body_pos[i].second] = _snake_head;
            else if (i == _body_pos.size() - 1)
                _data._map[_body_pos[i].first].Content[_body_pos[i].second] = _snake_tail;
            else
                _data._map[_body_pos[i].first].Content[_body_pos[i].second] = _snake_body;
            _prev_headpos = _body_pos[i];
    }
}

void Arcade::Nibbler::game_over()
{
    if (_data._score > 10)
        _data._win = true;
}

void Arcade::Nibbler::character_handler()
{
    char apple = 'a';
    int check = 0;
    int rand_x = 0;
    int rand_y = 0;

    for (size_t i = 0; i < _data._map.size(); i++) {
        if (_data._map[i].Content.find("a") != std::string::npos)
            check = _data._map[i].Content.find("a");
    }
    if (check == 0) {
        std::srand(std::time(nullptr));
        rand_x = std::rand() % 20;
        rand_y = std::rand() % 65;
        if (_data._map[rand_x].Content[rand_y] == 'W' || _data._map[rand_x].Content[rand_y] == '0' || _data._map[rand_x].Content[rand_y] == 'x' || _data._map[rand_x].Content[rand_y] == 'o') {
            rand_x++;
            rand_y++;
        }
        if (_data._map[rand_x].Content[rand_y] == 'W' || _data._map[rand_x].Content[rand_y] == '0' || _data._map[rand_x].Content[rand_y] == 'x' || _data._map[rand_x].Content[rand_y] == 'o')
            character_handler();
        _data._map[rand_x].Content[rand_y] = 'a';
    }
}

void Arcade::Nibbler::end_handler()
{
    if (_data._map[_body_pos[0].first].Content[_body_pos[0].second] == 'x' || _data._map[_body_pos[0].first].Content[_body_pos[0].second] == 'o' || _data._map[_body_pos[0].first].Content[_body_pos[0].second] == 'W')
        _data._loose = true;
}

void Arcade::Nibbler::points_handler()
{
    size_t i = 0;
    for (; i < _body_pos.size(); i++);
    i--;
    std::pair<int, int> to_push;

    if (_data._map[_body_pos[0].first].Content[_body_pos[0].second] == 'a') {
        if (_body_pos[i].first - 1 == _body_pos[i - 1].first) { // UP
            to_push.first = _body_pos[i].first + 1;
            to_push.second = _body_pos[i].second;
        }
        if (_body_pos[i].first + 1 == _body_pos[i - 1].first) { // DOWN
            to_push.first = _body_pos[i].first - 1;
            to_push.second = _body_pos[i].second;
        }
        if (_body_pos[i].second - 1 == _body_pos[i - 1].second) {// LEFT
            to_push.first = _body_pos[i].first;
            to_push.second = _body_pos[i].second + 1;
        }
        if (_body_pos[i].second + 1 == _body_pos[i - 1].second) {// RIGHT
            to_push.first = _body_pos[i].first;
            to_push.second = _body_pos[i].second - 1;
        }
        _body_pos.push_back(to_push);
        _data._score += 1;
    }
}

void Arcade::Nibbler::engine(Arcade::KEYS key)
{
    character_handler();
    getkey(key);
    game_over();
}

IInfo::GameData Arcade::Nibbler::get_game_data()
{
    return _data;
}

std::vector<IInfo::DataInfo> Arcade::Nibbler::read_file(std::string map_path)
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

extern "C" Arcade::Nibbler *get_game()
{
    return new Arcade::Nibbler;
}
