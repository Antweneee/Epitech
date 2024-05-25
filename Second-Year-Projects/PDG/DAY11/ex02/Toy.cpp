/*
** EPITECH PROJECT, 2022
** B-PDG-300-PAR-3-1-PDGD11-antoine.gavira-bottari
** File description:
** Toy
*/

#include <iostream>
#include "Toy.hpp"

Toy &Toy::operator=(Toy const &cpy)
{
    type = cpy.type;
    name = cpy.name;
    picture = cpy.picture;
    return *this;
}

Toy &Toy::operator<<(std::string const &ascii)
{
    picture.data = ascii;
    return *this;
}