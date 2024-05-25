/*
** EPITECH PROJECT, 2022
** B-PDG-300-PAR-3-1-PDGD06-antoine.gavira-bottari
** File description:
** SickKoala
*/

#include "SickKoala.hpp"

SickKoala::SickKoala(std::string set) : _name(set)
{
}

SickKoala::~SickKoala()
{
    std::cout << "Mr." << _name << ": Kreooogg!! I'm cuuuured!" << std::endl;
}

void SickKoala::poke(void)
    {
        std::cout << "Mr." << _name << ": Gooeeeeerrk!!" << std::endl;
    }

bool SickKoala::takeDrug(std::string check)
{
    if (check.compare("Mars") == 0) {
        std::cout << "Mr." << _name << ": Mars, and it kreogs!" << std::endl;
        return true;
    } else if (check.compare("Kinder") == 0) {
        std::cout << "Mr." << _name << ": There is a toy inside!" << std::endl;
        return true;
    } else
        std::cout << "Mr." << _name << ": Goerkreog!" << std::endl;
    return false;
}
void SickKoala::overDrive(std::string check)
{
    std::string tmp = std::regex_replace(check, std::regex("Kreog!"), "1337!");
    std::cout << "Mr." << _name << ": " << tmp << std::endl;
}

std::string SickKoala::getName(void)
{
    return _name;
}