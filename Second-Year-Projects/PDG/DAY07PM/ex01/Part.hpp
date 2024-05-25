/*
** EPITECH PROJECT, 2022
** B-PDG-300-PAR-3-1-PDGD07pm-antoine.gavira-bottari
** File description:
** Part
*/

#ifndef PART_HPP_
#define PART_HPP_

#include <iostream>
#include <string>

class Arms
{
    public:
        std::string _serial;
        bool _functional;

        Arms(const std::string &serial = "A-01", bool functional = true);
        ~Arms();
        std::string serial();
        bool isFunctional();
        void informations();
};

class Legs
{
    public:
        std::string _serial;
        bool _functional;

        Legs(const std::string &serial = "L-01", bool functional = true);
        ~Legs();
        std::string serial();
        bool isFunctional();
        void informations();
};

class Head
{
    public:
        std::string _serial;
        bool _functional;

        Head(const std::string &serial = "H-01", bool functional = true);
        ~Head();
        std::string serial();
        bool isFunctional();
        void informations();
};

#endif /* !PART_HPP_ */