/*
** EPITECH PROJECT, 2022
** B-PDG-300-PAR-3-1-PDGD09-antoine.gavira-bottari
** File description:
** Paladin
*/

#include "Paladin.hpp"

int Paladin::attack()
{
    return (Knight::attack());
}

int Paladin::special()
{
    return (Priest::Enchanter::special());
}

void Paladin::rest()
{
    Priest::rest();
}
