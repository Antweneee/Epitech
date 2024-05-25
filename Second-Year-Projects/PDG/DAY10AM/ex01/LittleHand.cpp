/*
** EPITECH PROJECT, 2022
** B-PDG-300-PAR-3-1-PDGD10am-antoine.gavira-bottari
** File description:
** LittleHand
*/

#include "LittleHand.hpp"

LittleHand::LittleHand()
{
}

LittleHand::~LittleHand()
{
}

void LittleHand::sortFruitBox(FruitBox &unsorted, FruitBox &lemons, FruitBox &bananas, FruitBox &limes)
{
    FruitBox temp(unsorted.nbFruits());
    Fruit *tmp;
    bool check = false;

    while((tmp = unsorted.pickFruit()))
        temp.putFruit(tmp);
    while ((tmp = temp.pickFruit()))
    {
        if ((tmp->getName() == "lemon")) {
            if ((lemons.nbFruits() < lemons._size))
                check = lemons.putFruit(tmp);
            else
                check = false;
        } else if ((tmp->getName() == "banana")) {
            if ((bananas.nbFruits() < bananas._size))
                check = bananas.putFruit(tmp);
            else
                check = false;
        } else if ((tmp->getName() == "lime")) {
            if ((limes.nbFruits() < limes._size))
                check = limes.putFruit(tmp);
            else
                check = false;
        }
        if (check == false)
            unsorted.putFruit(tmp);
        check = false;
    }
}