/*
** EPITECH PROJECT, 2022
** B-YEP-410-PAR-4-1-zappy-thomas.willson
** File description:
** Interpret
*/

#ifndef INTERPRET_HPP_
#define INTERPRET_HPP_


    #include <sys/types.h>
    #include <sys/socket.h>
    #include <vector>
    #include <arpa/inet.h>
    #include "Player.hpp"
    #include "Cases.hpp"
    #include "data_server.h"

class Interpret
{
    public:
        Interpret(int const port, std::string const &machine);
        Interpret(Interpret const &) = default;
        ~Interpret();
        int read_server();
        int write_server(std::string const &);
        int init_client();
        int compute_data_in_cpp();

        std::vector<Player> &get_players();
        std::vector<Cases> &get_cases();

        void debug();

    private:
        int can_be_read();

        fd_set _current_socket;
        struct timeval timeout;

        int _socket_fd;
        struct sockaddr_in _addrserver;
        int _port;
        std::string _ip;
        size_t _csize;

        bool _checked;
        data_server_to_gui_t _data_from_server;
        std::string _code;
        std::vector<Player> _players;
        std::vector<Cases> _cases;
};

#endif /* !INTERPRET_HPP_ */
