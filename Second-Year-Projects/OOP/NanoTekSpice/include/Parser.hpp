/*
** EPITECH PROJECT, 2022
** bootstrap
** File description:
** Parser
*/

#ifndef PARSER_HPP_
#define PARSER_HPP_

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <map>
#include <functional>
#include <unistd.h>

class Parser
{
public:
    Parser(std::string);
    Parser();
    ~Parser();
    /*
        ***********INIT GATE FUNCTION*********************
    */
    void InitGates()
    {
        __assignement__["4001"] = &Parser::nor_gate;
        __assignement__["4011"] = &Parser::nand_gate;
        __assignement__["4030"] = &Parser::xor_gate;
        //__assignement__["4069"] = &Parser::not_gate;
        __assignement__["4071"] = &Parser::or_gate;
        __assignement__["4081"] = &Parser::and_gate;

    }
    /*
        ***********BINARY OPERATOR FUNCTIONS**************
    */
    bool and_gate(bool &a, bool &b) const { return a & b; }
    bool or_gate(bool &a, bool &b) const { return a | b; }
    bool xor_gate(bool &a, bool &b) const { return a ^ b; }
    bool not_gate(bool &a) const {return !(a);}
    bool nand_gate(bool &a, bool &b) const {if (a == true && b == true)return true;return false;}
    bool nor_gate(bool &a, bool &b) const {return !(a + b);}
    bool xnor_gate(bool &a, bool &b) const {return !(a ^ b);}
    /*
        **************UTILITIES FUNCTIONS***************
    */
    void ExecuteNts();
    void ParseComponent();
    void AssignUndefined();
    void Assign(std::string &);
    void Simulate();
    void Display();
    void debug();
    void compute();

    std::vector<std::string> get_special_input()
    {
        std::vector<std::string> tmp;

        for (std::size_t i = 0; i < _input.size(); ++i) {
            if (_input[i].compare("U") == 0)
                continue;
            else
                tmp.push_back(_input[i]);
        }
        return tmp;
    }

    std::vector<std::string> get_special_output(){
        std::vector<std::string> tmp;

        for (std::size_t i = 0; i < _output.size(); ++i) {
            if (_output[i].compare("U") == 0)
                continue;
            else
                tmp.push_back(_output[i]);
        }
        return tmp;
    }
    std::string get_name() {return _name;}
    int get_tick() {return _tick;}
    std::vector<std::string> get_special_assign() {return _assign;}
    std::vector<std::string> get_input() {return _input;}
    std::vector<std::string> get_output() {return _output;}
    std::vector<std::string> get_component() {return _component;}
    std::vector<std::string> get_assign() {return _assign;}
    std::vector<std::string> get_display() {return _display;}
    std::vector<std::string> get_inputs() {return _inputs;}
    std::vector<std::string> get_outputs() {return _outputs;}

    /*
        *************OPERATOR FUNCTIONS*****************
    */
    Parser &operator=(Parser &assign);
    /*
        *************PARSING FUNCTIONS*****************
    */
    bool startsWith(const std::string &, const std::string &);
    bool isAssign(std::string &);
    std::vector<std::string> Split(std::string &s, const std::string &);
    int checkSeparation(std::string &);
    bool checkFirstarg(std::string &);
    int checkDuplicateName(std::vector<std::string> &);
    int checkDuplicateInstr(std::vector<std::string> &, const std::string &);

private:
    const std::vector<std::string> __components =
    {
        "4001", "4011", "4030", "4071", "4081",
        "4069", "4008", "4013", "4017", "4040",
        "4094", "4512", "4514", "4801", "2716"
    };
    std::map<std::string, bool (Parser::*)(bool &, bool &) const> __assignement__;

private:
    std::vector<std::string> _error;
    std::string _name;
    std::vector<std::string> _input;
    std::vector<std::string> _output;
    std::vector<std::string> _component;
    std::vector<std::string> _assign;
    std::vector<std::string> _display;
    int _tick = 0;
    std::vector<std::string> _inputs;
    std::vector<std::string> _outputs;
};

#endif /* !PARSER_HPP_ */
