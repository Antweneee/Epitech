/*
** EPITECH PROJECT, 2022
** B-PDG-300-PAR-3-1-PDGD07pm-antoine.gavira-bottari
** File description:
** Part
*/

#include "Part.hpp"

Arms::Arms(const std::string &serial, bool functional)
{
    _serial = serial;
    _functional= functional;
}

Arms::~Arms()
{
}

bool Arms::isFunctional()
{
    return _functional;
}

std::string Arms::serial()
{
    return _serial;
}

void Arms::informations()
{
    if (isFunctional() == true)
        std::cout << "\t[Parts] Arms " << _serial << " status : " << "OK" << std::endl;
    else
        std::cout << "\t[Parts] Arms " << _serial << " status : " << "KO" << std::endl;
}

Legs::Legs(const std::string &serial, bool functional)
{
    _serial = serial;
    _functional= functional;
}

Legs::~Legs()
{
}

bool Legs::isFunctional()
{
    return _functional;
}

std::string Legs::serial()
{
    return _serial;
}

void Legs::informations()
{
    if (isFunctional() == true)
        std::cout << "\t[Parts] Arms " << _serial << " status : " << "OK" << std::endl;
    else
        std::cout << "\t[Parts] Arms " << _serial << " status : " << "KO" << std::endl;
}

Head::Head(const std::string &serial, bool functional)
{
    _serial = serial;
    _functional= functional;
}

Head::~Head()
{
}

bool Head::isFunctional()
{
    return _functional;
}

std::string Head::serial()
{
    return _serial;
}

void Head::informations()
{
    if (isFunctional() == true)
        std::cout << "\t[Parts] Arms " << _serial << " status : " << "OK" << std::endl;
    else
        std::cout << "\t[Parts] Arms " << _serial << " status : " << "KO" << std::endl;
}