/*
** EPITECH PROJECT, 2022
** B-PDG-300-PAR-3-1-PDGD09-antoine.gavira-bottari
** File description:
** Peasant
*/

#include "Peasant.hpp"

const std::string &Peasant::getName() const
{
    return _name;
}

int Peasant::getPower() const
{
    return _power;
}

int Peasant::getHp() const
{
    return _health;
}

int Peasant::attack()
{
    int dmg = 5;

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
        std::cout << _name << " tosses a stone." << std::endl;
    }
    return dmg;
}

int Peasant::special()
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
        std::cout << _name << " doesn't know any special move." << std::endl;
    return dmg;
}

void Peasant::rest()
{
    if (_health == 0) {
        std::cout << _name << " is out of combat." << std::endl;
        return;
    }
    if (_power + 30 > 100)
        _power = 100;
    else
        _power += 30;
    std::cout << _name << " takes a nap." << std::endl;
}

void Peasant::damage(int damage)
{
    if (_health - damage <= 0) {
        _health = 0;
        std::cout << _name << " is out of combat." << std::endl;
    } else {
        _health -= damage;
        std::cout << _name << " takes " << damage << " damage." << std::endl;
    }
}

void Peasant::drink(const HealthPotion &popo)
{
    //+ 50 health
    if (_health + 50 > 100)
        _health = 100;
    else
        _health += 50;
    std::cout << _name << " feels rejuvenated." << std::endl;
}

void Peasant::drink(const PowerPotion &popo)
{
    //+ 50 power
    if (_power + 50 > 100)
        _power = 100;
    else
        _power += 50;
    std::cout << _name << "'s power is restored." << std::endl;
}

void Peasant::drink(const PoisonPotion &popo)
{
    //- 50 health
    if (_health - 50 < 0)
        _health = 0;
    else
        _health -= 50;
    std::cout << _name << " has been poisoned." << std::endl;
}

void Peasant::drink(const IPotion &popo)
{
    std::cout << _name << " drinks a mysterious potion." << std::endl;
    if (popo.getpotion() == "health") {
        if (_health + 50 > 100)
        _health = 100;
        else
            _health += 50;
    }
    if (popo.getpotion() == "power") {
        if (_power + 50 > 100)
        _power = 100;
        else
            _power += 50;
    }
    if (popo.getpotion() == "poison") {
        if (_health - 50 < 0)
        _health = 0;
        else
            _health -= 50;
    }
}