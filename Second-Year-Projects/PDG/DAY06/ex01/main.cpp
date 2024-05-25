/*
** EPITECH PROJECT, 2022
** B-PDG-300-PAR-3-1-PDGD06-antoine.gavira-bottari
** File description:
** main
*/

#include <iostream>
#include <string>
#include <cstring>
#include <iomanip>

class elem
{
    public:
    std::string _to_parse;
    std::string _first_half;
    std::string _second_half;
    float _res;
    int _case;

    elem(std::string get)
    {
        _to_parse = get;
        _res = 0;
        _case = 0;
    };

    int parse()
    {
        std::string delim = " ";
        size_t pos = 0;

        if (_to_parse.empty() || _to_parse.find(delim) == std::string::npos)
            return 84;
        while ((pos = _to_parse.find(delim)) != std::string::npos) {
            _first_half = _to_parse.substr(0, pos);
            _to_parse.erase(0, pos + delim.length());
        }
        _second_half = _to_parse;
        if (_error() == 1)
            return 84;
        _compute();
        return 0;
    }

    void _print()
    {
        if (_case == 1)
        {
            std::cout << std::fixed << std::setprecision(3) <<  std::setw(16) << _res;
            std::cout << std::setw(16) << "Celsius" << std::endl;
        }
        else
        {
            std::cout << std::fixed << std::setprecision(3) << std::setw(16) << _res;
            std::cout << std::setw(16) << "Fahrenheit" << std::endl;
        }
    }

    int _error()
    {
        int error = 0;
        int check = 0;

        if (_second_half.compare("Celsius") == 0)
        {
            check = 1;
        }
        else if (_second_half.compare("Fahrenheit") == 0)
        {
            check = 1;
        }
        if (check == 0)
            error += 1;
        if (error > 0)
            return 1;
        return 0;
    }

    private:
    void _compute()
    {
        float convert = std::stof(_first_half);

        if (_second_half.compare("Celsius") == 0)
        {
            _res = (convert * (9.0 / 5.0) + 32);
        }
        else {
            _res = ((convert - 32) * (5.0 / 9.0));
            _case = 1;
        }
    }
};

std::string get_line(void)
{
    std::string line;

    std::getline(std::cin, line);
    return line;
}

int main(int argc, char const **argv)
{
    std::string line = get_line();
    elem test(line);

    if (test.parse() == 84)
        return 0;
    test._print();
    return 0;
}