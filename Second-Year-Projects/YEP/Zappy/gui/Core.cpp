/*
** EPITECH PROJECT, 2022
** B-YEP-410-PAR-4-1-zappy-thomas.willson
** File description:
** Core
*/

#include "Interpret.hpp"
#include "Core.hpp"
#include "Display.hpp"

Core::Core(std::string &port, std::string machine) : _machine(machine)
{
    _port = std::stoi(port);
    if (_machine.empty())
        _machine = "127.0.0.1";
    _actualScene = Scenes::MENU;
}

Core::~Core()
{
}

int Core::engine()
{
    bool is_running = true;
    bool menu_running = true;
    Display display(_machine);

    display.init_menu();
    while (menu_running) {
        if (display.engine() == 1)
            return 0;
        if (display.getSettings()->getScene() == Scenes::GAME)
            menu_running = false;
    }
    Interpret interpreter(_port, display.getSettings()->getMachine());
    if (interpreter.init_client() == 1)
        return 1;
    interpreter.compute_data_in_cpp();
    display.init(interpreter.get_players(), interpreter.get_cases());
    while (is_running) {
        if (display.engine() == 1) {
            is_running = false;
        } else {
            if (display.getSettings()->getScene() == Scenes::GAME) {
                interpreter.read_server();
                if (interpreter.compute_data_in_cpp() == 1)
                    display.init(interpreter.get_players(), interpreter.get_cases());
                display.refresh_datas(interpreter.get_players(), interpreter.get_cases());
            }
        }
    }
    interpreter.write_server("QUIT");
    display.destroy_all();
    return 0;
}

