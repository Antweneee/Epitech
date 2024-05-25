/*
** EPITECH PROJECT, 2022
** B-PDG-300-PAR-3-1-PDGD09-antoine.gavira-bottari
** File description:
** Knight
*/

#include "Knight.hpp"

int Knight::attack()
{
    int dmg = 20;

    if (_health <= 0) {
        _health = 0;
        std::cout << _name << " is out of combat." << std::endl;
        dmg = 0;
        return dmg;
    }
    if (_power <= 0) {
        _power = 0;
        dmg = 0;
        std::cout << _name << " is out of power." << std::endl;
    } else if (_power < 10) {
        std::cout << _name << " is out of power." << std::endl;
        dmg = 0;
    } else {
        _power -= 10;
        std::cout << _name << " strikes with his sword." << std::endl;
    }
    return dmg;
}

int Knight::special()
{
    int dmg = 50;

    if (_health <= 0) {
        _health = 0;
        std::cout << _name << " is out of combat." << std::endl;
        dmg = 0;
        return dmg;
    }
    if (_power <= 0) {
        std:: cout << _name << " is out of power." << std::endl;
        dmg = 0;
        _power = 0;
    } else if (_power < 30) {
        std:: cout << _name << " is out of power." << std::endl;
        dmg = 0;
    } else {
        std::cout << _name << " impales his enemy." << std::endl;
        _power -= 30;
    }
    return dmg;
}

void Knight::rest()
{
    if (_health == 0) {
        std::cout << _name << " is out of combat." << std::endl;
        return;
    }
    if (_power + 50 > 100)
        _power = 100;
    else
        _power += 50;
    std::cout << _name << " eats." << std::endl;
}