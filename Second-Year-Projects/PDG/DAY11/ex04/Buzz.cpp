/*
** EPITECH PROJECT, 2022
** B-PDG-300-PAR-3-1-PDGD11-antoine.gavira-bottari
** File description:
** Buzz
*/

#include "Buzz.hpp"

void Buzz::speak(std::string say)
{
    std::cout << "BUZZ: ";
    Toy::speak(say);
}