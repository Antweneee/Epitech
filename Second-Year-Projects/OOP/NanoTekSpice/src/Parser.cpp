/*
** EPITECH PROJECT, 2022
** bootstrap
** File description:
** Parser
*/

#include "nanotekspice.hpp"

Parser::Parser(std::string name) : _name(name)
{
}

Parser::Parser()
{
    InitGates();
}

void Parser::compute()
{
    InitGates();
    ParseComponent();
    //ExecuteNts();
}

Parser::~Parser()
{
    //std::cout << std::endl << "~Parser(): dtor" << std::endl;
}

bool Parser::startsWith(const std::string &s, const std::string &prefix)
{
    return s.size() >= prefix.size() && s.compare(0, prefix.size(), prefix) == 0;
}

bool Parser::isAssign(std::string &line)
{
    for (std::size_t i = 0; i < line.length(); i += 1) {
        if (line[i] == '=')
            return true;
    }
    return false;
}

std::vector<std::string> Parser::Split(std::string &s, const std::string &delimiter)
{
    size_t pos_start = 0, pos_end = 0, delim_len = delimiter.length();
    std::string token = "";
    std::vector<std::string> res = {};

    while ((pos_end = s.find(delimiter, pos_start)) != std::string::npos) {
        token = s.substr(pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        res.push_back(token);
    }
    res.push_back(s.substr(pos_start));
    return res;
}

void Parser::AssignUndefined()
{
    for (std::size_t i = 0; i < _input.size(); i += 2) {
        _inputs.push_back(_input[i]);
        _inputs.push_back(_input[i + 1]);
    }
    for (std::size_t i = 0; i < _output.size(); i += 2) {
        _outputs.push_back(_output[i]);
        _outputs.push_back(_output[i + 1]);
    }
}

void Parser::ExecuteNts()
{
    char *lineptr = NULL;
    size_t n = 0;
    ssize_t rd = 0;
    std::vector<std::string> assign = {};

    AssignUndefined();
    for (std::cout << "> "; (rd = getline(&lineptr, &n, stdin)) > 0; std::cout << "> ") {
        lineptr[rd - 1] = '\0';
        std::string newline = lineptr;
        if (isAssign(newline) == true) Assign(newline);
        if (newline == "simulate") Simulate();
        if (newline == "display") Display();
        if (newline == "exit") break;
    }
    //debug();
}

void Parser::Assign(std::string &newline)
{
    std::vector<std::string> checkLine = Split(newline, "=");

    for (std::size_t i = 0; i < _input.size(); i += 1) {
        if (checkLine[0] == _input[i]) {
            _assign.push_back(newline);
        }
    }
}

void Parser::Simulate()
{
    if (_assign.size() == 0)
        return;
    _tick += 1;
    for (std::size_t i = 0; i < _assign.size(); i += 1) {
        std::vector<std::string> _tmp = Split(_assign[i], "=");
        for (std::size_t j = 0; j < _inputs.size(); j += 2) {
            if (_inputs[j] == _tmp[0]) _inputs[j + 1] = _tmp[1];
        }
    }
    for (std::size_t i = 0; i < _inputs.size() / 2; i += 2) {
        bool pin      = std::stoi(_inputs[i + 1]);
        bool otherPin = std::stoi(_inputs[i + 3]);
        for (std::size_t j = 1; j < _outputs.size(); j += 2)
            _outputs[j] = std::to_string((this->*(__assignement__[_component[0]]))(pin, otherPin));
    }
}

void Parser::Display()
{
    std::cout << "tick: " << _tick << std::endl;
    std::cout << "input(s):" << std::endl;
    /*
        parcourir le tableau, afficher input + value
    */
    for (std::size_t i = 0; i < _inputs.size(); i += 2) {
        std::cout << "  " << _inputs[i] << ": " << _inputs[i + 1] << std::endl;
    }
    std::cout << "output(s):" << std::endl;
    /*
        parcourir le tableau, afficher output + value
    */
    for (std::size_t i = 0; i < _outputs.size(); i += 2) {
        std::cout << "  " << _outputs[i] << ": " << _outputs[i + 1] << std::endl;
    }
}

int Parser::checkSeparation(std::string &s)
{
    int c = 0;

    for (const auto &ch : s) {
        if (ch == ' ')
            c += 1;
    }
    return c;
}

bool Parser::checkFirstarg(std::string &s)
{
    const std::vector<std::string> _valid = {
        "input", "output", "true", "false",
        "logger", "clock"
    };
    for (std::size_t i = 0; i < _valid.size(); i += 1) {
        if (s == _valid[i])
            return true;
    }
    for (std::size_t i = 0; i < __components.size(); i += 1) {
        if (s == __components[i])
            return true;
    }
    return false;
}

int Parser::checkDuplicateName(std::vector<std::string> &error)
{
    for (std::size_t i = 0; i < error.size(); i += 1) {
        int c = 0;
        std::string _psr = error[i];
        for (std::size_t j = 0; j < error.size(); j += 1) {
            if (_psr == error[j])
                c += 1;
        }
        if (c != 1)
            return c;
    }
    return 0;
}

int Parser::checkDuplicateInstr(std::vector<std::string> &info, const std::string &instr)
{
    for (std::size_t i = 0; i < info.size(); i += 1) {
        int c = 0;
        for (std::size_t j = 0; j < info.size(); j += 1) {
            if (instr == info[j])
                c += 1;
        }
        if (c != 1)
            return c;
    }
    return 0;
}

void Parser::ParseComponent()
{
    std::fstream file;
    std::string line = "";
    std::vector<std::string> info = {};

    file.open(_name, std::ios::in);
    /*
        if (!file.is_open()) error
        if (!file.good()) error
    */
    while (std::getline(file, line)) {
        if (startsWith(line, "#")) continue;
        if (line == "\0") continue;
        info.push_back(line);
    }
    if (checkDuplicateInstr(info, ".chipsets:") != 0 || checkDuplicateInstr(info, ".links:") != 0)
        std::exit(84);
    size_t _chipsets_line = 0;
    //std::cout << ".chipsets: info ->" << std::endl;
    std::vector<std::string> input = {};
    std::vector<std::string> output = {};
    std::vector<std::string> component = {};
    std::vector<std::string> error = {};
    for (size_t i = 0; i < info.size() && info[i] != ".links:"; i += 1, _chipsets_line += 1) {
        if (info[i] == ".chipsets:") continue;
        if (checkSeparation(info[i]) == 0)
            std::exit(84);
        std::vector<std::string> _tmp = Split(info[i], " ");
        if (checkFirstarg(_tmp[0]) == false)
            std::exit(84);
        error.push_back(_tmp[1]);
        if (checkDuplicateName(error) > 1)
            std::exit(84);
        if (_tmp[0] == "input") { input.push_back(_tmp[1]); input.push_back("U"); }
        if (_tmp[0] == "output") { output.push_back(_tmp[1]); output.push_back("U"); }
        for (size_t j = 0; j < __components.size(); j += 1) {
            if (_tmp[0] == __components[j]) {
                component.push_back(_tmp[0]);
                component.push_back(_tmp[1]);
            }
        }
        //std::cout << "[0] == " << _tmp[0] << " && [1] == " << _tmp[1] << std::endl;
    }
    if (component.size() > 2)
        std::exit(84);
    _input = input;
    _output = output;
    _component = component;
    //std::cout << ".links: info ->" << std::endl;
    for (size_t i = _chipsets_line; i < info.size(); i += 1) {
        if (info[i] == ".links:") continue;
        std::vector<std::string> _tmp = Split(info[i], " ");
        //std::cout << "[0] == " << _tmp[0] << " && [1] == " << _tmp[1] << std::endl;
    }
}

Parser &Parser::operator=(Parser &assign)
{
    _input = assign.get_input();
    _output = assign.get_output();
    _component = assign.get_component();
    _assign = assign.get_assign();
    _display = assign.get_display();
    _inputs = assign.get_inputs();
    _outputs = assign.get_outputs();
    return *this;
}

void Parser::debug()
{
    std::cout << "******************* INPUT *******************" << std::endl;
    for (std::size_t i = 0; i < _input.size(); i +=1)
        std::cout << _input[i] << std::endl;
    std::cout << "******************* OUTPUT *******************" << std::endl;
    for (std::size_t i = 0; i < _output.size(); i +=1)
        std::cout << _output[i] << std::endl;
    std::cout << "******************* INPUTS *******************" << std::endl;
    for (std::size_t i = 0; i < _inputs.size(); i +=1)
        std::cout << _inputs[i] << std::endl;
    std::cout << "******************* OUTPUTS *******************" << std::endl;
    for (std::size_t i = 0; i < _outputs.size(); i +=1)
        std::cout << _outputs[i] << std::endl;
    std::cout << "******************* COMPONENT *******************" << std::endl;
    for (std::size_t i = 0; i < _component.size(); i +=1)
        std::cout << _component[i] << std::endl;
    std::cout << "******************* ASSIGN *******************" << std::endl;
    for (std::size_t i = 0; i < _assign.size(); i +=1)
        std::cout << _assign[i] << std::endl;
    std::cout << "******************* DISPLAY *******************" << std::endl;
    for (std::size_t i = 0; i < _display.size(); i +=1)
        std::cout << _display[i] << std::endl;
}