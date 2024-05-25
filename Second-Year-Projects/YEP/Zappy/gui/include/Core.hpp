/*
** EPITECH PROJECT, 2022
** B-YEP-410-PAR-4-1-zappy-thomas.willson
** File description:
** Core
*/

#ifndef CORE_HPP_
#define CORE_HPP_

    #include <string>
    #include "scenes.hpp"

class Core {
    public:
        Core(std::string &port, std::string machine);
        ~Core();

        int engine();
    private:
        std::string _machine;
        int _port;
        Scenes _actualScene;
};

#endif /* !CORE_HPP_ */
