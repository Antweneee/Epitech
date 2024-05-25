/*
** EPITECH PROJECT, 2022
** B-PDG-300-PAR-3-1-PDGD10am-antoine.gavira-bottari
** File description:
** Banana
*/

#include "Banana.hpp"

Banana::Banana()
{
    _name = "banana";
    _vitamins = 5;
}

Banana::~Banana()
{
}

int Banana::getVitamins() const
{
    return _vitamins;
}

std::string Banana::getName() const
{
    return _name;
}