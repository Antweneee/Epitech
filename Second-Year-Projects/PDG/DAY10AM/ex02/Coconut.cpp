/*
** EPITECH PROJECT, 2022
** B-PDG-300-PAR-3-1-PDGD10am-antoine.gavira-bottari
** File description:
** Coconut
*/

#include "Coconut.hpp"

Coconut::Coconut()
{
    _name = "coconut";
    _vitamins = 15;
}

Coconut::~Coconut()
{
}

std::string Coconut::getName() const
{
    return _name;
}

int Coconut::getVitamins() const
{
    return _vitamins;
}