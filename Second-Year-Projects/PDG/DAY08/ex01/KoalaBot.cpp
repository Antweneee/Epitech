/*
** EPITECH PROJECT, 2022
** B-PDG-300-PAR-3-1-PDGD07pm-antoine.gavira-bottari
** File description:
** KoalaBot
*/

#include "KoalaBot.hpp"

KoalaBot::KoalaBot(std::string serial)
{
    _serial = serial;
}

KoalaBot::~KoalaBot()
{
}

void KoalaBot::setParts(Arms &arm)
{
    _arms = arm;
}

void KoalaBot::setParts(Legs &leg)
{
    _legs = leg;
}

void KoalaBot::setParts(Head &head)
{
    _head = head;
}

void KoalaBot::swapParts(Arms &arm)
{
    setParts(arm);
}

void KoalaBot::swapParts(Legs &leg)
{
    setParts(leg);
}

void KoalaBot::swapParts(Head &head)
{
    setParts(head);
}

void KoalaBot::informations()
{
    std::cout << "[KoalaBot] " << _serial << std::endl;
    _arms.informations();
    _legs.informations();
    _head.informations();
}

bool KoalaBot::status()
{
    if (_arms.isFunctional() && _legs.isFunctional() && _head.isFunctional())
        return true;
    return false;
}