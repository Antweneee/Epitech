/*
** EPITECH PROJECT, 2022
** B-PDG-300-PAR-3-1-PDGD10am-antoine.gavira-bottari
** File description:
** FruitNode
*/

#ifndef FRUITNODE_HPP_
#define FRUITNODE_HPP_

#include "Fruit.hpp"

class FruitNode
{
    public:
        FruitNode() {};
        ~FruitNode() {};
        Fruit *fruit;
        FruitNode *next;
};

#endif /* !FRUITNODE_HPP_ */
