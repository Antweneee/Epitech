/*
** EPITECH PROJECT, 2022
** B-PDG-300-PAR-3-1-PDGD10am-antoine.gavira-bottari
** File description:
** FruitBox
*/

#include "FruitBox.hpp"

FruitBox::FruitBox(int size)
{
    _node = nullptr;
    _size = size;
}

FruitBox::~FruitBox()
{
}

int FruitBox::nbFruits() const
{
    FruitNode *tmp = _node;
    int nb = 0;

    for (; tmp; tmp = tmp->next)
        nb += 1;
    return nb;
}

bool FruitBox::putFruit(Fruit *f)
{
    if (!f)
        return false;
    if (nbFruits() == _size)
        return false;
    FruitNode *temp = _node;
    FruitNode *to_add = new FruitNode;
    to_add->fruit = f;
    to_add->next = NULL;

    if (!_node) {
        _node = to_add;
        return true;
    }
    for (; temp->next; temp = temp->next) {
        if (temp->fruit == f) {
            delete to_add;
            return false;
        }
    }
    if (temp->fruit == f) {
        delete to_add;
        return false;
    }
    temp->next = to_add;
    return true;
}

Fruit *FruitBox::pickFruit()
{
    if (!_node)
        return NULL;

    FruitNode *new_head = _node;
    Fruit *tmp = new_head->fruit;

    if (!_node->next) {
        _node = NULL;
        return tmp;
    }
    _node = _node->next;
    delete new_head;
    return tmp;
}

FruitNode *FruitBox::head() const
{
    if (!_node)
        return NULL;
    return _node;
}