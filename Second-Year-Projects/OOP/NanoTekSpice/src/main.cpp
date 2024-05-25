/*
** EPITECH PROJECT, 2022
** B-OOP-400-PAR-4-1-tekspice-antoine.gavira-bottari
** File description:
** main
*/

#include <iostream>
#include "nanotekspice.hpp"
#include "Parser.hpp"
#include "IComponent.hpp"

std::vector<std::string> Chipset_list = {
    {"2716"},
    {"4001"},
    {"4008"},
    {"4011"},
    {"4013"},
    {"4017"},
    {"4030"},
    {"4040"},
    {"4069"},
    {"4071"},
    {"4081"},
    {"4094"},
    {"4512"},
    {"4514"},
    {"4801"}
};

class Pathing
{
    public:
        Pathing() {}
        ~Pathing() {}

        /******************** FUNCTION ********************/
        void case_4071(Parser &parser, std::string cmd)
        {
            Chipsets::fourty_seventy_one chip("4071", parser);

            if (cmd.compare("simulate") == 0)
                chip.simulate(0);
            // if (cmd.compare("display") == 0)
            //     std::cout << "DISPLAY" << std::endl;
        }

        void case_4001(Parser &parser, std::string cmd)
        {
            Chipsets::fourty_one chip("4001", parser);

            if (cmd.compare("simulate") == 0)
                chip.simulate(0);
            // if (cmd.compare("display") == 0)
            //     std::cout << "DISPLAY" << std::endl;
        }

        void case_4030(Parser &parser, std::string cmd)
        {
            Chipsets::fourty_thirty chip("4030", parser);

            if (cmd.compare("simulate") == 0)
                chip.simulate(0);
            // if (cmd.compare("display") == 0)
            //     std::cout << "DISPLAY" << std::endl;
        }

        void compute(Parser &parser)
        {
            _chipset_name = get_chipset(parser.get_component());
            init_chipset();
        }

        void execute(std::string cmd, Parser &parser)
        {
            (this->*(_chipset[_chipset_name]))(parser, cmd);
        }

        void init_chipset()
        {
            if (_chipset_name.empty())
                return;
            if (_chipset_name == "4071")
                _chipset[_chipset_name] = &Pathing::case_4071;
            if (_chipset_name == "4001")
                _chipset[_chipset_name] = &Pathing::case_4001;
            if (_chipset_name == "4030")
                _chipset[_chipset_name] = &Pathing::case_4030;
        }

        std::string get_chipset(std::vector<std::string> to_parse)
        {
            for (std::size_t i = 0; i < to_parse.size(); i++) {
                for (std::size_t j = 0; j < Chipset_list.size(); j++) {
                    if (to_parse[i].compare(Chipset_list[j]) == 0)
                        return Chipset_list[j];
                }
            }
            return std::string("");
        }

        /******************** MAP THAT LINK THE CHIPSET NAME WITH THE RIGHT CHIPSET ********************/
        std::map<std::string, void (Pathing::*)(Parser &, std::string)> _chipset;
    private:
        /******************** VARIABLES ********************/
        std::string _chipset_name;
};




void loop(Parser &parser)
{
    char *lineptr = NULL;
    size_t n = 0;
    ssize_t rd = 0;
    std::vector<std::string> assign = {};
    //Pathing right_chipset;

    //right_chipset.compute(parser);
    parser.AssignUndefined();
    for (std::cout << "> "; (rd = getline(&lineptr, &n, stdin)) > 0; std::cout << "> ") {
        lineptr[rd - 1] = '\0';
        std::string newline = lineptr;
        if (parser.isAssign(newline) == true) parser.Assign(newline);
        if (newline == "simulate") parser.Simulate();
        if (newline == "display") parser.Display();
        if (newline == "exit") break;
        //right_chipset.execute(newline, parser);
    }
    free(lineptr);
    //parser.debug();
}

int main(int argc, char const *argv[])
{
    if (argc != 2)
        return 84;
    return 84;
    Parser parser((std::string(argv[1])));
    parser.compute();
    loop(parser);
    return 0;
}