/*
** EPITECH PROJECT, 2022
** B-PDG-300-PAR-3-1-PDGD09-antoine.gavira-bottari
** File description:
** Enchanter
*/

#include "Enchanter.hpp"

int Enchanter::attack()
{
    int dmg = 0;

    if (_health <= 0) {
        _health = 0;
        std::cout << _name << " is out of combat." << std::endl;
        dmg = 0;
        return dmg;
    }
    if (_power <= 0)
        _power = 0;
    else
        std::cout << _name << " doesn't know how to fight." << std::endl;
    return dmg;
}

int Enchanter::special()
{
    int dmg = 99;

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
    } else if (_power < 50) {
        std:: cout << _name << " is out of power." << std::endl;
        dmg = 0;
    } else {
        std::cout << _name << " casts a fireball." << std::endl;
        _power -= 50;
    }
    return dmg;
}

void Enchanter::rest()
{
    if (_health == 0) {
        std::cout << _name << " is out of combat." << std::endl;
        return;
    }
    if (_power + 100 > 100)
        _power = 100;
    else
        _power += 100;
    std::cout << _name << " meditates." << std::endl;
}