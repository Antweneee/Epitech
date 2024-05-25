/*
** EPITECH PROJECT, 2022
** B-PDG-300-PAR-3-1-PDGD11-antoine.gavira-bottari
** File description:
** Woody
*/

#include "Woody.hpp"

void Woody::speak(std::string say)
{
    std::cout << "WOODY: ";
    Toy::speak(say);
}