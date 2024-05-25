/*
** EPITECH PROJECT, 2022
** B-PDG-300-PAR-3-1-PDGD07pm-antoine.gavira-bottari
** File description:
** KreogCom
*/

#include <iostream>
#include <string>

#include "KreogCom.hpp"

KreogCom::KreogCom(int x, int y, int serial)
{
    _x = x;
    _y = y;
    m_serial = serial;
    _next = nullptr;
    std::cout << "KreogCom "<< m_serial << " initialized" << std::endl;
}

KreogCom::~KreogCom()
{
    std::cout << "KreogCom " << m_serial << " shutting down" << std::endl;
}
void KreogCom::ping()
{
    std::cout << "KreogCom " << m_serial << " currently at " << _x << " " << _y << std::endl;
}

void KreogCom::locateSquad()
{
    KreogCom *nexxt = _next;

    while (nexxt != nullptr) {
        nexxt->ping();
        nexxt = nexxt->_next;
    }
    ping();
}

void KreogCom::addCom(int x, int y, int serial)
{
    KreogCom *new_node = new KreogCom(x, y, serial);

    if (_next == nullptr) {
        _next = new_node;
        return;
    }
    new_node->_next = _next;
    _next = new_node;
}

void KreogCom::removeCom()
{
    if (_next == NULL)
        return;

    KreogCom *to_del = _next;
    _next = _next->_next;
    delete to_del;
}

KreogCom *KreogCom::getCom()
{
    return _next;
}


