/*
** EPITECH PROJECT, 2022
** B-YEP-410-PAR-4-1-zappy-thomas.willson
** File description:
** Interpret
*/

#include <algorithm>
#include <string>
#include "Interpret.hpp"

Interpret::Interpret(int const port, std::string const &machine) : _socket_fd(0), _addrserver({}), _port(port), _csize(0), _checked(false), _data_from_server({}), _code(""), _players({}), _cases({})
{
    if (machine.compare("localhost") == 0)
        _ip = "127.0.0.1";
    else
        _ip = machine;
    //_data_from_server = data_server_to_gui_t {
    //   .code = "AA",
    //   .number_cases = 100,
    //   .cases = {
    //       {0, 0, 3, 4, 5, 6, 7, 8, 9}, {1, 0, 3, 4, 0, 6, 7, 8, 9}, {2, 0, 3, 4, 5, 6, 7, 8, 9}, {3, 0, 3, 4, 5, 6, 7, 8, 9}, {4, 0, 3, 4, 5, 6, 7, 8, 9}, {5, 0, 3, 4, 5, 6, 7, 8, 9}, {6, 0, 3, 4, 5, 6, 7, 8, 9}, {7, 0, 3, 4, 5, 6, 7, 8, 9}, {8, 0, 3, 4, 5, 6, 7, 8, 9}, {9, 0, 3, 4, 5, 6, 7, 8, 9},
    //       {0, 1, 3, 0, 5, 6, 0, 8, 9}, {1, 1, 3, 4, 5, 0, 7, 8, 9}, {2, 1, 3, 4, 5, 6, 7, 8, 9}, {3, 1, 3, 4, 5, 6, 7, 8, 9}, {4, 1, 3, 4, 5, 6, 7, 8, 9}, {5, 1, 3, 4, 5, 6, 7, 8, 9}, {6, 1, 3, 4, 5, 6, 7, 8, 9}, {7, 1, 3, 4, 5, 6, 7, 8, 9}, {8, 1, 3, 4, 5, 6, 7, 8, 9}, {9, 1, 3, 4, 5, 6, 7, 8, 9},
    //       {0, 2, 0, 4, 5, 6, 7, 8, 9}, {1, 2, 3, 4, 5, 6, 7, 8, 9}, {2, 2, 3, 4, 5, 6, 7, 8, 9}, {3, 2, 3, 4, 5, 6, 7, 8, 9}, {4, 2, 3, 4, 5, 6, 7, 8, 9}, {5, 2, 3, 4, 5, 6, 7, 8, 9}, {6, 2, 3, 4, 5, 6, 7, 8, 9}, {7, 2, 3, 4, 5, 6, 7, 8, 9}, {8, 2, 3, 4, 5, 6, 7, 8, 9}, {9, 2, 3, 4, 5, 6, 7, 8, 9},
    //       {0, 3, 3, 4, 5, 6, 7, 8, 9}, {1, 3, 0, 4, 5, 6, 7, 8, 9}, {2, 3, 3, 4, 5, 6, 7, 8, 9}, {3, 3, 3, 4, 5, 6, 7, 8, 9}, {4, 3, 3, 4, 5, 6, 7, 8, 9}, {5, 3, 3, 4, 5, 6, 7, 8, 9}, {6, 3, 3, 4, 5, 6, 7, 8, 9}, {7, 3, 3, 4, 5, 6, 7, 8, 9}, {8, 3, 3, 4, 5, 6, 7, 8, 9}, {9, 3, 3, 4, 5, 6, 7, 8, 9},
    //       {0, 4, 0, 4, 5, 6, 7, 8, 9}, {1, 4, 3, 4, 5, 6, 7, 8, 9}, {2, 4, 3, 4, 5, 6, 7, 8, 9}, {3, 4, 3, 4, 5, 6, 7, 8, 9}, {4, 4, 3, 4, 5, 6, 7, 8, 9}, {5, 4, 3, 4, 5, 6, 7, 8, 9}, {6, 4, 3, 4, 5, 6, 7, 8, 9}, {7, 4, 3, 4, 5, 6, 7, 8, 9}, {8, 4, 3, 4, 5, 6, 7, 8, 9}, {9, 4, 3, 4, 5, 6, 7, 8, 9},
    //       {0, 5, 3, 4, 5, 6, 7, 8, 9}, {1, 5, 3, 4, 5, 6, 7, 8, 9}, {2, 5, 3, 4, 5, 6, 7, 8, 9}, {3, 5, 3, 4, 5, 6, 7, 8, 9}, {4, 5, 3, 4, 5, 6, 7, 8, 9}, {5, 5, 3, 4, 5, 6, 7, 8, 9}, {6, 5, 3, 4, 5, 6, 7, 8, 9}, {7, 5, 3, 4, 5, 6, 7, 8, 9}, {8, 5, 3, 4, 5, 6, 7, 8, 9}, {9, 5, 3, 4, 5, 6, 7, 8, 9},
    //       {0, 6, 3, 4, 5, 6, 7, 8, 9}, {1, 6, 3, 4, 5, 6, 7, 8, 9}, {2, 6, 3, 4, 5, 6, 7, 8, 9}, {3, 6, 3, 4, 5, 6, 7, 8, 9}, {4, 6, 3, 4, 5, 6, 7, 8, 9}, {5, 6, 3, 4, 5, 6, 7, 8, 9}, {6, 6, 3, 4, 5, 6, 7, 8, 9}, {7, 6, 3, 4, 5, 6, 7, 8, 9}, {8, 6, 3, 4, 5, 6, 7, 8, 9}, {9, 6, 3, 4, 5, 6, 7, 8, 9},
    //       {0, 7, 3, 4, 5, 6, 7, 8, 9}, {1, 7, 3, 4, 5, 6, 7, 8, 9}, {2, 7, 3, 4, 5, 6, 7, 8, 9}, {3, 7, 3, 4, 5, 6, 7, 8, 9}, {4, 7, 3, 4, 5, 6, 7, 8, 9}, {5, 7, 3, 4, 5, 6, 7, 8, 9}, {6, 7, 3, 4, 5, 6, 7, 8, 9}, {7, 7, 3, 4, 5, 6, 7, 8, 9}, {8, 7, 3, 4, 5, 6, 7, 8, 9}, {9, 7, 3, 4, 5, 6, 7, 8, 9},
    //       {0, 8, 3, 4, 5, 6, 7, 8, 9}, {1, 8, 3, 4, 5, 6, 7, 8, 9}, {2, 8, 3, 4, 5, 6, 7, 8, 9}, {3, 8, 3, 4, 5, 6, 7, 8, 9}, {4, 8, 3, 4, 5, 6, 7, 8, 9}, {5, 8, 3, 4, 5, 6, 7, 8, 9}, {6, 8, 3, 4, 5, 6, 7, 8, 9}, {7, 8, 3, 4, 5, 6, 7, 8, 9}, {8, 8, 3, 4, 5, 6, 7, 8, 9}, {9, 8, 3, 4, 5, 6, 7, 8, 9},
    //       {0, 9, 3, 4, 5, 6, 7, 8, 9}, {1, 9, 3, 4, 5, 6, 7, 8, 9}, {2, 9, 3, 4, 5, 6, 7, 8, 9}, {3, 9, 3, 4, 5, 6, 7, 8, 9}, {4, 9, 3, 4, 5, 6, 7, 8, 9}, {5, 9, 3, 4, 5, 6, 7, 8, 9}, {6, 9, 3, 4, 5, 6, 7, 8, 9}, {7, 9, 3, 4, 5, 6, 7, 8, 9}, {8, 9, 3, 4, 5, 6, 7, 8, 9}, {9, 9, 3, 4, 5, 6, 7, 8, 9}
    //   },
    //   .number_players = 4,
    //   .players = {
    //       {0, 0, 1, 1, DEFAULT, 1},
    //       {0, 1, 2, 2, DEFAULT, 1},
    //       {0, 2, 3, 3, DEFAULT, 1},
    //       {0, 3, 4, 4, DEFAULT, 1}
    //   }
    //};
    timeout.tv_sec = 0;
    timeout.tv_usec = 300;
}

Interpret::~Interpret()
{
}

void Interpret::debug()
{
    std::cout << "code is :" << _code << std::endl;
    if (!_players.empty()) {
        for (size_t i = 0; i < _players.size(); ++i) {
            std::cout << "player if : " << _players[i].get_player_id() << std::endl;
            std::cout << "team id : " << _players[i].get_team_id() << std::endl;
            std::cout << "action id : " << _players[i].get_action_id() << std::endl;
            std::cout << "level : " << _players[i].get_level() << std::endl;
        }
    } else
        std::cout << "_players empty" << std::endl;
    if (!_cases.empty()) {
        for (size_t i = 0; i < _cases.size(); ++i) {
            std::cout << "food : " << _cases[i].get_food() << std::endl;
            std::cout << "deraumere : " << _cases[i].get_deraumere() << std::endl;
            std::cout << "linemate : " << _cases[i].get_linemate() << std::endl;
            std::cout << "mendiane : " << _cases[i].get_mendiane() << std::endl;
            std::cout << "phiras : " << _cases[i].get_phiras() << std::endl;
            std::cout << "sibur : " << _cases[i].get_sibur() << std::endl;
            std::cout << "thystame: " << _cases[i].get_thystame() << std::endl << std::endl;
        }
    } else
        std::cout << "_cases empty" << std::endl;
}

int Interpret::write_server(std::string const &str_to_send)
{
    receive_gui_t to_send{0};
    str_to_send.copy(to_send.code, str_to_send.size());

    try {
        send(_socket_fd, &to_send, sizeof(receive_gui_t), 0);
    } catch (std::exception &err) {
        std::cerr << "send failed " << err.what() << std::endl;
        return 1;
    }
    return 0;
}

int Interpret::can_be_read()
{
    FD_ZERO(&_current_socket);
    FD_SET(_socket_fd, &_current_socket);
    try {
        select(FD_SETSIZE, &_current_socket, NULL, NULL, &timeout);
    } catch (std::exception &err) {
        std::cerr << "select failed " << err.what() << std::endl;
        return -1;
    }
    if (FD_ISSET(_socket_fd, &_current_socket))
        return 1;
    return 0;
}

int Interpret::read_server()
{
    int check = 0;

    check = can_be_read();
    if (check == 0)
        return 0;
    else if (check == -1)
        return 1;
    try {
        recv(_socket_fd, &_data_from_server, sizeof(data_server_to_gui_t), 0);
        _checked = false;
    } catch (std::exception &err) {
        std::cerr << "recv failed " << err.what() << std::endl;
        return 1;
    }
    return 0;
}

std::vector<Player> &Interpret::get_players()
{
    return _players;
}

std::vector<Cases> &Interpret::get_cases()
{
    return _cases;
}

int Interpret::compute_data_in_cpp()
{
    _code = _data_from_server.code;

    _players.clear();
    _cases.clear();
    if (_code.compare("APLA") == 0 && _checked == false) {
        for (int i = 0; i < _data_from_server.number_players; i++) {
            _players.emplace_back(_data_from_server.players[i]);
            std::cout << "new player APLA" << std::endl;
        }
        _checked = true;
        return 0;
    } else if (_code.compare("AMAP") == 0 && _checked == false) {
        for (int i = 0; i < _data_from_server.number_cases; i++)
            _cases.emplace_back(_data_from_server.cases[i]);
        _checked = true;
        return 1;
    } else if (_code.compare("AA") == 0 && _checked == false) {
        for (int i = 0; i < _data_from_server.number_players; i++)
            _players.emplace_back(_data_from_server.players[i]);
        for (int i = 0; i < _data_from_server.number_cases; i++)
            _cases.emplace_back(_data_from_server.cases[i]);
        _checked = true;
        return 1;
    } else if (_code.compare("MPLA") == 0 && _checked == false) {
        for (int i = 0; i < _data_from_server.number_players; i++)
            _players.emplace_back(_data_from_server.players[i]);
        _checked = true;
        return 0;
    } else if (_code.compare("MMAP") == 0 && _checked == false) {
        for (int i = 0; i < _data_from_server.number_cases; i++)
            _cases.emplace_back(_data_from_server.cases[i]);
        _checked = true;
        return 0;
    }
    return 0;
}

int Interpret::init_client()
{
    try {
        _socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    } catch (std::exception &err) {
        std::cerr << "socket failed " << err.what() << std::endl;
        return 1;
    }
    _addrserver.sin_addr.s_addr = inet_addr(_ip.c_str());
    _addrserver.sin_family = AF_INET;
    _addrserver.sin_port = htons(_port);
    _ip = inet_ntoa(_addrserver.sin_addr);
    _csize = sizeof(_addrserver);
    try {
      connect(_socket_fd, (const struct sockaddr *)&_addrserver, _csize);
    } catch (std::exception &err) {
        std::cerr << "connect failed " << err.what() << std::endl;
        return 1;
    }
    if (write_server("/type GUI") == 1)
        return 1;
    read_server();
    return 0;
}