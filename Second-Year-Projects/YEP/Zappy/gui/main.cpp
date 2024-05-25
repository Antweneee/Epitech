/*
** EPITECH PROJECT, 2022
** B-YEP-410-PAR-4-1-zappy-thomas.willson
** File description:
** main
*/

#include <algorithm>
#include <iostream>
#include <unordered_map>
#include "Core.hpp"
#include "Settings.hpp"
#include "MenuScene.hpp"

int usage(char const *av[])
{
    std::string arg(av[1]);

    if (arg.compare("-help") == 0) {
        std::cout <<"USAGE: ./zappy_ai -p port -h machine" << std::endl;
        std::cout << "port is the port number" << std::endl;
        std::cout << "machine is the name of the machine; localhost by default" << std::endl;
        return 1;
    }
    return 0;
}

int check_machine(std::string const &machine)
{
    if (machine.compare("localhost") == 0)
        return 0;
    size_t n = std::count(machine.begin(), machine.end(), '.');
    if (n != 3) {
        std::cerr << "wrong machine" << std::endl;
        return 1;
    }
    return 0;
}

int check_args(int argc, const char *argv[], std::string &s_port, std::string &s_machine)
{
    std::string arg;
    std::string machine;

    for (size_t i = 1; i < (size_t)argc; i++) {
        arg = argv[i];
        if (arg.compare("-p") == 0 && argv[i + 1]) {
            try{
                std::stoi(argv[i + 1]);
                s_port = argv[i + 1];
            }
            catch(std::exception &err)
            {
                std::cout<<"Conversion failure: "<< err.what() << std::endl;
                return 1;
            }

            i++;
            continue;
        } else if (arg.compare("-h") == 0 && argv[i + 1]) {
            machine = argv[i + 1];
            i++;
            continue;
        } else {
            std::cerr << "wrong argument try ./zappy_gui -help" << std::endl;
            return 1;
        }
    }
    if (!machine.empty())
        if (check_machine(machine) == 1)
            return 1;
    s_machine = machine;
    return 0;
}

int main(int argc, const char* argv[])
{
    std::string port;
    std::string machine;

    if (argc < 3)
        return 84;
    if (usage(argv) == 1)
        return 0;
    if (check_args(argc, argv, port, machine) == 1)
        return 84;
    Core core(port, machine);
    if (core.engine() == 1)
       return 84;
    return (0);
}