/*
** EPITECH PROJECT, 2022
** B-PDG-300-PAR-3-1-PDGD10am-antoine.gavira-bottari
** File description:
** Lemon
*/

#include "Lemon.hpp"

Lemon::Lemon()
{
    _name = "lemon";
    _vitamins = 3;
}

Lemon::~Lemon()
{
}

int Lemon::getVitamins() const
{
    return _vitamins;
}


std::string Lemon::getName() const
{
    return _name;
}