/*
** EPITECH PROJECT, 2022
** B-PDG-300-PAR-3-1-PDGD09-antoine.gavira-bottari
** File description:
** Priest
*/

#include "Priest.hpp"

void Priest::rest()
{
    if (_health == 0) {
        std::cout << _name << " is out of combat." << std::endl;
        return;
    }
    if (_power + 100 > 100)
        _power = 100;
    else
        _power += 100;
    if (_health + 100 > 100)
        _health = 100;
    else
        _health += 100;
    std::cout << _name << " prays." << std::endl;
}