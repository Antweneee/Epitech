/*
** EPITECH PROJECT, 2022
** B-PDG-300-PAR-3-1-PDGD10am-antoine.gavira-bottari
** File description:
** FruitBox
*/

#include "FruitBox.hpp"

FruitBox::FruitBox(int size)
{
    _node = NULL;
    _size = size;
}

FruitBox::~FruitBox()
{
}

int FruitBox::nbFruits()
{
    FruitNode *tmp = _node;

    int nb = 0;

    for (; tmp; tmp = tmp->_next)
        nb += 1;
    return nb;
}

bool FruitBox::putFruit(Fruit *f)
{
    if (!f || nbFruits() == _size)
        return false;
    FruitNode *temp = _node;
    FruitNode *to_add = new FruitNode;
    to_add->_fruit = f;
    to_add->_next = NULL;

    if (!_node) {
        _node = to_add;
        return true;
    }
    for (; temp->_next; temp = temp->_next) {
        if (temp->_fruit == f) {
            delete to_add;
            return false;
        }
    }
    if (temp->_fruit == f) {
        delete to_add;
        return false;
    }
    temp->_next = to_add;
    return true;
}

Fruit *FruitBox::pickFruit()
{
    if (!_node)
        return NULL;

    FruitNode *new_head = _node;
    Fruit *tmp = new_head->_fruit;

    if (!_node->_next) {
        _node = NULL;
        return tmp;
    }
    _node = _node->_next;
    delete new_head;
    return tmp;
}

FruitNode *FruitBox::head()
{
    if (!_node)
        return NULL;
    return _node;
}